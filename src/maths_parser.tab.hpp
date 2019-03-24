/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#line 1 "src/maths_parser.y" /* yacc.c:1909  */


  #include "ast.hpp"

  #include <cassert>

  extern nodePtr g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 59 "src/maths_parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_TYPEDEF = 258,
    T_EXTERN = 259,
    T_STATIC = 260,
    T_REGISTER = 261,
    T_AUTO = 262,
    T_INT = 263,
    T_VOID = 264,
    T_CHAR = 265,
    T_SHORT = 266,
    T_LONG = 267,
    T_FLOAT = 268,
    T_DOUBLE = 269,
    T_SIGNED = 270,
    T_RETURN = 271,
    T_CONST = 272,
    T_VOLATILE = 273,
    I_FLOAT = 274,
    I_CHAR = 275,
    T_IF = 276,
    T_ELSE = 277,
    T_WHILE = 278,
    T_FOR = 279,
    T_REM = 280,
    T_DO = 281,
    T_SWITCH = 282,
    T_STRUCT = 283,
    T_CASE = 284,
    T_ENUM = 285,
    T_UNION = 286,
    T_UNSIGNED = 287,
    T_TIMES = 288,
    T_DIVIDE = 289,
    T_PLUS = 290,
    T_MINUS = 291,
    T_EXPONENT = 292,
    T_EQUAL = 293,
    T_LEXCLAIM = 294,
    T_INC = 295,
    T_DEC = 296,
    T_LBRACKET = 297,
    T_RBRACKET = 298,
    T_LCBRACKET = 299,
    T_RCBRACKET = 300,
    T_LSBRACKET = 301,
    T_RSBRACKET = 302,
    T_LOG = 303,
    T_EXP = 304,
    T_SQRT = 305,
    T_LSHIFT = 306,
    T_RSHIFT = 307,
    T_ADDASSIGN = 308,
    T_SUBASSIGN = 309,
    T_MULASSIGN = 310,
    T_DIVASSIGN = 311,
    T_MODASSIGN = 312,
    T_VARIABLE = 313,
    T_COMMA = 314,
    T_SEMI_COLON = 315,
    T_COLON = 316,
    T_GO_TO = 317,
    T_CONTINUE = 318,
    T_LE = 319,
    T_GE = 320,
    T_EQ = 321,
    T_NEQ = 322,
    T_LT = 323,
    T_GT = 324,
    T_BREAK = 325,
    T_LAND = 326,
    T_LOR = 327,
    T_AND = 328,
    T_OR = 329,
    T_XOR = 330,
    T_NOT = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/maths_parser.y" /* yacc.c:1909  */

	std::string *string;
  nodePtr expr;
  float number;
  

#line 155 "src/maths_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */
