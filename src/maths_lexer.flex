%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
#include <iostream>
#include "maths_parser.tab.hpp"


void debug();
bool DEBUG = true;
%}


%%

"typedef"						{debug(); return T_TYPEDEF;}
"extern"						{debug();return T_EXTERN;}
"static"						{debug();return T_STATIC;}
"auto"							{debug();return T_AUTO;}
"register"					{debug();return T_REGISTER;}

"void"							{debug();return T_VOID;}
"char"							{debug();return T_CHAR;}
"short"							{debug();return T_SHORT;}
"int"								{debug();return T_INT;}
"long"							{debug();return T_LONG;}
"float"							{debug();return T_FLOAT;}
"double"						{debug();return T_DOUBLE;}
"signed"						{debug();return T_SIGNED;}

"const"							{debug();return T_CONST;}
"volatile"					{debug();return T_VOLATILE;}	

"return"						{debug();return T_RETURN;}
"break"			  { debug();return T_BREAK; }

"while"							{debug();return T_WHILE;}
"if"								{debug();return T_IF;}
"else"							{debug();return T_ELSE;}
"for"								{debug();return T_FOR;}
"do"								{debug();return T_DO;}
"switch"         {debug();return T_SWITCH; }

"continue"		{ debug(); return T_CONTINUE; }
"goto"			{debug(); return T_GO_TO; }

"struct"  {debug();return T_STRUCT;}

"case"    {debug();return T_CASE;}
"enum"  { debug();return T_ENUM;}
"register" {debug();return T_REGISTER;}

"union" {debug();return T_UNION;}

"unsigned"  {debug();return T_UNSIGNED; }

[A-Za-z_]([A-Za-z_]|[0-9])*  { debug();  yylval.string=new std::string(yytext); return T_VARIABLE; }

[*]             { debug();  return T_TIMES; }
[-]             { debug();  return T_MINUS; }
[/]             { debug();  return T_DIVIDE; }
[+]             { debug();  return T_PLUS; }
[=]				      {debug();  return T_EQUAL; }

[(]             { debug();  return T_LBRACKET; }
[)]             { debug();  return T_RBRACKET; }

[{]             { debug();  return T_LCBRACKET; }
[}]             { debug();  return T_RCBRACKET; }

[\[]			{ debug();  return T_LSBRACKET; }
[\]]			{ debug();  return T_RSBRACKET; }

[,]				{ debug();  return T_COMMA; }
[;]				{debug();   return T_SEMI_COLON; }
[:]				{debug();   return T_COLON; }

[<]				{ debug();   return T_LT; }
[>]				{ debug();   return T_GT; }
[<][=]			{debug();   return T_LE; }
[>][=]			{debug();    return T_GE; }
[=][=]			{ debug();   return T_EQ; }
[!][=]			{ debug();  return T_NEQ; }

[!]				{ debug();  return T_LEXCLAIM; }
[&][&]			{ debug();  return T_LAND; }
[|][|]			{ debug();  return T_LOR; }
[<][<]			{ debug();  return T_LSHIFT; }
[>][>]			{ debug();  return T_RSHIFT; }

[&]				{ debug();  return T_AND; }
[|]				{ debug();  return T_OR; }
[%]				{ debug();  return T_REM; }
[\^]				{  debug(); return T_XOR; }

[~]				{  debug();return T_NOT; }

[-]?[0-9]+		{ debug(); yylval.number=strtod(yytext, 0); return I_INT; }

[-]?[0-9]+([.][0-9]*)? { debug(); yylval.number=strtod(yytext, 0); return I_FLOAT;}

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
