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
#line 2 "ass3_15CS30008.y" /* yacc.c:339  */

int yylex();
void yyerror(const char*);

#line 71 "ass3_15CS30008.tab.c" /* yacc.c:339  */

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
   by #include "ass3_15CS30008.tab.h".  */
#ifndef YY_YY_ASS3_15CS30008_TAB_H_INCLUDED
# define YY_YY_ASS3_15CS30008_TAB_H_INCLUDED
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
    IDENTIFIER = 260,
    CONSTANT = 261,
    STRING_LITERAL = 262
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS3_15CS30008_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 128 "ass3_15CS30008.tab.c" /* yacc.c:358  */

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
#define YYLAST   500

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    23,    18,     2,
       8,     9,    19,    20,    17,    21,    12,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    49,
      26,    38,    27,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    10,     2,    11,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    33,    62,     2,     2,     2,     2,
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
       5,     6,     7,    13,    14,    15,    16,    24,    25,    28,
      29,    30,    31,    34,    35,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    15,    15,    16,    17,    18,    19,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    33,    34,    37,    38,
      39,    40,    43,    44,    45,    46,    49,    52,    53,    54,
      55,    58,    59,    60,    63,    64,    65,    68,    69,    70,
      71,    72,    75,    76,    77,    80,    81,    84,    85,    88,
      89,    92,    93,    96,    97,   100,   101,   103,   104,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     120,   121,   124,   126,   127,   130,   131,   134,   135,   138,
     139,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   155,   156,   159,   160,   161,   162,   163,   164,
     165,   167,   168,   171,   173,   174,   177,   178,   181,   182,
     185,   186,   189,   190,   193,   194,   195,   198,   200,   201,
     204,   205,   208,   209,   210,   211,   212,   213,   216,   217,
     218,   221,   222,   225,   226,   229,   230,   233,   234,   237,
     238,   239,   242,   243,   246,   247,   248,   249,   252,   253,
     254,   255,   258,   259,   262,   263,   266,   267,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"then\"", "\"else\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "'('", "')'", "'['", "']'", "'.'",
  "\"->\"", "\"++\"", "\"--\"", "\".'\"", "','", "'&'", "'*'", "'+'",
  "'-'", "'/'", "'%'", "\"<<\"", "\">>\"", "'<'", "'>'", "\"<=\"",
  "\">=\"", "\"==\"", "\"!=\"", "'^'", "'|'", "\"&&\"", "\"||\"", "'?'",
  "':'", "'='", "\"*=\"", "\"/=\"", "\"%=\"", "\"+=\"", "\"-=\"",
  "\"<<=\"", "\">>=\"", "\"&=\"", "\"^=\"", "\"|=\"", "';'", "\"void\"",
  "\"char\"", "\"short\"", "\"int\"", "\"long\"", "\"float\"",
  "\"double\"", "\"Matrix\"", "\"signed\"", "\"unsigned\"", "\"Bool\"",
  "'{'", "'}'", "\"case\"", "\"default\"", "\"if\"", "\"switch\"",
  "\"while\"", "\"do\"", "\"for\"", "\"goto\"", "\"continue\"",
  "\"break\"", "\"return\"", "$accept", "start", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_row_list", "initializer_row", "designation",
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
       0,   256,   257,   258,   259,   260,   261,   262,    40,    41,
      91,    93,    46,   263,   264,   265,   266,    44,    38,    42,
      43,    45,    47,    37,   267,   268,    60,    62,   269,   270,
     271,   272,    94,   124,   273,   274,    63,    58,    61,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,    59,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   123,   125,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     429,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,    10,  -159,    15,   429,   429,  -159,  -159,  -159,
    -159,    24,    -4,  -159,   -12,  -159,   354,    93,    30,  -159,
    -159,    27,  -159,    24,  -159,   307,   196,  -159,    15,  -159,
     417,   343,   411,    93,  -159,  -159,   -13,  -159,  -159,  -159,
     445,   445,   445,  -159,  -159,  -159,  -159,    41,  -159,   134,
     452,   445,  -159,    89,   131,   132,    88,   144,    32,    35,
      12,    23,    49,  -159,  -159,  -159,    33,  -159,  -159,   445,
      43,    81,    85,   102,   290,   113,    91,    74,   104,   445,
    -159,    -5,  -159,  -159,  -159,  -159,   221,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,    24,   146,   142,  -159,
      54,  -159,   152,    57,  -159,  -159,   445,   162,  -159,     3,
     166,   307,    16,  -159,   428,   445,   174,   181,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,   445,  -159,  -159,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   290,  -159,   151,   290,   445,   445,
     445,   122,   326,   141,  -159,  -159,   175,   145,   445,  -159,
    -159,  -159,  -159,  -159,   429,  -159,   186,  -159,  -159,   182,
    -159,    41,  -159,   307,  -159,  -159,  -159,  -159,    59,  -159,
      83,  -159,  -159,  -159,  -159,  -159,  -159,    89,    89,   131,
     131,   132,   132,   132,   132,    88,    88,   144,    32,    35,
      12,    23,   -10,  -159,   290,  -159,    60,    64,    70,   187,
     445,   147,  -159,  -159,  -159,  -159,  -159,  -159,   166,  -159,
    -159,   445,  -159,   445,  -159,   290,   290,   290,   445,   148,
     445,  -159,  -159,   195,  -159,  -159,    73,   445,   156,   290,
     157,   200,   445,  -159,  -159,   290,   204,  -159,   290,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,   155,     0,    76,     2,   152,   154,     1,
      94,     0,   101,    74,     0,    77,    79,    92,     0,    75,
     153,     0,   102,     0,    73,     0,     0,   158,     0,   157,
       0,     0,     0,    93,    95,    78,    79,     3,     4,     5,
       0,     0,     0,    22,    23,    24,    25,     0,     7,    18,
      26,     0,    27,    31,    34,    37,    42,    45,    47,    49,
      51,    53,    55,    57,   110,    80,     3,   137,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
      70,     0,   135,   136,   122,   123,     0,   133,   124,   125,
     126,   127,   159,   156,   108,   100,   107,     0,   103,   104,
       0,    97,     0,     0,    19,    20,     0,     0,   114,     0,
     112,     0,     0,   118,     0,     0,     0,     0,    13,    14,
      15,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    26,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,   143,     0,   149,   150,   142,     0,     0,   138,
     132,   134,   106,    98,     0,    99,     0,    96,     6,     0,
     121,     0,   111,     0,   115,   117,   119,    10,     0,    16,
       0,    11,    12,    58,    28,    29,    30,    32,    33,    35,
      36,    38,    39,    40,    41,    43,    44,    46,    48,    50,
      52,    54,     0,   128,     0,   130,     0,     0,     0,     0,
     143,     0,   148,   151,    71,   105,   109,   120,   113,   116,
       9,     0,     8,     0,   129,     0,     0,     0,     0,     0,
     143,    17,    56,   139,   141,   144,     0,   143,     0,     0,
       0,     0,   143,   140,   145,     0,     0,   147,     0,   146
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,  -159,  -159,   -21,  -159,   -40,    13,    26,
      18,    25,    61,    62,    58,    63,    68,  -159,   -75,   -33,
    -159,   -50,   107,   -18,     1,  -159,   192,  -159,    -8,   203,
     198,  -159,  -159,    48,  -159,   -24,  -159,    42,  -159,  -159,
     112,   -81,  -159,    -7,  -159,   205,  -159,  -159,  -158,  -159,
    -159,  -159,   222,  -159,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    58,    59,   198,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    90,
     142,    91,   166,    13,    38,    24,    25,    15,    46,    27,
      28,   107,   108,   109,   110,   118,   119,   120,   121,   122,
     123,    93,    94,    95,    96,    97,    98,    99,   177,   100,
     101,    16,    17,    18,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     113,    14,    74,   171,   165,    33,    26,   178,    37,   112,
      19,    75,   178,    31,   231,    22,    29,    14,    92,    39,
      20,   144,   102,    21,    74,    35,   116,   243,   117,    20,
     114,   115,    21,   103,    22,    20,    44,    34,    21,   176,
     143,   165,   106,    22,   179,   160,    47,    48,    49,    50,
     158,   116,   191,   117,   195,    51,    52,   161,   143,    53,
      54,    55,    56,   185,    23,   192,   188,   159,   240,   245,
     164,   186,   249,   246,   178,   200,   241,   178,    92,   247,
     167,   178,   260,   223,   162,   163,   225,   178,    74,   168,
     178,   199,   258,   169,   242,   143,   173,   194,   182,   261,
     178,    41,    57,    42,   266,   204,   205,   206,   145,   203,
     170,   146,   147,   222,   152,   153,   154,   155,   226,   227,
     228,   172,   176,   174,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   124,   244,   125,   234,   126,   127,   128,   129,
     130,   148,   149,   175,   230,   183,   150,   151,    74,   184,
      74,   207,   208,   187,   253,   254,   255,   190,   252,   239,
     211,   212,   213,   214,   156,   157,   209,   210,   263,   201,
     176,   215,   216,   193,   267,   106,   202,   269,   224,   229,
     232,   236,   178,   237,   233,   248,   250,   257,   256,   259,
     176,    76,    48,    49,    50,   262,   264,   176,   251,   265,
      51,    52,   176,   268,    53,    54,    55,    56,   219,   217,
      32,   218,   143,   189,   220,    45,    76,    48,    49,    50,
     221,    43,   235,   238,   196,    51,    52,     0,    30,    53,
      54,    55,    56,     0,     0,    77,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    36,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      77,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    36,   180,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    76,    48,    49,    50,     0,
       0,   181,     0,     0,    51,    52,     0,     0,    53,    54,
      55,    56,    47,    48,    49,    50,     0,     0,     0,     0,
       0,    51,    52,     0,     0,    53,    54,    55,    56,     0,
       0,    47,    48,    49,    50,     0,     0,     0,     0,    77,
      51,    52,     0,     0,    53,    54,    55,    56,   104,     0,
       0,    36,   105,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,    35,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    36,    47,    48,    49,    50,
       0,     0,   111,     0,     0,    51,    52,     0,     0,    53,
      54,    55,    56,    47,    48,    49,    50,   197,     0,     0,
       0,     0,    51,    52,     0,     0,    53,    54,    55,    56,
      47,    48,    49,    50,     0,     0,     0,     0,     0,    51,
      52,     0,     0,    53,    54,    55,    56,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    36,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141
};

static const yytype_int16 yycheck[] =
{
      50,     0,    35,    84,    79,    17,    14,    17,    26,    42,
       0,    35,    17,    21,   172,    19,    15,    16,    36,    26,
       5,    61,    40,     8,    57,    38,    10,    37,    12,     5,
      51,    52,     8,    40,    19,     5,     9,    49,     8,    89,
      61,   116,    41,    19,    49,    33,     5,     6,     7,     8,
      18,    10,    49,    12,    38,    14,    15,    34,    79,    18,
      19,    20,    21,     9,    49,    62,     9,    32,     9,     9,
      37,    17,   230,     9,    17,   125,    17,    17,    96,     9,
      37,    17,     9,   164,    35,    36,   167,    17,   121,     8,
      17,   124,   250,     8,    11,   116,     5,   121,   106,   257,
      17,     8,    61,    10,   262,   145,   146,   147,    19,   142,
       8,    22,    23,   163,    26,    27,    28,    29,   168,   169,
     170,     8,   172,    49,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     8,   224,    10,   178,    12,    13,    14,    15,
      16,    20,    21,    49,   172,     9,    24,    25,   191,    17,
     193,   148,   149,    11,   245,   246,   247,     5,   243,   193,
     152,   153,   154,   155,    30,    31,   150,   151,   259,     5,
     230,   156,   157,    17,   265,   184,     5,   268,    37,    67,
      49,     5,    17,    11,    49,     8,    49,    49,   248,     4,
     250,     5,     6,     7,     8,    49,    49,   257,   241,     9,
      14,    15,   262,     9,    18,    19,    20,    21,   160,   158,
      22,   159,   243,   116,   161,    33,     5,     6,     7,     8,
     162,    28,   184,   191,   122,    14,    15,    -1,    16,    18,
      19,    20,    21,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     5,     6,     7,     8,    -1,
      -1,    96,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
      20,    21,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    49,
      14,    15,    -1,    -1,    18,    19,    20,    21,     5,    -1,
      -1,    61,     9,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    38,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     5,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      19,    20,    21,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    18,    19,    20,    21,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    18,    19,    20,    21,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    75,    97,    98,   101,   125,   126,   127,     0,
       5,     8,    19,    49,    99,   100,   102,   103,   104,    98,
     126,   102,   104,    17,    49,    38,    61,    97,    98,   117,
     128,     8,    10,   103,     9,   100,   102,     5,     6,     7,
       8,    14,    15,    18,    19,    20,    21,    61,    76,    77,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   109,     5,    49,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      93,    95,    97,   115,   116,   117,   118,   119,   120,   121,
     123,   124,    97,   117,     5,     9,    98,   105,   106,   107,
     108,    11,    93,    95,    79,    79,    10,    12,   109,   110,
     111,   112,   113,   114,     8,    10,    12,    13,    14,    15,
      16,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    94,    79,    81,    19,    22,    23,    20,    21,
      24,    25,    26,    27,    28,    29,    30,    31,    18,    32,
      33,    34,    35,    36,    37,    92,    96,    37,     8,     8,
       8,   115,     8,     5,    49,    49,    95,   122,    17,    49,
      62,   119,   102,     9,    17,     9,    17,    11,     9,    96,
       5,    49,    62,    17,   109,    38,   114,     9,    78,    93,
      95,     5,     5,    93,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    85,    85,    86,    87,    88,
      89,    90,    95,   115,    37,   115,    95,    95,    95,    67,
      97,   122,    49,    49,    93,   107,     5,    11,   111,   109,
       9,    17,    11,    37,   115,     9,     9,     9,     8,   122,
      49,    93,    92,   115,   115,   115,    95,    49,   122,     4,
       9,   122,    49,   115,    49,     9,   122,   115,     9,   115
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    79,    80,    80,    80,    80,    81,    82,    82,    82,
      82,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   121,   122,   122,   123,   123,   123,   123,   124,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     4,
       3,     3,     3,     2,     2,     2,     1,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     1,     1,     3,     2,     1,     1,     3,
       1,     3,     1,     3,     1,     2,     3,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     5,
       7,     5,     1,     0,     5,     7,     9,     8,     3,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     1,     2
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
#line 15 "ass3_15CS30008.y" /* yacc.c:1646  */
    {exit(-1);}
#line 1465 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 16 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("primary_expression <<--- IDENTIFIER\n");}
#line 1471 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 17 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("primary_expression <<--- CONSTANT\n");}
#line 1477 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 18 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("primary_expression <<--- STRING_LITERAL\n");}
#line 1483 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 19 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("primary_expression <<--- (expression)\n");}
#line 1489 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 22 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- primary_expression \n");}
#line 1495 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 23 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression[expression]\n");}
#line 1501 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 24 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression (argument_expression_list) \n");}
#line 1507 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 25 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression () \n");}
#line 1513 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 26 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression . IDENTIFIER \n");}
#line 1519 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 27 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression -> IDENTIFIER \n");}
#line 1525 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 28 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression ++\n");}
#line 1531 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 29 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression --\n");}
#line 1537 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 30 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("postfix_expression <<--- postfix_expression .'\n");}
#line 1543 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 33 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("argument_expression_list <<--- assignment_expression \n");}
#line 1549 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 34 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("argument_expression_list <<--- argument_expression_list , assignment_expression\n");}
#line 1555 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 37 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_expression <<--- postfix_expression  \n");}
#line 1561 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 38 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_expression <<--- ++ unary_expression  \n");}
#line 1567 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 39 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_expression <<--- -- unary_expression \n");}
#line 1573 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 40 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_expression <<--- unary_operator cast_expression\n");}
#line 1579 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 43 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_operator <<--- &\n");}
#line 1585 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 44 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_operator <<--- *\n");}
#line 1591 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 45 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_operator <<--- +\n");}
#line 1597 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 46 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("unary_operator <<--- -\n");}
#line 1603 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 49 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("cast_expression <<--- unary_expression\n");}
#line 1609 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 52 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("multiplicative_expression <<--- cast_expression\n");}
#line 1615 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 53 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("multiplicative_expression <<--- multiplicative_expression * cast_expression \n");}
#line 1621 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 54 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("multiplicative_expression <<--- multiplicative_expression / cast_expression\n");}
#line 1627 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 55 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("multiplicative_expression <<--- multiplicative_expression %% cast_expression\n");}
#line 1633 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 58 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("additive_expression <<--- multiplicative_expression\n");}
#line 1639 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 59 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("additive_expression <<--- additive_expression + multiplicative_expression\n");}
#line 1645 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 60 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("additive_expression <<--- additive_expression - multiplicative_expression\n");}
#line 1651 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 63 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("shift_expression <<--- additive_expression\n");}
#line 1657 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 64 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("shift_expression <<--- shift_expression << additive_expression\n");}
#line 1663 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 65 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("shift_expression <<--- shift_expression >> additive_expression\n");}
#line 1669 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 68 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("relational_expression <<--- shift_expression\n");}
#line 1675 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 69 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("relational_expression <<--- relational_expression < shift_expression\n");}
#line 1681 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 70 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("relational_expression <<--- relational_expression > shift_expression\n");}
#line 1687 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 71 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("relational_expression <<--- relational_expression <= shift_expression\n");}
#line 1693 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 72 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("relational_expression <<--- relational_expression >= shift_expression\n");}
#line 1699 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 75 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("equality_expression <<--- relational_expression\n");}
#line 1705 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 76 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("equality_expression <<--- equality_expression == relational_expression\n");}
#line 1711 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 77 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("equality_expression <<--- equality_expression != relational_expression\n");}
#line 1717 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 80 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("AND_expression <<--- equality_expression\n");}
#line 1723 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 81 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("AND_expression <<--- AND_expression & equality_expression\n");}
#line 1729 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 84 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("exclusive_OR_expression <<--- AND_expression\n");}
#line 1735 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 85 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("exclusive_OR_expression <<--- exclusive_OR_expression ^ AND_expression\n");}
#line 1741 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 88 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("inclusive_OR_expression <<--- exclusive_OR_expression\n");}
#line 1747 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 89 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("inclusive_OR_expression <<--- inclusive_OR_expression | exclusive_OR_expression \n");}
#line 1753 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 92 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("logical_AND_expression <<--- inclusive_OR_expression\n");}
#line 1759 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 93 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("logical_AND_expression <<--- logical_AND_expression && inclusive_OR_expression\n");}
#line 1765 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 96 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("logical_OR_expression <<--- logical_AND_expression\n");}
#line 1771 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 97 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("logical_OR_expression <<--- logical_OR_expression || logical_AND_expression\n");}
#line 1777 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 100 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("conditional_expression <<--- logical_OR_expression\n");}
#line 1783 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 101 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("conditional_expression <<--- logical_OR_expression ? expression : conditional_expression\n");}
#line 1789 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 103 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_expression <<--- conditional_expression\n");}
#line 1795 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 104 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_expression <<--- unary_expression assignment_operator assignment_expression \n");}
#line 1801 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 107 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- =\n");}
#line 1807 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 108 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- *=\n");}
#line 1813 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 109 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- /=\n");}
#line 1819 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 110 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- %%=\n");}
#line 1825 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 111 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- +=\n");}
#line 1831 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 112 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- -=\n");}
#line 1837 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 113 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- <<=\n");}
#line 1843 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 114 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- >>=\n");}
#line 1849 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 115 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- &=\n");}
#line 1855 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 116 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- ^=\n");}
#line 1861 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 117 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("assignment_operator <<--- |=\n");}
#line 1867 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 120 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression <<--- assignment_expression\n");}
#line 1873 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 121 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression <<--- expression , assignment_expression\n");}
#line 1879 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 124 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("constant_expression <<--- conditional_expression\n");}
#line 1885 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 126 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration <<--- declaration_specifiers init_declarator_list ;\n");}
#line 1891 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 127 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration <<--- declaration_specifiers ;\n");}
#line 1897 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 130 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_specifiers <<--- type_specifier declaration_specifiers\n");}
#line 1903 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 131 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_specifiers <<--- type_specifier\n");}
#line 1909 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 134 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("init_declarator_list <<--- init_declarator\n");}
#line 1915 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 135 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("init_declarator_list <<--- init_declarator_list , init_declarator\n");}
#line 1921 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 138 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("init_declarator <<--- declarator\n");}
#line 1927 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 139 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("init_declarator <<--- declarator = initializer\n");}
#line 1933 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 142 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : void\n");}
#line 1939 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 143 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : char\n");}
#line 1945 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 144 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : short\n");}
#line 1951 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 145 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : int\n");}
#line 1957 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 146 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : long\n");}
#line 1963 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 147 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : float\n");}
#line 1969 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 148 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : double\n");}
#line 1975 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 149 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : Matrix\n");}
#line 1981 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 150 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : signed\n");}
#line 1987 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 151 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : unsigned\n");}
#line 1993 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 152 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("type_specifier : Bool\n");}
#line 1999 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 155 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declarator <<--- direct_declarator\n");}
#line 2005 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 156 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declarator <<--- pointer direct_declarator \n");}
#line 2011 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 159 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- IDENTIFIER\n");}
#line 2017 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 160 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- (declarator)\n");}
#line 2023 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 161 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- direct_declarator [assignment_expression]\n");}
#line 2029 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 162 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- direct_declarator []\n");}
#line 2035 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 163 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- direct_declarator (parameter_type_list)\n");}
#line 2041 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 164 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- direct_declarator (identifier_list)\n");}
#line 2047 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 165 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("direct_declarator <<--- direct_declarator ()\n");}
#line 2053 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 167 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("pointer <<--- *\n");}
#line 2059 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 168 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("pointer <<--- * pointer\n");}
#line 2065 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 171 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_type_list <<--- parameter_list\n");}
#line 2071 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 173 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_list <<--- parameter_declaration\n");}
#line 2077 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 174 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_list <<--- parameter_list ',' parameter_declaration\n");}
#line 2083 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 177 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_declaration <<--- declaration_specifiers declarator\n");}
#line 2089 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 178 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("parameter_declaration <<--- declaration_specifiers\n");}
#line 2095 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 181 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("identifier_list <<--- IDENTIFIER \n");}
#line 2101 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 182 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("identifier_list <<--- identifier_list , IDENTIFIER \n");}
#line 2107 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 185 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer <<--- assignment_expression\n");}
#line 2113 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 186 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer <<--- {initializer_row_list}\n");}
#line 2119 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 189 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row_list <<--- initializer_row\n");}
#line 2125 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 190 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row_list <<--- initializer_row_list ; initializer_row\n");}
#line 2131 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 193 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<--- initializer\n");}
#line 2137 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 194 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<--- designation initializer\n");}
#line 2143 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 195 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("initializer_row <<---  initializer_row , initializer\n");}
#line 2149 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 198 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designation <<--- designator_list =\n");}
#line 2155 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 200 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator_list <<--- designator\n");}
#line 2161 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 201 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator_list <<--- designator_list designator\n");}
#line 2167 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 204 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator <<--- [constant_expression]\n");}
#line 2173 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 205 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("designator <<--- . IDENTIFIER\n");}
#line 2179 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 208 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- labeled_statement\n");}
#line 2185 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 209 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- compound_statement\n");}
#line 2191 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 210 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- expression_statement\n");}
#line 2197 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 211 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- selection_statement\n");}
#line 2203 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 212 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- iteration_statement\n");}
#line 2209 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 213 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("statement <<--- jump_statement\n");}
#line 2215 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 216 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- IDENTIFIER : statement\n");}
#line 2221 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 217 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- case constant_expression : statement\n");}
#line 2227 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 218 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("labeled_statement <<--- default statement\n");}
#line 2233 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 221 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("compound_statement : {}\n");}
#line 2239 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 222 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("compound_statement : {block_item_list}\n");}
#line 2245 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 225 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("block_item_list <<--- block_item\n");}
#line 2251 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 226 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("block_item_list <<--- block_item_list block_item\n");}
#line 2257 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 229 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("block_item <<--- declaration\n");}
#line 2263 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 230 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("block_item <<--- statement\n");}
#line 2269 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 233 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_statement <<--- ;\n");}
#line 2275 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 234 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_statement <<--- expression ;\n");}
#line 2281 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 237 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("selection_statement <<--- if (expression) statement\n");}
#line 2287 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 238 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("selection_statement <<--- if (expression) statement else statement\n");}
#line 2293 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 239 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("selection_statement <<--- switch (expression) statement\n");}
#line 2299 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 242 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_opt <<--- expression\n");}
#line 2305 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 243 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("expression_opt <<--- epsilon\n");}
#line 2311 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 246 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- while (expression) statement \n");}
#line 2317 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 247 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- do statement while (expression);\n");}
#line 2323 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 248 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- for (expression_opt ; expression_opt ; expression_opt) statement\n");}
#line 2329 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 249 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("iteration_statement <<--- for(declaration expression_opt; expression_opt) statement\n");}
#line 2335 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 252 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- goto IDENTIFIER ;\n");}
#line 2341 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 253 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- continue;\n");}
#line 2347 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 254 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- break;\n");}
#line 2353 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 255 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("jump_statement <<--- return expression_opt ;\n");}
#line 2359 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 258 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("translation_unit <<--- external_declaration\n");}
#line 2365 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 259 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("translation_unit <<--- translation_unit external_declaration\n");}
#line 2371 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 262 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("external_declaration <<--- function_definition\n");}
#line 2377 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 263 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("external_declaration <<--- definition\n");}
#line 2383 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 266 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("function_definition <<--- declaration_specifiers declarator declaration_list compound_statement\n");}
#line 2389 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 267 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("function_definition <<---declaration_specifiers declarator compound_statement\n");}
#line 2395 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 270 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_list <<--- declaration\n");}
#line 2401 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 271 "ass3_15CS30008.y" /* yacc.c:1646  */
    {printf("declaration_list <<--- declaration_list declaration\n");}
#line 2407 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
    break;


#line 2411 "ass3_15CS30008.tab.c" /* yacc.c:1646  */
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
#line 275 "ass3_15CS30008.y" /* yacc.c:1906  */


void yyerror(const char* s){
    printf("%s\n",s);
    exit(-1);
}
