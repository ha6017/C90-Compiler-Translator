/* A Bison parser, made by GNU Bison 3.3.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/maths_parser.y" /* yacc.c:1927  */


  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 63 "src/maths_parser.tab.hpp" /* yacc.c:1927  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_VOID = 259,
    T_RETURN = 260,
    I_INT = 261,
    I_FLOAT = 262,
    I_CHAR = 263,
    T_IF = 264,
    T_ELSE = 265,
    T_WHILE = 266,
    T_FOR = 267,
    T_REM = 268,
    T_DO = 269,
    T_TIMES = 270,
    T_DIVIDE = 271,
    T_PLUS = 272,
    T_MINUS = 273,
    T_EXPONENT = 274,
    T_EQUAL = 275,
    T_LEXCLAIM = 276,
    T_LBRACKET = 277,
    T_RBRACKET = 278,
    T_LCBRACKET = 279,
    T_RCBRACKET = 280,
    T_LSBRACKET = 281,
    T_RSBRACKET = 282,
    T_LOG = 283,
    T_EXP = 284,
    T_SQRT = 285,
    T_LSHIFT = 286,
    T_RSHIFT = 287,
    T_XOR = 288,
    T_NUMBER = 289,
    T_VARIABLE = 290,
    T_COMM = 291,
    T_SEMI_COLON = 292,
    T_COLON = 293,
    T_GO_TO = 294,
    T_CONTINUE = 295,
    T_LE = 296,
    T_GE = 297,
    T_EQ = 298,
    T_NEQ = 299,
    T_LT = 300,
    T_GT = 301,
    T_BREAK = 302,
    T_LAND = 303,
    T_LOR = 304,
    T_AND = 305,
    T_OR = 306,
    T_NOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/maths_parser.y" /* yacc.c:1927  */

  const Expression *expr;
  double number;
  std::string *string;

#line 96 "src/maths_parser.tab.hpp" /* yacc.c:1927  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */
