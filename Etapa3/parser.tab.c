/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "stdio.h"
#include "stdlib.h"
#include "ast.h"

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);

#line 83 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_CHAR = 6,                 /* TK_PR_CHAR  */
  YYSYMBOL_TK_PR_STRING = 7,               /* TK_PR_STRING  */
  YYSYMBOL_TK_PR_IF = 8,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_THEN = 9,                 /* TK_PR_THEN  */
  YYSYMBOL_TK_PR_ELSE = 10,                /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 11,               /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_DO = 12,                  /* TK_PR_DO  */
  YYSYMBOL_TK_PR_INPUT = 13,               /* TK_PR_INPUT  */
  YYSYMBOL_TK_PR_OUTPUT = 14,              /* TK_PR_OUTPUT  */
  YYSYMBOL_TK_PR_RETURN = 15,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_PR_CONST = 16,               /* TK_PR_CONST  */
  YYSYMBOL_TK_PR_STATIC = 17,              /* TK_PR_STATIC  */
  YYSYMBOL_TK_PR_FOREACH = 18,             /* TK_PR_FOREACH  */
  YYSYMBOL_TK_PR_FOR = 19,                 /* TK_PR_FOR  */
  YYSYMBOL_TK_PR_SWITCH = 20,              /* TK_PR_SWITCH  */
  YYSYMBOL_TK_PR_CASE = 21,                /* TK_PR_CASE  */
  YYSYMBOL_TK_PR_BREAK = 22,               /* TK_PR_BREAK  */
  YYSYMBOL_TK_PR_CONTINUE = 23,            /* TK_PR_CONTINUE  */
  YYSYMBOL_TK_PR_CLASS = 24,               /* TK_PR_CLASS  */
  YYSYMBOL_TK_PR_PRIVATE = 25,             /* TK_PR_PRIVATE  */
  YYSYMBOL_TK_PR_PUBLIC = 26,              /* TK_PR_PUBLIC  */
  YYSYMBOL_TK_PR_PROTECTED = 27,           /* TK_PR_PROTECTED  */
  YYSYMBOL_TK_PR_END = 28,                 /* TK_PR_END  */
  YYSYMBOL_TK_PR_DEFAULT = 29,             /* TK_PR_DEFAULT  */
  YYSYMBOL_TK_OC_LE = 30,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 31,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 32,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 33,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 34,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 35,                  /* TK_OC_OR  */
  YYSYMBOL_TK_OC_SL = 36,                  /* TK_OC_SL  */
  YYSYMBOL_TK_OC_SR = 37,                  /* TK_OC_SR  */
  YYSYMBOL_TK_LIT_INT = 38,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 39,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 40,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 41,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_LIT_CHAR = 42,               /* TK_LIT_CHAR  */
  YYSYMBOL_TK_LIT_STRING = 43,             /* TK_LIT_STRING  */
  YYSYMBOL_TK_IDENTIFICADOR = 44,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '|'  */
  YYSYMBOL_57_ = 57,                       /* '*'  */
  YYSYMBOL_58_ = 58,                       /* '/'  */
  YYSYMBOL_59_ = 59,                       /* '<'  */
  YYSYMBOL_60_ = 60,                       /* '>'  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* '!'  */
  YYSYMBOL_63_ = 63,                       /* '&'  */
  YYSYMBOL_64_ = 64,                       /* '%'  */
  YYSYMBOL_65_ = 65,                       /* '#'  */
  YYSYMBOL_66_ = 66,                       /* '^'  */
  YYSYMBOL_67_ = 67,                       /* '.'  */
  YYSYMBOL_68_ = 68,                       /* '$'  */
  YYSYMBOL_69_ = 69,                       /* '?'  */
  YYSYMBOL_TOKEN_ERRO = 70,                /* TOKEN_ERRO  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_program = 72,                   /* program  */
  YYSYMBOL_optionalStatic = 73,            /* optionalStatic  */
  YYSYMBOL_optionalConst = 74,             /* optionalConst  */
  YYSYMBOL_globalVariable = 75,            /* globalVariable  */
  YYSYMBOL_globalVariableList = 76,        /* globalVariableList  */
  YYSYMBOL_type = 77,                      /* type  */
  YYSYMBOL_value = 78,                     /* value  */
  YYSYMBOL_functionDefinition = 79,        /* functionDefinition  */
  YYSYMBOL_functionHeader = 80,            /* functionHeader  */
  YYSYMBOL_headerParameters = 81,          /* headerParameters  */
  YYSYMBOL_headerParametersList = 82,      /* headerParametersList  */
  YYSYMBOL_commandBlock = 83,              /* commandBlock  */
  YYSYMBOL_commandList = 84,               /* commandList  */
  YYSYMBOL_command = 85,                   /* command  */
  YYSYMBOL_attribution = 86,               /* attribution  */
  YYSYMBOL_inputOutput = 87,               /* inputOutput  */
  YYSYMBOL_output = 88,                    /* output  */
  YYSYMBOL_input = 89,                     /* input  */
  YYSYMBOL_functionCall = 90,              /* functionCall  */
  YYSYMBOL_functionParameters = 91,        /* functionParameters  */
  YYSYMBOL_functionParametersList = 92,    /* functionParametersList  */
  YYSYMBOL_shift = 93,                     /* shift  */
  YYSYMBOL_shiftOperator = 94,             /* shiftOperator  */
  YYSYMBOL_executionControl = 95,          /* executionControl  */
  YYSYMBOL_fluxControl = 96,               /* fluxControl  */
  YYSYMBOL_conditional = 97,               /* conditional  */
  YYSYMBOL_else = 98,                      /* else  */
  YYSYMBOL_while = 99,                     /* while  */
  YYSYMBOL_for = 100,                      /* for  */
  YYSYMBOL_expression = 101,               /* expression  */
  YYSYMBOL_orLogicalExpression = 102,      /* orLogicalExpression  */
  YYSYMBOL_andLogicalExpression = 103,     /* andLogicalExpression  */
  YYSYMBOL_bitwiseOrExpression = 104,      /* bitwiseOrExpression  */
  YYSYMBOL_bitwiseAndExpression = 105,     /* bitwiseAndExpression  */
  YYSYMBOL_equalityExpression = 106,       /* equalityExpression  */
  YYSYMBOL_comparisonExpression = 107,     /* comparisonExpression  */
  YYSYMBOL_sumExpression = 108,            /* sumExpression  */
  YYSYMBOL_multiplicationExpression = 109, /* multiplicationExpression  */
  YYSYMBOL_powerExpression = 110,          /* powerExpression  */
  YYSYMBOL_unaryExpression = 111,          /* unaryExpression  */
  YYSYMBOL_orLogicalOperator = 112,        /* orLogicalOperator  */
  YYSYMBOL_andLogicalOperator = 113,       /* andLogicalOperator  */
  YYSYMBOL_bitwiseOrOperator = 114,        /* bitwiseOrOperator  */
  YYSYMBOL_bitwiseAndOperator = 115,       /* bitwiseAndOperator  */
  YYSYMBOL_equalityOperator = 116,         /* equalityOperator  */
  YYSYMBOL_comparisonOperator = 117,       /* comparisonOperator  */
  YYSYMBOL_sumOperator = 118,              /* sumOperator  */
  YYSYMBOL_multiplicationOperator = 119,   /* multiplicationOperator  */
  YYSYMBOL_powerOperator = 120,            /* powerOperator  */
  YYSYMBOL_unaryOperator = 121,            /* unaryOperator  */
  YYSYMBOL_variableDeclaration = 122,      /* variableDeclaration  */
  YYSYMBOL_variable = 123,                 /* variable  */
  YYSYMBOL_variableDeclarationList = 124,  /* variableDeclarationList  */
  YYSYMBOL_operand = 125,                  /* operand  */
  YYSYMBOL_vector_identifier = 126,        /* vector_identifier  */
  YYSYMBOL_identifier = 127,               /* identifier  */
  YYSYMBOL_positive_integer = 128          /* positive_integer  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    65,    68,    64,    63,     2,
      48,    49,    57,    54,    45,    55,    67,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
      59,    61,    60,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    56,    53,     2,     2,     2,     2,
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
      70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   157,   157,   158,   159,   161,   162,   163,   164,   166,
     167,   168,   170,   171,   172,   173,   174,   176,   177,   178,
     179,   180,   181,   183,   185,   187,   188,   189,   190,   192,
     194,   205,   207,   208,   209,   210,   211,   212,   213,   214,
     217,   218,   220,   221,   223,   224,   226,   228,   231,   232,
     233,   234,   236,   237,   239,   240,   242,   243,   244,   246,
     247,   248,   249,   251,   252,   254,   257,   259,   260,   262,
     263,   265,   266,   268,   269,   271,   272,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   285,   286,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   313,   315,   316,   317,   319,   320,   323,   324,
     325,   326,   327,   329,   330,   331,   334,   335
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF",
  "TK_PR_THEN", "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT",
  "TK_PR_OUTPUT", "TK_PR_RETURN", "TK_PR_CONST", "TK_PR_STATIC",
  "TK_PR_FOREACH", "TK_PR_FOR", "TK_PR_SWITCH", "TK_PR_CASE",
  "TK_PR_BREAK", "TK_PR_CONTINUE", "TK_PR_CLASS", "TK_PR_PRIVATE",
  "TK_PR_PUBLIC", "TK_PR_PROTECTED", "TK_PR_END", "TK_PR_DEFAULT",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_OC_SL", "TK_OC_SR", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE",
  "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "','",
  "';'", "':'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'+'", "'-'",
  "'|'", "'*'", "'/'", "'<'", "'>'", "'='", "'!'", "'&'", "'%'", "'#'",
  "'^'", "'.'", "'$'", "'?'", "TOKEN_ERRO", "$accept", "program",
  "optionalStatic", "optionalConst", "globalVariable",
  "globalVariableList", "type", "value", "functionDefinition",
  "functionHeader", "headerParameters", "headerParametersList",
  "commandBlock", "commandList", "command", "attribution", "inputOutput",
  "output", "input", "functionCall", "functionParameters",
  "functionParametersList", "shift", "shiftOperator", "executionControl",
  "fluxControl", "conditional", "else", "while", "for", "expression",
  "orLogicalExpression", "andLogicalExpression", "bitwiseOrExpression",
  "bitwiseAndExpression", "equalityExpression", "comparisonExpression",
  "sumExpression", "multiplicationExpression", "powerExpression",
  "unaryExpression", "orLogicalOperator", "andLogicalOperator",
  "bitwiseOrOperator", "bitwiseAndOperator", "equalityOperator",
  "comparisonOperator", "sumOperator", "multiplicationOperator",
  "powerOperator", "unaryOperator", "variableDeclaration", "variable",
  "variableDeclarationList", "operand", "vector_identifier", "identifier",
  "positive_integer", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,    59,    58,    40,    41,
      91,    93,   123,   125,    43,    45,   124,    42,    47,    60,
      62,    61,    33,    38,    37,    35,    94,    46,    36,    63,
     300
};
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -88,    14,    82,    13,    13,   -33,   -88,   -88,   -88,
     -88,   -88,   -88,   -13,   -88,   -88,    10,   -88,    19,   -17,
       0,     7,    17,    68,    36,    16,   -88,   -88,    -1,    25,
      12,    47,    10,    24,    51,   -88,   -88,    56,    57,    58,
      67,   -88,   -88,   -88,    69,    20,    -7,   -16,    80,    81,
      36,    36,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,    44,    36,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -23,    92,    73,    62,    50,   -20,    -3,
       8,    65,   -88,    36,   -88,   -88,    88,   -88,   -88,    36,
      36,    36,    95,   -88,    82,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    36,   -16,    82,    85,   -88,
      97,    86,    89,   -17,   -88,    87,    93,    94,   -88,    36,
      36,   -88,    36,   -88,    36,   -88,    36,   -88,   -88,    36,
     -88,   -88,   -88,   -88,    36,   -88,   -88,    36,   -88,   -88,
     -88,    36,   -88,    36,   -88,   -35,    98,    83,    99,    96,
     100,   -88,   -88,   102,   -88,   -88,   105,   -88,   -88,   -88,
     -88,   -33,   128,   -88,   103,    92,    73,    62,    50,   -20,
      -3,     8,    65,   -88,    36,   -88,    36,   -88,   -88,   122,
     108,   109,   146,   -33,    36,   110,    96,    79,   102,   -88,
      25,   -88,   -33,   -88,   -88,   -88,    88,   -88,   -88,   -88,
     108,    82,   -88,   111,   -88,   114,   -33,   109,   -88,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     5,     0,     0,     6,     6,     0,     1,    12,    13,
      15,    14,    16,     0,     2,     3,     6,    23,   124,    11,
       0,     0,     0,     0,     0,     0,    57,    58,     0,     8,
       0,     0,     6,     0,     0,    43,    42,     0,     0,     0,
       0,    59,    60,    61,     0,     0,     8,     0,     0,     0,
       0,     0,    46,    17,    18,    19,    20,    21,    22,    44,
      45,   118,     0,   105,   106,   109,   107,   108,   111,   110,
     120,   121,    56,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    86,     0,    88,   119,     0,    54,    55,    49,
       0,     0,     0,     7,     0,    39,    29,    30,    33,    34,
      35,    36,    37,    38,    32,     0,     0,     0,     0,   127,
       0,     0,   124,    11,     9,     0,     0,     0,    89,     0,
       0,    90,     0,    91,     0,    92,     0,    93,    94,     0,
      95,    96,    97,    98,     0,    99,   100,     0,   101,   102,
     103,     0,   104,     0,    87,     0,     0,     0,     0,    51,
       0,    40,    52,     0,    41,    53,     0,    24,   126,   125,
      10,     0,     0,   122,     0,    69,    71,    73,    75,    77,
      79,    81,    83,    85,     0,    47,     0,    48,   123,   113,
     117,    28,    64,     0,     0,     0,    51,     0,     0,   112,
       8,    25,     0,    62,    65,    67,     0,    50,   115,   114,
     117,     0,    63,     0,   116,     0,     0,    28,    66,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,    91,    18,   -43,   -88,    46,   -87,   -21,   -88,   -88,
     -88,   -45,    -6,   129,   -88,   -80,   -88,   -88,   -88,    21,
     -88,   -22,   -88,   118,   -88,   -88,   -88,   -88,   -88,   -88,
     -46,   -88,    45,    48,    43,    42,    40,    37,    35,    32,
     -75,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -14,   -25,   -88,   -15,   130,    70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    94,     4,    49,    13,    70,     5,     6,
     108,   191,    30,    31,    32,    33,    34,    35,    36,    71,
     148,   177,    38,    92,    39,    40,    41,   193,    42,    43,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   120,   122,   124,   126,   129,   134,   137,   141,   143,
      83,    44,   180,   189,    84,    85,    19,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    45,    60,   107,   115,   116,   146,   153,   144,    93,
     130,   131,   118,    -4,     7,    90,   117,    45,    20,    16,
     156,    21,   109,    22,    23,    24,    91,     1,    48,    25,
       1,    18,    26,    27,    29,    87,    88,    37,   110,   132,
     133,    93,   -26,   149,   150,   151,   119,    89,    50,    90,
      29,   135,   136,    37,    28,    51,    87,    88,    95,   154,
      91,    52,    16,   -31,    86,   138,   139,    46,   173,    47,
      98,   147,   140,   164,    53,    54,    55,    56,    57,    58,
      61,   105,   127,   128,    62,     8,     9,    10,    11,    12,
      63,    64,    89,    65,    90,    14,    15,    99,    66,    67,
      96,    68,   100,   101,   102,    69,    53,    54,    55,    56,
      57,    58,    59,   103,   205,   104,   203,    53,    54,    55,
      56,    57,    58,   198,   112,   125,   121,   114,   185,   123,
     186,   142,   145,   152,   157,   158,   161,   159,   195,    47,
     183,   176,   162,   163,   105,   174,   179,   201,   175,   181,
     184,   178,   187,   188,   190,   182,   192,   196,   207,   160,
     206,    97,   209,   106,   197,   165,   199,   167,   168,   169,
     166,   170,   171,   172,   200,   204,   155,   194,   113,     0,
       0,   147,     0,     0,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208
};

static const yytype_int16 yycheck[] =
{
       6,    16,    23,    46,    50,    51,    86,    94,    83,    16,
      30,    31,    35,     0,     0,    50,    62,    32,     8,    52,
     107,    11,    38,    13,    14,    15,    61,    17,    45,    19,
      17,    44,    22,    23,    16,    36,    37,    16,    54,    59,
      60,    16,    49,    89,    90,    91,    69,    48,    48,    50,
      32,    54,    55,    32,    44,    48,    36,    37,    46,   105,
      61,    44,    52,    53,    48,    57,    58,    48,   143,    50,
      46,    86,    64,   119,    38,    39,    40,    41,    42,    43,
      44,    61,    32,    33,    48,     3,     4,     5,     6,     7,
      54,    55,    48,    57,    50,     4,     5,    46,    62,    63,
      53,    65,    46,    46,    46,    69,    38,    39,    40,    41,
      42,    43,    44,    46,   201,    46,   196,    38,    39,    40,
      41,    42,    43,    44,    44,    63,    34,    46,   174,    56,
     176,    66,    44,    38,    49,    38,    49,    51,   184,    50,
      12,    45,    49,    49,    61,    47,    44,   190,    49,    44,
      47,    51,    30,    45,    45,   161,    10,    47,    44,   113,
      49,    32,   207,    45,   186,   120,   187,   124,   126,   129,
     122,   134,   137,   141,   188,   200,   106,   183,    48,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    72,    73,    75,    79,    80,     0,     3,     4,
       5,     6,     7,    77,    72,    72,    52,    83,    44,   127,
       8,    11,    13,    14,    15,    19,    22,    23,    44,    73,
      83,    84,    85,    86,    87,    88,    89,    90,    93,    95,
      96,    97,    99,   100,   122,   126,    48,    50,    45,    76,
      48,    48,    44,    38,    39,    40,    41,    42,    43,    44,
      78,    44,    48,    54,    55,    57,    62,    63,    65,    69,
      78,    90,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   121,   125,   126,    48,    36,    37,    48,
      50,    61,    94,    16,    74,    46,    53,    84,    46,    46,
      46,    46,    46,    46,    46,    61,    94,    74,    81,    38,
      54,   128,    44,   127,    46,   101,   101,   101,    35,    69,
     112,    34,   113,    56,   114,    63,   115,    32,    33,   116,
      30,    31,    59,    60,   117,    54,    55,   118,    57,    58,
      64,   119,    66,   120,   111,    44,    86,   126,    91,   101,
     101,   101,    38,    77,   101,   128,    77,    49,    38,    51,
      76,    49,    49,    49,   101,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    47,    49,    45,    92,    51,    44,
     123,    44,    83,    12,    47,   101,   101,    30,    45,   124,
      45,    82,    10,    98,    83,   101,    47,    92,    44,    78,
     123,    74,    83,    86,   124,    77,    49,    44,    83,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    97,    98,    98,    99,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     113,   114,   115,   116,   116,   117,   117,   117,   117,   118,
     118,   119,   119,   119,   120,   121,   121,   121,   121,   121,
     121,   121,   122,   123,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   126,   127,   127,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     0,     1,     0,     5,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     6,     4,     0,     5,     0,     3,
       2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     1,     1,     2,     2,     2,     4,     2,     0,
       3,     0,     3,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     6,     2,     0,     6,     9,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     3,     3,     3,     0,     1,     1,
       1,     1,     3,     4,     1,     4,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* program: globalVariable program  */
#line 157 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); arvore = (yyval.node); }
#line 1883 "parser.tab.c"
    break;

  case 3: /* program: functionDefinition program  */
#line 158 "parser.y"
                                     {(yyval.node)=(yyvsp[-1].node); addNext((yyvsp[-1].node), (yyvsp[0].node)); arvore=(yyval.node); }
#line 1889 "parser.tab.c"
    break;

  case 4: /* program: %empty  */
#line 159 "parser.y"
          {(yyval.node)=NULL;}
#line 1895 "parser.tab.c"
    break;

  case 5: /* optionalStatic: TK_PR_STATIC  */
#line 161 "parser.y"
                              { (yyval.node) = NULL; }
#line 1901 "parser.tab.c"
    break;

  case 6: /* optionalStatic: %empty  */
#line 162 "parser.y"
           { (yyval.node) = NULL; }
#line 1907 "parser.tab.c"
    break;

  case 7: /* optionalConst: TK_PR_CONST  */
#line 163 "parser.y"
                            { (yyval.node) = NULL; }
#line 1913 "parser.tab.c"
    break;

  case 8: /* optionalConst: %empty  */
#line 164 "parser.y"
           { (yyval.node) = NULL; }
#line 1919 "parser.tab.c"
    break;

  case 9: /* globalVariable: optionalStatic type identifier globalVariableList ';'  */
#line 166 "parser.y"
                                                                      {(yyval.node)=NULL; freeAST((yyvsp[-1].node));}
#line 1925 "parser.tab.c"
    break;

  case 10: /* globalVariableList: ',' identifier globalVariableList  */
#line 167 "parser.y"
                                                      {(yyval.node)=NULL; freeToken((yyvsp[-2].valor_lexico));}
#line 1931 "parser.tab.c"
    break;

  case 11: /* globalVariableList: %empty  */
#line 168 "parser.y"
          {(yyval.node)=NULL;}
#line 1937 "parser.tab.c"
    break;

  case 12: /* type: TK_PR_INT  */
#line 170 "parser.y"
                { (yyval.node) = NULL; }
#line 1943 "parser.tab.c"
    break;

  case 13: /* type: TK_PR_FLOAT  */
#line 171 "parser.y"
                       { (yyval.node) = NULL; }
#line 1949 "parser.tab.c"
    break;

  case 14: /* type: TK_PR_CHAR  */
#line 172 "parser.y"
                      { (yyval.node) = NULL; }
#line 1955 "parser.tab.c"
    break;

  case 15: /* type: TK_PR_BOOL  */
#line 173 "parser.y"
                      { (yyval.node) = NULL; }
#line 1961 "parser.tab.c"
    break;

  case 16: /* type: TK_PR_STRING  */
#line 174 "parser.y"
                        { (yyval.node) = NULL; }
#line 1967 "parser.tab.c"
    break;

  case 17: /* value: TK_LIT_INT  */
#line 176 "parser.y"
                  {createNode((yyvsp[0].valor_lexico));}
#line 1973 "parser.tab.c"
    break;

  case 18: /* value: TK_LIT_FLOAT  */
#line 177 "parser.y"
                       {createNode((yyvsp[0].valor_lexico));}
#line 1979 "parser.tab.c"
    break;

  case 19: /* value: TK_LIT_FALSE  */
#line 178 "parser.y"
                       {createNode((yyvsp[0].valor_lexico));}
#line 1985 "parser.tab.c"
    break;

  case 20: /* value: TK_LIT_TRUE  */
#line 179 "parser.y"
                      {createNode((yyvsp[0].valor_lexico));}
#line 1991 "parser.tab.c"
    break;

  case 21: /* value: TK_LIT_CHAR  */
#line 180 "parser.y"
                      {createNode((yyvsp[0].valor_lexico));}
#line 1997 "parser.tab.c"
    break;

  case 22: /* value: TK_LIT_STRING  */
#line 181 "parser.y"
                        {createNode((yyvsp[0].valor_lexico));}
#line 2003 "parser.tab.c"
    break;

  case 23: /* functionDefinition: functionHeader commandBlock  */
#line 183 "parser.y"
                                                {addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2009 "parser.tab.c"
    break;

  case 24: /* functionHeader: optionalStatic type TK_IDENTIFICADOR '(' headerParameters ')'  */
#line 185 "parser.y"
                                                                              {(yyval.node)=createNode((yyvsp[-3].valor_lexico));}
#line 2015 "parser.tab.c"
    break;

  case 25: /* headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList  */
#line 187 "parser.y"
                                                                           {freeToken((yyvsp[-1].valor_lexico));(yyval.node)=NULL;}
#line 2021 "parser.tab.c"
    break;

  case 27: /* headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList  */
#line 189 "parser.y"
                                                                                   {(yyval.node)=NULL;}
#line 2027 "parser.tab.c"
    break;

  case 28: /* headerParametersList: %empty  */
#line 190 "parser.y"
          {(yyval.node)=NULL;}
#line 2033 "parser.tab.c"
    break;

  case 29: /* commandBlock: '{' commandList '}'  */
#line 192 "parser.y"
                                  {(yyval.node)=(yyvsp[-1].node); freeToken((yyvsp[-2].valor_lexico)); freeToken((yyvsp[0].valor_lexico));}
#line 2039 "parser.tab.c"
    break;

  case 30: /* commandList: command commandList  */
#line 194 "parser.y"
                                 {

		if((yyvsp[-1].node)!=NULL)
		{
			addNext((yyvsp[-1].node)->children[(yyvsp[-1].node)->numberOfChildren - 1], (yyvsp[0].node));
			(yyval.node)=(yyvsp[-1].node);
		}
		else {
			(yyval.node)=(yyvsp[0].node);
		}
	}
#line 2055 "parser.tab.c"
    break;

  case 31: /* commandList: %empty  */
#line 205 "parser.y"
          {(yyval.node)=NULL;}
#line 2061 "parser.tab.c"
    break;

  case 32: /* command: variableDeclaration ';'  */
#line 207 "parser.y"
                                 {(yyval.node) = (yyvsp[-1].node); freeToken((yyvsp[0].valor_lexico)); }
#line 2067 "parser.tab.c"
    break;

  case 33: /* command: attribution ';'  */
#line 208 "parser.y"
                          {(yyval.node) = (yyvsp[-1].node); freeToken((yyvsp[0].valor_lexico)); }
#line 2073 "parser.tab.c"
    break;

  case 34: /* command: inputOutput ';'  */
#line 209 "parser.y"
                          {(yyval.node) = (yyvsp[-1].node);  freeToken((yyvsp[0].valor_lexico));}
#line 2079 "parser.tab.c"
    break;

  case 35: /* command: functionCall ';'  */
#line 210 "parser.y"
                           {(yyval.node) = (yyvsp[-1].node);  freeToken((yyvsp[0].valor_lexico));}
#line 2085 "parser.tab.c"
    break;

  case 36: /* command: shift ';'  */
#line 211 "parser.y"
                    {(yyval.node) = (yyvsp[-1].node); freeToken((yyvsp[0].valor_lexico)); }
#line 2091 "parser.tab.c"
    break;

  case 37: /* command: executionControl ';'  */
#line 212 "parser.y"
                               {(yyval.node) = (yyvsp[-1].node);  freeToken((yyvsp[0].valor_lexico));}
#line 2097 "parser.tab.c"
    break;

  case 38: /* command: fluxControl ';'  */
#line 213 "parser.y"
                          {(yyval.node) = (yyvsp[-1].node); freeToken((yyvsp[0].valor_lexico));}
#line 2103 "parser.tab.c"
    break;

  case 39: /* command: commandBlock ';'  */
#line 214 "parser.y"
                           {(yyval.node) = (yyvsp[-1].node); freeToken((yyvsp[0].valor_lexico));}
#line 2109 "parser.tab.c"
    break;

  case 40: /* attribution: TK_IDENTIFICADOR '=' expression  */
#line 217 "parser.y"
                                             {(yyval.node)=createAttributionNode(); addChild((yyval.node),createNode((yyvsp[-2].valor_lexico))); addChild((yyval.node),(yyvsp[0].node));}
#line 2115 "parser.tab.c"
    break;

  case 41: /* attribution: vector_identifier '=' expression  */
#line 218 "parser.y"
                                           {(yyval.node)=createAttributionNode(); addChild((yyval.node),(yyvsp[-2].node)); addChild((yyval.node),(yyvsp[0].node));}
#line 2121 "parser.tab.c"
    break;

  case 42: /* inputOutput: input  */
#line 220 "parser.y"
                   {(yyval.node)=(yyvsp[0].node);}
#line 2127 "parser.tab.c"
    break;

  case 43: /* inputOutput: output  */
#line 221 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2133 "parser.tab.c"
    break;

  case 44: /* output: TK_PR_OUTPUT TK_IDENTIFICADOR  */
#line 223 "parser.y"
                                      {(yyval.node)=createNode((yyvsp[-1].valor_lexico)); addChild((yyval.node),createNode((yyvsp[0].valor_lexico)));}
#line 2139 "parser.tab.c"
    break;

  case 45: /* output: TK_PR_OUTPUT value  */
#line 224 "parser.y"
                             {(yyval.node)=createNode((yyvsp[-1].valor_lexico)); addChild((yyval.node),(yyvsp[0].node));}
#line 2145 "parser.tab.c"
    break;

  case 46: /* input: TK_PR_INPUT TK_IDENTIFICADOR  */
#line 226 "parser.y"
                                    {(yyval.node)=createNode((yyvsp[-1].valor_lexico)); addChild((yyval.node),createNode((yyvsp[0].valor_lexico)));}
#line 2151 "parser.tab.c"
    break;

  case 47: /* functionCall: TK_IDENTIFICADOR '(' functionParameters ')'  */
#line 228 "parser.y"
                                                          {(yyval.node)=createFuncCallNode(); addChild((yyval.node), createNode((yyvsp[-3].valor_lexico))); addChild((yyval.node),(yyvsp[-1].node));}
#line 2157 "parser.tab.c"
    break;

  case 52: /* shift: TK_IDENTIFICADOR shiftOperator TK_LIT_INT  */
#line 236 "parser.y"
                                                 {addChild((yyvsp[-1].node),createNode((yyvsp[-2].valor_lexico))); addChild((yyvsp[-1].node),createNode((yyvsp[0].valor_lexico))); (yyval.node)=(yyvsp[-1].node);}
#line 2163 "parser.tab.c"
    break;

  case 53: /* shift: vector_identifier shiftOperator positive_integer  */
#line 237 "parser.y"
                                                           {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2169 "parser.tab.c"
    break;

  case 54: /* shiftOperator: TK_OC_SL  */
#line 239 "parser.y"
                        {(yyval.node)=createShiftNode((yyvsp[0].valor_lexico));}
#line 2175 "parser.tab.c"
    break;

  case 55: /* shiftOperator: TK_OC_SR  */
#line 240 "parser.y"
                   {(yyval.node)=createShiftNode((yyvsp[0].valor_lexico));}
#line 2181 "parser.tab.c"
    break;

  case 57: /* executionControl: TK_PR_BREAK  */
#line 243 "parser.y"
                      {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2187 "parser.tab.c"
    break;

  case 58: /* executionControl: TK_PR_CONTINUE  */
#line 244 "parser.y"
                         {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2193 "parser.tab.c"
    break;

  case 59: /* fluxControl: conditional  */
#line 246 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2199 "parser.tab.c"
    break;

  case 60: /* fluxControl: while  */
#line 247 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 2205 "parser.tab.c"
    break;

  case 61: /* fluxControl: for  */
#line 248 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 2211 "parser.tab.c"
    break;

  case 62: /* conditional: TK_PR_IF '(' expression ')' commandBlock else  */
#line 249 "parser.y"
                                                           {(yyval.node)=createNode((yyvsp[-5].valor_lexico)); addChild((yyval.node),(yyvsp[-3].node));addChild((yyval.node),(yyvsp[-1].node));addChild((yyval.node),(yyvsp[0].node));}
#line 2217 "parser.tab.c"
    break;

  case 63: /* else: TK_PR_ELSE commandBlock  */
#line 251 "parser.y"
                              {(yyval.node)=createNode((yyvsp[-1].valor_lexico));}
#line 2223 "parser.tab.c"
    break;

  case 64: /* else: %empty  */
#line 252 "parser.y"
          {(yyval.node)=NULL;}
#line 2229 "parser.tab.c"
    break;

  case 65: /* while: TK_PR_WHILE '(' expression ')' TK_PR_DO commandBlock  */
#line 254 "parser.y"
                                                            {(yyval.node)=createNode((yyvsp[-5].valor_lexico)); addChild((yyval.node),(yyvsp[-3].node)); addChild((yyval.node),(yyvsp[0].node));}
#line 2235 "parser.tab.c"
    break;

  case 66: /* for: TK_PR_FOR '(' attribution ':' expression ':' attribution ')' commandBlock  */
#line 257 "parser.y"
                                                                                {(yyval.node)=createNode((yyvsp[-8].valor_lexico)); addChild((yyval.node),(yyvsp[-6].node)); addChild((yyval.node),(yyvsp[-4].node)); addChild((yyval.node),(yyvsp[-2].node)); addChild((yyval.node),(yyvsp[0].node));}
#line 2241 "parser.tab.c"
    break;

  case 67: /* expression: orLogicalExpression '?' expression ':' expression  */
#line 259 "parser.y"
                                                              {(yyval.node)=createNode((yyvsp[-3].valor_lexico)); addChild((yyval.node),(yyvsp[-4].node)); addChild((yyval.node),(yyvsp[-2].node)); addChild((yyval.node),(yyvsp[0].node));  }
#line 2247 "parser.tab.c"
    break;

  case 68: /* expression: orLogicalExpression  */
#line 260 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2253 "parser.tab.c"
    break;

  case 69: /* orLogicalExpression: orLogicalExpression orLogicalOperator andLogicalExpression  */
#line 262 "parser.y"
                                                                                {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2259 "parser.tab.c"
    break;

  case 70: /* orLogicalExpression: andLogicalExpression  */
#line 263 "parser.y"
                               {(yyval.node)=(yyvsp[0].node);}
#line 2265 "parser.tab.c"
    break;

  case 71: /* andLogicalExpression: andLogicalExpression andLogicalOperator bitwiseOrExpression  */
#line 265 "parser.y"
                                                                                  {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2271 "parser.tab.c"
    break;

  case 72: /* andLogicalExpression: bitwiseOrExpression  */
#line 266 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2277 "parser.tab.c"
    break;

  case 73: /* bitwiseOrExpression: bitwiseOrExpression bitwiseOrOperator bitwiseAndExpression  */
#line 268 "parser.y"
                                                                                {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2283 "parser.tab.c"
    break;

  case 74: /* bitwiseOrExpression: bitwiseAndExpression  */
#line 269 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2289 "parser.tab.c"
    break;

  case 75: /* bitwiseAndExpression: bitwiseAndExpression bitwiseAndOperator equalityExpression  */
#line 271 "parser.y"
                                                                                 {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2295 "parser.tab.c"
    break;

  case 76: /* bitwiseAndExpression: equalityExpression  */
#line 272 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2301 "parser.tab.c"
    break;

  case 77: /* equalityExpression: equalityExpression equalityOperator comparisonExpression  */
#line 274 "parser.y"
                                                                             {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2307 "parser.tab.c"
    break;

  case 78: /* equalityExpression: comparisonExpression  */
#line 275 "parser.y"
                               {(yyval.node)=(yyvsp[0].node);}
#line 2313 "parser.tab.c"
    break;

  case 79: /* comparisonExpression: comparisonExpression comparisonOperator sumExpression  */
#line 276 "parser.y"
                                                                            {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2319 "parser.tab.c"
    break;

  case 80: /* comparisonExpression: sumExpression  */
#line 277 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2325 "parser.tab.c"
    break;

  case 81: /* sumExpression: sumExpression sumOperator multiplicationExpression  */
#line 278 "parser.y"
                                                                  {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2331 "parser.tab.c"
    break;

  case 82: /* sumExpression: multiplicationExpression  */
#line 279 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2337 "parser.tab.c"
    break;

  case 83: /* multiplicationExpression: multiplicationExpression multiplicationOperator powerExpression  */
#line 280 "parser.y"
                                                                                          {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2343 "parser.tab.c"
    break;

  case 84: /* multiplicationExpression: powerExpression  */
#line 281 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2349 "parser.tab.c"
    break;

  case 85: /* powerExpression: powerExpression powerOperator unaryExpression  */
#line 282 "parser.y"
                                                               {addChild((yyvsp[-1].node),(yyvsp[-2].node)); addChild((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2355 "parser.tab.c"
    break;

  case 86: /* powerExpression: unaryExpression  */
#line 283 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2361 "parser.tab.c"
    break;

  case 89: /* orLogicalOperator: TK_OC_OR  */
#line 288 "parser.y"
                            {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2367 "parser.tab.c"
    break;

  case 90: /* andLogicalOperator: TK_OC_AND  */
#line 289 "parser.y"
                              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2373 "parser.tab.c"
    break;

  case 91: /* bitwiseOrOperator: '|'  */
#line 290 "parser.y"
                       {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2379 "parser.tab.c"
    break;

  case 92: /* bitwiseAndOperator: '&'  */
#line 291 "parser.y"
                        {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2385 "parser.tab.c"
    break;

  case 93: /* equalityOperator: TK_OC_EQ  */
#line 292 "parser.y"
                           {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2391 "parser.tab.c"
    break;

  case 94: /* equalityOperator: TK_OC_NE  */
#line 293 "parser.y"
                   {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2397 "parser.tab.c"
    break;

  case 95: /* comparisonOperator: TK_OC_LE  */
#line 294 "parser.y"
                             {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2403 "parser.tab.c"
    break;

  case 96: /* comparisonOperator: TK_OC_GE  */
#line 295 "parser.y"
                   {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2409 "parser.tab.c"
    break;

  case 97: /* comparisonOperator: '<'  */
#line 296 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2415 "parser.tab.c"
    break;

  case 98: /* comparisonOperator: '>'  */
#line 297 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2421 "parser.tab.c"
    break;

  case 99: /* sumOperator: '+'  */
#line 298 "parser.y"
                 {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2427 "parser.tab.c"
    break;

  case 100: /* sumOperator: '-'  */
#line 299 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2433 "parser.tab.c"
    break;

  case 102: /* multiplicationOperator: '/'  */
#line 301 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2439 "parser.tab.c"
    break;

  case 103: /* multiplicationOperator: '%'  */
#line 302 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2445 "parser.tab.c"
    break;

  case 106: /* unaryOperator: '-'  */
#line 305 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2451 "parser.tab.c"
    break;

  case 107: /* unaryOperator: '!'  */
#line 306 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2457 "parser.tab.c"
    break;

  case 108: /* unaryOperator: '&'  */
#line 307 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2463 "parser.tab.c"
    break;

  case 109: /* unaryOperator: '*'  */
#line 308 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2469 "parser.tab.c"
    break;

  case 110: /* unaryOperator: '?'  */
#line 309 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2475 "parser.tab.c"
    break;

  case 111: /* unaryOperator: '#'  */
#line 310 "parser.y"
              {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2481 "parser.tab.c"
    break;

  case 113: /* variable: TK_IDENTIFICADOR  */
#line 315 "parser.y"
                           {(yyval.node)=NULL; freeToken((yyvsp[0].valor_lexico));}
#line 2487 "parser.tab.c"
    break;

  case 114: /* variable: TK_IDENTIFICADOR TK_OC_LE value  */
#line 316 "parser.y"
                                          {(yyval.node)=createInitializationNode(); addChild((yyval.node),createNode((yyvsp[-2].valor_lexico))); addChild((yyval.node),(yyvsp[0].node)); }
#line 2493 "parser.tab.c"
    break;

  case 115: /* variable: TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR  */
#line 317 "parser.y"
                                                     {(yyval.node)=createInitializationNode(); addChild((yyval.node),createNode((yyvsp[-2].valor_lexico))); addChild((yyval.node),createNode((yyvsp[0].valor_lexico))); }
#line 2499 "parser.tab.c"
    break;

  case 117: /* variableDeclarationList: %empty  */
#line 320 "parser.y"
          {(yyval.node)=NULL;}
#line 2505 "parser.tab.c"
    break;

  case 118: /* operand: TK_IDENTIFICADOR  */
#line 323 "parser.y"
                          {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2511 "parser.tab.c"
    break;

  case 119: /* operand: vector_identifier  */
#line 324 "parser.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2517 "parser.tab.c"
    break;

  case 120: /* operand: value  */
#line 325 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 2523 "parser.tab.c"
    break;

  case 122: /* operand: '(' expression ')'  */
#line 327 "parser.y"
                             {freeToken((yyvsp[-2].valor_lexico)); freeToken((yyvsp[0].valor_lexico)); (yyval.node)=(yyvsp[-1].node);}
#line 2529 "parser.tab.c"
    break;

  case 124: /* identifier: TK_IDENTIFICADOR  */
#line 330 "parser.y"
                             {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2535 "parser.tab.c"
    break;

  case 126: /* positive_integer: '+' TK_LIT_INT  */
#line 334 "parser.y"
                                 {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2541 "parser.tab.c"
    break;

  case 127: /* positive_integer: TK_LIT_INT  */
#line 335 "parser.y"
                             {(yyval.node)=createNode((yyvsp[0].valor_lexico));}
#line 2547 "parser.tab.c"
    break;


#line 2551 "parser.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 337 "parser.y"


int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}
