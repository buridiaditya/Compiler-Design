/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_CONSTANT = 260,
     DOUBLE_CONSTANT = 261,
     CHAR_CONSTANT = 262,
     STRING_LITERAL = 263,
     IDENTIFIER = 264
   };
#endif
/* Tokens.  */
#define INT_CONSTANT 260
#define DOUBLE_CONSTANT 261
#define CHAR_CONSTANT 262
#define STRING_LITERAL 263
#define IDENTIFIER 264




/* Copy the first part of user declarations.  */
#line 1 "15CS30008.y"

	int yylex();
	void yyerror(const char*);
	

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 6 "15CS30008.y"
{
		int integerVal;
		char charVal;
		double doubleVal;
		string* strVal;
		decl_t* decl; 
		exp_t* exp;
		type_t* type;
		vector<int>* list;
	}
/* Line 193 of yacc.c.  */
#line 126 "15CS30008.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 139 "15CS30008.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   520

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  292

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     7,     9,    11,    13,    15,
      17,    21,    23,    28,    33,    37,    41,    45,    48,    51,
      54,    56,    60,    62,    65,    68,    71,    73,    75,    77,
      79,    81,    83,    87,    91,    95,    97,   101,   105,   107,
     111,   115,   117,   121,   125,   129,   133,   135,   139,   143,
     145,   149,   151,   155,   157,   161,   163,   168,   170,   175,
     177,   185,   187,   191,   193,   195,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   215,   219,   221,   225,   228,
     231,   233,   235,   239,   241,   245,   247,   249,   251,   253,
     255,   257,   259,   261,   263,   265,   267,   269,   270,   274,
     276,   280,   285,   289,   290,   296,   297,   303,   307,   309,
     312,   314,   316,   320,   323,   325,   327,   331,   333,   337,
     339,   343,   345,   348,   352,   355,   357,   360,   364,   367,
     369,   371,   373,   375,   377,   379,   383,   388,   392,   395,
     400,   402,   406,   408,   410,   412,   415,   422,   433,   440,
     442,   443,   451,   461,   475,   484,   488,   491,   494,   498,
     500,   503,   505,   507,   512,   516,   518
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      77,     0,    -1,   132,    -1,    -1,    -1,     9,    -1,     5,
      -1,     7,    -1,     6,    -1,     8,    -1,    10,    99,    11,
      -1,    80,    -1,    81,    12,    99,    13,    -1,    81,    10,
      82,    11,    -1,    81,    10,    11,    -1,    81,    14,     9,
      -1,    81,    15,     9,    -1,    81,    16,    -1,    81,    17,
      -1,    81,    18,    -1,    97,    -1,    82,    19,    97,    -1,
      81,    -1,    16,    83,    -1,    17,    83,    -1,    84,    85,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    83,
      -1,    85,    -1,    86,    21,    85,    -1,    86,    24,    85,
      -1,    86,    25,    85,    -1,    86,    -1,    87,    22,    86,
      -1,    87,    23,    86,    -1,    87,    -1,    88,    26,    87,
      -1,    88,    27,    87,    -1,    88,    -1,    89,    28,    88,
      -1,    89,    29,    88,    -1,    89,    30,    88,    -1,    89,
      31,    88,    -1,    89,    -1,    90,    32,    89,    -1,    90,
      33,    89,    -1,    90,    -1,    91,    20,    90,    -1,    91,
      -1,    92,    34,    91,    -1,    92,    -1,    93,    35,    92,
      -1,    93,    -1,    94,    36,    78,    93,    -1,    94,    -1,
      95,    37,    78,    94,    -1,    95,    -1,    95,    38,    78,
      99,    39,    78,    96,    -1,    96,    -1,    83,    98,    97,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,    97,    -1,    99,    19,    97,    -1,    96,
      -1,   102,   103,    51,    -1,   102,    51,    -1,   105,   102,
      -1,   105,    -1,   104,    -1,   103,    19,   104,    -1,   106,
      -1,   106,    40,   116,    -1,    52,    -1,    53,    -1,    54,
      -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,   108,    -1,    -1,
     111,   107,   108,    -1,     9,    -1,    10,   106,    11,    -1,
     108,    12,    97,    13,    -1,   108,    12,    13,    -1,    -1,
     108,    10,   109,   112,    11,    -1,    -1,   108,    10,   110,
     115,    11,    -1,   108,    10,    11,    -1,    21,    -1,    21,
     111,    -1,   113,    -1,   114,    -1,   113,    19,   114,    -1,
     102,   106,    -1,   102,    -1,     9,    -1,   115,    19,     9,
      -1,    97,    -1,    63,   117,    64,    -1,   118,    -1,   117,
      51,   118,    -1,   116,    -1,   119,   116,    -1,   118,    19,
     116,    -1,   120,    40,    -1,   121,    -1,   120,   121,    -1,
      12,   100,    13,    -1,    14,     9,    -1,   123,    -1,   124,
      -1,   127,    -1,   128,    -1,   130,    -1,   131,    -1,     9,
      39,   122,    -1,    65,   100,    39,   122,    -1,    66,    39,
     122,    -1,    63,    64,    -1,    63,   125,    78,    64,    -1,
     126,    -1,   125,    78,   126,    -1,   101,    -1,   122,    -1,
      51,    -1,    99,    51,    -1,    67,    10,    99,    11,    78,
     122,    -1,    67,    10,    99,    11,    78,   122,    79,     4,
      78,   122,    -1,    68,    10,    99,    11,    78,   122,    -1,
      99,    -1,    -1,    69,    78,    10,    99,    11,    78,   122,
      -1,    70,    78,   122,    78,    69,    10,    99,    11,    51,
      -1,    71,    10,   129,    51,    78,   129,    51,    78,   129,
      79,    11,    78,   122,    -1,    71,    10,   101,   129,    51,
     129,    11,   122,    -1,    72,     9,    51,    -1,    73,    51,
      -1,    74,    51,    -1,    75,   129,    51,    -1,   133,    -1,
     132,   133,    -1,   134,    -1,   101,    -1,   102,   106,   135,
     124,    -1,   102,   106,   124,    -1,   101,    -1,   135,   101,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    60,    66,    73,    82,    90,    98,   106,
     110,   117,   122,   152,   158,   164,   165,   166,   222,   277,
     284,   292,   302,   307,   357,   407,   449,   454,   459,   464,
     471,   478,   483,   572,   661,   751,   756,   845,   936,   941,
    1030,  1121,  1126,  1220,  1314,  1408,  1504,  1509,  1601,  1697,
    1702,  1788,  1793,  1879,  1884,  1971,  1976,  1986,  1991,  2001,
    2006,  2008,  2012,  2289,  2293,  2297,  2301,  2305,  2309,  2313,
    2314,  2318,  2319,  2320,  2325,  2330,  2337,  2339,  2340,  2343,
    2349,  2357,  2358,  2361,  2375,  2427,  2432,  2437,  2441,  2446,
    2447,  2448,  2453,  2458,  2459,  2460,  2463,  2469,  2468,  2479,
    2485,  2493,  2509,  2518,  2517,  2532,  2531,  2546,  2559,  2565,
    2573,  2575,  2576,  2579,  2584,  2591,  2598,  2607,  2612,  2615,
    2616,  2619,  2620,  2621,  2624,  2626,  2627,  2630,  2631,  2634,
    2639,  2644,  2649,  2654,  2659,  2666,  2667,  2668,  2671,  2672,
    2679,  2684,  2693,  2698,  2705,  2706,  2709,  2716,  2725,  2733,
    2738,  2744,  2754,  2763,  2771,  2777,  2778,  2779,  2780,  2827,
    2831,  2837,  2838,  2844,  2852,  2862,  2863
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "type_specifier", "declarator", "@1", "direct_declarator", "@2", "@3",
  "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer",
  "initializer_row_list", "initializer_row", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "expression_opt",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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
       1,     3,     1,     1,     1,     2,     6,    10,     6,     1,
       0,     7,     9,    13,     8,     3,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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
     136,     3,     3,     0,     0,     0,     3,   112,   116,    21,
       3,     0,     0,     3,     0,   150,   150,     0,   146,   148,
       0,     0,     0,     0,    60,     0,   151,     0,     0,     3,
       3,     0,   154,   150,     0,   152,     4,   147,     0,     3,
       0,   153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,   169,   275,    60,    61,   197,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    92,   141,    93,   165,    13,    38,    24,    25,    15,
      46,    43,    27,   107,   108,    28,   181,   182,   183,   185,
     117,   118,   119,   120,   121,   122,    95,    96,    97,    98,
      99,   100,   101,   176,   102,   103,    16,    17,    18,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -166
static const yytype_int16 yypact[] =
{
     447,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,    48,  -166,    12,   447,   447,  -166,  -166,  -166,
    -166,     8,    34,  -166,    -8,  -166,   365,    55,  -166,  -166,
    -166,    41,  -166,     8,  -166,   353,   219,  -166,    12,  -166,
     435,    27,   186,    75,  -166,  -166,    28,  -166,  -166,  -166,
    -166,  -166,   463,   463,   463,  -166,  -166,  -166,  -166,   334,
    -166,    60,   470,   463,  -166,    78,    82,    65,    81,   110,
      51,    45,    71,    83,    77,  -166,  -166,  -166,   108,  -166,
    -166,   463,   109,    76,   111,  -166,  -166,   140,   144,   103,
     105,   463,  -166,    -5,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   447,   149,  -166,
     153,    55,    16,  -166,  -166,   463,   158,  -166,   -17,   143,
     353,    11,  -166,   444,   463,   160,   166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   463,  -166,  -166,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
    -166,  -166,  -166,   315,  -166,   146,   315,   463,   463,   169,
     315,   386,   131,  -166,  -166,   164,   135,   463,  -166,   244,
       8,   176,   171,  -166,  -166,    31,  -166,  -166,   175,  -166,
     334,  -166,   353,  -166,  -166,  -166,  -166,    38,  -166,    26,
    -166,  -166,  -166,  -166,  -166,  -166,    78,    78,    82,    82,
      65,    65,    65,    65,    81,    81,   110,    51,    45,   463,
     463,   463,  -166,   315,  -166,    43,    47,   463,  -166,   463,
     154,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   447,  -166,
     195,  -166,   143,  -166,  -166,   463,  -166,    71,    83,   -11,
    -166,  -166,  -166,    50,   142,   162,  -166,  -166,  -166,  -166,
    -166,   315,   315,  -166,   206,   463,   463,   463,   213,  -166,
     315,   463,   207,   168,  -166,   217,  -166,    69,   315,  -166,
    -166,   172,  -166,   463,   315,  -166,  -166,  -166,   211,  -166,
     315,  -166
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,   -79,   -56,  -166,  -166,  -166,   -22,  -166,   -50,
      -2,   -52,   -13,     9,    74,    79,    84,    14,    24,  -166,
     -78,   -33,  -166,   -51,   119,   -16,     0,  -166,   214,  -166,
      -9,  -166,   203,  -166,  -166,   226,  -166,  -166,    17,  -166,
     -31,  -166,    66,  -166,  -166,   136,  -110,  -166,     4,  -166,
      80,  -166,  -166,  -165,  -166,  -166,  -166,   242,  -166,  -166
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -106
static const yytype_int16 yytable[] =
{
      14,   112,    76,   164,    77,    26,   230,   170,   177,   110,
      37,    33,    31,   143,   177,    29,    14,    20,    21,   179,
      94,    20,    21,   115,   104,   116,    76,   187,   260,    22,
      39,   113,   114,    22,   190,   177,  -105,   164,   106,   246,
     175,   142,   239,    34,   105,   177,   178,   191,    19,   244,
     240,   194,    44,   222,   251,    22,   224,   245,   252,   142,
     228,   263,   177,    23,   255,    41,   177,    42,    35,   177,
     123,   157,   124,   199,   125,   126,   127,   128,   129,   158,
     281,   219,   220,   221,    20,    21,   167,    76,   177,   193,
     198,   149,   150,   142,   203,   204,   205,   208,   209,   144,
     272,   273,   145,   146,   147,   148,   159,   180,   202,   151,
     152,   153,   154,   250,   161,   162,   225,   226,   286,   160,
     175,   168,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   210,   211,
     212,   213,   155,   156,   233,   206,   207,   163,   166,   254,
     171,   268,   269,   172,   173,   229,   174,    76,   184,    76,
     276,   243,   192,    94,   214,   215,   186,   189,   282,   200,
     249,   236,   261,   262,   287,   201,   253,   266,   175,   227,
     291,   267,   231,   177,   270,   223,   232,   237,   241,   274,
     238,    47,    48,    49,    50,    51,    52,   142,   142,   109,
     283,   284,    53,    54,   258,   256,    55,    56,    57,    58,
     290,   264,   259,   265,   175,   175,   271,    -4,   278,   279,
     277,   280,   289,   285,    47,    48,    49,    50,    78,    52,
     288,   216,   175,   247,   188,    53,    54,   217,   180,    55,
      56,    57,    58,   218,   248,   142,   111,    45,    32,    47,
      48,    49,    50,    78,    52,   257,   242,   195,    30,   235,
      53,    54,     0,     0,    55,    56,    57,    58,     0,     0,
      79,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    36,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    79,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    36,   234,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      47,    48,    49,    50,    78,    52,     0,     0,     0,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,    47,
      48,    49,    50,    51,    52,     0,   115,     0,   116,     0,
      53,    54,     0,     0,    55,    56,    57,    58,    47,    48,
      49,    50,    51,    52,     0,     0,    79,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,     0,    36,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    47,    48,    49,    50,    51,    52,    59,     0,     0,
       0,     0,    53,    54,     0,    35,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,    59,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    47,
      48,    49,    50,    51,    52,   196,     0,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    36,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140
};

static const yytype_int16 yycheck[] =
{
       0,    52,    35,    81,    35,    14,   171,    86,    19,    42,
      26,    19,    21,    63,    19,    15,    16,     9,    10,    98,
      36,     9,    10,    12,    40,    14,    59,    11,    39,    21,
      26,    53,    54,    21,    51,    19,     9,   115,    11,    13,
      91,    63,    11,    51,    40,    19,    51,    64,     0,    11,
      19,    40,    11,   163,    11,    21,   166,    19,    11,    81,
     170,    11,    19,    51,   229,    10,    19,    12,    40,    19,
      10,    20,    12,   124,    14,    15,    16,    17,    18,    34,
      11,   160,   161,   162,     9,    10,    10,   120,    19,   120,
     123,    26,    27,   115,   144,   145,   146,   149,   150,    21,
     265,   266,    24,    25,    22,    23,    35,   107,   141,    28,
      29,    30,    31,   223,    37,    38,   167,   168,   283,    36,
     171,    10,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   151,   152,
     153,   154,    32,    33,   177,   147,   148,    39,    39,   228,
      10,   261,   262,     9,    51,   171,    51,   190,     9,   192,
     270,   192,    19,   179,   155,   156,    13,     9,   278,     9,
     221,   180,   251,   252,   284,     9,   227,   256,   229,    10,
     290,   260,    51,    19,   263,    39,    51,    11,    13,   267,
      19,     5,     6,     7,     8,     9,    10,   219,   220,    13,
     279,   280,    16,    17,     9,    51,    20,    21,    22,    23,
     289,    69,   245,    51,   265,   266,    10,     4,    11,    51,
     271,     4,    11,    51,     5,     6,     7,     8,     9,    10,
     286,   157,   283,   219,   115,    16,    17,   158,   238,    20,
      21,    22,    23,   159,   220,   267,    43,    33,    22,     5,
       6,     7,     8,     9,    10,   238,   190,   121,    16,   179,
      16,    17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    -1,
      16,    17,    -1,    -1,    20,    21,    22,    23,     5,     6,
       7,     8,     9,    10,    -1,    -1,    51,    -1,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     5,     6,     7,     8,     9,    10,    63,    -1,    -1,
      -1,    -1,    16,    17,    -1,    40,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    21,    22,    23,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50
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
      39,    78,    78,    11,    69,    51,    78,    78,   122,   122,
      78,    10,   129,   129,    96,    79,   122,    99,    11,    51,
       4,    11,   122,    78,    78,    51,   129,   122,    79,    11,
      78,   122
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 51 "15CS30008.y"
    {
		cout << "Symbol Table" << endl;
		STCurrent->print();
		cout << "===================================================" << endl;
		cout << "Quad Array" << endl;
		QA->print();
		exit(0);
	;}
    break;

  case 3:
#line 60 "15CS30008.y"
    {
		// Augmented for getting the next instruction number
		(yyval.integerVal) = QA->getSize();
	;}
    break;

  case 4:
#line 66 "15CS30008.y"
    {
		// Augmented to generate GOTO instruction when necessary
		(yyval.list) = makelist(QA->getSize());
		QuadEntry *qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
	;}
    break;

  case 5:
#line 74 "15CS30008.y"
    {
		SymbolEntry* se = STCurrent->lookup((yyvsp[(1) - (1)].strVal)); 
		if(se == NULL){
			se = ST->lookup((yyvsp[(1) - (1)].strVal));
		}
		(yyval.exp) = new exp_t(se);
		
	;}
    break;

  case 6:
#line 83 "15CS30008.y"
    {	
		(yyval.exp) = new exp_t();
		init_t i;
		i.intVal = (yyvsp[(1) - (1)].integerVal);
		(yyval.exp)->setConstant(true,i,INT);
		
	;}
    break;

  case 7:
#line 91 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		init_t i;
		i.charVal = (yyvsp[(1) - (1)].charVal);
		(yyval.exp)->setConstant(true,i,CHAR);
		
	;}
    break;

  case 8:
#line 99 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		init_t i;
		i.doubleVal = (yyvsp[(1) - (1)].doubleVal);
		(yyval.exp)->setConstant(true,i,DOUBLE);
		
	;}
    break;

  case 9:
#line 107 "15CS30008.y"
    {
		
	;}
    break;

  case 10:
#line 111 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(2) - (3)].exp);
		
	;}
    break;

  case 11:
#line 118 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp); 
		
	;}
    break;

  case 12:
#line 123 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (4)].exp);
		SymbolEntry* se = (yyvsp[(1) - (4)].exp)->getSymbolEntry();
		SymbolEntry* se1 = (yyvsp[(3) - (4)].exp)->getSymbolEntry();
		if((yyvsp[(3) - (4)].exp)->isConstant()){
			type_t * ty = new type_t((yyvsp[(3) - (4)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty);
			se1->initialize((yyvsp[(3) - (4)].exp)->getConstantVal());
		}
		SymbolEntry* se2;
		type_t* ty = se->getType();
		type_t *ty1 = new type_t(INT);
		ty = ty->getArrayType();
		if(ty == NULL)
			yyerror("Array Element Does not Exist");
		int width_ = getWidth(ty);
		QuadEntry* qe0 = new QuadEntry(OP_MUL,se1->getName(),se1->getName(),to_string(width_));	
		QA->emit(qe0);
		if((yyvsp[(1) - (4)].exp)->isArrayAccess()){
			se2 = (yyvsp[(1) - (4)].exp)->getArraySum();
			qe0 = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
			QA->emit(qe0);
		}
		se2 = new SymbolEntry(se);
		se2->setType(ty);
		(yyval.exp)->setArrayAccess(true,se1);
		(yyval.exp)->setSymbolEntry(se2);
		
	;}
    break;

  case 13:
#line 153 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (4)].exp);
		(yyval.exp)->setFunctionCall(true,(yyvsp[(3) - (4)].integerVal));
		
	;}
    break;

  case 14:
#line 159 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (3)].exp);
		(yyval.exp)->setFunctionCall(true,0);
		
	;}
    break;

  case 15:
#line 164 "15CS30008.y"
    {;}
    break;

  case 16:
#line 165 "15CS30008.y"
    {;}
    break;

  case 17:
#line 167 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (2)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 ;
		init_t i;
		i.intVal = 1;
		type_t * ty = new type_t(INT);
		se2 = STCurrent->gentemp(ty);
		se2->initialize(i);

		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[(1) - (2)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (2)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (2)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (2)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (2)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (2)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (2)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (2)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (2)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se1);
			(yyval.exp)->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

	;}
    break;

  case 18:
#line 223 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (2)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 ;
		init_t i;
		i.intVal = 1;
		type_t * ty = new type_t(INT);
		se2 = STCurrent->gentemp(ty);
		se2->initialize(i);

		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[(1) - (2)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (2)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (2)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (2)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (2)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (2)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (2)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (2)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (2)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_SUB,se1->getName(),se1->getName(),se2->getName());
			(yyval.exp) = new exp_t(se1);
			(yyval.exp)->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
	;}
    break;

  case 19:
#line 278 "15CS30008.y"
    {
		// TODO
		
	;}
    break;

  case 20:
#line 285 "15CS30008.y"
    {
		(yyval.integerVal) = 1;
		SymbolEntry *se = (yyvsp[(1) - (1)].exp)->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		
	;}
    break;

  case 21:
#line 293 "15CS30008.y"
    {
		(yyval.integerVal) = (yyvsp[(1) - (3)].integerVal) +1;
		SymbolEntry *se = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		
	;}
    break;

  case 22:
#line 303 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp); 
		
	;}
    break;

  case 23:
#line 308 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(2) - (2)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[(2) - (2)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(2) - (2)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(2) - (2)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(2) - (2)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(2) - (2)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(2) - (2)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(2) - (2)].exp)->getConstantVal());
		}
		else if((yyvsp[(2) - (2)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(2) - (2)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_INCR,se1->getName(),se1->getName());
			(yyval.exp) = new exp_t(se1);
			(yyval.exp)->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	;}
    break;

  case 24:
#line 358 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(2) - (2)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if((yyvsp[(2) - (2)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(2) - (2)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(2) - (2)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(2) - (2)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(2) - (2)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(2) - (2)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(2) - (2)].exp)->getConstantVal());
		}
		else if((yyvsp[(2) - (2)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(2) - (2)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_DECR,se1->getName(),se1->getName());
			(yyval.exp) = new exp_t(se1);
			(yyval.exp)->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	;}
    break;

  case 25:
#line 408 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(2) - (2)].exp);
		SymbolEntry* se = (yyvsp[(2) - (2)].exp)->getSymbolEntry();
		SymbolEntry* se1 = se;
		type_t* ty = se->getType();
		QuadEntry *qe;
		if((*(yyvsp[(1) - (2)].strVal)).compare("+") != 0){
			if((yyvsp[(2) - (2)].exp)->isArrayAccess()){
				se1 = STCurrent->gentemp(se->getType());
				qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(2) - (2)].exp)->getArraySum()->getName());
				QA->emit(qe);
				(yyval.exp)->setArrayAccess(false,NULL);
				(yyval.exp)->setSymbolEntry(se1);
			}
			else if((yyvsp[(2) - (2)].exp)->isConstant()){
				type_t *ty = new type_t((yyvsp[(2) - (2)].exp)->getConstantType());
				se1 = STCurrent->gentemp(ty);
				se1->initialize((yyvsp[(2) - (2)].exp)->getConstantVal());
				(yyval.exp)->setConstant(false);
				(yyval.exp)->setSymbolEntry(se1);
			}
			if((*(yyvsp[(1) - (2)].strVal)).compare("&") == 0){
				if((yyvsp[(2) - (2)].exp)->isConstant())
					yyerror("Invalid reference");
				(yyval.exp)->setAddress(true);
			}
			else if((*(yyvsp[(1) - (2)].strVal)).compare("*") == 0 && ty->getTypeName() == POINTER){
				if((yyvsp[(2) - (2)].exp)->isConstant())
					yyerror("Invalid reference");
				(yyval.exp)->setDeReference(true);
			}
			else if((*(yyvsp[(1) - (2)].strVal)).compare("-") == 0){
				qe = new QuadEntry(OP_NEG,se1->getName(),se1->getName());
				QA->emit(qe);
				(yyval.exp)->setSymbolEntry(se1);				
			}
		}
		
	;}
    break;

  case 26:
#line 450 "15CS30008.y"
    {
		(yyval.strVal) = new string("&"); 
		
	;}
    break;

  case 27:
#line 455 "15CS30008.y"
    {
		(yyval.strVal) = new string("*"); 
		
	;}
    break;

  case 28:
#line 460 "15CS30008.y"
    {
		(yyval.strVal) = new string("+"); 
		
	;}
    break;

  case 29:
#line 465 "15CS30008.y"
    {
		(yyval.strVal) = new string("-"); 
		
	;}
    break;

  case 30:
#line 472 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 31:
#line 479 "15CS30008.y"
    { 
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 32:
#line 484 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
			
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 33:
#line 573 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 34:
#line 661 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 35:
#line 752 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 36:
#line 757 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 37:
#line 846 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 38:
#line 937 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 39:
#line 942 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 40:
#line 1031 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
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
		
	;}
    break;

  case 41:
#line 1122 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 42:
#line 1127 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LT_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 43:
#line 1221 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GT_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 44:
#line 1315 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LTE_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 45:
#line 1409 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GTE_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 46:
#line 1505 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 47:
#line 1510 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_EQ_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 48:
#line 1602 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_NEQ_GOTO,"",se1->getName(),se2->getName());
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
		
	;}
    break;

  case 49:
#line 1698 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 50:
#line 1703 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_AND,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		
	;}
    break;

  case 51:
#line 1789 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 52:
#line 1794 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_XOR,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		
	;}
    break;

  case 53:
#line 1880 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 54:
#line 1885 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			ty1 = new type_t((yyvsp[(1) - (3)].exp)->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize((yyvsp[(1) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string((yyvsp[(1) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if((yyvsp[(3) - (3)].exp)->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if((yyvsp[(3) - (3)].exp)->isConstant()){
			ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
		}
		else if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
			QA->emit(qe);
		}

		
		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_OR,se->getName(),se1->getName(),se2->getName());
		(yyval.exp) = new exp_t(se);
		(yyval.exp)->setSymbolEntry(se);
		QA->emit(qe);
		
		
	;}
    break;

  case 55:
#line 1972 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 56:
#line 1977 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (4)].exp);
		backpatch((yyvsp[(1) - (4)].exp)->getTrueList(),(yyvsp[(3) - (4)].integerVal));
		(yyval.exp)->setFalseList(merge((yyvsp[(1) - (4)].exp)->getFalseList(),(yyvsp[(4) - (4)].exp)->getFalseList()));
		(yyval.exp)->setTrueList((yyvsp[(1) - (4)].exp)->getTrueList());
		
	;}
    break;

  case 57:
#line 1987 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 58:
#line 1992 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (4)].exp);
		backpatch((yyvsp[(1) - (4)].exp)->getFalseList(),(yyvsp[(3) - (4)].integerVal));
		(yyval.exp)->setTrueList(merge((yyvsp[(1) - (4)].exp)->getTrueList(),(yyvsp[(4) - (4)].exp)->getTrueList()));
		(yyval.exp)->setFalseList((yyvsp[(4) - (4)].exp)->getFalseList());
		
	;}
    break;

  case 59:
#line 2002 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 60:
#line 2006 "15CS30008.y"
    {;}
    break;

  case 61:
#line 2009 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);		
	;}
    break;

  case 62:
#line 2013 "15CS30008.y"
    {
		SymbolEntry *se = (yyvsp[(1) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se_ = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		bool b1 = false,b2 = false;
		if((yyvsp[(1) - (3)].exp)->isAddress()){
			yyerror("Invalid Assignment.");	
		}
		else if((yyvsp[(1) - (3)].exp)->isConstant()){
			yyerror("Invalid Assignment.");
		}
		else if((yyvsp[(1) - (3)].exp)->isFunctionCall()){
			yyerror("Invalid Assignment.");
		}
		if((yyvsp[(1) - (3)].exp)->isArrayAccess() || (yyvsp[(1) - (3)].exp)->isDeReference())
			b1 = true;
		if((yyvsp[(3) - (3)].exp)->isFunctionCall() || (yyvsp[(3) - (3)].exp)->isArrayAccess() || (yyvsp[(3) - (3)].exp)->isDeReference() || (yyvsp[(3) - (3)].exp)->isAddress() || (yyvsp[(3) - (3)].exp)->isConstant())
			b2 = true;

		if(b1 && b2){
			if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isAddress()){
				ty2 = new type_t(POINTER);
				ty2->setPointedType(se_->getType());
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isConstant()){
				ty2 = new type_t((yyvsp[(3) - (3)].exp)->getConstantType(),false,false);
				se2 = STCurrent->gentemp(ty2);
				se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
			}
			if((*(yyvsp[(2) - (3)].strVal)).compare("=") != 0){
				if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(1) - (3)].exp)->isDeReference()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
					QA->emit(qe);
				}
				if((yyvsp[(2) - (3)].strVal)->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}			
			}

			if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName(),se2->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(1) - (3)].exp)->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se2->getName());
				QA->emit(qe);
			}

		}
		else if(b1 && !b2){
			se2 = se_;
			if((*(yyvsp[(2) - (3)].strVal)).compare("=") != 0){
				ty1 = se->getType();
				se1 = STCurrent->gentemp(ty1);
				if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
					
					qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(1) - (3)].exp)->isDeReference()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
					QA->emit(qe);
				}
				if((yyvsp[(2) - (3)].strVal)->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}			
			}
			if((yyvsp[(1) - (3)].exp)->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),(yyvsp[(1) - (3)].exp)->getArraySum()->getName(),se1->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(1) - (3)].exp)->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se1->getName());
				QA->emit(qe);
			}
			

		}
		else if(!b1 && b2){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
				
			if((yyvsp[(3) - (3)].exp)->isFunctionCall()){
				se2 = se_;
				SymbolTable *st = se2->getNestedTable();
				qe = new QuadEntry(OP_CALL,se1->getName(),se_->getName(),to_string((yyvsp[(3) - (3)].exp)->getNoOfParams()));
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se_->getName(),(yyvsp[(3) - (3)].exp)->getArraySum()->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isAddress()){
				qe = new QuadEntry(OP_REF,se1->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isConstant()){
				se2 = STCurrent->lookup(se1->getName());
				se2->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
			}
			if((*(yyvsp[(2) - (3)].strVal)).compare("=") != 0){
				
				if((yyvsp[(2) - (3)].strVal)->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if((yyvsp[(2) - (3)].strVal)->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}			
			}
		}
		else{
			if(typecheck(ty1,ty2)){
				if((*(yyvsp[(2) - (3)].strVal)).compare("=") != 0){
					
					if((yyvsp[(2) - (3)].strVal)->compare("*=") == 0){
						qe = new QuadEntry(OP_MUL,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare("/=") == 0){
						qe = new QuadEntry(OP_DIV,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare("%=") == 0){
						qe = new QuadEntry(OP_MOD,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare("+=") == 0){
						qe = new QuadEntry(OP_ADD,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare("-=") == 0){
						qe = new QuadEntry(OP_SUB,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare(">>=") == 0){
						qe = new QuadEntry(OP_RSFT,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if((yyvsp[(2) - (3)].strVal)->compare("|=") == 0){
						qe = new QuadEntry(OP_OR,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}			
				}
				else{
					qe = new QuadEntry(OP_COPY,se->getName(),se_->getName());
					QA->emit(qe);
				}
			}
			else
				yyerror("Incompactible types.");
		}
		
	;}
    break;

  case 63:
#line 2290 "15CS30008.y"
    {
		(yyval.strVal) = new string("=");
	;}
    break;

  case 64:
#line 2294 "15CS30008.y"
    {
		(yyval.strVal) = new string("*=");
	;}
    break;

  case 65:
#line 2298 "15CS30008.y"
    {
		(yyval.strVal) = new string("/=");
	;}
    break;

  case 66:
#line 2302 "15CS30008.y"
    {
		(yyval.strVal) = new string("\%=");
	;}
    break;

  case 67:
#line 2306 "15CS30008.y"
    {
		(yyval.strVal) = new string("+=");
	;}
    break;

  case 68:
#line 2310 "15CS30008.y"
    {
		(yyval.strVal) = new string("-=");
	;}
    break;

  case 69:
#line 2313 "15CS30008.y"
    {;}
    break;

  case 70:
#line 2315 "15CS30008.y"
    {
		(yyval.strVal) = new string(">>=");
	;}
    break;

  case 71:
#line 2318 "15CS30008.y"
    {;}
    break;

  case 72:
#line 2319 "15CS30008.y"
    {;}
    break;

  case 73:
#line 2321 "15CS30008.y"
    {
		(yyval.strVal) = new string("|=");
	;}
    break;

  case 74:
#line 2326 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 75:
#line 2331 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(3) - (3)].exp);
		
	;}
    break;

  case 76:
#line 2337 "15CS30008.y"
    {;}
    break;

  case 77:
#line 2339 "15CS30008.y"
    {;}
    break;

  case 78:
#line 2340 "15CS30008.y"
    {;}
    break;

  case 79:
#line 2344 "15CS30008.y"
    {
		(yyval.type) = (yyvsp[(1) - (2)].type); 
		type_global = (yyvsp[(1) - (2)].type);
		
	;}
    break;

  case 80:
#line 2350 "15CS30008.y"
    {
		(yyval.type) = (yyvsp[(1) - (1)].type); 
		type_global = (yyvsp[(1) - (1)].type);
		
	;}
    break;

  case 81:
#line 2357 "15CS30008.y"
    { ;}
    break;

  case 82:
#line 2358 "15CS30008.y"
    { ;}
    break;

  case 83:
#line 2362 "15CS30008.y"
    {
		type_t *ty = (yyvsp[(1) - (1)].decl)->getType();
		SymbolEntry *se;
		if(ty->getTypeName() == FUNCTION){
			se = STStack.back()->gentemp((yyvsp[(1) - (1)].decl));
			se->setNestedTable(STCurrent);
			STCurrent = STStack.back();
			STStack.pop_back();
		}
		else	
			se = STCurrent->gentemp((yyvsp[(1) - (1)].decl));
		
	;}
    break;

  case 84:
#line 2375 "15CS30008.y"
    {
		SymbolEntry *se = STCurrent->gentemp((yyvsp[(1) - (3)].decl));
		SymbolEntry *se1 = (yyvsp[(3) - (3)].exp)->getSymbolEntry();
		QuadEntry *qe;
		type_t* ty1 = (yyvsp[(1) - (3)].decl)->getType();
		type_n ty_N = ty1->getTypeName();
		if(ty_N == POINTER){
			if((yyvsp[(3) - (3)].exp)->isAddress()){
				type_t * ty2 = new type_t(POINTER,true,false);
				ty2->setPointedType(se1->getType());
				SymbolEntry *se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isDeReference()){
				type_t * ty2 = se1->getType();
				SymbolEntry *se2 = STCurrent->gentemp(ty2->getPointedType());
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isConstant())
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
			if((yyvsp[(3) - (3)].exp)->isAddress())
				yyerror("Cannot Initialize with Address");
			else if((yyvsp[(3) - (3)].exp)->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_R,se->getName(),se1->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(3) - (3)].exp)->isConstant())
				se->initialize((yyvsp[(3) - (3)].exp)->getConstantVal());
			else{
				qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());	
				QA->emit(qe);
			}
		}
		
	;}
    break;

  case 85:
#line 2428 "15CS30008.y"
    {
		(yyval.type) = new type_t(VOID,false,false);
		
	;}
    break;

  case 86:
#line 2433 "15CS30008.y"
    {
		(yyval.type) = new type_t(CHAR,false,false);
		
	;}
    break;

  case 87:
#line 2438 "15CS30008.y"
    {
		
	;}
    break;

  case 88:
#line 2442 "15CS30008.y"
    {
		(yyval.type) = new type_t(INT,false,false);
		
	;}
    break;

  case 89:
#line 2446 "15CS30008.y"
    {;}
    break;

  case 90:
#line 2447 "15CS30008.y"
    {;}
    break;

  case 91:
#line 2449 "15CS30008.y"
    {
		(yyval.type) = new type_t(DOUBLE,false,false);
		
	;}
    break;

  case 92:
#line 2454 "15CS30008.y"
    {
		(yyval.type) = new type_t(MATRIX,false,true);
		
	;}
    break;

  case 93:
#line 2458 "15CS30008.y"
    {;}
    break;

  case 94:
#line 2459 "15CS30008.y"
    {;}
    break;

  case 95:
#line 2460 "15CS30008.y"
    {;}
    break;

  case 96:
#line 2464 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (1)].decl);
		
	;}
    break;

  case 97:
#line 2469 "15CS30008.y"
    {
		type_global = (yyvsp[(1) - (1)].type);
	;}
    break;

  case 98:
#line 2473 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(3) - (3)].decl);
		
	;}
    break;

  case 99:
#line 2480 "15CS30008.y"
    {
		(yyval.decl) = new decl_t(type_global);  
		(yyval.decl)->setName((yyvsp[(1) - (1)].strVal)); 
		
	;}
    break;

  case 100:
#line 2486 "15CS30008.y"
    { 
		type_t* ty = (yyvsp[(2) - (3)].decl)->getType();
		typecheck(type_global,ty);
		(yyval.decl) = (yyvsp[(2) - (3)].decl);
		(yyval.decl)->setType(type_global); 
		
	;}
    break;

  case 101:
#line 2494 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (4)].decl);
		int arraySize;
		if((yyvsp[(3) - (4)].exp)->isConstant()){
			arraySize = ((yyvsp[(3) - (4)].exp)->getConstantVal()).intVal;
		}
		else{
			SymbolEntry *se = (yyvsp[(3) - (4)].exp)->getSymbolEntry();
			arraySize = (se->getInitialValue()).intVal;
		}
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType((yyvsp[(1) - (4)].decl)->getType(),arraySize);
		(yyval.decl)->setType(ty);
		
	;}
    break;

  case 102:
#line 2510 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (3)].decl); 
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType((yyvsp[(1) - (3)].decl)->getType(),0);
		(yyval.decl)->setType(ty);
		
	;}
    break;

  case 103:
#line 2518 "15CS30008.y"
    { 
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();	
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
	;}
    break;

  case 104:
#line 2525 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (5)].decl);
		type_t* ty = new type_t(FUNCTION);
		(yyval.decl)->setType(ty);
		(yyval.decl)->setNestedTable(STCurrent); 
	;}
    break;

  case 105:
#line 2532 "15CS30008.y"
    {
		STStack.push_back(STCurrent);
	;}
    break;

  case 106:
#line 2536 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (5)].decl);
		type_t* ty = new type_t(FUNCTION);
		(yyval.decl)->setType(ty);
		STCurrent = new SymbolTable();
		(yyval.decl)->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);		
		
	;}
    break;

  case 107:
#line 2547 "15CS30008.y"
    {
		(yyval.decl) = (yyvsp[(1) - (3)].decl);
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();
		type_t* ty = new type_t(FUNCTION);
		(yyval.decl)->setType(ty);
		(yyval.decl)->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
		
	;}
    break;

  case 108:
#line 2560 "15CS30008.y"
    {
		(yyval.type) = new type_t(POINTER,true,false);
		(yyval.type)->setPointedType(type_global);
		
	;}
    break;

  case 109:
#line 2566 "15CS30008.y"
    {
		(yyval.type) = (yyvsp[(2) - (2)].type);
		(yyval.type)->setPointedType((yyvsp[(2) - (2)].type));
		
	;}
    break;

  case 110:
#line 2573 "15CS30008.y"
    {;}
    break;

  case 111:
#line 2575 "15CS30008.y"
    {;}
    break;

  case 112:
#line 2576 "15CS30008.y"
    {;}
    break;

  case 113:
#line 2580 "15CS30008.y"
    {
		STCurrent->gentemp((yyvsp[(2) - (2)].decl)); 
		
	;}
    break;

  case 114:
#line 2585 "15CS30008.y"
    {
		STCurrent->gentemp((yyvsp[(1) - (1)].type));
		
	;}
    break;

  case 115:
#line 2592 "15CS30008.y"
    {
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup((yyvsp[(1) - (1)].strVal));
		STCurrent->gentemp(se);
		
	;}
    break;

  case 116:
#line 2599 "15CS30008.y"
    {
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup((yyvsp[(3) - (3)].strVal));
		STCurrent->gentemp(se);	
		
	;}
    break;

  case 117:
#line 2608 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);	
		
	;}
    break;

  case 118:
#line 2612 "15CS30008.y"
    {;}
    break;

  case 119:
#line 2615 "15CS30008.y"
    {;}
    break;

  case 120:
#line 2616 "15CS30008.y"
    {;}
    break;

  case 121:
#line 2619 "15CS30008.y"
    {;}
    break;

  case 122:
#line 2620 "15CS30008.y"
    {;}
    break;

  case 123:
#line 2621 "15CS30008.y"
    {;}
    break;

  case 124:
#line 2624 "15CS30008.y"
    {;}
    break;

  case 125:
#line 2626 "15CS30008.y"
    {;}
    break;

  case 126:
#line 2627 "15CS30008.y"
    {;}
    break;

  case 127:
#line 2630 "15CS30008.y"
    {;}
    break;

  case 128:
#line 2631 "15CS30008.y"
    {;}
    break;

  case 129:
#line 2635 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		
	;}
    break;

  case 130:
#line 2640 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		
	;}
    break;

  case 131:
#line 2645 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 132:
#line 2650 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 133:
#line 2655 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 134:
#line 2660 "15CS30008.y"
    {
	 	(yyval.exp) = new exp_t();
		
	;}
    break;

  case 135:
#line 2666 "15CS30008.y"
    {;}
    break;

  case 136:
#line 2667 "15CS30008.y"
    {;}
    break;

  case 137:
#line 2668 "15CS30008.y"
    {;}
    break;

  case 138:
#line 2671 "15CS30008.y"
    {;}
    break;

  case 139:
#line 2673 "15CS30008.y"
    {
		backpatch((yyvsp[(2) - (4)].exp)->getNextList(),(yyvsp[(3) - (4)].integerVal));
		
	;}
    break;

  case 140:
#line 2680 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 141:
#line 2685 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(1) - (3)].exp)->getNextList(),(yyvsp[(2) - (3)].integerVal));
		(yyval.exp)->setNextList(merge((yyval.exp)->getNextList(),(yyvsp[(3) - (3)].exp)->getNextList()));
		
	;}
    break;

  case 142:
#line 2694 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		
	;}
    break;

  case 143:
#line 2699 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
		
	;}
    break;

  case 144:
#line 2705 "15CS30008.y"
    {;}
    break;

  case 145:
#line 2706 "15CS30008.y"
    {(yyval.exp) = (yyvsp[(1) - (2)].exp);;}
    break;

  case 146:
#line 2710 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(3) - (6)].exp)->getTrueList(),(yyvsp[(5) - (6)].integerVal));
		(yyval.exp)->setNextList(merge((yyvsp[(3) - (6)].exp)->getFalseList(),(yyvsp[(6) - (6)].exp)->getNextList()));	
		
	;}
    break;

  case 147:
#line 2717 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(3) - (10)].exp)->getTrueList(),(yyvsp[(5) - (10)].integerVal));
		backpatch((yyvsp[(3) - (10)].exp)->getFalseList(),(yyvsp[(9) - (10)].integerVal));
		vector<int>* temp = merge((yyvsp[(6) - (10)].exp)->getNextList(),(yyvsp[(7) - (10)].list));
		(yyval.exp)->setNextList(merge(temp,(yyvsp[(10) - (10)].exp)->getNextList()));
		
	;}
    break;

  case 148:
#line 2726 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(3) - (6)].exp)->getTrueList(),(yyvsp[(5) - (6)].integerVal));
		(yyval.exp)->setNextList(merge((yyvsp[(3) - (6)].exp)->getFalseList(),(yyvsp[(6) - (6)].exp)->getNextList()));
	;}
    break;

  case 149:
#line 2734 "15CS30008.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp); 
	;}
    break;

  case 150:
#line 2738 "15CS30008.y"
    {
		(yyval.exp) = NULL;
		
	;}
    break;

  case 151:
#line 2745 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(7) - (7)].exp)->getNextList(),(yyvsp[(2) - (7)].integerVal));
		backpatch((yyvsp[(4) - (7)].exp)->getTrueList(),(yyvsp[(6) - (7)].integerVal));
		(yyval.exp)->setNextList((yyvsp[(4) - (7)].exp)->getFalseList());
		QuadEntry *qe = new QuadEntry(OP_GOTO,to_string((yyvsp[(2) - (7)].integerVal)));
		QA->emit(qe);
		
	;}
    break;

  case 152:
#line 2755 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		backpatch((yyvsp[(7) - (9)].exp)->getTrueList(),(yyvsp[(2) - (9)].integerVal));
		backpatch((yyvsp[(3) - (9)].exp)->getNextList(),(yyvsp[(4) - (9)].integerVal));
		(yyval.exp)->setNextList((yyvsp[(7) - (9)].exp)->getFalseList());
		
	;}
    break;

  case 153:
#line 2764 "15CS30008.y"
    {
		(yyval.exp) = new exp_t();
		(yyval.exp)->setNextList((yyvsp[(6) - (13)].exp)->getFalseList());
		backpatch((yyvsp[(6) - (13)].exp)->getTrueList(),(yyvsp[(12) - (13)].integerVal));
		backpatch((yyvsp[(13) - (13)].exp)->getNextList(),(yyvsp[(8) - (13)].integerVal));
		backpatch((yyvsp[(10) - (13)].list),(yyvsp[(5) - (13)].integerVal));
	;}
    break;

  case 154:
#line 2772 "15CS30008.y"
    {
		
	;}
    break;

  case 155:
#line 2777 "15CS30008.y"
    {;}
    break;

  case 156:
#line 2778 "15CS30008.y"
    {;}
    break;

  case 157:
#line 2779 "15CS30008.y"
    {;}
    break;

  case 158:
#line 2781 "15CS30008.y"
    {
		QuadEntry *qe;
		if( (yyvsp[(2) - (3)].exp) == NULL )
			qe = new QuadEntry(OP_RETURN,"");
		else{
			SymbolEntry* se_ = (yyvsp[(2) - (3)].exp)->getSymbolEntry();
			SymbolEntry* se2 = se_;
			type_t* ty2;
			if((yyvsp[(2) - (3)].exp)->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),(yyvsp[(2) - (3)].exp)->getArraySum()->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(2) - (3)].exp)->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if((yyvsp[(2) - (3)].exp)->isAddress()){
				yyerror("Invalid variable type for multiplying.");
			}
			else if((yyvsp[(2) - (3)].exp)->isConstant()){
				ty2 = new type_t((yyvsp[(2) - (3)].exp)->getConstantType());
				se2 = STCurrent->gentemp(ty2);
				se2->initialize((yyvsp[(2) - (3)].exp)->getConstantVal());
			}
			else if((yyvsp[(2) - (3)].exp)->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string((yyvsp[(2) - (3)].exp)->getNoOfParams()));
				QA->emit(qe);
			}

			qe = new QuadEntry(OP_RETURN,se2->getName());
			QA->emit(qe);
		}
		
	;}
    break;

  case 159:
#line 2828 "15CS30008.y"
    {
		
	;}
    break;

  case 160:
#line 2832 "15CS30008.y"
    {		
		
	;}
    break;

  case 161:
#line 2837 "15CS30008.y"
    {;}
    break;

  case 162:
#line 2839 "15CS30008.y"
    {
		
	;}
    break;

  case 163:
#line 2845 "15CS30008.y"
    {
		SymbolEntry *se = (STStack.back())->gentemp((yyvsp[(2) - (4)].decl));
		se->setNestedTable(STCurrent);
		STCurrent = STStack.back();
		STStack.pop_back();
		
	;}
    break;

  case 164:
#line 2853 "15CS30008.y"
    {
		SymbolEntry *se = (STStack.back())->gentemp((yyvsp[(2) - (3)].decl));
		se->setNestedTable(STCurrent);
		STCurrent = STStack.back();
		STStack.pop_back();
		
	;}
    break;

  case 165:
#line 2862 "15CS30008.y"
    {;}
    break;

  case 166:
#line 2863 "15CS30008.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 4926 "15CS30008.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2866 "15CS30008.y"


	void yyerror(const char* s){
		
		exit(-1);
	}
