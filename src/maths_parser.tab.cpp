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
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  332

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
      80,    81,    82,    83,    84,    85,    88,    90,    91,    92,
      93,    94,    95,    97,    98,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   111,   112,   119,   120,   123,   124,
     125,   126,   129,   132,   133,   136,   137,   138,   139,   140,
     141,   144,   145,   148,   149,   152,   153,   156,   157,   158,
     159,   160,   163,   164,   166,   169,   170,   172,   173,   174,
     175,   176,   178,   179,   180,   182,   184,   186,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   209,   210,   212,
     213,   215,   216,   218,   219,   221,   222,   224,   225,   227,
     228,   229,   231,   232,   233,   234,   235,   237,   238,   239,
     241,   242,   243,   245,   246,   247,   248,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   273,   274,
     275,   276,   277
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
  "TYPE_NAME", "ENUM_SPECIFIER", "ENUMERATOR_LIST", "SCOPE", "STATEMENT",
  "EXPR_STATEMENT", "FOR_STATEMENT", "NEW_SCOPE", "RETURN_STATEMENT",
  "DEC_STATEMENT", "VAL_LIST", "DEC_VAR_LIST", "VARIABLE_DECLARATION",
  "GLOBAL_ARRAY_DECLARATION", "GLOBAL_VAL_LIST",
  "GLOBLE_VARIABLE_DECLARATION", "GLO_DEC_VAR_LIST", "GLO_DEC_VARIABLE",
  "IF_OR_ELSE", "WHILE_STATEMENT", "DO_WHILE_STATEMENT", "EXPR16",
  "EXPR15", "EXPR", "EXPR2", "EXPR3", "EXPR4", "EXPR5", "EXPR6", "EXPR7",
  "EXPR8", "EXPR9", "EXPR10", "EXPR11", "EXPR12", "EXPR13", "EXPR14", YY_NULLPTR
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

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     463,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
       5,   463,  -162,   -42,  -162,  -162,  -162,  -162,  -162,  -162,
      86,   184,  -162,    51,   191,    -9,   -12,  -162,  -162,    -8,
     -11,    23,    37,    19,    79,   111,   140,   144,  -162,  -162,
     165,   179,   344,  -162,    74,   463,  -162,    12,   188,   187,
    -162,   185,    59,  -162,   221,   221,   195,   344,   221,   194,
     102,   110,   290,   215,   217,   221,   344,   448,  -162,  -162,
    -162,   290,   237,  -162,    21,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,   189,  -162,  -162,   167,   229,   232,
     243,   235,   201,   190,   219,   242,   146,  -162,  -162,  -162,
     344,  -162,   266,   284,  -162,    26,   315,  -162,  -162,   286,
     344,   344,   386,   318,   344,   300,   328,   281,  -162,  -162,
    -162,   290,   167,  -162,   303,   304,   319,   206,   221,  -162,
    -162,    69,    66,   221,   221,   221,   221,   221,  -162,     3,
     233,  -162,  -162,  -162,  -162,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   275,  -162,   315,   317,  -162,  -162,   -33,
    -162,   342,  -162,   101,   101,   221,  -162,   311,  -162,    70,
    -162,    97,   112,  -162,  -162,  -162,  -162,   133,  -162,   325,
     354,  -162,  -162,  -162,  -162,  -162,   221,    56,   320,  -162,
     229,   232,   243,   235,   201,   190,   190,   219,   219,   219,
     219,   242,   242,   146,   146,  -162,  -162,  -162,  -162,    31,
     315,   321,   356,   344,   394,   424,   322,   339,    80,   340,
     370,   343,   372,   345,   374,  -162,   221,   109,   359,  -162,
     361,   384,   371,   373,  -162,   350,   124,  -162,  -162,  -162,
     344,   369,   344,   376,  -162,   134,  -162,   357,   240,   377,
    -162,   385,  -162,   392,  -162,   221,  -162,  -162,   221,   221,
     221,   221,   221,   400,   378,   395,   379,  -162,   387,  -162,
     344,  -162,   344,  -162,   398,   393,   263,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,   221,  -162,  -162,   221,   221,
     221,   221,   221,   401,   410,   221,  -162,  -162,  -162,  -162,
     155,  -162,  -162,  -162,  -162,  -162,  -162,   221,   405,   130,
    -162,  -162,   431,   148,   221,  -162,   221,  -162,  -162,   150,
    -162,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    25,    17,    20,    22,    23,    24,    18,    19,
       0,     2,     6,     0,     8,     7,     1,     3,     5,     4,
      81,     0,    75,     0,     0,     0,     0,    74,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    76,    78,
       0,     0,     0,    12,     0,     0,    14,     0,     0,     0,
      79,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,    47,    45,
      44,     0,     0,    37,     0,    34,    38,    43,    42,    35,
      36,    39,    40,    41,     0,    87,    88,   108,   110,   112,
     114,   116,   118,   121,   126,   129,   132,   136,   147,   157,
       0,    11,     0,     0,    67,     0,     0,    80,    54,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   140,   159,
     139,     0,   107,   136,   137,   138,     0,     0,     0,   149,
     150,     0,     0,     0,     0,     0,     0,     0,   142,    66,
       0,    63,    10,    33,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,    69,    72,     0,
      53,    83,    85,     0,     0,     0,    84,     0,   160,     0,
     141,     0,     0,   148,    52,    89,   152,     0,    16,     0,
       0,    90,    91,    92,    93,    94,     0,     0,     0,    55,
     109,   111,   113,   115,   117,   119,   120,   122,   123,   124,
     125,   127,   128,   130,   131,   135,   134,   133,     9,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,   151,     0,   161,     0,    65,
       0,     0,     0,    66,    64,     0,     0,    71,    73,    82,
       0,     0,     0,     0,    86,     0,    26,     0,   161,     0,
     143,     0,   144,     0,    15,     0,   153,   154,     0,     0,
       0,     0,     0,   162,    56,     0,     0,    68,     0,    51,
       0,    50,     0,    28,     0,    32,   162,   145,   146,    95,
      96,    97,    98,    99,   100,     0,   155,   156,     0,     0,
       0,     0,     0,     0,    57,     0,    70,    49,    48,    29,
       0,   101,   102,   103,   104,   105,   106,     0,     0,     0,
      61,    30,     0,     0,     0,    60,     0,    31,    58,     0,
      62,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,   440,  -162,  -162,    28,  -162,  -162,   -57,
     -56,  -105,  -162,  -162,  -162,   346,  -127,  -162,   270,   450,
    -161,   458,  -162,   453,  -162,  -162,  -162,   -52,  -114,  -162,
     418,   336,   337,   338,   348,   335,   162,    58,   180,   181,
     -47,   282,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    32,   187,    72,    73,   228,    74,
      75,    76,    77,    78,    79,    80,   319,   140,   141,    14,
     169,    15,    21,    22,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     109,   113,   110,   111,   219,    16,   114,   173,    40,   127,
      34,    39,   221,   126,   185,   123,    20,   188,   143,   191,
     192,   193,   194,   195,   138,    41,   222,    35,    13,     1,
       2,     3,     4,     5,     6,     7,     8,    52,    36,    13,
      53,   196,    54,   163,    55,    56,    37,    57,    58,   197,
     103,    59,    33,     9,   171,   172,    60,    61,   176,   246,
      62,    63,    64,    65,   166,    66,   142,    42,   224,   225,
      28,   143,   104,   102,   180,   240,   245,    46,    53,    67,
      44,    68,   239,    43,    69,   189,   167,    29,    53,   229,
     222,    70,   241,    30,    60,    61,    45,    71,    62,    63,
      64,    65,   190,   242,    60,    61,   230,   143,    62,    63,
      64,    65,   186,   215,   216,   217,   231,    67,   100,   108,
      53,    53,   264,   226,    23,   256,    47,    67,    24,   119,
      48,   233,    25,   232,   101,    71,    60,    61,   116,   257,
      62,    63,    64,    65,    65,    71,   116,   265,   234,   266,
     267,   289,    65,   283,   290,   291,   292,   293,   294,    67,
     117,    68,   268,   269,   270,   271,   272,   249,   117,   278,
     284,   160,   251,   253,   321,   325,   235,    71,    49,   161,
     162,   311,    23,   222,   312,   313,   314,   315,   316,   326,
     323,   322,   236,   328,   279,   331,   281,   329,    51,     1,
       2,     3,     4,     5,     6,     7,     8,   326,    50,   326,
     207,   208,   209,   210,     1,     2,     3,     4,     5,     6,
       7,     8,    52,     9,   307,    53,   308,    54,   107,    55,
      56,   106,    57,    58,    31,   105,    59,   112,     9,   145,
      53,    60,    61,    26,    27,    62,    63,    64,    65,   144,
      66,   184,   115,   320,   152,   153,    60,    61,   154,   155,
      62,    63,    64,    65,    67,   320,    68,   150,   151,    69,
     156,   157,   320,   124,   330,   125,    70,   158,   159,    67,
     266,   267,    71,     1,     2,     3,     4,     5,     6,     7,
       8,    52,   198,   199,    53,   139,    54,    71,    55,    56,
     146,    57,    58,   296,   297,    59,   147,     9,   149,    53,
      60,    61,   205,   206,    62,    63,    64,    65,   148,    66,
     218,   129,   130,   131,   164,    60,    61,   179,   165,   121,
      63,    64,    65,    67,   168,    68,   211,   212,    69,   213,
     214,   175,   118,   120,   177,    70,   170,   178,   117,   181,
     182,    71,     1,     2,     3,     4,     5,     6,     7,     8,
      52,   220,   183,    53,   223,    54,    71,    55,    56,   227,
      57,    58,   237,   238,    59,   248,     9,   255,   243,    60,
      61,   247,   254,    62,    63,    64,    65,   258,    66,   259,
     260,   261,   262,   263,     1,     2,     3,     4,     5,     6,
       7,     8,    67,   275,    68,    53,   273,    69,   274,   276,
     277,   196,   280,    53,    70,   285,   303,   309,     9,   282,
      71,    60,    61,   305,   286,    62,    63,    64,    65,    60,
      61,   310,   287,    62,    63,    64,    65,   250,   295,   288,
     296,   297,   304,    53,    67,   317,    68,   306,   318,   324,
     327,    17,    67,   298,   299,   300,   301,   302,   174,    60,
      61,    18,    71,    62,    63,    64,    65,   252,   244,    19,
      71,     1,     2,     3,     4,     5,     6,     7,     8,    38,
     122,   200,    67,   201,   204,   202,   128,     0,   129,   130,
     131,     0,     0,     0,   132,     9,   203,     0,     0,     0,
      71,   133,   134,   135,   136,   137
};

static const yytype_int16 yycheck[] =
{
      52,    57,    54,    55,   165,     0,    58,   112,    19,    66,
      19,    19,    45,    65,   128,    62,    58,   131,    74,   133,
     134,   135,   136,   137,    71,    36,    59,    36,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    47,    11,
      19,    38,    21,   100,    23,    24,    58,    26,    27,    46,
      38,    30,    24,    32,   110,   111,    35,    36,   114,   220,
      39,    40,    41,    42,    38,    44,    45,    44,   173,   174,
      19,   127,    60,    45,   121,    19,    45,    58,    19,    58,
      43,    60,   196,    60,    63,    19,    60,    36,    19,    19,
      59,    70,    36,    42,    35,    36,    59,    76,    39,    40,
      41,    42,    36,    47,    35,    36,    36,   163,    39,    40,
      41,    42,    43,   160,   161,   162,    19,    58,    44,    60,
      19,    19,   236,   175,    38,    45,    47,    58,    42,    19,
      19,    19,    46,    36,    60,    76,    35,    36,    36,    59,
      39,    40,    41,    42,    42,    76,    36,    38,    36,    40,
      41,   265,    42,    19,   268,   269,   270,   271,   272,    58,
      58,    60,    53,    54,    55,    56,    57,   223,    58,    45,
      36,    25,   224,   225,    19,    45,    43,    76,    38,    33,
      34,   295,    38,    59,   298,   299,   300,   301,   302,    59,
     317,    36,    59,    45,   250,    45,   252,   324,    19,     8,
       9,    10,    11,    12,    13,    14,    15,    59,    43,    59,
     152,   153,   154,   155,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    32,   280,    19,   282,    21,    43,    23,
      24,    44,    26,    27,    43,    47,    30,    42,    32,    72,
      19,    35,    36,    59,    60,    39,    40,    41,    42,    60,
      44,    45,    58,   305,    64,    65,    35,    36,    68,    69,
      39,    40,    41,    42,    58,   317,    60,    66,    67,    63,
      51,    52,   324,    58,   326,    58,    70,    35,    36,    58,
      40,    41,    76,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    59,    60,    19,    58,    21,    76,    23,    24,
      71,    26,    27,    40,    41,    30,    74,    32,    73,    19,
      35,    36,   150,   151,    39,    40,    41,    42,    75,    44,
      45,    40,    41,    42,    58,    35,    36,    46,    44,    39,
      40,    41,    42,    58,    19,    60,   156,   157,    63,   158,
     159,    23,    60,    61,    44,    70,    60,    19,    58,    46,
      46,    76,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    44,    43,    19,    22,    21,    76,    23,    24,    58,
      26,    27,    47,    19,    30,    19,    32,    38,    58,    35,
      36,    60,    60,    39,    40,    41,    42,    47,    44,    19,
      47,    19,    47,    19,     8,     9,    10,    11,    12,    13,
      14,    15,    58,    19,    60,    19,    47,    63,    47,    38,
      60,    38,    43,    19,    70,    58,    38,    19,    32,    43,
      76,    35,    36,    44,    47,    39,    40,    41,    42,    35,
      36,    38,    47,    39,    40,    41,    42,    43,    38,    47,
      40,    41,    47,    19,    58,    44,    60,    60,    38,    44,
      19,    11,    58,    53,    54,    55,    56,    57,   112,    35,
      36,    11,    76,    39,    40,    41,    42,    43,   198,    11,
      76,     8,     9,    10,    11,    12,    13,    14,    15,    26,
      62,   145,    58,   146,   149,   147,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    32,   148,    -1,    -1,    -1,
      76,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    32,
      78,    79,    80,    83,    96,    98,     0,    80,    96,    98,
      58,    99,   100,    38,    42,    46,    59,    60,    19,    36,
      42,    43,    81,    83,    19,    36,    47,    58,   100,    19,
      19,    36,    44,    60,    43,    59,    58,    47,    19,    38,
      43,    19,    16,    19,    21,    23,    24,    26,    27,    30,
      35,    36,    39,    40,    41,    42,    44,    58,    60,    63,
      70,    76,    83,    84,    86,    87,    88,    89,    90,    91,
      92,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      44,    60,    83,    38,    60,    47,    44,    43,    60,   104,
     104,   104,    42,    87,   104,    58,    36,    58,   118,    19,
     118,    39,   107,   117,    58,    58,   104,    86,    38,    40,
      41,    42,    46,    53,    54,    55,    56,    57,   117,    58,
      94,    95,    45,    87,    60,    72,    71,    74,    75,    73,
      66,    67,    64,    65,    68,    69,    51,    52,    35,    36,
      25,    33,    34,    86,    58,    44,    38,    60,    19,    97,
      60,    87,    87,    88,    92,    23,    87,    44,    19,    46,
     117,    46,    46,    43,    45,   105,    43,    82,   105,    19,
      36,   105,   105,   105,   105,   105,    38,    46,    59,    60,
     108,   109,   110,   111,   112,   113,   113,   114,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   117,    45,    97,
      44,    45,    59,    22,    88,    88,   104,    58,    85,    19,
      36,    19,    36,    19,    36,    43,    59,    47,    19,   105,
      19,    36,    47,    58,    95,    45,    97,    60,    19,    87,
      43,   104,    43,   104,    60,    38,    45,    59,    47,    19,
      47,    19,    47,    19,   105,    38,    40,    41,    53,    54,
      55,    56,    57,    47,    47,    19,    38,    60,    45,    87,
      43,    87,    43,    19,    36,    58,    47,    47,    47,   105,
     105,   105,   105,   105,   105,    38,    40,    41,    53,    54,
      55,    56,    57,    38,    47,    44,    60,    87,    87,    19,
      38,   105,   105,   105,   105,   105,   105,    44,    38,    93,
     104,    19,    36,    93,    44,    45,    59,    19,    45,    93,
     104,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    97,    97,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   101,   102,   103,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
     115,   115,   115,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     8,
       7,     6,     5,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     3,     4,
       5,     6,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     7,     7,
       6,     6,     3,     3,     2,     3,     5,     6,     9,    10,
       8,     1,     3,     1,     3,     3,     1,     6,    10,     7,
      11,     9,     1,     3,     3,     1,     3,     3,     4,     5,
       6,     1,     5,     3,     3,     3,     5,     1,     1,     3,
       3,     3,     3,     3,     3,     6,     6,     6,     6,     6,
       6,     7,     7,     7,     7,     7,     7,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
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
#line 55 "src/maths_parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].expr); }
#line 1580 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), (yyvsp[-1].expr));}
#line 1586 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1592 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1598 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1604 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1610 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Top_List((yyvsp[0].expr), NULL); }
#line 1616 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-7].string), *(yyvsp[-6].string), (yyvsp[-4].expr), (yyvsp[-1].expr)); }
#line 1622 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncDef(*(yyvsp[-6].string), *(yyvsp[-5].string), NULL, (yyvsp[-1].expr)); }
#line 1628 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].expr)); }
#line 1634 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-4].string), *(yyvsp[-3].string), NULL); }
#line 1640 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 71 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), (yyvsp[-3].expr)); }
#line 1646 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 72 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), NULL); }
#line 1652 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1658 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArgumentNoType((yyvsp[0].expr), NULL); }
#line 1664 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1670 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1676 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1682 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1688 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1694 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 82 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1700 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 83 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1706 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 84 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1712 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 85 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1718 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 88 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Enum((yyvsp[-1].expr)); }
#line 1724 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new EnumList(NULL, *(yyvsp[0].string), -293); }
#line 1730 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new EnumList(NULL, *(yyvsp[-2].string), (yyvsp[0].number)); }
#line 1736 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new EnumList(NULL, *(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 1742 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new EnumList((yyvsp[-4].expr), *(yyvsp[-2].string), (yyvsp[0].number)); }
#line 1748 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new EnumList((yyvsp[-5].expr), *(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 1754 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new EnumList((yyvsp[-2].expr), *(yyvsp[0].string), -293); }
#line 1760 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 97 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr),(yyvsp[-1].expr)); }
#line 1766 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 98 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BranchList((yyvsp[0].expr), NULL); }
#line 1772 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 101 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1778 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 102 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1784 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 103 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1790 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 104 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1796 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 105 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1802 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 106 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1808 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 107 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1814 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 108 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1820 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 109 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1826 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 111 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Break();}
#line 1832 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 112 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Continue();}
#line 1838 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 119 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement((yyvsp[-1].expr)); }
#line 1844 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExprStatement(NULL); }
#line 1850 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1856 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-4].expr),(yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1862 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 125 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1868 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 126 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr), NULL);}
#line 1874 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NewScope((yyvsp[-1].expr)); }
#line 1880 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 132 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement((yyvsp[-1].expr)); }
#line 1886 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 133 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReturnStatement(NULL); }
#line 1892 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 136 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 1898 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 137 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[-1].number), NULL);}
#line 1904 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 138 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-1].number), NULL);}
#line 1910 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 139 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-8].string), *(yyvsp[-7].string), (yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1916 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 140 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-9].string), *(yyvsp[-8].string), -(yyvsp[-5].number), (yyvsp[-1].expr)); }
#line 1922 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 141 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LocalInitArray(*(yyvsp[-7].string), *(yyvsp[-6].string), 0, (yyvsp[-1].expr)); }
#line 1928 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 144 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new ArrayList((yyvsp[0].expr), NULL);}
#line 1934 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 145 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrayList((yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1940 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 148 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 1946 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 149 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 1952 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 152 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[0].expr)); }
#line 1958 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 153 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Declare(*(yyvsp[0].string), NULL); }
#line 1964 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 156 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].number), NULL);}
#line 1970 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 157 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-9].string), *(yyvsp[-8].string), (yyvsp[-6].number), (yyvsp[-2].expr));}
#line 1976 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 158 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-6].string), *(yyvsp[-5].string), (yyvsp[-2].number), NULL);}
#line 1982 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 159 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-10].string), *(yyvsp[-9].string), -(yyvsp[-6].number), (yyvsp[-2].expr)); }
#line 1988 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 160 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalInitArray(*(yyvsp[-8].string), *(yyvsp[-7].string), 0, (yyvsp[-2].expr)); }
#line 1994 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 163 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new GlobalArrayList(NULL, (yyvsp[0].number));}
#line 2000 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 164 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new GlobalArrayList((yyvsp[-2].expr), (yyvsp[0].number));}
#line 2006 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 166 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].expr)); }
#line 2012 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 169 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr), NULL); }
#line 2018 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 170 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dec_Var_List((yyvsp[0].expr),(yyvsp[-2].expr)); }
#line 2024 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 172 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-2].string), (yyvsp[0].number)); }
#line 2030 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 173 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 2036 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 174 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-4].string), (yyvsp[-1].number)); }
#line 2042 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 175 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[-5].string), -(yyvsp[-1].number)); }
#line 2048 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 176 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GlobalDeclare(*(yyvsp[0].string)); }
#line 2054 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 178 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IfElse((yyvsp[-3].expr),(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2060 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 179 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2066 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 180 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Switch((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2072 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 182 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new While((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2078 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 184 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoWhile((yyvsp[-1].expr),(yyvsp[-3].expr)); }
#line 2084 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 186 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2090 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 189 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2096 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 190 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new AssignEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2102 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 191 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2108 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 192 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2114 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 193 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2120 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 194 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2126 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 195 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-2].string), (yyvsp[0].expr), -1);}
#line 2132 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 196 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-5].string),(yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2138 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 197 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number));}
#line 2144 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 198 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2150 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 199 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2156 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 200 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2162 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 201 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-5].string), (yyvsp[0].expr), (yyvsp[-3].number)); }
#line 2168 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 202 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2174 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 203 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number));}
#line 2180 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 204 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2186 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 205 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2192 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 206 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2198 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 207 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-6].string), (yyvsp[0].expr), -(yyvsp[-3].number)); }
#line 2204 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 209 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new  LogNot((yyvsp[0].expr));}
#line 2210 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 210 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2216 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 212 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogOr((yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 2222 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 213 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2228 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 215 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LogAnd((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2234 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 216 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2240 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 218 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitOr((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2246 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 219 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2252 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 221 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitXor((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2258 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 222 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2264 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 224 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BitAnd((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2270 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 225 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2276 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 227 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CondEqual((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2282 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 228 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NotEqual((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2288 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 229 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2294 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 231 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LessOrEqual((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2300 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 232 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GreaterOrEqual ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2306 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 233 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Less((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2312 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 234 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Greater ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2318 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 235 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2324 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 237 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new LShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2330 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 238 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2336 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 239 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2342 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 241 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Add((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2348 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 242 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Sub((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2354 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 243 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2360 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 245 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Div((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2366 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 246 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mult((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2372 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 247 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Mod((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2378 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 248 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2384 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 250 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[0].string), -1);}
#line 2390 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 251 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[0].string), -1);}
#line 2396 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 252 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryNeg((yyvsp[0].expr));}
#line 2402 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 253 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new UnaryPos((yyvsp[0].expr));}
#line 2408 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 254 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) =new LogNot((yyvsp[0].expr));}
#line 2414 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 255 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new BitNot((yyvsp[0].expr));}
#line 2420 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 256 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2426 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 257 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2432 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 258 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2438 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 259 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2444 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 260 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2450 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 262 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2456 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 263 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostIncrement(*(yyvsp[-1].string), -1);}
#line 2462 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 264 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new PostDecrement(*(yyvsp[-1].string), -1);}
#line 2468 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 265 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 2474 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 266 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionStatementInExpr(*(yyvsp[-2].string), NULL); }
#line 2480 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 267 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2486 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 268 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-4].string), (yyvsp[-2].number));}
#line 2492 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 269 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostIncrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2498 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 270 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostDecrement(*(yyvsp[-5].string), -(yyvsp[-2].number));}
#line 2504 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 271 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2510 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 273 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Variable( *(yyvsp[0].string) ); }
#line 2516 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 274 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( (yyvsp[0].number), 0); }
#line 2522 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 275 "src/maths_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number( 0, (yyvsp[0].number)); }
#line 2528 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 276 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-3].string), (yyvsp[-1].number));}
#line 2534 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 277 "src/maths_parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ArrElement(*(yyvsp[-4].string), -(yyvsp[-1].number));}
#line 2540 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2544 "src/maths_parser.tab.cpp" /* yacc.c:1646  */
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
#line 282 "src/maths_parser.y" /* yacc.c:1906  */



nodePtr g_root; // Definition of variable (to match declaration earlier)

nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
 
