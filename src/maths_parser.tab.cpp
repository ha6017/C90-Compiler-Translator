/* A Bison parser, made by GNU Bison 3.3.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
#line 1 "src/maths_parser.y" /* yacc.c:352  */


  #include "ast.hpp"

  #include <cassert>

  extern nodePtr g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 117 "src/maths_parser.tab.cpp" /* yacc.c:352  */

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
#line 18 "src/maths_parser.y" /* yacc.c:352  */

  nodePtr expr;
  int number;
  std::string *string;

#line 207 "src/maths_parser.tab.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

#define YYUNDEFTOK  2
#define YYMAXUTOK   326

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    60,    61,    62,    63,    64,    65,    66,
      67,    74,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    96,    98,    99,   101,   103,   106,   115,   116,
     118,   119,   121,   122,   123,   124,   126,   127,   129,   131,
     132,   133,   137,   138,   139,   140,   141,   143,   144,   145,
     147,   148,   150,   151,   153,   154,   157,   158,   160,   161,
     163,   164,   165
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
  "I_INT", "I_FLOAT", "I_CHAR", "T_IF", "T_ELSE", "T_WHILE", "T_FOR",
  "T_REM", "T_DO", "T_SWITCH", "T_STRUCT", "T_CASE", "T_ENUM", "T_UNION",
  "T_UNSIGNED", "T_TIMES", "T_DIVIDE", "T_PLUS", "T_MINUS", "T_EXPONENT",
  "T_EQUAL", "T_LEXCLAIM", "T_LBRACKET", "T_RBRACKET", "T_LCBRACKET",
  "T_RCBRACKET", "T_LSBRACKET", "T_RSBRACKET", "T_LOG", "T_EXP", "T_SQRT",
  "T_LSHIFT", "T_RSHIFT", "T_NUMBER", "T_VARIABLE", "T_COMMA",
  "T_SEMI_COLON", "T_COLON", "T_GO_TO", "T_CONTINUE", "T_LE", "T_GE",
  "T_EQ", "T_NEQ", "T_LT", "T_GT", "T_BREAK", "T_LAND", "T_LOR", "T_AND",
  "T_OR", "T_XOR", "T_NOT", "$accept", "ROOT", "STATEMENT",
  "VAR_DEC_FUNCTION", "ASSIGNMENT_STATEMENT", "IF_CONDITION_STATEMENT",
  "IF_ELSE_CONDITION_STATEMENT", "WHILE_CONDITION_STATEMENT",
  "FOR_STATEMENT", "DO_WHILE_STATEMENT", "RETURN_STATEMENT",
  "RETURN_VALUE", "EXPR", "EXPR3", "EXPR4", "EXPR5", "EXPR6", "EXPR7",
  "EXPR8", "EXPR9", "EXPR10", "EXPR11", "EXPR12", "EXPR13", YY_NULLPTR
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
     325,   326
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,   -33,   -53,   -12,    -2,     4,    -7,    18,    19,   -16,
       7,   -15,    61,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -11,   -27,    13,   -52,    17,     0,
      -4,     3,     8,     9,   -53,   -53,   -16,   -16,    76,    -6,
      34,    37,   -53,    50,    54,    55,    58,   -22,    -5,   -16,
      57,   -11,   -53,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,    59,    60,    45,    62,   -53,   -53,   -53,   -16,   -16,
     -16,   -53,   -16,   -53,   -16,   -53,   -53,   -27,   -27,   -27,
      13,    13,   -52,   -52,    17,    17,    17,    17,     0,     0,
      -4,     3,     8,     9,   -53,    -6,    64,   -16,    79,   -53,
     -53,   -53,   -53,   -53,    81,    -6,    53,    68,    -6,    66,
     -31,   -16,   -53,   -53,    23,    63,    69,    70,   -53,    -6,
      71,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     2,     7,     8,     4,     5,     6,     9,
      10,     3,    27,    29,    31,    35,    38,    41,    46,    49,
      51,    53,    55,    57,    59,    11,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    16,    60,     0,     0,
       0,    13,     0,    15,     0,    12,    28,    34,    33,    32,
      36,    37,    39,    40,    42,    43,    44,    45,    47,    48,
      50,    52,    54,    56,    58,     0,     0,     0,     0,    21,
      19,    20,    17,    18,    22,     0,     0,     0,     0,     0,
       0,     0,    23,    24,     0,     0,     0,     0,    26,     0,
       0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -38,    78,    -3,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,    -9,   103,    28,    29,    30,   -10,    31,    52,
      56,    51,    65,    67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    74,     1,     2,     2,     7,     8,    60,    61,    56,
      57,    62,    63,     2,    81,    53,     3,    82,     4,     5,
      35,     6,   124,    54,    55,     9,     9,    71,    72,    36,
       7,     8,    83,    44,    84,     9,    39,    42,    42,    37,
      85,    45,    46,    47,    48,    38,    49,    10,    50,    44,
      94,    95,    96,    97,    40,    11,    41,    45,    46,    47,
      48,    52,    49,    58,    59,    11,    67,   114,    66,   109,
     110,   111,    68,   112,    69,   113,    70,   119,    64,    65,
     122,    87,    88,    89,     1,    90,    91,    75,    92,    93,
      76,   130,    77,    78,    79,    98,    99,    80,   116,    86,
     107,   105,   106,   117,   118,   127,   108,   115,   120,   121,
     123,   128,   126,   129,    51,   131,    73,   125,   100,   102,
       0,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       9,    39,     8,    19,    19,    36,    37,    59,    60,    36,
      37,    63,    64,    19,    36,    26,    22,    39,    24,    25,
      53,    27,    53,    34,    35,    41,    41,    36,    37,    41,
      36,    37,    37,    26,    39,    41,    43,    53,    53,    41,
      49,    34,    35,    36,    37,    41,    39,    53,    41,    26,
      60,    61,    62,    63,    36,    71,    37,    34,    35,    36,
      37,     0,    39,    50,    51,    71,    70,   105,    68,    78,
      79,    80,    69,    82,    66,    84,    67,   115,    61,    62,
     118,    53,    54,    55,     8,    56,    57,    53,    58,    59,
      53,   129,    42,    39,    39,    64,    65,    39,   107,    42,
      55,    42,    42,    24,    23,    42,    44,    43,    55,    41,
      44,    42,   121,    43,    11,    44,    38,   120,    66,    68,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    19,    22,    24,    25,    27,    36,    37,    41,
      53,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    53,    41,    41,    41,    43,
      36,    37,    53,    84,    26,    34,    35,    36,    37,    39,
      41,    85,     0,    26,    34,    35,    36,    37,    50,    51,
      59,    60,    63,    64,    61,    62,    68,    70,    69,    66,
      67,    84,    84,    75,    74,    53,    53,    42,    39,    39,
      39,    36,    39,    37,    39,    84,    42,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      91,    92,    93,    94,    95,    42,    42,    55,    44,    84,
      84,    84,    84,    84,    74,    43,    84,    24,    23,    74,
      55,    41,    74,    44,    53,    76,    84,    42,    42,    43,
      74,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    83,
      84,    84,    85,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     5,     7,     7,    11,     8,     1,     3,     1,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 52 "src/maths_parser.y" /* yacc.c:1667  */
    { g_root = (yyvsp[0].expr); }
#line 1403 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 3:
#line 60 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1409 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 4:
#line 61 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1415 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 5:
#line 62 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1421 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 6:
#line 63 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1427 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 7:
#line 64 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr)  = (yyvsp[0].expr); }
#line 1433 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 8:
#line 65 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr)  = (yyvsp[0].expr); }
#line 1439 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 9:
#line 66 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1445 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 10:
#line 67 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1451 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 11:
#line 74 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new InitInt(*(yyvsp[0].string), NULL);}
#line 1457 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 12:
#line 82 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new AssignEqual(*(yyvsp[-2].string),(yyvsp[0].expr));}
#line 1463 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 13:
#line 83 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new PostIncrement(*(yyvsp[-2].string));}
#line 1469 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 14:
#line 84 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new PreIncrement(*(yyvsp[0].string));}
#line 1475 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 15:
#line 85 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new PostDecrement(*(yyvsp[-2].string));}
#line 1481 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 16:
#line 86 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new PreDecrement(*(yyvsp[0].string));}
#line 1487 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 17:
#line 87 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) =  new PlusEqual(*(yyvsp[-3].string),(yyvsp[0].expr));}
#line 1493 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 18:
#line 88 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) =  new SubEqual(*(yyvsp[-3].string),(yyvsp[0].expr));}
#line 1499 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 19:
#line 89 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) =  new MultEqual(*(yyvsp[-3].string),(yyvsp[0].expr));}
#line 1505 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 20:
#line 90 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) =  new DivEqual(*(yyvsp[-3].string),(yyvsp[0].expr));}
#line 1511 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 21:
#line 91 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) =  new RemEqual(*(yyvsp[-3].string),(yyvsp[0].expr));}
#line 1517 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 22:
#line 96 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new If((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1523 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 23:
#line 98 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new IfElse((yyvsp[-4].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1529 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 24:
#line 99 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new While((yyvsp[-4].expr),(yyvsp[-1].expr));}
#line 1535 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 25:
#line 101 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new For((yyvsp[-8].expr),(yyvsp[-6].expr),(yyvsp[-4].expr),(yyvsp[-1].expr));}
#line 1541 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 26:
#line 103 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new DoWhile((yyvsp[-1].expr), (yyvsp[-5].expr));}
#line 1547 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 27:
#line 106 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1553 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 28:
#line 115 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new FuncCall(*(yyvsp[-2].string),NULL); }
#line 1559 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 29:
#line 116 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1565 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 30:
#line 118 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new  LogNot((yyvsp[0].expr));}
#line 1571 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 31:
#line 119 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1577 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 32:
#line 121 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Div((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1583 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 33:
#line 122 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Mult((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1589 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 34:
#line 123 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Mod((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1595 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 35:
#line 124 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1601 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 36:
#line 126 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Add((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1607 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 37:
#line 127 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Sub((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1613 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 38:
#line 129 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1619 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 39:
#line 131 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new LShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1625 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 40:
#line 132 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new RShift((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1631 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 41:
#line 133 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1637 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 42:
#line 137 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new LessOrEqual((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1643 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 43:
#line 138 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new GreaterOrEqual ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1649 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 44:
#line 139 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Less((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1655 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 45:
#line 140 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new Greater ((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1661 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 46:
#line 141 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1667 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 47:
#line 143 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new CondEqual((yyvsp[-2].expr),(yyvsp[0].expr));  }
#line 1673 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 48:
#line 144 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new NotEqual((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1679 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 49:
#line 145 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1685 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 50:
#line 147 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new BitAnd((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1691 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 51:
#line 148 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1697 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 52:
#line 150 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new BitXor((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1703 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 53:
#line 151 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1709 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 54:
#line 153 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new BitOr((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1715 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 55:
#line 154 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1721 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 56:
#line 157 "src/maths_parser.y" /* yacc.c:1667  */
    {(yyval.expr) = new LogAnd((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1727 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 57:
#line 158 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1733 "src/maths_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 58:
#line 160 "src/maths_parser.y" /* yacc.c:1667  */
    { (yyval.expr) = new LogOr((yyvsp[-2].expr), 