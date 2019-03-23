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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

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
       0,    55,    55,    57,    58,    59,    60,    61,    62,    65,
      66,    67,    68,    71,    72,    74,    75,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    96,    97,   100,   101,
     102,   103,   104,   105,   106,   107,   109,   110,   117,   118,
     121,   122,   123,   124,   127,   130,   131,   134,   135,   136,
     137,   138,   139,   142,   143,   146,   147,   150,   151,   154,
     155,   156,   157,   158,   161,   162,   164,   167,   168,   170,
     171,   172,   173,   174,   176,   177,   178,   180,   182,   184,
     185,   187,   188,   189,   190,   191,   192,   193,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     212,   213,   215,   216,   218,   219,   221,   222,   224,   225,
     227,   228,   230,   231,   232,   234,   235,   236,   237,   238,
     240,   241,   242,   244,   245,   246,   248,   249,   250,   251,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   274,
     275,   276,   277,   278
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
  "DEC_VAR_LIST", "VARIABLE_DECLARATION", "GLOBAL_ARRAY_DECLARATION",
  "GLOBAL_VAL_LIST", "GLOBLE_VARIABLE_DECLARATION", "GLO_DEC_VAR_LIST",
  "GLO_DEC_VARIABLE", "IF_OR_ELSE", "WHILE_STATEMENT",
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

#define YYPACT_NINF -222

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-222)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     461,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
       9,   461,  -222,   -45,  -222,  -222,  -222,  -222,  -222,  -222,
     235,    60,  -222,   -15,   445,    52,   -35,  -222,  -222,    31,
      51,   -36,    13,   110,   124,   112,   143,   148,  -222,  -222,
     145,   180,   374,  -222,    16,   461,  -222,   -16,   159,   165,
    -222,   160,    54,  -222,   384,   384,   169,   374,   384,    79,
     210,   410,   166,   177,   384,   374,   441,  -222,  -222,  -222,
     187,    22,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,    65,  -222,  -222,   175,   179,   202,   204,   197,    84,
     245,   167,   207,   203,  -222,  -222,  -222,   374,  -222,   224,
     247,  -222,   -13,   293,  -222,  -222,   206,   181,   181,    94,
     231,   181,   312,   137,  -222,  -222,  -222,   175,   261,   287,
      32,   248,   384,  -222,  -222,   191,    91,   384,   384,   384,
     384,   384,    40,   226,  -222,  -222,  -222,   384,  -222,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   311,  -222,   293,
     292,  -222,  -222,   -17,  -222,   320,  -222,   122,   122,   384,
    -222,  -222,   103,   104,   119,  -222,  -222,  -222,  -222,    38,
    -222,   307,   347,  -222,  -222,  -222,  -222,  -222,   384,    64,
     309,  -222,  -222,   179,   202,   204,   197,    84,   245,   245,
     167,   167,   167,   167,   207,   207,   203,   203,  -222,  -222,
    -222,  -222,    73,   293,   308,   351,   374,   259,   322,   237,
     325,   354,   332,   372,   345,   375,  -222,   384,   451,   349,
    -222,   352,   383,   366,   367,  -222,   348,   108,  -222,  -222,
    -222,   374,    85,   374,   100,  -222,   275,   360,  -222,   364,
    -222,   365,  -222,   384,  -222,  -222,   384,   384,   384,   384,
     384,   462,   379,   380,   377,  -222,   362,  -222,   374,  -222,
     374,   288,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
     384,  -222,  -222,   384,   384,   384,   384,   384,   386,   390,
     384,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
     384,   387,   111,   376,   139,   384,  -222,   384,  -222,   156,
     376,  -222
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    25,    17,    20,    22,    23,    24,    18,    19,
       0,     2,     6,     0,     8,     7,     1,     3,     5,     4,
      73,     0,    67,     0,     0,     0,     0,    66,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    68,    70,
       0,     0,     0,    12,     0,     0,    14,     0,     0,     0,
      71,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,    39,    37,    36,
       0,     0,    27,    30,    35,    34,    28,    29,    31,    32,
      33,     0,    79,    81,   101,   103,   105,   107,   109,   111,
     114,   119,   122,   125,   129,   138,   148,     0,    11,     0,
       0,    59,     0,     0,    72,    46,     0,     0,     0,     0,
       0,     0,     0,   149,   133,   150,   132,   100,   130,   131,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    55,    10,    26,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,    61,    64,     0,    45,    75,    77,     0,     0,     0,
      76,   151,     0,     0,     0,   139,    44,    82,   143,     0,
      16,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,    47,    80,   102,   104,   106,   108,   110,   112,   113,
     115,   116,   117,   118,   120,   121,   123,   124,   128,   127,
     126,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,   152,     0,
      57,     0,     0,     0,    58,    56,     0,     0,    63,    65,
      74,     0,     0,     0,     0,    78,   152,     0,   134,     0,
     135,     0,    15,     0,   144,   145,     0,     0,     0,     0,
       0,   153,    48,     0,     0,    60,     0,    43,     0,    42,
       0,   153,   136,   137,    88,    89,    90,    91,    92,    93,
       0,   146,   147,     0,     0,     0,     0,     0,     0,    49,
       0,    62,    41,    40,    94,    95,    96,    97,    98,    99,
       0,     0,     0,    53,     0,     0,    52,     0,    50,     0,
      54,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,   422,  -222,  -222,    29,   -58,   -56,   -99,
    -222,  -222,  -222,   327,  -221,  -222,   249,   427,  -154,   429,
    -222,   415,  -222,  -222,  -222,   -52,  -111,  -222,   382,   310,
     321,   306,   323,   305,   195,   229,   194,   196,   149,   300,
    -222
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    32,   179,    70,    71,    72,    73,
      74,    75,    76,    77,   302,   133,   134,    14,   163,    15,
      21,    22,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     106,   110,   107,   108,    28,   212,   111,   121,    42,    16,
     167,   177,   120,    20,   180,   136,   183,   184,   185,   186,
     187,    29,   100,    37,    43,   160,   192,    30,   214,    13,
       1,     2,     3,     4,     5,     6,     7,     8,    52,   157,
      13,    53,   215,    54,   101,    55,    56,   161,    57,    58,
      39,   165,   166,    33,     9,   170,    44,    59,    60,   237,
      97,    61,    62,    63,    64,   136,    65,   135,   217,   218,
      40,    34,    45,    53,    99,   175,    98,   230,   188,   304,
      66,   226,    67,   231,   309,    68,   189,    41,    35,    59,
      60,   137,    69,    61,    62,    63,    64,   227,    53,    36,
     232,   136,     1,     2,     3,     4,     5,     6,     7,     8,
     181,   233,    66,    53,   105,   112,   252,   219,   236,    26,
      27,    64,   220,   222,   137,   138,     9,   182,   268,    59,
      60,    48,   215,    61,    62,    63,    64,   113,   224,   221,
     223,    53,   274,   270,   137,   275,   276,   277,   278,   279,
     144,   145,    66,   266,    67,   225,   306,    59,    60,   137,
     240,    61,    62,    63,    64,   242,   244,   215,    46,   294,
     307,    47,   295,   296,   297,   298,   299,   123,   124,   125,
      66,    49,    67,   172,   308,   267,    23,   269,    50,     1,
       2,     3,     4,     5,     6,     7,     8,    52,   307,    51,
      53,   311,    54,   104,    55,    56,   102,    57,    58,   103,
      53,   109,   292,     9,   293,   307,    59,    60,   150,   151,
      61,    62,    63,    64,   118,    65,    59,    60,   154,   115,
      61,    62,    63,    64,   178,   119,   155,   156,   303,    66,
     137,    67,   152,   153,    68,   132,   112,   139,   303,    66,
     140,    69,    64,   303,   169,   310,     1,     2,     3,     4,
       5,     6,     7,     8,    52,   137,   164,    53,   113,    54,
     143,    55,    56,    23,    57,    58,   141,    24,    53,   142,
       9,    25,   158,    59,    60,   190,   191,    61,    62,    63,
      64,   159,    65,   176,    59,    60,   137,   245,    61,    62,
      63,    64,   241,   208,   209,   210,    66,   173,    67,   146,
     147,    68,   162,   148,   149,   254,   255,    66,    69,     1,
       2,     3,     4,     5,     6,     7,     8,    52,   281,   282,
      53,   171,    54,   174,    55,    56,   213,    57,    58,   198,
     199,    53,   216,     9,   204,   205,    59,    60,   206,   207,
      61,    62,    63,    64,   228,    65,   211,    59,    60,   114,
     116,    61,    62,    63,    64,   243,   229,   234,   238,    66,
     239,    67,   246,   247,    68,   200,   201,   202,   203,   248,
      66,    69,     1,     2,     3,     4,     5,     6,     7,     8,
      52,   249,   250,    53,   251,    54,   261,    55,    56,   262,
      57,    58,   263,    53,   264,   188,     9,   271,   265,    59,
      60,   272,   273,    61,    62,    63,    64,   288,    65,    59,
      60,   290,   291,    61,    62,    63,    64,   289,   301,    53,
     300,   305,    66,    17,    67,   137,   168,    68,    18,   235,
      19,    38,    66,   117,    69,    59,    60,   195,   197,   193,
      62,    63,    64,     1,     2,     3,     4,     5,     6,     7,
       8,   194,     0,     0,     0,   196,     0,     0,   113,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,   122,
       0,   123,   124,   125,     0,     0,     0,   126,    31,   253,
       0,   254,   255,     9,   127,   128,   129,   130,   131,     0,
     280,     0,   281,   282,   256,   257,   258,   259,   260,     0,
       0,     0,     0,     0,     0,   283,   284,   285,   286,   287
};

static const yytype_int16 yycheck[] =
{
      52,    57,    54,    55,    19,   159,    58,    65,    44,     0,
     109,   122,    64,    58,   125,    71,   127,   128,   129,   130,
     131,    36,    38,    58,    60,    38,   137,    42,    45,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    97,
      11,    19,    59,    21,    60,    23,    24,    60,    26,    27,
      19,   107,   108,    24,    32,   111,    43,    35,    36,   213,
      44,    39,    40,    41,    42,   121,    44,    45,   167,   168,
      19,    19,    59,    19,    45,    43,    60,   188,    38,   300,
      58,    43,    60,    19,   305,    63,    46,    36,    36,    35,
      36,    59,    70,    39,    40,    41,    42,    59,    19,    47,
      36,   157,     8,     9,    10,    11,    12,    13,    14,    15,
      19,    47,    58,    19,    60,    36,   227,   169,    45,    59,
      60,    42,    19,    19,    59,    60,    32,    36,    43,    35,
      36,    19,    59,    39,    40,    41,    42,    58,    19,    36,
      36,    19,   253,    43,    59,   256,   257,   258,   259,   260,
      66,    67,    58,    45,    60,    36,    45,    35,    36,    59,
     216,    39,    40,    41,    42,   217,   218,    59,    58,   280,
      59,    47,   283,   284,   285,   286,   287,    40,    41,    42,
      58,    38,    60,    46,    45,   241,    38,   243,    43,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    59,    19,
      19,    45,    21,    43,    23,    24,    47,    26,    27,    44,
      19,    42,   268,    32,   270,    59,    35,    36,    51,    52,
      39,    40,    41,    42,    58,    44,    35,    36,    25,    19,
      39,    40,    41,    42,    43,    58,    33,    34,   290,    58,
      59,    60,    35,    36,    63,    58,    36,    72,   300,    58,
      71,    70,    42,   305,    23,   307,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    59,    60,    19,    58,    21,
      73,    23,    24,    38,    26,    27,    74,    42,    19,    75,
      32,    46,    58,    35,    36,    59,    60,    39,    40,    41,
      42,    44,    44,    45,    35,    36,    59,    60,    39,    40,
      41,    42,    43,   154,   155,   156,    58,    46,    60,    64,
      65,    63,    19,    68,    69,    40,    41,    58,    70,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    40,    41,
      19,    19,    21,    46,    23,    24,    44,    26,    27,   144,
     145,    19,    22,    32,   150,   151,    35,    36,   152,   153,
      39,    40,    41,    42,    47,    44,    45,    35,    36,    59,
      60,    39,    40,    41,    42,    43,    19,    58,    60,    58,
      19,    60,    47,    19,    63,   146,   147,   148,   149,    47,
      58,    70,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    19,    47,    19,    19,    21,    47,    23,    24,    47,
      26,    27,    19,    19,    38,    38,    32,    47,    60,    35,
      36,    47,    47,    39,    40,    41,    42,    38,    44,    35,
      36,    44,    60,    39,    40,    41,    42,    47,    38,    19,
      44,    44,    58,    11,    60,    59,   109,    63,    11,   190,
      11,    26,    58,    61,    70,    35,    36,   141,   143,   139,
      40,    41,    42,     8,     9,    10,    11,    12,    13,    14,
      15,   140,    -1,    -1,    -1,   142,    -1,    -1,    58,     8,
       9,    10,    11,    12,    13,    14,    15,    32,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    43,    38,
      -1,    40,    41,    32,    53,    54,    55,    56,    57,    -1,
      38,    -1,    40,    41,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    32,
      78,    79,    80,    83,    94,    96,     0,    80,    94,    96,
      58,    97,    98,    38,    42,    46,    59,    60,    19,    36,
      42,    43,    81,    83,    19,    36,    47,    58,    98,    19,
      19,    36,    44,    60,    43,    59,    58,    47,    19,    38,
      43,    19,    16,    19,    21,    23,    24,    26,    27,    35,
      36,    39,    40,    41,    42,    44,    58,    60,    63,    70,
      83,    84,    85,    86,    87,    88,    89,    90,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    44,    60,    83,
      38,    60,    47,    44,    43,    60,   102,   102,   102,    42,
      85,   102,    36,    58,   116,    19,   116,   105,    58,    58,
     102,    84,    38,    40,    41,    42,    46,    53,    54,    55,
      56,    57,    58,    92,    93,    45,    85,    59,    60,    72,
      71,    74,    75,    73,    66,    67,    64,    65,    68,    69,
      51,    52,    35,    36,    25,    33,    34,    84,    58,    44,
      38,    60,    19,    95,    60,    85,    85,    86,    90,    23,
      85,    19,    46,    46,    46,    43,    45,   103,    43,    82,
     103,    19,    36,   103,   103,   103,   103,   103,    38,    46,
      59,    60,   103,   106,   107,   108,   109,   110,   111,   111,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,    45,    95,    44,    45,    59,    22,    86,    86,   102,
      19,    36,    19,    36,    19,    36,    43,    59,    47,    19,
     103,    19,    36,    47,    58,    93,    45,    95,    60,    19,
      85,    43,   102,    43,   102,    60,    47,    19,    47,    19,
      47,    19,   103,    38,    40,    41,    53,    54,    55,    56,
      57,    47,    47,    19,    38,    60,    45,    85,    43,    85,
      43,    47,    47,    47,   103,   103,   103,   103,   103,   103,
      38,    40,    41,    53,    54,    55,    56,    57,    38,    47,
      44,    60,    85,    85,   103,   103,   103,   103,   103,   103,
      44,    38,    91,   102,    91,    44,    45,    59,    45,    91,
     102,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    96,    97,    97,    98,
      98,    98,    98,    98,    99,    99,    99,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     8,
       7,     6,     5,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       7,     7,     6,     6,     3,     3,     2,     3,     5,     6,
       9,    10,     8,     1,     3,     1,     3,     3,     1,     6,
      10,     7,    11,     9,     1,     3,     3,     1,     3,     3,
       4,     5,     6,     1,     5,     3,     3,     3,     5,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     6,     6,     6,     7,     7,     7,     7,     7,     7,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     5,     5,     6,     6,     1,     3,
       2,     2,     4,     3,     5,     5,     6,     6,     1,     1,
       1,     2,     4,     5
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
#line 55 "src/maths_parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].expr); }
#line 1573 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), (yyvsp[-1].expr));}
#line 1579 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1585 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1591 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1597 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1603 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1609 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-7].string), *(yyvsp[-6].string), (yyvsp[-4].expr), (yyvsp[-1].expr)); }
#line 1615 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-6].string), *(yyvsp[-5].string), NULL, (yyvsp[-1].expr)); }
#line 1621 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].expr)); }
#line 1627 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-4].string), *(yyvsp[-3].string), NULL); }
#line 1633 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 71 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), (yyvsp[-3].expr)); }
#line 1639 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 72 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), NULL); }
#line 1645 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1651 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), NULL); }
#line 1657 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1663 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1669 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1675 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1681 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1687 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 82 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1693 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 83 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1699 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 84 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1705 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 85 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1711 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 96 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1717 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 97 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr), NULL); }
#line 1723 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 100 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1729 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 101 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1735 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 102 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1741 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 103 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1747 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 104 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1753 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 105 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1759 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 106 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1765 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 107 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1771 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 109 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Break();}
#line 1777 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Continue();}
#line 1783 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement((yyvsp[-1].expr)); }
#line 1789 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 118 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement(NULL); }
#line 1795 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 121 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1801 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1807 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 123 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1813 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 124 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1819 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NewScope((yyvsp[-1].expr)); }
#line 1825 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement((yyvsp[-1].expr)); }
#line 1831 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement(NULL); }
#line 1837 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 134 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 1843 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[-1].number), NULL);}
#line 1849 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-1].number), NULL);}
#line 1855 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-8].string), *(yyvsp[-7].string), (yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1861 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-9].string), *(yyvsp[-8].string), -(yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1867 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-7].string), *(yyvsp[-6].string), 0, (yyvsp[-1].expr)); }
#line 1873 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new ArrayList((yyvsp[0].expr), NULL);}
#line 1879 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 143 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrayList((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1885 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 146 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 1891 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 1897 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[0].expr)); }
#line 1903 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 151 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[0].string), NULL); }
#line 1909 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 154 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].number), NULL);}
#line 1915 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 155 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-9].string), *(yyvsp[-8].string), (yyvsp[-6].number), (yyvsp[-2].expr));}
#line 1921 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 156 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-6].string), *(yyvsp[-5].string), (yyvsp[-2].number), NULL);}
#line 1927 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 157 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-10].string), *(yyvsp[-9].string), -(yyvsp[-6].number), (yyvsp[-2].expr)); }
#line 1933 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 158 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-8].string), *(yyvsp[-7].string), 0, (yyvsp[-2].expr)); }
#line 1939 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 161 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new GlobalArrayList(NULL, (yyvsp[0].number));}
#line 1945 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 162 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalArrayList((yyvsp[-2].expr), (yyvsp[0].number));}
#line 1951 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 164 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 1957 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 167 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 1963 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 1969 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 170 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-2].string), (yyvsp[0].number)); }
#line 1975 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 171 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 1981 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 172 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-4].string), (yyvsp[-1].number)); }
#line 1987 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 173 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-5].string), -(yyvsp[-1].number)); }
#line 1993 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 174 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[0].string)); }
#line 1999 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 176 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IfElse((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2005 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 177 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2011 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 178 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Switch((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2017 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 180 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new While((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2023 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 182 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoWhile((yyvsp[-1].expr),(yyvsp[-3].expr)); }
#line 2029 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 184 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2035 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 185 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Comma((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2041 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 187 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2047 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 188 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2053 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 189 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2059 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 190 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2065 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 191 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2071 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 192 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2077 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 193 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2083 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 199 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-5].string),(yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2089 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 200 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number));}
#line 2095 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 201 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2101 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 202 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2107 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 203 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2113 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 204 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2119 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 205 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2125 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 206 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number));}
#line 2131 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 207 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2137 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 208 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2143 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 209 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2149 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 210 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2155 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 212 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new  LogNot((yyvsp[0].expr));}
#line 2161 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 213 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2167 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 215 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogOr((yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 2173 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 216 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2179 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 218 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LogAnd((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2185 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 219 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2191 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 221 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitOr((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2197 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 222 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2203 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 224 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitXor((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2209 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 225 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2215 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 227 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitAnd((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2221 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 228 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2227 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 230 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CondEqual((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2233 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 231 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NotEqual((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2239 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 232 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2245 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 234 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LessOrEqual((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2251 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 235 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GreaterOrEqual ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2257 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 236 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Less((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2263 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 237 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Greater ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2269 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 238 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2275 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 240 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2281 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 241 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2287 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 242 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2293 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 244 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Add((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2299 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 245 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Sub((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2305 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 246 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2311 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 248 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Div((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2317 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 249 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mult((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2323 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 250 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mod((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2329 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 251 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2335 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 253 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[0].string), -1);}
#line 2341 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 254 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[0].string), -1);}
#line 2347 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 255 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryNeg((yyvsp[0].expr));}
#line 2353 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 256 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryPos((yyvsp[0].expr));}
#line 2359 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 257 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2365 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 258 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2371 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 259 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2377 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 260 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2383 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 261 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2389 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 263 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2395 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 264 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostIncrement(*(yyvsp[-1].string), -1);}
#line 2401 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 265 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostDecrement(*(yyvsp[-1].string), -1);}
#line 2407 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 266 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 2413 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 267 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-2].string), NULL); }
#line 2419 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 268 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2425 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 269 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2431 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 270 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2437 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 271 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2443 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 272 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2449 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 274 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Variable( *(yyvsp[0].string) ); }
#line 2455 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 275 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( (yyvsp[0].number), 0); }
#line 2461 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 276 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( 0, (yyvsp[0].number)); }
#line 2467 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 277 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2473 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 278 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2479 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2483 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
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
#line 283 "src/maths_parser.y" /* yacc.c:1906  */



nodePtr g_root; // Definition of variable (to match declaration earlier)

nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
 
