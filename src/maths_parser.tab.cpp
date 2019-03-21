/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/maths_parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "maths_parser.tab.hpp".  */
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
#line 1 "src/maths_parser.y" /* yacc.c:355  */


  #include "ast.hpp"

  #include <cassert>

  extern nodePtr g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 112 "src/maths_parser.tab.cpp" /* yacc.c:355  */

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
#line 18 "src/maths_parser.y" /* yacc.c:355  */

	std::string *string;
  nodePtr expr;
  float number;
  

#line 208 "src/maths_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "src/maths_parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  280

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    58,    59,    60,    61,    64,    65,    66,
      67,    70,    71,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    87,    88,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   107,   108,
     109,   110,   112,   114,   115,   117,   118,   119,   120,   121,
     123,   124,   126,   127,   129,   130,   132,   134,   135,   137,
     138,   139,   140,   141,   143,   144,   146,   148,   232,   233,
     235,   236,   237,   238,   239,   240,   241,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   260,
     261,   263,   264,   266,   267,   269,   270,   272,   273,   275,
     276,   278,   279,   280,   282,   283,   284,   285,   286,   288,
     289,   290,   292,   293,   294,   296,   297,   298,   299,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   322,   323,
     324,   325,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TYPEDEF", "T_EXTERN", "T_STATIC",
  "T_REGISTER", "T_AUTO", "T_INT", "T_VOID", "T_CHAR", "T_SHORT", "T_LONG",
  "T_FLOAT", "T_DOUBLE", "T_SIGNED", "T_RETURN", "T_CONST", "T_VOLATILE",
  "I_FLOAT", "I_CHAR", "T_IF", "T_ELSE", "T_WHILE", "T_FOR", "T_REM",
  "T_DO", "T_SWITCH", "T_STRUCT", "T_CASE", "T_ENUM", "T_UNION",
  "T_UNSIGNED", "T_TIMES", "T_DIVIDE", "T_PLUS", "T_MINUS", "T_EXPONENT",
  "T_EQUAL", "T_LEXCLAIM", "T_INC", "T_DEC", "T_LBRACKET", "T_RBRACKET",
  "T_LCBRACKET", "T_RCBRACKET", "T_LSBRACKET", "T_RSBRACKET", "T_LOG",
  "T_EXP", "T_SQRT", "T_LSHIFT", "T_RSHIFT", "T_ADDASSIGN", "T_SUBASSIGN",
  "T_MULASSIGN", "T_DIVASSIGN", "T_MODASSIGN", "T_VARIABLE", "T_COMMA",
  "T_SEMI_COLON", "T_COLON", "T_GO_TO", "T_CONTINUE", "T_LE", "T_GE",
  "T_EQ", "T_NEQ", "T_LT", "T_GT", "T_BREAK", "T_LAND", "T_LOR", "T_AND",
  "T_OR", "T_XOR", "T_NOT", "$accept", "ROOT", "PROGRAM_LIST",
  "FUNCTION_DECLARATION", "PARAMETER_LIST", "PARAMETER_LIST_NO_TYPE",
  "TYPE_NAME", "SCOPE", "STATEMENT", "EXPR_STATEMENT", "FOR_STATEMENT",
  "NEW_SCOPE", "RETURN_STATEMENT", "DEC_STATEMENT", "VAL_LIST",
  "DEC_VAR_LIST", "VARIABLE_DECLARATION", "GLOBLE_VARIABLE_DECLARATION",
  "GLO_DEC_VAR_LIST", "GLO_DEC_VARIABLE", "IF_OR_ELSE", "WHILE_STATEMENT",
  "DO_WHILE_STATEMENT", "EXPR16", "EXPR15", "EXPR", "EXPR2", "EXPR3",
  "EXPR4", "EXPR5", "EXPR6", "EXPR7", "EXPR8", "EXPR9", "EXPR10", "EXPR11",
  "EXPR12", "EXPR13", "EXPR14", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

#define YYPACT_NINF -233

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-233)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     489,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
      11,   489,  -233,   -45,  -233,  -233,  -233,  -233,   115,    62,
    -233,   -12,   464,   -26,  -233,  -233,    16,   -11,    18,    46,
     -20,    27,  -233,  -233,    24,    55,   368,  -233,    53,   489,
    -233,  -233,    59,    51,  -233,   413,   413,    54,   368,   -13,
      41,    36,    56,   413,   368,   470,  -233,  -233,  -233,   244,
      68,    40,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,   119,  -233,  -233,    45,    48,    58,    67,    78,   122,
     142,   143,   173,     9,  -233,  -233,  -233,   368,  -233,    96,
    -233,  -233,   163,   161,   161,   405,   133,   145,   158,  -233,
    -233,  -233,   120,   137,    61,   230,   413,  -233,  -233,   105,
     -10,   413,   413,   413,   413,   413,    45,    -7,   174,  -233,
    -233,  -233,   413,  -233,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   299,  -233,  -233,   146,  -233,   241,   241,   413,
    -233,     8,    21,    52,  -233,  -233,  -233,  -233,    64,  -233,
     139,   172,  -233,  -233,  -233,  -233,  -233,   413,   -14,   171,
    -233,  -233,    48,    58,    67,    78,   122,   142,   142,   143,
     143,   143,   143,   173,   173,     9,     9,  -233,  -233,  -233,
    -233,   368,   310,   330,   176,   203,   233,   208,   240,   214,
     250,  -233,   413,   429,   217,  -233,   226,   259,   249,   251,
    -233,  -233,   368,    69,   368,    72,  -233,   177,   256,  -233,
     257,  -233,   258,  -233,   413,  -233,  -233,   413,   413,   413,
     413,   413,   477,   260,   269,   252,  -233,   368,  -233,   368,
     207,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,   413,
    -233,  -233,   413,   413,   413,   413,   413,   253,   281,   413,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,   413,   277,
      80,   265,    84,   413,  -233,   413,  -233,    93,   265,  -233
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    23,    15,    18,    20,    21,    22,    16,    17,
       0,     2,     5,     0,     6,     1,     3,     4,    63,     0,
      57,     0,     0,     0,    56,    59,     0,     0,     0,     0,
       0,    63,    58,    60,     0,     0,     0,    10,     0,     0,
      12,    61,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    37,    35,    34,     0,
       0,     0,    25,    28,    33,    32,    26,    27,    29,    30,
      31,     0,    68,    70,    90,    92,    94,    96,    98,   100,
     103,   108,   111,   114,   118,   127,   137,     0,     9,     0,
      62,    44,     0,     0,     0,     0,     0,     0,   138,   122,
     139,   121,   119,   120,     0,     0,     0,   129,   130,     0,
       0,     0,     0,     0,     0,     0,    89,    55,     0,    52,
       8,    24,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    43,    65,    66,     0,     0,     0,
     140,     0,     0,     0,   128,    42,    71,   132,     0,    14,
       0,     0,    72,    73,    74,    75,    76,     0,     0,     0,
      45,    69,    91,    93,    95,    97,    99,   101,   102,   104,
     105,   106,   107,   109,   110,   112,   113,   117,   116,   115,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   141,     0,    54,     0,     0,     0,    55,
      53,    64,     0,     0,     0,     0,    67,   141,     0,   123,
       0,   124,     0,    13,     0,   133,   134,     0,     0,     0,
       0,     0,   142,    46,     0,     0,    41,     0,    40,     0,
     142,   125,   126,    77,    78,    79,    80,    81,    82,     0,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    38,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    50,     0,     0,    49,     0,    47,     0,    51,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,  -233,  -233,   315,  -233,  -233,    79,   -50,   -47,   -79,
    -233,  -233,  -233,   232,  -232,  -233,   159,   319,  -233,   309,
    -233,  -233,  -233,   -43,   -94,  -233,   274,   212,   213,   211,
     215,   219,   128,    81,   132,   154,    87,   245,  -233
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    29,   158,    60,    61,    62,    63,
      64,    65,    66,    67,   270,   118,   119,    14,    19,    20,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      92,    96,    93,    94,   105,   206,    44,    25,    34,   160,
     104,    15,   156,    18,   121,   159,   147,   162,   163,   164,
     165,   166,   207,    97,    26,    35,   161,   195,   171,    53,
      27,   167,    31,   208,   139,    33,   272,   142,    40,   168,
     197,   277,   140,   141,   196,    98,   145,   146,     1,     2,
       3,     4,     5,     6,     7,     8,    43,   198,   121,    44,
     100,    45,    36,    46,    47,    21,    48,    41,   192,   193,
      44,   199,     9,   205,    42,    49,    50,    97,    37,    13,
      51,    52,    53,    53,    54,   120,    49,    50,   200,    38,
      13,    51,    52,    53,   102,   121,    95,    87,    55,    98,
      56,    30,    90,    57,   154,    39,   194,   201,   223,    55,
      58,    91,   237,    88,   103,   239,    59,   124,    89,   125,
     122,    23,    24,   202,    44,   274,   117,    59,   122,   276,
     243,   122,   126,   244,   245,   246,   247,   248,   279,   275,
      49,    50,   127,   275,   211,    51,    52,    53,   157,   213,
     215,   128,   275,    21,   143,   262,   149,    22,   263,   264,
     265,   266,   267,    55,   150,   236,   152,   238,   191,     1,
       2,     3,     4,     5,     6,     7,     8,    43,   122,   123,
      44,    59,    45,   153,    46,    47,   203,    48,   129,   130,
     260,   204,   261,     9,   135,   136,    49,    50,   107,   108,
     109,    51,    52,    53,   151,    54,   131,   132,   137,   138,
     133,   134,   179,   180,   181,   182,   271,   225,   226,    55,
     122,    56,   122,   144,    57,   271,   187,   188,   189,   209,
     271,    58,   278,   169,   170,   122,   216,    59,     1,     2,
       3,     4,     5,     6,     7,     8,    43,   250,   251,    44,
     217,    45,   218,    46,    47,   219,    48,   177,   178,   220,
      44,   221,     9,    44,   232,    49,    50,   183,   184,   222,
      51,    52,    53,   233,    54,   155,    49,    50,   234,    49,
      50,    51,    52,    53,    51,    52,    53,   235,    55,   167,
      56,   185,   186,    57,    99,   101,   259,   268,   257,    55,
      58,    56,    98,   240,   241,   242,    59,     1,     2,     3,
       4,     5,     6,     7,     8,    43,   258,    59,    44,   269,
      45,   273,    46,    47,   122,    48,    16,   148,   210,    44,
      17,     9,    32,   116,    49,    50,   172,   174,   173,    51,
      52,    53,   175,    54,   190,    49,    50,   176,     0,    44,
      51,    52,    53,   212,     0,     0,     0,    55,     0,    56,
       0,     0,    57,     0,     0,    49,    50,     0,    55,    58,
      51,    52,    53,   214,     0,    59,     1,     2,     3,     4,
       5,     6,     7,     8,    43,     0,    59,    44,    55,    45,
       0,    46,    47,     0,    48,     0,     0,     0,     0,     0,
       9,     0,     0,    49,    50,     0,    59,     0,    51,    52,
      53,     0,    54,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    44,     0,    55,     0,    56,     0,
       0,    57,    44,     0,     0,     0,     0,     9,    58,     0,
      49,    50,     0,     0,    59,    51,    52,    53,    49,    50,
       0,     0,     0,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,   224,     0,   225,
     226,    55,     1,     2,     3,     4,     5,     6,     7,     8,
       0,    59,   227,   228,   229,   230,   231,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     9,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     0,    28,   106,     0,
     107,   108,   109,     0,     0,   249,   110,   250,   251,     0,
       0,     9,     0,   111,   112,   113,   114,   115,     0,     0,
     252,   253,   254,   255,   256
};

static const yytype_int16 yycheck[] =
{
      43,    48,    45,    46,    54,    19,    19,    19,    19,    19,
      53,     0,   106,    58,    61,   109,    95,   111,   112,   113,
     114,   115,    36,    36,    36,    36,    36,    19,   122,    42,
      42,    38,    58,    47,    25,    19,   268,    87,    58,    46,
      19,   273,    33,    34,    36,    58,    93,    94,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    36,   105,    19,
      19,    21,    44,    23,    24,    38,    26,    43,   147,   148,
      19,    19,    32,   167,    19,    35,    36,    36,    60,     0,
      40,    41,    42,    42,    44,    45,    35,    36,    36,    43,
      11,    40,    41,    42,    58,   142,    42,    44,    58,    58,
      60,    22,    43,    63,    43,    59,   149,    43,   202,    58,
      70,    60,    43,    60,    58,    43,    76,    72,    39,    71,
      59,    59,    60,    59,    19,    45,    58,    76,    59,    45,
     224,    59,    74,   227,   228,   229,   230,   231,    45,    59,
      35,    36,    75,    59,   191,    40,    41,    42,    43,   192,
     193,    73,    59,    38,    58,   249,    23,    42,   252,   253,
     254,   255,   256,    58,    19,   212,    46,   214,    22,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    59,    60,
      19,    76,    21,    46,    23,    24,    47,    26,    66,    67,
     237,    19,   239,    32,    51,    52,    35,    36,    40,    41,
      42,    40,    41,    42,    46,    44,    64,    65,    35,    36,
      68,    69,   131,   132,   133,   134,   259,    40,    41,    58,
      59,    60,    59,    60,    63,   268,   139,   140,   141,    58,
     273,    70,   275,    59,    60,    59,    60,    76,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    40,    41,    19,
      47,    21,    19,    23,    24,    47,    26,   129,   130,    19,
      19,    47,    32,    19,    47,    35,    36,   135,   136,    19,
      40,    41,    42,    47,    44,    45,    35,    36,    19,    35,
      36,    40,    41,    42,    40,    41,    42,    38,    58,    38,
      60,   137,   138,    63,    49,    50,    44,    44,    38,    58,
      70,    60,    58,    47,    47,    47,    76,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    47,    76,    19,    38,
      21,    44,    23,    24,    59,    26,    11,    95,   169,    19,
      11,    32,    23,    59,    35,    36,   124,   126,   125,    40,
      41,    42,   127,    44,    45,    35,    36,   128,    -1,    19,
      40,    41,    42,    43,    -1,    -1,    -1,    58,    -1,    60,
      -1,    -1,    63,    -1,    -1,    35,    36,    -1,    58,    70,
      40,    41,    42,    43,    -1,    76,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    76,    19,    58,    21,
      -1,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    -1,    76,    -1,    40,    41,
      42,    -1,    44,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    58,    -1,    60,    -1,
      -1,    63,    19,    -1,    -1,    -1,    -1,    32,    70,    -1,
      35,    36,    -1,    -1,    76,    40,    41,    42,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    -1,    38,    -1,    40,
      41,    58,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    76,    53,    54,    55,    56,    57,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    32,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    43,    38,    -1,
      40,    41,    42,    -1,    -1,    38,    46,    40,    41,    -1,
      -1,    32,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    32,
      78,    79,    80,    83,    94,     0,    80,    94,    58,    95,
      96,    38,    42,    59,    60,    19,    36,    42,    43,    81,
      83,    58,    96,    19,    19,    36,    44,    60,    43,    59,
      58,    43,    19,    16,    19,    21,    23,    24,    26,    35,
      36,    40,    41,    42,    44,    58,    60,    63,    70,    76,
      83,    84,    85,    86,    87,    88,    89,    90,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    44,    60,    83,
      43,    60,   100,   100,   100,    42,    85,    36,    58,   114,
      19,   114,    58,    58,   100,    84,    38,    40,    41,    42,
      46,    53,    54,    55,    56,    57,   103,    58,    92,    93,
      45,    85,    59,    60,    72,    71,    74,    75,    73,    66,
      67,    64,    65,    68,    69,    51,    52,    35,    36,    25,
      33,    34,    84,    58,    60,    85,    85,    86,    90,    23,
      19,    46,    46,    46,    43,    45,   101,    43,    82,   101,
      19,    36,   101,   101,   101,   101,   101,    38,    46,    59,
      60,   101,   104,   105,   106,   107,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   113,
      45,    22,    86,    86,   100,    19,    36,    19,    36,    19,
      36,    43,    59,    47,    19,   101,    19,    36,    47,    58,
      93,    85,    43,   100,    43,   100,    60,    47,    19,    47,
      19,    47,    19,   101,    38,    40,    41,    53,    54,    55,
      56,    57,    47,    47,    19,    38,    85,    43,    85,    43,
      47,    47,    47,   101,   101,   101,   101,   101,   101,    38,
      40,    41,    53,    54,    55,    56,    57,    38,    47,    44,
      85,    85,   101,   101,   101,   101,   101,   101,    44,    38,
      91,   100,    91,    44,    45,    59,    45,    91,   100,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    88,    89,    89,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    95,    95,    96,
      96,    96,    96,    96,    97,    97,    98,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     8,     7,     6,
       5,     4,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     7,     7,
       6,     6,     3,     3,     2,     3,     5,     9,    10,     8,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     3,
       4,     5,     6,     1,     5,     3,     3,     5,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     6,     6,     6,
       6,     6,     6,     7,     7,     7,     7,     7,     7,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     5,     5,     6,     6,     1,     3,     2,
       2,     4,     3,     5,     5,     6,     6,     1,     1,     1,
       2,     4,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "src/maths_parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].expr); }
#line 1559 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), (yyvsp[-1].expr));}
#line 1565 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1571 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1577 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 61 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1583 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-7].string), *(yyvsp[-6].string), (yyvsp[-4].expr), (yyvsp[-1].expr)); }
#line 1589 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-6].string), *(yyvsp[-5].string), NULL, (yyvsp[-1].expr)); }
#line 1595 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].expr)); }
#line 1601 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-4].string), *(yyvsp[-3].string), NULL); }
#line 1607 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), (yyvsp[-3].expr)); }
#line 1613 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), NULL); }
#line 1619 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1625 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 74 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), NULL); }
#line 1631 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 76 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1637 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1643 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 78 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1649 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 79 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1655 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1661 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1667 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1673 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 83 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1679 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1685 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1691 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr), NULL); }
#line 1697 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1703 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1709 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1715 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1721 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1727 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 96 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1733 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1739 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 98 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1745 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 99 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Break();}
#line 1751 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 100 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Continue();}
#line 1757 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 103 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement((yyvsp[-1].expr)); }
#line 1763 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 104 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement(NULL); }
#line 1769 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1775 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1781 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1787 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1793 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 112 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NewScope((yyvsp[-1].expr)); }
#line 1799 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 114 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement((yyvsp[-1].expr)); }
#line 1805 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 115 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement(NULL); }
#line 1811 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 117 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 1817 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 118 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[-1].number), NULL);}
#line 1823 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 119 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-8].string), *(yyvsp[-7].string), (yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1829 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 120 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-9].string), *(yyvsp[-8].string), -(yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1835 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 121 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-7].string), *(yyvsp[-6].string), 0, (yyvsp[-1].expr)); }
#line 1841 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 123 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new ArrayList((yyvsp[0].expr), NULL);}
#line 1847 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 124 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrayList((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1853 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 126 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 1859 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 127 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 1865 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 129 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[0].expr)); }
#line 1871 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 130 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[0].string), NULL); }
#line 1877 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 132 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 1883 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 1889 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 1895 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 137 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-2].string), (yyvsp[0].number)); }
#line 1901 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 138 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 1907 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 139 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-4].string), (yyvsp[-1].number)); }
#line 1913 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 140 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-5].string), -(yyvsp[-1].number)); }
#line 1919 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 141 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[0].string)); }
#line 1925 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 143 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IfElse((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1931 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 144 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 1937 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 146 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new While((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 1943 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 148 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoWhile((yyvsp[-1].expr),(yyvsp[-3].expr)); }
#line 1949 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 232 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 1955 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 233 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Comma((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1961 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 235 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1967 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 236 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 1973 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 237 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 1979 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 238 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 1985 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 239 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 1991 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 240 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 1997 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 241 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2003 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 247 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-5].string),(yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2009 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 248 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number));}
#line 2015 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 249 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2021 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 250 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2027 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 251 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2033 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 252 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2039 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 253 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2045 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 254 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number));}
#line 2051 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 255 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2057 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 256 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2063 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 257 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2069 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 258 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2075 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 260 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new  LogNot((yyvsp[0].expr));}
#line 2081 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 261 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2087 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 263 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogOr((yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 2093 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 264 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2099 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 266 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LogAnd((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2105 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 267 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2111 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 269 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitOr((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2117 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 270 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2123 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 272 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitXor((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2129 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 273 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2135 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 275 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitAnd((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2141 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 276 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2147 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 278 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CondEqual((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2153 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 279 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NotEqual((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2159 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 280 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2165 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 282 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LessOrEqual((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2171 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 283 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GreaterOrEqual ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2177 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 284 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Less((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2183 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 285 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Greater ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2189 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 286 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2195 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 288 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2201 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 289 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2207 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 290 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2213 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 292 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Add((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2219 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 293 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Sub((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2225 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 294 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2231 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 296 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Div((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2237 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 297 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mult((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2243 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 298 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mod((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2249 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 299 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2255 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 301 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[0].string), -1);}
#line 2261 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 302 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[0].string), -1);}
#line 2267 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 303 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryNeg((yyvsp[0].expr));}
#line 2273 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 304 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryPos((yyvsp[0].expr));}
#line 2279 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 305 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2285 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 306 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2291 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 307 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2297 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 308 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2303 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 309 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2309 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 311 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2315 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 312 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostIncrement(*(yyvsp[-1].string), -1);}
#line 2321 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 313 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostDecrement(*(yyvsp[-1].string), -1);}
#line 2327 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 314 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 2333 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 315 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-2].string), NULL); }
#line 2339 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 316 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2345 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 317 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2351 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 318 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2357 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 319 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2363 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 320 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2369 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 322 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Variable( *(yyvsp[0].string) ); }
#line 2375 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 323 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( (yyvsp[0].number), 0); }
#line 2381 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 324 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( 0, (yyvsp[0].number)); }
#line 2387 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 325 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2393 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 326 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2399 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2403 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 331 "src/maths_parser.y" /* yacc.c:1906  */



nodePtr g_root; // Definition of variable (to match declaration earlier)

nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
 
