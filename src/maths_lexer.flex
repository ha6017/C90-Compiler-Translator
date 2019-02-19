%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%
"int"			{ return T_INT; }
"void"			{ return T_VOID; }
"return"		{  return T_RETURN; }
"if"			{  return T_IF; }
"else"			{  return T_ELSE; }
"while"			{  return T_WHILE; }
"for"			{  return T_FOR; }
"do"			{  return T_DO; }
"break"			{ return T_BREAK; }
"continue"		{  return T_CONTINUE; }
"go to"			{ return T_GO_TO; }

[*]             {  return T_TIMES; }
[-]             {   return T_MINUS; }
[/]             {   return T_DIVIDE; }
[+]             {   return T_PLUS; }
[=]				{   return T_EQUAL; }

[(]             {   return T_LBRACKET; }
[)]             {   return T_RBRACKET; }

[{]             {   return T_LCBRACKET; }
[}]             {   return T_RCBRACKET; }

[\[]			{   return T_LSBRACKET; }
[\]]			{   return T_RSBRACKET; }

[,]				{   return T_COMM; }
[;]				{   return T_SEMI_COLON; }
[:]				{   return T_COLON; }

[<]				{    return T_LT; }
[>]				{    return T_GT; }
[<][=]			{   return T_LE; }
[>][=]			{    return T_GE; }
[=][=]			{    return T_EQ; }
[!][=]			{   return T_NEQ; }

[!]				{   return T_LEXCLAIM; }
[&][&]			{   return T_LAND; }
[|][|]			{   return T_LOR; }
[<][<]			{   return T_LSHIFT; }
[>][>]			{   return T_RSHIFT; }

[&]				{   return T_AND; }
[|]				{   return T_OR; }
[%]				{   return T_REM; }
[\^]				{   return T_XOR; }

[~]				{  return T_NOT; }

[-]?[0-9]+		{  yylval.number=strtod(yytext, 0); return I_INT; }



[-]?[0-9]+([.][0-9]*)? {  yylval.number=strtod(yytext, 0); return I_FLOAT;}

log             { return T_LOG;   }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

[a-z]+[a-z0-9]*          {   yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{ ;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
