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
    I_INT = 274,
    I_FLOAT = 275,
    I_CHAR = 276,
    T_IF = 277,
    T_ELSE = 278,
    T_WHILE = 279,
    T_FOR = 280,
    T_REM = 281,
    T_DO = 282,
    T_SWITCH = 283,
    T_STRUCT = 284,
    T_CASE = 285,
    T_ENUM = 286,
    T_UNION = 287,
    T_UNSIGNED = 288,
    T_TIMES = 289,
    T_DIVIDE = 290,
    T_PLUS = 291,
    T_MINUS = 292,
    T_EXPONENT = 293,
    T_EQUAL = 294,
    T_LEXCLAIM = 295,
    T_LBRACKET = 296,
    T_RBRACKET = 297,
    T_LCBRACKET = 298,
    T_RCBRACKET = 299,
    T_LSBRACKET = 300,
    T_RSBRACKET = 301,
    T_LOG = 302,
    T_EXP = 303,
    T_SQRT = 304,
    T_LSHIFT = 305,
    T_RSHIFT = 306,
    T_NUMBER = 307,
    T_VARIABLE = 308,
    T_COMMA = 309,
    T_SEMI_COLON = 310,
    T_COLON = 311,
    T_GO_TO = 312,
    T_CONTINUE = 313,
    T_LE = 314,
    T_GE = 315,
    T_EQ = 316,
    T_NEQ = 317,
    T_LT = 318,
    T_GT = 319,
    T_BREAK = 320,
    T_LAND = 321,
    T_LOR = 322,
    T_AND = 323,
    T_OR = 324,
    T_XOR = 325,
    T_NOT = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/maths_parser.y" /* yacc.c:1927  */

  const Ast_node *node;
  const Expression *expr;
  double float;
  int number;
  std::string *string;

#line 155 "src/maths_parser.tab.hpp" /* yacc.c:1927  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */
