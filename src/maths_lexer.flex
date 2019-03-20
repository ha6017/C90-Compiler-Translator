%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
#include <iostream>
#include "maths_parser.tab.hpp"


void debug();
bool DEBUG = false;
%}


%%

"typedef"						{debug();  yylval.string=new std::string("typedef"); return T_TYPEDEF;}
"extern"						{debug();  yylval.string=new std::string("extern"); return T_EXTERN;}
"static"						{debug();  yylval.string=new std::string("static"); return T_STATIC;}
"auto"							{debug();  yylval.string=new std::string("auto"); return T_AUTO;}
"register"						{debug();  yylval.string=new std::string("register"); return T_REGISTER;}

"void"							{debug();  yylval.string=new std::string("void"); return T_VOID;}
"char"							{debug();  yylval.string=new std::string("char"); return T_CHAR;}
"short"							{debug();  yylval.string=new std::string("short"); return T_SHORT;}
"int"							{debug();  yylval.string=new std::string("int"); return T_INT;}
"long"							{debug();  yylval.string=new std::string("long"); return T_LONG;}
"float"							{debug();  yylval.string=new std::string("float"); return T_FLOAT;}
"double"						{debug();  yylval.string=new std::string("double"); return T_DOUBLE;}
"signed"						{debug();  yylval.string=new std::string("signed"); return T_SIGNED;}

"const"							{debug();  yylval.string=new std::string("const"); return T_CONST;}
"volatile"						{debug();  yylval.string=new std::string("volatile"); return T_VOLATILE;}	

"return"						{debug();  yylval.string=new std::string("return"); return T_RETURN;}
"break"			  				{ debug();  yylval.string=new std::string("break"); return T_BREAK; }

"while"							{debug();  yylval.string=new std::string("while"); return T_WHILE;}
"if"							{debug();  yylval.string=new std::string("if"); return T_IF;}
"else"							{debug();  yylval.string=new std::string("else"); return T_ELSE;}
"for"							{debug();  yylval.string=new std::string("for"); return T_FOR;}
"do"							{debug();  yylval.string=new std::string("do"); return T_DO;}
"switch"        				{debug();  yylval.string=new std::string("switch"); return T_SWITCH; }

"continue"						{debug();  yylval.string=new std::string("continue"); return T_CONTINUE; }

"struct"  						{debug();  yylval.string=new std::string("struct"); return T_STRUCT;}

"case"    						{debug();  yylval.string=new std::string("case"); return T_CASE;}
"enum"  						{debug();  yylval.string=new std::string("enum"); return T_ENUM;}

"union" 						{debug();  yylval.string=new std::string("union"); return T_UNION;}

"unsigned"  					{debug();  yylval.string=new std::string("unsigned"); return T_UNSIGNED; }

[A-Za-z_]([A-Za-z_]|[0-9])*  	{debug();  yylval.string=new std::string(yytext); return T_VARIABLE; }

[*]             { debug();   return T_TIMES; }
[-]             { debug();  return T_MINUS; }
[/]             { debug();  return T_DIVIDE; }
[+]             { debug();  return T_PLUS; }
[=]				 {debug();  return T_EQUAL; }

[(]             { debug();  return T_LBRACKET; }
[)]             { debug();  return T_RBRACKET; }

[{]             { debug();  return T_LCBRACKET; }
[}]             { debug();  return T_RCBRACKET; }

[\[]			{ debug();  return T_LSBRACKET; }
[\]]			{ debug();  return T_RSBRACKET; }

[,]				{ debug();  return T_COMMA; }
[;]				{debug();   return T_SEMI_COLON; }
[:]				{debug();   return T_COLON; }

[<]				{ debug(); yylval.string = new std::string("<");   return T_LT; }
[>]				{ debug(); yylval.string = new std::string("<");   return T_GT; }
[<][=]			{debug();  yylval.string = new std::string("<=");   return T_LE; }
[>][=]			{debug(); yylval.string = new std::string(">=");   return T_GE; }
[=][=]			{ debug(); yylval.string = new std::string("==");   return T_EQ; }
[!][=]			{ debug(); yylval.string = new std::string("!=");  return T_NEQ; }

[!]				{ debug();  return T_LEXCLAIM; }
[&][&]			{ debug();  return T_LAND; }
[|][|]			{ debug();  return T_LOR; }
[<][<]			{ debug();  return T_LSHIFT; }
[>][>]			{ debug();  return T_RSHIFT; }

"++"    	{ return T_INC; }
"--"    	{ return T_DEC; }
"+="    { return T_ADDASSIGN; }
"-="    { return T_SUBASSIGN; }
"*="    { return T_MULASSIGN; }
"/="    { return T_DIVASSIGN; }
"%="    { return T_MODASSIGN; }

[&]				{ debug();  return T_AND; }
[|]				{ debug();  return T_OR; }
[%]				{ debug();  return T_REM; }
[\^]				{  debug(); return T_XOR; }

[~]				{  debug();return T_NOT; }
[0-9]+([.][0-9]*)? { debug(); yylval.number=strtod(yytext, 0); return I_FLOAT;}

log             { return T_LOG;   }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

"//".*		{debug();}

[ \t\r\n]+		{ debug();}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}

void debug() {
	
	if(DEBUG) {
		std::cout << yytext;
	}
	return;
}
