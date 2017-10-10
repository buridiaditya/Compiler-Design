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
#line 1 "ass3_15CS30008.y" /* yacc.c:339  */

	#include "translator.h"
	int yylex();
	void yyerror(const char*);
	

#line 73 "ass3_15CS30008.tab.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_CONSTANT = 260,
    DOUBLE_CONSTANT = 261,
    CHAR_CONSTANT = 262,
    STRING_LITERAL = 263,
    IDENTIFIER = 264
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "ass3_15CS30008.y" /* yacc.c:355  */

		int integerVal;
		char charVal;
		double doubleVal;
		string* strVal;
		vector<vector<double> > matVal; 
		decl_t* decl; 
		exp_t* exp;
		type_t* type;
		vector<int>* list;
	

#line 131 "ass3_15CS30008.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 148 "ass3_15CS30008.tab.c" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,    20,     2,
      10,    11,    21,    22,    19,    23,    14,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    51,
      28,    40,    29,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    35,    64,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    15,    16,    17,    18,    26,
      27,    30,    31,    32,    33,    36,    37,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    40,    45,    51,    57,    65,    73,    81,
      85,    92,    97,   123,   129,   135,   136,   137,   138,   139,
     146,   154,   164,   169,   219,   269,   311,   316,   321,   326,
     333,   340,   345,   429,   513,   598,   603,   687,   773,   778,
     862,   948,   953,  1042,  1131,  1220,  1311,  1316,  1405,  1496,
    1501,  1582,  1587,  1668,  1673,  1755,  1760,  1770,  1775,  1785,
    1790,  1792,  1797,  1936,  1937,  1938,  1939,  1940,  1941,  1942,
    1943,  1944,  1945,  1946,  1949,  1950,  1953,  1955,  1957,  1960,
    1966,  1974,  1975,  1978,  1992,  2044,  2049,  2054,  2058,  2063,
    2064,  2065,  2070,  2075,  2076,  2077,  2080,  2086,  2085,  2096,
    2102,  2110,  2120,  2129,  2128,  2143,  2142,  2156,  2168,  2174,
    2182,  2184,  2185,  2188,  2193,  2200,  2207,  2216,  2221,  2224,
    2225,  2228,  2229,  2230,  2233,  2235,  2236,  2239,  2240,  2243,
    2244,  2245,  2246,  2251,  2256,  2259,  2260,  2261,  2264,  2265,
    2273,  2278,  2290,  2295,  2302,  2303,  2306,  2312,  2320,  2323,
    2328,  2334,  2343,  2350,  2351,  2354,  2355,  2356,  2357,  2373,
    2374,  2377,  2378,  2385,  2393,  2403,  2404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"then\"", "\"else\"", "INT_CONSTANT",
  "DOUBLE_CONSTANT", "CHAR_CONSTANT", "STRING_LITERAL", "IDENTIFIER",
  "'('", "')'", "'['", "']'", "'.'", "\"->\"", "\"++\"", "\"--\"",
  "\".'\"", "','", "'&'", "'*'", "'+'", "'-'", "'/'", "'%'", "\"<<\"",
  "\">>\"", "'<'", "'>'", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "'^'",
  "'|'", "\"&&\"", "\"||\"", "'?'", "':'", "'='", "\"*=\"", "\"/=\"",
  "\"%=\"", "\"+=\"", "\"-=\"", "\"<<=\"", "\">>=\"", "\"&=\"", "\"^=\"",
  "\"|=\"", "';'", "\"void\"", "\"char\"", "\"short\"", "\"int\"",
  "\"long\"", "\"float\"", "\"double\"", "\"Matrix\"", "\"signed\"",
  "\"unsigned\"", "\"Bool\"", "'{'", "'}'", "\"case\"", "\"default\"",
  "\"if\"", "\"switch\"", "\"while\"", "\"do\"", "\"for\"", "\"goto\"",
  "\"continue\"", "\"break\"", "\"return\"", "$accept", "start", "M", "N",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "$@1", "direct_declarator", "$@2", "$@3",
  "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer",
  "initializer_row_list", "initializer_row", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "expression_opt",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      40,    41,    91,    93,    46,   265,   266,   267,   268,    44,
      38,    42,    43,    45,    47,    37,   269,   270,    60,    62,
     271,   272,   273,   274,    94,   124,   275,   276,    63,    58,
      61,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,    59,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   123,   125,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     445,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,    38,  -160,    18,   445,   445,  -160,  -160,  -160,
    -160,    62,     2,  -160,    -8,  -160,   364,    42,  -160,  -160,
    -160,    45,  -160,    62,  -160,   334,   219,  -160,    18,  -160,
     433,    24,   423,   100,  -160,  -160,    20,  -160,  -160,  -160,
    -160,  -160,   461,   461,   461,  -160,  -160,  -160,  -160,    41,
    -160,   135,   468,   461,  -160,    90,    96,   116,   110,   136,
      59,    31,    39,    52,   137,  -160,  -160,  -160,    73,  -160,
    -160,   461,    82,    81,    85,  -160,  -160,    95,   145,   107,
     109,   461,  -160,    -6,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,   445,   153,  -160,
     133,    42,    10,  -160,  -160,   461,   163,  -160,   -34,   158,
     334,    54,  -160,   442,   461,   170,   175,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,   461,  -160,  -160,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
    -160,  -160,  -160,   315,  -160,   149,   315,   461,   461,   182,
     315,   353,   142,  -160,  -160,   176,   150,   461,  -160,   244,
      62,   185,   181,  -160,  -160,    23,  -160,  -160,   190,  -160,
      41,  -160,   334,  -160,  -160,  -160,  -160,    25,  -160,    79,
    -160,  -160,  -160,  -160,  -160,  -160,    90,    90,    96,    96,
     116,   116,   116,   116,   110,   110,   136,    59,    31,   461,
     461,   461,  -160,   315,  -160,    56,    65,   461,  -160,   461,
     155,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   445,  -160,
     195,  -160,   158,  -160,  -160,   461,  -160,    39,    52,   -14,
    -160,  -160,   315,    66,   138,   157,   461,  -160,  -160,  -160,
    -160,   315,  -160,  -160,   199,   461,   160,   461,   209,   315,
     461,   206,   461,  -160,   214,  -160,    67,   315,   211,  -160,
     169,  -160,   315,   315,  -160,  -160,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,   162,     0,    80,     2,   159,   161,     1,
      99,     0,   108,    78,     0,    81,    83,    96,    97,    79,
     160,     0,   109,     0,    77,     0,     0,   165,     0,   164,
       0,   103,     0,     0,   100,    82,    83,     6,     8,     7,
       9,     5,     0,     0,     0,    26,    27,    28,    29,     0,
      11,    22,    30,     0,    31,    35,    38,    41,    46,    49,
      51,    53,    55,    57,    59,    61,   117,    84,     5,   144,
     138,     0,     0,     0,     0,     3,     3,     0,     0,     0,
       0,   150,    74,     0,   142,   143,   129,   130,     3,   140,
     131,   132,   133,   134,   166,   163,   107,     0,     0,   102,
       0,    98,     0,    23,    24,     0,     0,   121,     0,   119,
       0,     0,   125,     0,     0,     0,     0,    17,    18,    19,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    30,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     3,     3,     0,    76,     0,     0,     0,     0,     0,
       0,   150,     0,   156,   157,   149,     0,     0,   145,     0,
     114,     0,   110,   111,   115,     0,   101,    10,     0,   128,
       0,   118,     0,   122,   124,   126,    14,     0,    20,     0,
      15,    16,    62,    32,    33,    34,    36,    37,    39,    40,
      42,    43,    44,    45,    47,    48,    50,    52,    54,     0,
       0,     0,   135,     0,   137,     0,     0,     0,     3,   150,
       0,   155,   158,    75,   139,   141,   113,   104,     0,   106,
       0,   127,   120,   123,    13,     0,    12,    56,    58,     0,
     136,     3,     0,     0,     0,     0,   150,   112,   116,    21,
       3,     0,   148,     3,     0,   150,     0,     0,   146,     0,
       0,     0,   150,    60,     0,   151,     0,     0,     0,     3,
       0,   154,     0,     0,   152,   153,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   -80,  -160,  -160,  -160,  -160,   -22,  -160,   -44,
      34,    37,    13,    35,    74,    72,    64,    14,    12,  -160,
     -78,   -33,  -160,   -51,   119,   -16,     0,  -160,   204,  -160,
      -7,  -160,   200,  -160,  -160,   222,  -160,  -160,     8,  -160,
     -31,  -160,    57,  -160,  -160,   127,   -67,  -160,   -18,  -160,
      76,  -160,  -160,  -159,  -160,  -160,  -160,   240,  -160,  -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,   169,   274,    60,    61,   197,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    92,   141,    93,   165,    13,    38,    24,    25,    15,
      46,    43,    27,   107,   108,    28,   181,   182,   183,   185,
     117,   118,   119,   120,   121,   122,    95,    96,    97,    98,
      99,   100,   101,   176,   102,   103,    16,    17,    18,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   112,    76,   164,    77,   177,   170,    26,    39,   110,
      37,    33,   230,   177,    31,    29,    14,   190,   179,   143,
      94,   187,   105,    22,   104,   260,    76,    20,    21,   177,
     191,   113,   114,  -105,   239,   106,   244,   164,    19,    22,
     175,   142,   240,    34,   245,   178,    47,    48,    49,    50,
      51,    52,    41,   115,    42,   116,    44,    53,    54,   142,
      35,    55,    56,    57,    58,   158,   115,   251,   116,    23,
     255,    20,    21,   199,   159,   177,   252,   263,   280,   157,
     219,   220,   221,    22,   177,   177,   177,    76,   160,   193,
     198,   167,   246,   142,   194,   168,   222,   266,   177,   224,
     203,   204,   205,   228,    59,   171,   271,   180,   202,    20,
      21,   144,   163,   278,   145,   146,   225,   226,   147,   148,
     175,   166,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   151,   152,
     153,   154,   149,   150,   233,   123,   186,   124,   254,   125,
     126,   127,   128,   129,   172,   229,   250,    76,   173,    76,
     174,   243,   184,    94,   210,   211,   212,   213,   155,   156,
     249,   261,   189,   236,   161,   162,   253,   192,   175,   200,
     267,   206,   207,   269,   201,   262,   208,   209,   223,   273,
     214,   215,   227,   231,   268,   177,   237,   142,   142,   283,
     238,   232,   275,   241,   258,   175,   256,   264,   265,   270,
     281,   272,   259,    -4,   175,   285,   286,   277,   279,   276,
     284,   175,   282,   218,    47,    48,    49,    50,    78,    52,
     217,   216,   248,   247,   188,    53,    54,    45,   180,    55,
      56,    57,    58,   111,    32,   142,   257,   242,   195,    47,
      48,    49,    50,    78,    52,   235,    30,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,     0,     0,
      79,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    36,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    79,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    36,   234,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      47,    48,    49,    50,    78,    52,     0,     0,     0,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,    47,    48,
      49,    50,    51,    52,     0,     0,    79,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,     0,    36,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    35,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    36,    47,    48,
      49,    50,    51,    52,     0,     0,   109,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,    47,    48,    49,
      50,    51,    52,   196,     0,     0,     0,     0,    53,    54,
       0,     0,    55,    56,    57,    58,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     0,     0,    53,    54,     0,
       0,    55,    56,    57,    58,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    36,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140
};

static const yytype_int16 yycheck[] =
{
       0,    52,    35,    81,    35,    19,    86,    14,    26,    42,
      26,    19,   171,    19,    21,    15,    16,    51,    98,    63,
      36,    11,    40,    21,    40,    39,    59,     9,    10,    19,
      64,    53,    54,     9,    11,    11,    11,   115,     0,    21,
      91,    63,    19,    51,    19,    51,     5,     6,     7,     8,
       9,    10,    10,    12,    12,    14,    11,    16,    17,    81,
      40,    20,    21,    22,    23,    34,    12,    11,    14,    51,
     229,     9,    10,   124,    35,    19,    11,    11,    11,    20,
     160,   161,   162,    21,    19,    19,    19,   120,    36,   120,
     123,    10,    13,   115,    40,    10,   163,   256,    19,   166,
     144,   145,   146,   170,    63,    10,   265,   107,   141,     9,
      10,    21,    39,   272,    24,    25,   167,   168,    22,    23,
     171,    39,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    28,    29,
      30,    31,    26,    27,   177,    10,    13,    12,   228,    14,
      15,    16,    17,    18,     9,   171,   223,   190,    51,   192,
      51,   192,     9,   179,   151,   152,   153,   154,    32,    33,
     221,   251,     9,   180,    37,    38,   227,    19,   229,     9,
     260,   147,   148,   263,     9,   252,   149,   150,    39,   267,
     155,   156,    10,    51,   261,    19,    11,   219,   220,   279,
      19,    51,   269,    13,     9,   256,    51,    69,    51,    10,
     277,    51,   245,     4,   265,   282,   283,    11,     4,   270,
      51,   272,    11,   159,     5,     6,     7,     8,     9,    10,
     158,   157,   220,   219,   115,    16,    17,    33,   238,    20,
      21,    22,    23,    43,    22,   267,   238,   190,   121,     5,
       6,     7,     8,     9,    10,   179,    16,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    21,    22,    23,     5,     6,
       7,     8,     9,    10,    -1,    -1,    51,    -1,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    21,    22,    23,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    20,    21,    22,    23,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    77,   101,   102,   105,   132,   133,   134,     0,
       9,    10,    21,    51,   103,   104,   106,   108,   111,   102,
     133,   106,   111,    19,    51,    40,    63,   101,   102,   124,
     135,    10,    12,   107,    11,   104,   106,     5,     6,     7,
       8,     9,    10,    16,    17,    20,    21,    22,    23,    63,
      80,    81,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,   116,     9,    51,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    97,    99,   101,   122,   123,   124,   125,   126,
     127,   128,   130,   131,   101,   124,    11,   109,   110,    13,
      97,   108,    99,    83,    83,    12,    14,   116,   117,   118,
     119,   120,   121,    10,    12,    14,    15,    16,    17,    18,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    98,    83,    85,    21,    24,    25,    22,    23,    26,
      27,    28,    29,    30,    31,    32,    33,    20,    34,    35,
      36,    37,    38,    39,    96,   100,    39,    10,    10,    78,
      78,    10,     9,    51,    51,    99,   129,    19,    51,    78,
     102,   112,   113,   114,     9,   115,    13,    11,   100,     9,
      51,    64,    19,   116,    40,   121,    11,    82,    97,    99,
       9,     9,    97,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    89,    89,    90,    91,    92,    78,
      78,    78,   122,    39,   122,    99,    99,    10,   122,   101,
     129,    51,    51,    97,    64,   126,   106,    11,    19,    11,
      19,    13,   118,   116,    11,    19,    13,    93,    94,    99,
     122,    11,    11,    99,    78,   129,    51,   114,     9,    97,
      39,    78,   122,    11,    69,    51,   129,    78,   122,    78,
      10,   129,    51,    96,    79,   122,    99,    11,   129,     4,
      11,   122,    11,    78,    51,   122,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    79,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    86,    86,    86,    86,    87,    87,    87,    88,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   107,   106,   108,
     108,   108,   108,   109,   108,   110,   108,   108,   111,   111,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     0,     1,     1,     1,     1,     1,
       3,     1,     4,     4,     3,     3,     3,     2,     2,     2,
       1,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     1,     4,     1,
       7,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       3,     4,     3,     0,     5,     0,     5,     3,     1,     2,
       1,     1,     3,     2,     1,     1,     3,     1,     3,     1,
       3,     1,     2,     3,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     4,
       1,     3,     1,     1,     1,     2,     6,    10,     5,     1,
       0,     7,     9,     9,     8,     3,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2
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
#line 38 "ass3_15CS30008.y" /* yacc.c:1646  */
    {exit(-1);}
#line 1497 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 40 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.integerVal) = QA->getSize();
	}
#line 1505 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 45 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.list) = makelist(QA->getSize());
		QuadEntry *qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
	}
#line 1515 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry* se = STCurrent->lookup((yyvsp[0].strVal)); 
		(yyval.exp) = new exp_t(se);
		printf("primary_expression <<--- IDENTIFIER\n");
	}
#line 1525 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "ass3_15CS30008.y" /* yacc.c:1646  */
    {	
		(yyval.exp) = new exp_t();
		init_t i;
		i.intVal = (yyvsp[0].integerVal);
		(yyval.exp)->setConstant(true,i,INT);
		printf("primary_expression <<--- CONSTANT\n");
	}
#line 1537 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = new exp_t();
		init_t i;
		i.charVal = (yyvsp[0].charVal);
		(yyval.exp)->setConstant(true,i,CHAR);
		printf("primary_expression <<--- CONSTANT\n");
	}
#line 1549 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = new exp_t();
		init_t i;
		i.doubleVal = (yyvsp[0].doubleVal);
		(yyval.exp)->setConstant(true,i,DOUBLE);
		printf("primary_expression <<--- CONSTANT\n");
	}
#line 1561 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		printf("primary_expression <<--- STRING_LITERAL\n");
	}
#line 1569 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-1].exp);
		printf("primary_expression <<--- (expression)\n");
	}
#line 1578 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp); 
		printf("postfix_expression <<--- primary_expression \n");
	}
#line 1587 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-3].exp);
		SymbolEntry* se = (yyvsp[-3].exp)->getSymbolEntry();
		SymbolEntry* se1 = (yyvsp[-1].exp)->getSymbolEntry();
		SymbolEntry* se2;
		type_t* ty = se->getType();
		type_t *ty1 = new type_t(INT);
		ty = ty->getArrayType();
		if(ty == NULL)
			yyerror("Array Element Does not Exist");
		int width_ = getWidth(ty);
		SymbolEntry* se3 = STCurrent->gentemp(ty1);
		QuadEntry* qe0 = new QuadEntry(OP_MUL,se3->getName(),se1->getName(),to_string(width_));	
		QA->emit(qe0);
		if((yyvsp[-3].exp)->isArrayAccess()){
			se2 = (yyvsp[-3].exp)->getArraySum();
			qe0 = new QuadEntry(OP_ADD,se3->getName(),se3->getName(),se2->getName());
			QA->emit(qe0);
		}
		se2 = new SymbolEntry(se);
		se2->setType(ty);
		(yyval.exp)->setArrayAccess(true,se3);
		(yyval.exp)->setSymbolEntry(se2);
		printf("postfix_expression <<--- postfix_expression[expression]\n");
	}
#line 1617 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-3].exp);
		(yyval.exp)->setFunctionCall(true,(yyvsp[-1].integerVal));
		printf("postfix_expression <<--- postfix_expression (argument_expression_list) \n");
	}
#line 1627 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-2].exp);
		(yyval.exp)->setFunctionCall(true,0);
		printf("postfix_expression <<--- postfix_expression () \n");
	}
#line 1637 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression . IDENTIFIER \n");}
#line 1643 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression -> IDENTIFIER \n");}
#line 1649 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression ++\n");}
#line 1655 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression --\n");}
#line 1661 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		// TODO
		printf("postfix_expression <<--- postfix_expression .'\n");
	}
#line 1670 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.integerVal) = 1;
		SymbolEntry *se = (yyvsp[0].exp)->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		printf("argument_expression_list <<--- assignment_expression \n");
	}
#line 1682 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 155 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.integerVal) = (yyvsp[-2].integerVal) +1;
		SymbolEntry *se = (yyvsp[0].exp)->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		printf("argument_expression_list <<--- argument_expression_list , assignment_expression\n");
	}
#line 1694 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp); 
		printf("unary_expression <<--- postfix_expression  \n");
	}
#line 1703 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 170 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[0].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty1 = new type_t((yyvsp[0].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(ty1->getTypeName() != DOUBLE){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_INCR,se->getName(),se1->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("unary_expression <<--- ++ unary_expression  \n");
	}
#line 1757 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 220 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[0].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty1 = new type_t((yyvsp[0].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(ty1->getTypeName() != DOUBLE){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DECR,se->getName(),se1->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("unary_expression <<--- -- unary_expression \n");
	}
#line 1811 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 270 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		SymbolEntry* se = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry* se1 = se;
		type_t* ty = se->getType();
		QuadEntry *qe;
		if(strcmp(*(yyvsp[-1].strVal),"+") != 0){
			if((yyvsp[0].exp)->isArrayAccess()){
				se1 = STCurrent->gentemp(se->getType());
				qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[0].exp)->getArraySum()->getName());
				QA->emit(qe);
				(yyval.exp)->setArrayAccess(false,NULL);
				(yyval.exp)->setSymbolEntry(se1);
			}
			else if((yyvsp[0].exp)->isConstant()){
				type_t *ty = new type_t((yyvsp[0].exp)->getConstantType());
				se1 = STCurrent->gentemp(ty);
				se1->initialize((yyvsp[0].exp)->getConstantVal());
				(yyval.exp)->setConstant(false);
				(yyval.exp)->setSymbolEntry(se1);
			}
			if(strcmp(*(yyvsp[-1].strVal),"&") == 0){
				if((yyvsp[0].exp)->isConstant())
					yyerror("Invalid reference");
				(yyval.exp)->setAddress(true);
			}
			else if(strcmp(*(yyvsp[-1].strVal),"*") == 0 && ty->getTypeName() == POINTER){
				if((yyvsp[0].exp)->isConstant())
					yyerror("Invalid reference");
				(yyval.exp)->setDeReference(true);
			}
			else if(strcmp(*(yyvsp[-1].strVal),"-") == 0){
				qe = new QuadEntry(OP_NEG,se1->getName(),se1->getName());
				QA->emit(qe);
				(yyval.exp)->setSymbolEntry(se1);				
			}
		}
		printf("unary_expression <<--- unary_operator cast_expression\n");
	}
#line 1855 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 312 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.strVal) = new string("&"); 
		printf("unary_operator <<--- &\n");
	}
#line 1864 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 317 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.strVal) = new string("*"); 
		printf("unary_operator <<--- *\n");
	}
#line 1873 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 322 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.strVal) = new string("+"); 
		printf("unary_operator <<--- +\n");
	}
#line 1882 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 327 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.strVal) = new string("-"); 
		printf("unary_operator <<--- -\n");
	}
#line 1891 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 334 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("cast_expression <<--- unary_expression\n");
	}
#line 1900 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 341 "ass3_15CS30008.y" /* yacc.c:1646  */
    { 
		(yyval.exp) = (yyvsp[0].exp);
		printf("multiplicative_expression <<--- cast_expression\n");
	}
#line 1909 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 346 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_MUL,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("multiplicative_expression <<--- multiplicative_expression * cast_expression \n");
	}
#line 1997 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 430 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DIV,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("multiplicative_expression <<--- multiplicative_expression / cast_expression\n");
	}
#line 2085 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 513 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_MOD,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("multiplicative_expression <<--- multiplicative_expression %% cast_expression\n");
	}
#line 2173 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 599 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("additive_expression <<--- multiplicative_expression\n");
	}
#line 2182 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 604 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ADD,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("additive_expression <<--- additive_expression + multiplicative_expression\n");
	}
#line 2270 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 688 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_SUB,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("additive_expression <<--- additive_expression - multiplicative_expression\n");
	}
#line 2358 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 774 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("shift_expression <<--- additive_expression\n");
	}
#line 2367 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 779 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(ty2->getTypeName() == INT && typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_LSFT,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("shift_expression <<--- shift_expression << additive_expression\n");
	}
#line 2455 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 863 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(ty2->getTypeName() == INT && typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_RSFT,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		printf("shift_expression <<--- shift_expression >> additive_expression\n");
	}
#line 2543 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 949 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("relational_expression <<--- shift_expression\n");
	}
#line 2552 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 954 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LT_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression < shift_expression\n");
	}
#line 2645 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1043 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GT_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression > shift_expression\n");
	}
#line 2738 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1132 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LTE_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression <= shift_expression\n");
	}
#line 2831 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1221 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GTE_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression >= shift_expression\n");
	}
#line 2924 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1312 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("equality_expression <<--- relational_expression\n");
	}
#line 2933 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1317 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_EQ_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("equality_expression <<--- equality_expression == relational_expression\n");
	}
#line 3026 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1406 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_NEQ_GOTO,se->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se);
			(yyval.exp)->setSymbolEntry(se);
			(yyval.exp)->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		(yyval.exp)->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("equality_expression <<--- equality_expression != relational_expression\n");
	}
#line 3119 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1497 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("AND_expression <<--- equality_expression\n");
	}
#line 3128 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1502 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_AND,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		printf("AND_expression <<--- AND_expression & equality_expression\n");
	}
#line 3211 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1583 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("exclusive_OR_expression <<--- AND_expression\n");
	}
#line 3220 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1588 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_XOR,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		printf("exclusive_OR_expression <<--- exclusive_OR_expression ^ AND_expression\n");
	}
#line 3303 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1669 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("inclusive_OR_expression <<--- exclusive_OR_expression\n");
	}
#line 3312 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1674 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if((yyvsp[-2].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[-2].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[-2].exp)->isConstant()){
			ty1 = new type_t((yyvsp[-2].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[-2].exp)->getConstantVal());
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[-2].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[0].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[0].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[0].exp)->isConstant()){
			ty2 = new type_t((yyvsp[0].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[0].exp)->getConstantVal());
		}
		else if((yyvsp[0].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		
		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_OR,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		printf("inclusive_OR_expression <<--- inclusive_OR_expression | exclusive_OR_expression \n");
	}
#line 3396 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1756 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("logical_AND_expression <<--- inclusive_OR_expression\n");
	}
#line 3405 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1761 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-3].exp);
		backpatch((yyvsp[-3].exp)->getTrueList(),(yyvsp[-1].integerVal));
		(yyval.exp)->setFalseList(merge((yyvsp[-3].exp)->getFalseList(),(yyvsp[0].exp)->getFalseList()));
		(yyval.exp)->setTrueList((yyvsp[-3].exp)->getTrueList());
		printf("logical_AND_expression <<--- logical_AND_expression && inclusive_OR_expression\n");
	}
#line 3417 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1771 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("logical_OR_expression <<--- logical_AND_expression\n");
	}
#line 3426 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1776 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[-3].exp);
		backpatch((yyvsp[-3].exp)->getFalseList(),(yyvsp[-1].integerVal));
		(yyval.exp)->setTrueList(merge((yyvsp[-3].exp)->getTrueList(),(yyvsp[0].exp)->getTrueList()));
		(yyval.exp)->setFalseList((yyvsp[0].exp)->getFalseList());
		printf("logical_OR_expression <<--- logical_OR_expression || logical_AND_expression\n");
	}
#line 3438 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1786 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("conditional_expression <<--- logical_OR_expression\n");
	}
#line 3447 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1790 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("conditional_expression <<--- logical_OR_expression ? expression : conditional_expression\n");}
#line 3453 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1793 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);	
		printf("assignment_expression <<--- conditional_expression\n");
	}
#line 3462 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1798 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = (yyvsp[-2].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[0].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* t2 = se_->getType();
		type_t* ty1;
		type_t* ty2;
		bool b1,b2;
		if((yyvsp[-2].exp)->isAddress()){
			yyerror("Invalid Assignment.");	
		}
		else if((yyvsp[-2].exp)->isConstant()){
			yyerror("Invalid Assignment.");
		}
		else if((yyvsp[-2].exp)->isFunctionCall()){
			yyerror("Invalid Assignment.");
		}
		if((yyvsp[-2].exp)->isArrayAccess() || (yyvsp[-2].exp)->isDeReference())
			b1 = true;
		if((yyvsp[0].exp)->isFunctionCall() || (yyvsp[0].exp)->isArrayAccess() || (yyvsp[0].exp)->isDeReference() || (yyvsp[0].exp)->isAddress() || (yyvsp[0].exp)->isConstant())
			b2 = true;

		if(b1 && b2){
			if((yyvsp[0].exp)->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isAddress()){
				ty2 = new type_t(POINTER);
				ty2->setPointedType(se_->getType());
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isConstant()){
				ty2 = new type_t((yyvsp[0].exp)->getConstantType(),false,false);
				se2 = STCurrent->gentemp(ty2);
				se2->initialize((yyvsp[0].exp)->getConstantVal());
			}

			if((yyvsp[-2].exp)->isArrayAccess()){
				ty1 = se->getType();
				se1 = STCurrent->gentemp(ty1);
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),(yyvsp[-2].exp)->getArraySum()->getName(),se2->getName());
				QA->emit(qe);
			}
			else if((yyvsp[-2].exp)->isDeReference()){
				ty1 = se1->getType();
				ty1 = ty1->getPointedType();
				se1 = STCurrent->gentemp(ty1);
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se2->getName());
				QA->emit(qe);
			}
		}
		else if(b1 && !b2){
			if((yyvsp[-2].exp)->isArrayAccess()){
				ty1 = se->getType();
				se1 = STCurrent->gentemp(ty1);
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),(yyvsp[-2].exp)->getArraySum()->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[-2].exp)->isDeReference()){
				ty1 = se1->getType();
				ty1 = ty1->getPointedType();
				se1 = STCurrent->gentemp(ty1);
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se_->getName());
				QA->emit(qe);
			}
		}
		else if(!b1 && b2){
			if((yyvsp[0].exp)->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se->getName(),se_->getName(),to_string((yyvsp[0].exp)->getNoOfParams()));
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se->getName(),se_->getName(),(yyvsp[0].exp)->getArraySum()->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isAddress()){
				ty2 = new type_t(POINTER,true,false);
				ty2->setPointedType(se_->getType());
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isConstant()){
				ty2 = new type_t((yyvsp[0].exp)->getConstantType(),false,false);
				se2 = STCurrent->gentemp(ty2);
				se2->initialize((yyvsp[0].exp)->getConstantVal());
			}
		}
		else{
			if(typecheck(ty1,ty2)){
				qe = new QuadEntry(OP_COPY,se->getName(),se_->getName());
				QA->emit(qe);
			}
			else
				yyerror("Incompactible types.");
		}
		printf("assignment_expression <<--- unary_expression assignment_operator assignment_expression \n");
	}
#line 3603 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1936 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- =\n");}
#line 3609 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1937 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- *=\n");}
#line 3615 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1938 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- /=\n");}
#line 3621 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1939 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- %%=\n");}
#line 3627 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1940 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- +=\n");}
#line 3633 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1941 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- -=\n");}
#line 3639 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1942 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- <<=\n");}
#line 3645 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1943 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- >>=\n");}
#line 3651 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1944 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- &=\n");}
#line 3657 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1945 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- ^=\n");}
#line 3663 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1946 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- |=\n");}
#line 3669 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1949 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression <<--- assignment_expression\n");}
#line 3675 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1950 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression <<--- expression , assignment_expression\n");}
#line 3681 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1953 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("constant_expression <<--- conditional_expression\n");}
#line 3687 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1956 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration <<--- declaration_specifiers init_declarator_list ;\n");}
#line 3693 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1957 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration <<--- declaration_specifiers ;\n");}
#line 3699 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1961 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = (yyvsp[-1].type); 
		type_global = (yyvsp[-1].type);
		printf("declaration_specifiers <<--- type_specifier declaration_specifiers\n");
	}
#line 3709 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1967 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = (yyvsp[0].type); 
		type_global = (yyvsp[0].type);
		printf("declaration_specifiers <<--- type_specifier\n");
	}
#line 3719 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1974 "ass3_15CS30008.y" /* yacc.c:1646  */
    { printf("init_declarator_list <<--- init_declarator\n");}
#line 3725 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1975 "ass3_15CS30008.y" /* yacc.c:1646  */
    { printf("init_declarator_list <<--- init_declarator_list , init_declarator\n");}
#line 3731 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1979 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		type_t *ty = (yyvsp[0].decl)->getType();
		SymbolEntry *se;
		if(ty->getTypeName() == FUNCTION){
			se = STStack.back()->gentemp((yyvsp[0].decl));
			se->setNestedTable(STCurrent);
			STCurrent = STStack.back();
			STStack.pop_back();
		}
		else	
			se = STCurrent->gentemp((yyvsp[0].decl));
		printf("init_declarator <<--- declarator\n");
	}
#line 3749 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1992 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = STCurrent->gentemp((yyvsp[-2].decl));
		SymbolEntry *se1 = (yyvsp[0].exp)->getSymbolEntry();
		QuadEntry *qe;
		type_t* ty1 = (yyvsp[-2].decl)->getType();
		type_n ty_N = ty1->getTypeName();
		if(ty_N == POINTER){
			if((yyvsp[0].exp)->isAddress()){
				type_t * ty2 = new type_t(POINTER,true,false);
				ty2->setPointedType(se1->getType());
				SymbolEntry *se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isDeReference()){
				type_t * ty2 = se1->getType();
				SymbolEntry *se2 = STCurrent->gentemp(ty2->getPointedType());
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isConstant())
			yyerror("Invalid Declaration");
			else{
				qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());	
				QA->emit(qe);
			}
		}
		else if(ty_N == MATRIX){
			// TODO
		}
		else{
			if((yyvsp[0].exp)->isAddress())
				yyerror("Invalid Declaration");
			else if((yyvsp[0].exp)->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_R,se->getName(),se1->getName());
				QA->emit(qe);
			}
			else if((yyvsp[0].exp)->isConstant())
				se->initialize((yyvsp[0].exp)->getConstantVal());
			else{
				qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());	
				QA->emit(qe);
			}
		}
		printf("init_declarator <<--- declarator = initializer\n");
	}
#line 3804 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2045 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(VOID,false,false);
		printf("type_specifier : void\n");
	}
#line 3813 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2050 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(CHAR,false,false);
		printf("type_specifier : char\n");
	}
#line 3822 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2055 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		printf("type_specifier : short\n");
	}
#line 3830 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2059 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(INT,false,false);
		printf("type_specifier : int\n");
	}
#line 3839 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2063 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : long\n");}
#line 3845 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 2064 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : float\n");}
#line 3851 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 2066 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(DOUBLE,false,false);
		printf("type_specifier : double\n");
	}
#line 3860 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 2071 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(MATRIX,false,true);
		printf("type_specifier : Matrix\n");
	}
#line 3869 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2075 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : signed\n");}
#line 3875 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 2076 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : unsigned\n");}
#line 3881 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 2077 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : Bool\n");}
#line 3887 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 2081 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[0].decl);
		printf("declarator <<--- direct_declarator\n");
	}
#line 3896 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 2086 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		type_global = (yyvsp[0].type);
	}
#line 3904 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 2090 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[0].decl);
		printf("declarator <<--- pointer direct_declarator \n");
	}
#line 3913 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 2097 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = new decl_t(type_global);  
		(yyval.decl)->setName((yyvsp[0].strVal)); 
		printf("direct_declarator <<--- IDENTIFIER\n");
	}
#line 3923 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 2103 "ass3_15CS30008.y" /* yacc.c:1646  */
    { 
		type_t* ty = (yyvsp[-1].decl)->getType();
		typecheck(type_global,ty);
		(yyval.decl) = (yyvsp[-1].decl);
		(yyval.decl)->setType(type_global); 
		printf("direct_declarator <<--- (declarator)\n");
	}
#line 3935 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 2111 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[-3].decl);
		SymbolEntry *se = (yyvsp[-1].exp)->getSymbolEntry();
		int arraySize = (se->getInitialValue()).intVal;
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType((yyvsp[-3].decl)->getType(),arraySize);
		(yyval.decl)->setType(ty);
		printf("direct_declarator <<--- direct_declarator [assignment_expression]\n");
	}
#line 3949 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 2121 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[-2].decl); 
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType((yyvsp[-2].decl)->getType(),0);
		(yyval.decl)->setType(ty);
		printf("direct_declarator <<--- direct_declarator []\n");
	}
#line 3961 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 2129 "ass3_15CS30008.y" /* yacc.c:1646  */
    { 
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();	
	}
#line 3970 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 2134 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[-4].decl);
		(yyval.decl)->setType(FUNCTION);
		(yyval.decl)->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
		printf("direct_declarator <<--- direct_declarator (parameter_type_list)\n");
	}
#line 3983 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 2143 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		STStack.push_back(STCurrent);
	}
#line 3991 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 2147 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[-4].decl);
		(yyval.decl)->setType(FUNCTION);
		STCurrent = new SymbolTable();
		(yyval.decl)->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);		
		printf("direct_declarator <<--- direct_declarator (identifier_list)\n");
	}
#line 4005 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 2157 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.decl) = (yyvsp[-2].decl);
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();
		(yyval.decl)->setType(FUNCTION);
		(yyval.decl)->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
		printf("direct_declarator <<--- direct_declarator ()\n");
	}
#line 4020 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 2169 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = new type_t(POINTER,true,false);
		(yyval.type)->setPointedType(type_global);
		printf("pointer <<--- *\n");
	}
#line 4030 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2175 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.type) = (yyvsp[0].type);
		(yyval.type)->setPointedType((yyvsp[0].type));
		printf("pointer <<--- * pointer\n");
	}
#line 4040 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2182 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_type_list <<--- parameter_list\n");}
#line 4046 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2184 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_list <<--- parameter_declaration\n");}
#line 4052 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2185 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_list <<--- parameter_list ',' parameter_declaration\n");}
#line 4058 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2189 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		STCurrent->gentemp((yyvsp[0].decl)); 
		printf("parameter_declaration <<--- declaration_specifiers declarator\n");
	}
#line 4067 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2194 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		STCurrent->gentemp((yyvsp[0].type));
		printf("parameter_declaration <<--- declaration_specifiers\n");
	}
#line 4076 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2201 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup((yyvsp[0].strVal));
		STCurrent->gentemp(se);
		printf("identifier_list <<--- IDENTIFIER \n");
	}
#line 4087 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2208 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup((yyvsp[0].strVal));
		STCurrent->gentemp(se);	
		printf("identifier_list <<--- identifier_list , IDENTIFIER \n");
	}
#line 4098 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2217 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);	
		printf("initializer <<--- assignment_expression\n");
	}
#line 4107 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2221 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer <<--- {initializer_row_list}\n");}
#line 4113 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2224 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row_list <<--- initializer_row\n");}
#line 4119 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2225 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row_list <<--- initializer_row_list ; initializer_row\n");}
#line 4125 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2228 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<--- initializer\n");}
#line 4131 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2229 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<--- designation initializer\n");}
#line 4137 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2230 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<---  initializer_row , initializer\n");}
#line 4143 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2233 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designation <<--- designator_list =\n");}
#line 4149 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2235 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator_list <<--- designator\n");}
#line 4155 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2236 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator_list <<--- designator_list designator\n");}
#line 4161 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2239 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator <<--- [constant_expression]\n");}
#line 4167 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2240 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator <<--- . IDENTIFIER\n");}
#line 4173 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2243 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- labeled_statement\n");}
#line 4179 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2244 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- compound_statement\n");}
#line 4185 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2245 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- expression_statement\n");}
#line 4191 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2247 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("statement <<--- selection_statement\n");
	}
#line 4200 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2252 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("statement <<--- iteration_statement\n");
	}
#line 4209 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 2256 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- jump_statement\n");}
#line 4215 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 2259 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- IDENTIFIER : statement\n");}
#line 4221 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 2260 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- case constant_expression : statement\n");}
#line 4227 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2261 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- default statement\n");}
#line 4233 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2264 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("compound_statement : {}\n");}
#line 4239 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2266 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].exp) != NULL)
			backpatch((yyvsp[-2].exp)->getNextList(),(yyvsp[-1].integerVal));
		printf("compound_statement : {block_item_list}\n");
	}
#line 4249 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2274 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("block_item_list <<--- block_item\n");
	}
#line 4258 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2279 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].exp) != NULL){
			backpatch((yyvsp[-2].exp)->getNextList(),(yyvsp[-1].integerVal));
			(yyval.exp)->setNextList((yyvsp[0].exp)->getNextList());
		}
		else
			(yyval.exp) = NULL;
		printf("block_item_list <<--- block_item_list block_item\n");
	}
#line 4272 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2291 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = NULL;
		printf("block_item <<--- declaration\n");
	}
#line 4281 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 2296 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp);
		printf("block_item <<--- statement\n");
	}
#line 4290 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2302 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_statement <<--- ;\n");}
#line 4296 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2303 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_statement <<--- expression ;\n");}
#line 4302 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2307 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-3].exp)->getTrueList(),(yyvsp[-1].integerVal));
		(yyval.exp)->setNextList(merge((yyvsp[-3].exp)->getFalseList(),(yyvsp[0].exp)->getNextList()));	
		printf("selection_statement <<--- if (expression) statement\n");
	}
#line 4312 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2313 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-7].exp)->getTrueList(),(yyvsp[-5].integerVal));
		backpatch((yyvsp[-7].exp)->getFalseList(),(yyvsp[-1].integerVal));
		vector<int>* temp = merge((yyvsp[-4].exp)->getNextList(),(yyvsp[-3].list));
		(yyval.exp)->setNextList(merge(temp,(yyvsp[0].exp)->getNextList()));
		printf("selection_statement <<--- if (expression) statement else statement\n");
	}
#line 4324 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2320 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("selection_statement <<--- switch (expression) statement\n");}
#line 4330 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2324 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = (yyvsp[0].exp); printf("expression_opt <<--- expression\n");
	}
#line 4338 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2328 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		(yyval.exp) = NULL;
		printf("expression_opt <<--- epsilon\n");
	}
#line 4347 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 2335 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[0].exp)->getNextList(),(yyvsp[-5].integerVal));
		backpatch((yyvsp[-3].exp)->getTrueList(),(yyvsp[-1].integerVal));
		(yyval.exp)->setNextList((yyvsp[-3].exp)->getFalseList());
		QuadEntry *qe = new QuadEntry(OP_GOTO,to_string((yyvsp[-5].integerVal)));
		QA->emit(qe);
		printf("iteration_statement <<--- while (expression) statement \n");
	}
#line 4360 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2344 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-2].exp)->getTrueList(),(yyvsp[-7].integerVal));
		backpatch((yyvsp[-6].exp)->getNextList(),(yyvsp[-5].integerVal));
		(yyval.exp)->setNextList((yyvsp[-2].exp)->getFalseList());
		printf("iteration_statement <<--- do statement while (expression);\n");
	}
#line 4371 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2350 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- for (expression_opt ; expression_opt ; expression_opt) statement\n");}
#line 4377 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2351 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- for(declaration expression_opt; expression_opt) statement\n");}
#line 4383 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2354 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- goto IDENTIFIER ;\n");}
#line 4389 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2355 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- continue;\n");}
#line 4395 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2356 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- break;\n");}
#line 4401 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 2358 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		QuadEntry *qe;
		if( (yyvsp[-1].exp) == NULL )
			qe = new QuadEntry(OP_RETURN,"");
		else{
			string *name = new string("retVal");
			SymbolEntry *se = STCurrent->lookup(name);
			SymbolEntry *se1 = (yyvsp[-1].exp)->getSymbolEntry();
			se->initialize(se1->getInitialValue());
			qe = new QuadEntry(OP_RETURN,se1->getName());
		}
		printf("jump_statement <<--- return expression_opt ;\n");
	}
#line 4419 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2373 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("translation_unit <<--- external_declaration\n");}
#line 4425 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2374 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("translation_unit <<--- translation_unit external_declaration\n");}
#line 4431 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 2377 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("external_declaration <<--- function_definition\n");}
#line 4437 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 2379 "ass3_15CS30008.y" /* yacc.c:1646  */
    {

		printf("external_declaration <<--- definition\n");
	}
#line 4446 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2386 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = STStack.back()->gentemp((yyvsp[-2].decl));
		se->setNestedTable(STCurrent);
		STCurrent = STStack.back();
		STStack.pop_back();
		printf("function_definition <<--- declaration_specifiers declarator declaration_list compound_statement\n");
	}
#line 4458 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2394 "ass3_15CS30008.y" /* yacc.c:1646  */
    {
		SymbolEntry *se = STStack.back()->gentemp((yyvsp[-1].decl));
		se->setNestedTable(STCurrent);
		STCurrent = STStack.back();
		STStack.pop_back();
		printf("function_definition <<---declaration_specifiers declarator compound_statement\n");
	}
#line 4470 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2403 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_list <<--- declaration\n");}
#line 4476 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 2404 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_list <<--- declaration_list declaration\n");}
#line 4482 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;


#line 4486 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
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
#line 2407 "ass3_15CS30008.y" /* yacc.c:1906  */


	void yyerror(const char* s){
		printf("%s\n",s);
		exit(-1);
	}
