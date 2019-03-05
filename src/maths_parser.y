%code requires{

  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Ast_node *node;
  const Expression *expr;
  double float;
  int number;
  std::string *string;
}

%token T_TYPEDEF T_EXTERN T_STATIC T_REGISTER T_AUTO
%token T_INT T_VOID T_CHAR T_SHORT T_LONG T_FLOAT T_DOUBLE T_SIGNED T_RETURN
%token T_CONST T_VOLATILE 
%token I_INT I_FLOAT I_CHAR T_IF T_ELSE T_WHILE T_FOR T_REM T_DO T_SWITCH
%token T_STRUCT T_CASE T_ENUM T_UNION T_UNSIGNED
%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT T_EQUAL T_LEXCLAIM
%token T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET T_LSBRACKET T_RSBRACKET
%token T_LOG T_EXP T_SQRT T_LSHIFT T_RSHIFT 
%token T_NUMBER T_VARIABLE 

%token T_COMMA T_SEMI_COLON T_COLON T_GO_TO  T_CONTINUE
%token T_LE T_GE T_EQ T_NEQ T_LT T_GT T_BREAK 
%token T_LAND T_LOR T_AND T_OR T_XOR T_NOT


%type <node> STATEMENT RETURN_STATEMENT PROGRAM FUNCTION_DECLARATION VARIABLE_DECLARATION ASSIGNMENT_STATEMENT 
%type <node> SCOPE STATEMENT_LIST PARAMETER PARAMETER_LIST PROGRAM_LIST FOR_STATEMENT 
%type <node> IF_CONDITION_STATEMENT IF_ELSE_CONDITION_STATEMENT WHILE_CONDITION_STATEMENT VARIABLE_DECLARATION_FUNCTION
%type <node> RETURN_LIST RETURN_VALUE ARRAY_DECLARATION DO_WHILE_STATEMENT
%type <expr> EXPR EXPR10 EXPR11 EXPR12 EXPR13 EXPR3 EXPR4 EXPR5 EXPR6 EXPR7 EXPR8 EXPR9
%type <number> I_INT
%type <string> T_VARIABLE T_INT T_VOID 
%type <Float> I_FLOAT

%start ROOT

%%

ROOT : 	PROG_LIST{ g_root = $1; }

PROG_LIST: PROG PROG_LIST { $$ = new ProgList($1,$2);} DONE
			      | PROG { $$ = new Prog($1);} DONE

			
PROG : FUNC_DEC { $$ = $1; }
		| VAR_DEC	{ $$ = $1; }
	
FUNC_DEC :	 T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON { $$ = new FuncProto(*$1,*$2); } DONE
						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_SEMI_COLON { $$ = new FuncProto(*$1,*$2); }	 DONE					
						| T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,$6);}  DONE
						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,$6);}  DONE
						| T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,NULL);}  DONE
						| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_LCBRACKET T_RCBRACKET {$$ = new FuncDef(*$1,*$2,NULL,NULL);}  DONE
						| T_INT T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,$7);}  DONE
						| T_VOID T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET T_LCBRACKET SCOPE T_RCBRACKET {$$ = new FuncDef(*$1,*$2,$4,$7);}  DONE
	
PARAMETER_LIST :  PARAMETER T_COMMA PARAMETER_LIST {$$ = new ParameterList($1, $3);}
				| PARAMETER { $$ = $1;}

PARAMETER : T_INT T_VARIABLE { $$ = new VariableDeclaration2(*$1,*$2, NULL, true);}
		| EXPR {$$ = new ParameterDef($1);}
		
SCOPE:
		STATEMENT_LIST { $$ = $1; }
	
STATEMENT_LIST :  STATEMENT T_SEMI_COLON STATEMENT_LIST {$$ = new BranchList($1, $3);}
				| STATEMENT T_SEMI_COLON {$$ = $1;}
				| STATEMENT STATEMENT_LIST {$$ = new BranchList($1, $2);}
				| STATEMENT {$$ = $1;}
				
		
STATEMENT :
	RETURN_STATEMENT { $$ = $1; }
	| IF_CONDITION_STATEMENT { $$ = $1; }
	| ARRAY_DECLARATION { $$ = $1;}
	| IF_ELSE_CONDITION_STATEMENT { $$ = $1; }
	| WHILE_CONDITION_STATEMENT { $$ = $1; }
	| VARIABLE_DECLARATION_FUNCTION { $$  = $1; }
	| ASSIGNMENT_STATEMENT { $$  = $1; }
	| FOR_STATEMENT { $$ = $1;}
	| DO_WHILE_STATEMENT { $$ = $1;} 
	//| T_GO_TO T_VARIABLE { $$ = new Jump(*$2);} 
	//| T_BREAK { $$ = new Break();} 
	//| T_CONTINUE { $$ = new Continue();} 
	//| T_VARIABLE T_COLON { $$ = new Label(*$1);} 

	
	
	
// Local Variables	
VARIABLE_DECLARATION_FUNCTION :
	| T_INT T_VARIABLE { $$ = new InitInt(*$2, NULL);}
	| T_INT T_VARIABLE T_EQUAL EXPR  { $$ = new InitInt(*$2,$4); }

//ARRAY_DECLARATION:
//	T_INT T_VARIABLE T_LSBRACKET I_INT T_RSBRACKET { $$ = new ArrayDeclaration(*$2, $4);}
	
	
	
// Global Variables	
VARIABLE_DECLARATION :
	| T_INT T_VARIABLE T_SEMI_COLON { $$ = new InitInt(*$2, NULL);}
	| T_INT T_VARIABLE T_EQUAL EXPR T_SEMI_COLON { $$ = new InitInt(*$2,$4); }

ASSIGNMENT_STATEMENT :
	| T_VARIABLE T_EQUAL EXPR { $$ = new AssignEqual(*$1,$3);} DONE
	| T_VARIABLE T_PLUS T_PLUS {$$ = new PostIncrement(*$1);}  DONE
	| T_PLUS T_PLUS T_VARIABLE { $$ = new PreIncrement(*$3);}  DONE
	| T_VARIABLE T_MINUS T_MINUS {$$ = new PostDecrement(*$1);} DONE
	| T_MINUS T_MINUS T_VARIABLE { $$ = new PreDecrement(*$3);} DONE
	| T_VARIABLE T_PLUS T_EQUAL EXPR { $$ =  new PlusEqual(*$1,$4);}  DONE
	| T_VARIABLE T_MINUS T_EQUAL EXPR { $$ =  new SubEqual(*$1,$4);}  DONE
	| T_VARIABLE T_TIMES T_EQUAL EXPR { $$ =  new MultEqual(*$1,$4);}  DONE
	| T_VARIABLE T_DIVIDE T_EQUAL EXPR { $$ =  new DivEqual(*$1,$4);}  DONE
	| T_VARIABLE T_REM T_EQUAL EXPR { $$ =  new RemEqual(*$1,$4);}  DONE
//	| T_VARIABLE T_EQUAL T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET { $$ = new FuncCall(*$1,*$3,$5); }
//	| T_VARIABLE T_EQUAL T_VARIABLE T_LBRACKET T_RBRACKET { $$ = new FuncCall(*$1,*$3,NULL); }
		
	
IF_CONDITION_STATEMENT : T_IF T_LBRACKET EXPR T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new If($3,$6);} DONE
					| T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT { $$ = new If($3,$5);} DONE
IF_ELSE_CONDITION_STATEMENT : T_IF T_LBRACKET EXPR T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET T_ELSE T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new IfElse($3,$6,$10);} DONE
					| T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT T_ELSE STATEMENT { $$ = new IfElse($3,$5,$7);} DONE
WHILE_CONDITION_STATEMENT : T_WHILE T_LBRACKET EXPR T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new While($3,$6);} DONE

FOR_STATEMENT : T_FOR T_LBRACKET VARIABLE_DECLARATION_FUNCTION T_SEMI_COLON EXPR T_SEMI_COLON ASSIGNMENT_STATEMENT T_RBRACKET T_LCBRACKET STATEMENT_LIST T_RCBRACKET { $$ = new For($3,$5,$7,$10);} DONE

DO_WHILE_STATEMENT : T_DO T_LCBRACKET STATEMENT_LIST T_RCBRACKET T_WHILE T_LBRACKET EXPR T_RBRACKET { $$ = new DoWhile($7, $3);} DONE

RETURN_STATEMENT : T_RETURN RETURN_LIST {$$ = new ReturnStatement(NULL, $2);}	

									
RETURN_LIST : RETURN_VALUE T_PLUS RETURN_LIST {$$ = new ReturnList($1,$3);}
			| RETURN_VALUE T_MINUS RETURN_LIST {$$ = new MinReturnList($1,$3);}
			| RETURN_VALUE T_TIMES RETURN_LIST {$$ = new MulReturnList($1,$3);}
			| RETURN_VALUE {$$ = new ReturnList($1,NULL); }
			
RETURN_VALUE: T_VARIABLE T_LBRACKET PARAMETER_LIST T_RBRACKET { $$ = new FuncCall(*$1,$3); } DONE
			| T_VARIABLE T_LBRACKET T_RBRACKET { $$ = new FuncCall(*$1,NULL); }  DONE
			| EXPR {$$ = $1;}
	
	
EXPR : 	T_NOT EXPR3 {$$ = new  LogNot(NULL,$2);}  DONE
		| EXPR3 { $$ = $1;}
        
		
EXPR3 :		| EXPR3 T_DIVIDE EXPR4  { $$ = new Div($1,$3);}   DONE
			| EXPR3 T_TIMES EXPR4 { $$ = new Mult($1,$3);}   DONE
			| EXPR3 T_REM EXPR4 { $$ = new Mod($1,$3);}  DONE
			| EXPR4 { $$ = $1;}
		
EXPR4 : 	| EXPR4  T_PLUS EXPR5   { $$ = new Add($1,$3); }   DONE
			| EXPR4  T_MINUS EXPR5  { $$ = new Sub($1,$3); }  DONE
			| EXPR4  I_INT  { $$ = new SpecialSubOperator($1,$2); }
			| EXPR5 { $$ = $1;}

EXPR5 :		  EXPR5 T_LSHIFT  EXPR6 {$$ = new LShift($1,$3);} DONE
			| EXPR5 T_RSHIFT EXPR6 {$$ = new RShift($1,$3);} DONE
			| EXPR6 { $$ = $1;}
			
			
			
EXPR6 :		 EXPR6 T_LE EXPR7	{ $$ = new LessOrEqual($1,$3); }  DONE
			| EXPR6 T_GE EXPR7 	{ $$ = new GreaterOrEqual ($1,$3); } DONE
		    | EXPR6 T_LT EXPR7	{ $$ = new Less($1,$3);}  DONE
			| EXPR6 T_GT EXPR7	{ $$ = new Greater ($1,$3); } DONE
			| EXPR7 { $$ = $1;}
		
EXPR7 :		| EXPR7 T_EQ  EXPR8	{ $$ = new CondEqual($1,$3);  }  DONE
			| EXPR7 T_NEQ EXPR8	{ $$ = new NotEqual($1, $3);} DONE
			| EXPR8 { $$ = $1;}
			
EXPR8 :		EXPR8 T_AND  EXPR9	{ $$ = new BitAnd($1,$3); } DONE
			| EXPR9 { $$ = $1;}
			
EXPR9 :		EXPR9 T_XOR  EXPR10	{ $$ = new BitXor($1,$3); } DONE
			| EXPR10 { $$ = $1;}
			
EXPR10 :	EXPR10 T_OR  EXPR11	{ $$ = new BitOr($1,$3); } DONE
			| EXPR11 { $$ = $1;}


EXPR11 :	 EXPR11 T_LAND EXPR12	{ $$ = new LogAnd($1, $3); } DONE
			| EXPR12 { $$ = $1;}
			
EXPR12 :	EXPR12 T_LOR EXPR13	{ $$ = new LogOr($1, $3);  } DONE
			| EXPR13 { $$ = $1;}

EXPR13 :
     T_LBRACKET EXPR T_RBRACKET { $$ = $2; }
	| T_VARIABLE {$$ = new Variable( *$1 ); } DONE
	| I_INT   { $$ = new Number( $1); } DONE


%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
