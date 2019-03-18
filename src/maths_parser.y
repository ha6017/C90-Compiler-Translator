%code requires{

  #include "ast.hpp"

  #include <cassert>

  extern nodePtr g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}
//%define parse.error verbose
// Represents the value associated with any kind of
// AST node.
%union {
	std::string *string;
  nodePtr expr;
  float number;
  
}

%token T_TYPEDEF T_EXTERN T_STATIC T_REGISTER T_AUTO
%token T_INT T_VOID T_CHAR T_SHORT T_LONG T_FLOAT T_DOUBLE T_SIGNED T_RETURN
%token T_CONST T_VOLATILE 
%token I_INT I_FLOAT I_CHAR T_IF T_ELSE T_WHILE T_FOR T_REM T_DO T_SWITCH
%token T_STRUCT T_CASE T_ENUM T_UNION T_UNSIGNED
%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT T_EQUAL T_LEXCLAIM T_INC T_DEC
%token T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET T_LSBRACKET T_RSBRACKET
%token T_LOG T_EXP T_SQRT T_LSHIFT T_RSHIFT T_ADDASSIGN T_SUBASSIGN T_MULASSIGN T_DIVASSIGN T_MODASSIGN
%token T_VARIABLE 

%token T_COMMA T_SEMI_COLON T_COLON T_GO_TO  T_CONTINUE
%token T_LE T_GE T_EQ T_NEQ T_LT T_GT T_BREAK 
%token T_LAND T_LOR T_AND T_OR T_XOR T_NOT


%type <expr> STATEMENT EXPR_STATEMENT RETURN_STATEMENT PROGRAM FUNCTION_DECLARATION VARIABLE_DECLARATION ASSIGNMENT_STATEMENT DEC_STATEMENT DEC_VAR_LIST
%type <expr> NEW_SCOPE SCOPE STATEMENT_LIST PARAMETER PARAMETER_LIST PROGRAM_LIST FOR_STATEMENT PARAMETER_LIST_NO_TYPE VAL_LIST GLO_DEC_VAR_LIST
%type <expr> IF_CONDITION_STATEMENT IF_OR_ELSE IF_ELSE_CONDITION_STATEMENT WHILE_STATEMENT VARIABLE_DECLARATION_FUNCTION GLO_DEC_VARIABLE
%type <expr> RETURN_VALUE DO_WHILE_STATEMENT RETURN_LIST
%type <expr> EXPR EXPR10 EXPR11 EXPR12 EXPR2 EXPR3 EXPR4 EXPR5 EXPR6 EXPR7 EXPR8 EXPR9 EXPR13 EXPR14 EXPR15 EXPR16 
%type <number> I_INT
%type <string> T_VARIABLE T_INT T_VOID T_CHAR T_SHORT T_LONG T_FLOAT T_DOUBLE T_SIGNED T_UNSIGNED 
%type <string> TYPE_NAME
// %type <Float> I_FLOAT

%start ROOT

%%

/* --------------------------- START NODE  ------------------------------- */

ROOT : PROGRAM_LIST{ g_root = $1; };

PROGRAM_LIST: 	PROGRAM_LIST FUNCTION_DECLARATION 		 	{ $$ = new Top_List($2, $1);}
			|	PROGRAM_LIST VARIABLE_DECLARATION    		{ $$ = new Top_List($2,$1); }
       	 	| 	FUNCTION_DECLARATION                  		{ $$ = new Top_List($1, NULL); }
        	| 	VARIABLE_DECLARATION             			{ $$ = new Top_List($1, NULL); }
			;

FUNCTION_DECLARATION : 		TYPE_NAME T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET { $$ = new FuncDef(*$1, *$2, $4, $7); }
        				 | 	TYPE_NAME T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET { $$ = new FuncDef(*$1, *$2, NULL, $6); }
       					 | 	TYPE_NAME T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_SEMI_COLON { $$ = new FuncCall(*$1, *$2, $4); }
       					 | 	TYPE_NAME T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON { $$ = new FuncCall(*$1, *$2, NULL); }
						;

PARAMETER_LIST : PARAMETER_LIST T_COMMA TYPE_NAME T_VARIABLE         { $$ = new Argument(*$3, *$4, $1); }
        | TYPE_NAME T_VARIABLE                                     { $$ = new Argument(*$1, *$2, NULL); }
		;
PARAMETER_LIST_NO_TYPE : PARAMETER_LIST_NO_TYPE T_COMMA EXPR15    { $$ = new ArgumentNoType($3, $1); }
        | EXPR15                                                { $$ = new ArgumentNoType($1, NULL); }                                         
		;
TYPE_NAME : 	T_CHAR          { $$ = $1; }
        | T_SIGNED         		{ $$ = $1; }
        | T_UNSIGNED        	{ $$ = $1; }
        | T_SHORT               { $$ = $1; }
        | T_INT                 { $$ = $1; }      
        | T_LONG                { $$ = $1; }
        | T_FLOAT               { $$ = $1; }
        | T_DOUBLE              { $$ = $1; }
        | T_VOID                { $$ = $1; }
		;

SCOPE : SCOPE STATEMENT           { $$ = new BranchList($2,$1); }
        | STATEMENT             { $$ = new BranchList($1, NULL); }
		;
    
STATEMENT :  	RETURN_STATEMENT           	  { $$ = $1; }
        	| 	DEC_STATEMENT                 { $$ = $1; }
        	| 	EXPR_STATEMENT                { $$ = $1; }
        	| 	IF_OR_ELSE                    { $$ = $1; }
        	| 	WHILE_STATEMENT               { $$ = $1; }
        	| 	DO_WHILE_STATEMENT            { $$ = $1; }
        	| 	NEW_SCOPE                     { $$ = $1; }
        	| 	FOR_STATEMENT                 { $$ = $1; }
			;

EXPR_STATEMENT : EXPR16 T_SEMI_COLON             { $$ = new ExprStatement($1); }
        | T_SEMI_COLON                           { $$ = new ExprStatement(NULL); }
		;

FOR_STATEMENT : T_FOR T_LBRACKET DEC_STATEMENT EXPR_STATEMENT EXPR16 T_RBRACKET STATEMENT       { $$ = new For($3,$4,$5,$7);}
        | T_FOR T_LBRACKET EXPR_STATEMENT EXPR_STATEMENT EXPR16 T_RBRACKET STATEMENT            { $$ = new For($3,$4,$5,$7);}
        | T_FOR T_LBRACKET DEC_STATEMENT EXPR_STATEMENT T_RBRACKET STATEMENT                    { $$ = new For($3,$4,$6, NULL);}
        | T_FOR T_LBRACKET EXPR_STATEMENT EXPR_STATEMENT T_RBRACKET STATEMENT                   { $$ = new For($3,$4,$6, NULL);}

NEW_SCOPE : T_LCBRACKET SCOPE T_RCBRACKET      { $$ = new NewScope($2); }

RETURN_STATEMENT : T_RETURN EXPR16 T_SEMI_COLON          { $$ = new ReturnStatement($2); }
        | T_RETURN T_SEMI_COLON                          { $$ = new ReturnStatement(NULL); }
		//| T_RETURN T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON	{$$ = new FuncProto(*$2, NULL);}
		//| T_RETURN T_VARIABLE T_LBRACKET T_

DEC_STATEMENT : TYPE_NAME DEC_VAR_LIST T_SEMI_COLON      { $$ = new DeclareStatement(*$1, $2); }
       
DEC_VAR_LIST : VARIABLE_DECLARATION                     { $$ = new Dec_Var_List($1, NULL); }
        | DEC_VAR_LIST T_COMMA VARIABLE_DECLARATION     { $$ = new Dec_Var_List($3,$1); }

VARIABLE_DECLARATION : T_VARIABLE T_EQUAL EXPR15             { $$ = new Declare(*$1, $3); }  
        | T_VARIABLE                                  { $$ = new Declare(*$1, NULL); }

VARIABLE_DECLARATION : TYPE_NAME GLO_DEC_VAR_LIST T_SEMI_COLON   { $$ = new DeclareStatement(*$1, $2); }

GLO_DEC_VAR_LIST : GLO_DEC_VARIABLE                     { $$ = new Dec_Var_List($1, NULL); }
        | GLO_DEC_VAR_LIST T_COMMA GLO_DEC_VARIABLE     { $$ = new Dec_Var_List($3,$1); }

GLO_DEC_VARIABLE : T_VARIABLE T_EQUAL I_INT                       { $$ = new GlobalDeclare(*$1, $3); } 
        | T_VARIABLE T_EQUAL T_MINUS I_INT                        { $$ = new GlobalDeclare(*$1, -$4); }
        | T_VARIABLE T_EQUAL T_LBRACKET I_INT T_RBRACKET          { $$ = new GlobalDeclare(*$1, $4); } 
        | T_VARIABLE T_EQUAL T_LBRACKET T_MINUS I_INT T_RBRACKET  { $$ = new GlobalDeclare(*$1, -$5); } 
        | T_VARIABLE                                                  { $$ = new GlobalDeclare(*$1); }

IF_OR_ELSE : T_IF EXPR16 STATEMENT T_ELSE STATEMENT      { $$ = new IfElse($2,$3,$5); }
        | T_IF EXPR16 STATEMENT                                 { $$ = new If($2,$3); }

WHILE_STATEMENT : T_WHILE EXPR16 STATEMENT                              { $$ = new While($2,$3); }

DO_WHILE_STATEMENT : T_DO STATEMENT T_WHILE EXPR16 T_SEMI_COLON                { $$ = new DoWhile($4,$2); }


// PROGRAM_LIST: PROGRAM PROGRAM_LIST { $$ = new ProgList($1,$2);} 
// 			| PROGRAM { $$ = new Program($1);}

			
// PROGRAM : FUNCTION_DECLARATION { $$ = $1; }
// 		| VARIABLE_DECLARATION	{ $$ = $1; }
	
// FUNCTION_DECLARATION :	 T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON { $$ = new FuncProto(*$1, *$2); }
// 						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON { $$ = new FuncProto(*$1, *$2); }						
// 						| T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,$6);}
// 						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,$6);}
// 						| T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,NULL);}
// 						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,NULL);}
// 						| T_INT T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,$7);}
// 						| T_VOID T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,$7);}
// 						| T_INT T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,NULL);}
// 						| T_VOID T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,NULL);}
	

// PARAMETER_LIST :  PARAMETER T_COMMA PARAMETER_LIST {$$ = new ParamList($1, $3);}
// 				| PARAMETER { $$ = $1;}

// PARAMETER : EXPR15 {$$ = new ParameterDef($1);}
// 		|	T_INT T_VARIABLE { $$ = new LocalInitInt(*$1,*$2, NULL);}

		
// SCOPE: STATEMENT_LIST { $$ = $1; }

// STATEMENT_LIST :  STATEMENT T_SEMI_COLON STATEMENT_LIST {$$ = new BranchList($1, $3);}
// 				| STATEMENT T_SEMI_COLON {$$ = $1;}
// 				| STATEMENT STATEMENT_LIST {$$ = new BranchList($1, $2);}
// 				| STATEMENT {$$ = $1;}

// STATEMENT: IF_CONDITION_STATEMENT { $$ = $1; }
// 	| RETURN_STATEMENT { $$ = $1; }
// 	| IF_ELSE_CONDITION_STATEMENT { $$ = $1; }
// 	| WHILE_STATEMENT { $$ = $1; } 
// 	| VARIABLE_DECLARATION_FUNCTION { $$  = $1; }
// 	| ASSIGNMENT_STATEMENT { $$  = $1; }
// 	| FOR_STATEMENT { $$ = $1;}
// 	| DO_WHILE_STATEMENT { $$ = $1;} 
// 	| T_BREAK { $$ = new Break();} 
// 	| T_CONTINUE { $$ = new Continue();} 

	

// ASSIGNMENT_STATEMENT :  T_VARIABLE T_EQUAL T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET { $$ = new FuncCall(*$1,*$3,$5); }
// 	| T_VARIABLE T_EQUAL T_VARIABLE T_LBRACKET T_RBRACKET { $$ = new FuncCall(*$1,*$3,NULL); }

// FOR_STATEMENT : T_FOR T_LBRACKET VARIABLE_DECLARATION_FUNCTION T_SEMI_COLON EXPR15 T_SEMI_COLON EXPR15 T_RBRACKET T_LCBRACKET STATEMENT T_RCBRACKET { $$ = new For($3,$5,$7,$10);} 

// RETURN_STATEMENT: 	T_RETURN EXPR15 T_SEMI_COLON {$$ = new ReturnStatement($2);}	
//  				|	T_RETURN T_SEMI_COLON {$$ = new ReturnStatement(NULL);}

									
// // RETURN_LIST : 	RETURN_VALUE T_PLUS RETURN_LIST {$$ = new ReturnList($1,$3);}
// // 			| 	RETURN_VALUE T_MINUS RETURN_LIST {$$ = new MinReturnList($1,$3);}
// // 			| 	RETURN_VALUE T_TIMES RETURN_LIST {$$ = new MulReturnList($1,$3);}
// // 			| 	RETURN_VALUE {$$ = new ReturnList($1,NULL); }
			
// // RETURN_VALUE: 	EXPR15 {$$ = $1;}
// // 			|	T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET { $$ = new FuncCall(*$1,$3); } 
// // 			|	T_VARIABLE T_LBRACKET T_RBRACKET { $$ = new FuncCall(*$1,NULL); }  
			
// // Local Variables	
// VARIABLE_DECLARATION_FUNCTION: 	T_INT T_VARIABLE { $$ = new LocalInitInt(*$1, *$2, NULL);}
// 							| 	T_INT T_VARIABLE T_EQUAL EXPR  { $$ = new LocalInitInt(*$1, *$2, $4); }

// // //GLOBAL VARIABLE DECLARATION
// VARIABLE_DECLARATION:	T_INT T_VARIABLE T_SEMI_COLON { $$ = new GlobalInitInt(*$1, *$2, NULL);}
// 					| 	T_INT T_VARIABLE T_EQUAL EXPR T_SEMI_COLON { $$ = new GlobalInitInt(*$1,*$2,$4); }

// IF_CONDITION_STATEMENT : T_IF T_LBRACKET EXPR15 T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new If($3,$6);} 
//  						| T_IF T_LBRACKET EXPR15 T_RBRACKET STATEMENT { $$ = new If($3,$5);} 
// IF_ELSE_CONDITION_STATEMENT : T_IF T_LBRACKET EXPR15 T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET T_ELSE T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new IfElse($3,$6,$10);} 
//  							| T_IF T_LBRACKET EXPR15 T_RBRACKET STATEMENT T_ELSE STATEMENT { $$ = new IfElse($3,$5,$7);}

// WHILE_STATEMENT : T_WHILE T_LBRACKET EXPR15 T_RBRACKET T_LCBRACKET STATEMENT T_RCBRACKET { $$ = new While($3, $6);} 

// DO_WHILE_STATEMENT : T_DO T_LCBRACKET STATEMENT T_RCBRACKET T_WHILE T_LBRACKET EXPR15 T_RBRACKET { $$ = new DoWhile($7, $3);} 

EXPR16: 	EXPR15 {$$=$1;}
 		|	EXPR16 T_COMMA EXPR15	{$$ = new Comma($1, $3);}

EXPR15: 		EXPR {$$ = $1;}
			|	T_VARIABLE T_EQUAL EXPR15 { $$ = new AssignEqual(*$1,$3);}
			|	T_VARIABLE T_ADDASSIGN EXPR15 { $$ =  new PlusEqual(*$1,$3);}  
		 	| 	T_VARIABLE T_SUBASSIGN EXPR15 { $$ =  new SubEqual(*$1,$3);}  
			| 	T_VARIABLE T_MULASSIGN EXPR15 { $$ =  new MultEqual(*$1,$3);}  
			| 	T_VARIABLE T_DIVASSIGN EXPR15 { $$ =  new DivEqual(*$1,$3);}  
			| 	T_VARIABLE T_MODASSIGN EXPR15 { $$ =  new RemEqual(*$1,$3);} 
			// and assign?
			// or assign?
			// left assign?
			// right assighn?
			// xor assighn?
	
EXPR : 			T_NOT EXPR2 {$$ = new  LogNot($2);}  
			| 	EXPR2 { $$ = $1;}

EXPR2 :			EXPR2 T_LOR EXPR3	{ $$ = new LogOr($1, $3);  } 
			| 	EXPR3 { $$ = $1;}

EXPR3 :	 		EXPR3 T_LAND EXPR4	{$$ = new LogAnd($1,$3);}
			| 	EXPR4 { $$ = $1;}

EXPR4 :			EXPR4 T_OR  EXPR5	{ $$ = new BitOr($1,$3); } 
			|	EXPR5 { $$ = $1;}

EXPR5 :			EXPR5 T_XOR  EXPR6	{ $$ = new BitXor($1,$3); } 
			| 	EXPR6 { $$ = $1;}

EXPR6 :			EXPR6 T_AND  EXPR7	{ $$ = new BitAnd($1,$3); } 
			| 	EXPR7 { $$ = $1;}

EXPR7 :		 	EXPR7 T_EQ  EXPR8	{ $$ = new CondEqual($1,$3);}  
			| 	EXPR7 T_NEQ EXPR8	{ $$ = new NotEqual($1, $3);} 
			| 	EXPR8 { $$ = $1;}

EXPR8 :		 	EXPR8 T_LE EXPR9	{ $$ = new LessOrEqual($1,$3); }  
			| 	EXPR8 T_GE EXPR9 	{ $$ = new GreaterOrEqual ($1,$3); } 
		    | 	EXPR8 T_LT EXPR9	{ $$ = new Less($1,$3);}  
			| 	EXPR8 T_GT EXPR9	{ $$ = new Greater ($1,$3); } 
			| 	EXPR9 { $$ = $1;}
        
EXPR9 :		  	EXPR9 T_LSHIFT  EXPR10 {$$ = new LShift($1,$3);} 
			| 	EXPR9 T_RSHIFT EXPR10 {$$ = new RShift($1,$3);} 
			| 	EXPR10 { $$ = $1;}

EXPR10 : 	 	EXPR10  T_PLUS EXPR11   { $$ = new Add($1,$3); }   
			| 	EXPR10  T_MINUS EXPR11  { $$ = new Sub($1,$3); }  
			| 	EXPR11 { $$ = $1;}

EXPR11 :		EXPR11 T_DIVIDE EXPR12  { $$ = new Div($1,$3);}   
			| 	EXPR11 T_TIMES EXPR12 { $$ = new Mult($1,$3);}   
			| 	EXPR11 T_REM EXPR12 { $$ = new Mod($1,$3);}  
			| 	EXPR12 { $$ = $1;}

EXPR12:  		
				T_INC T_VARIABLE { $$ = new PreIncrement(*$2);}  
			| 	T_DEC T_VARIABLE { $$ = new PreDecrement(*$2);}
			|	EXPR13 {$$ = $1;}
	
EXPR13: 		
				T_VARIABLE T_INC {$$ = new PostIncrement(*$1);}  
			| 	T_VARIABLE T_DEC {$$ = new PostDecrement(*$1);} 
			| 	T_VARIABLE T_LBRACKET PARAMETER_LIST_NO_TYPE T_RBRACKET      { $$ = new FunctionStatementInExpr(*$1,$3); }
			| 	T_VARIABLE T_LBRACKET T_RBRACKET      { $$ = new FunctionStatementInExpr(*$1, NULL); }	
			|	EXPR14 {$$ = $1;}

EXPR14 :		T_LBRACKET EXPR16 T_RBRACKET { $$ = $2; }
			| 	T_VARIABLE {$$ = new Variable( *$1 ); } 
			| 	I_INT   { $$ = new Number( $1, 0); } 
			//| 	T_MINUS I_INT   { $$ = new Number( 0, $2); } 


  EXPR16: 	EXPR15 {$$=$1;}
	|	EXPR16 T_COMMA EXPR15	{$$ = new Comma($1, $3);}
%%


nodePtr g_root; // Definition of variable (to match declaration earlier)

nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
 