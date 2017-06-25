/* $Id: Parser.c,v 1.54 2010/07/07 09:53:21 grosch Exp $ */

# include "expr_pars.h"
# include <stdio.h>
# include <stddef.h>

# ifndef EXTERN_C_BEGIN
#  define EXTERN_C_BEGIN
#  define EXTERN_C_END
# endif

EXTERN_C_BEGIN
# include "rString.h"
# include "rSystem.h"
# include "rMemory.h"
# include "General.h"
# include "DynArray.h"
# ifndef NO_RECOVER
#  include "Sets.h"
# endif
# if ! defined NO_RECOVER | defined YYReParse
#  include "Errors.h"
# endif
# if defined YYDEBUG | defined lex_interface
#  include "Position.h"
# endif
EXTERN_C_END

# ifdef lex_interface
#  define expr_scan_GetToken	yylex
     extern int yylex ARGS ((void));
#  ifndef AttributeDef
#   include "Position.h"
	   typedef struct { tPosition Position; } expr_scan_tScanAttribute;
	   expr_scan_tScanAttribute	expr_scan_Attribute = {{ 0, 0 }};
#  endif
#  ifndef ErrorAttributeDef
#   define expr_scan_ErrorAttribute(Token, RepairAttribute)
#  endif
#  ifndef yyGetAttribute
#   define yyGetAttribute(yyAttrStackPtr, a) * yyAttrStackPtr = yylval
#  endif
# else
#  include "expr_scan.h"
#  ifndef yyGetAttribute
#   define yyGetAttribute(yyAttrStackPtr, a) (yyAttrStackPtr)->Scan = a
#  endif
# endif

static void yyExit ARGS ((void)) { rExit (1); }

	void		(* expr_pars_Exit) ARGS ((void)) = yyExit;

static void yyCheckMemory
# ifdef HAVE_ARGS
   (char * ptr)
# else
   (ptr) char * ptr;
# endif
{
  if (! (ptr)) expr_pars_Exit ();
}

# define yyMakeArray(ptr, count, size)	 { MakeArray (ptr, count, size); \
					   yyCheckMemory (* ptr); }
# define yyExtendArray(ptr, count, size) { ExtendArray (ptr, count, size); \
					   yyCheckMemory (* ptr); }

typedef unsigned short	yyStateRange	;
typedef unsigned short	yySymbolRange	;
typedef struct { yyStateRange Check, Next; } yytComb;
typedef enum {
yyNT0_intern	= 29,
yyNTroot	= 30,
yyNTprogram	= 31,
yyNTblock_scoped	= 32,
yyNTblock_exec	= 33,
yyNTstatement	= 34,
yyNTdeclaration	= 35,
yyNTassignment	= 36,
yyNTcomputation	= 37,
yyNTttt	= 38,
yyNTfff	= 39,
yyNTvariable	= 40,
yyNTvariable_	= 41,
yyNTkeyword	= 42,
yyNTkeyword_if	= 43,
yyNTkeyword_elseif	= 44,
yyNTkeyword_else	= 45,
yyNTkeyword_while	= 46,
yyNTkeyword_for	= 47,
yyNTcondition	= 48
} yytNonterminal;
typedef struct { short yyMode; rbool yyActions, yyMessages; } yytControl;

static	yytControl	yyControl	= { 0, rtrue, rtrue };
	rbool		expr_pars_Debug	= rfalse;

# define yyFirstTerminal	0
# define yyLastTerminal	28
# define yySetSize	29
# define yyFirstSymbol	0
# define yyLastSymbol	48
# define yyTTableMax	118
# define yyNTableMax	88
# define yyStartState	1
# define yyFirstReadState	1
# define yyLastReadState	61
# define yyFirstReadReduceState	62
# define yyLastReadReduceState	69
# define yyFirstReduceState	70
# define yyLastReduceState	114
# define yyLastState	114
# define yyLastStopState	70
# define YYTDefault
# define YYNDefault

# define yyFirstFinalState	yyFirstReadReduceState

# define ErrorMessages(Messages) yyControl.yyMessages = Messages
# define SemActions(Actions)	 yyControl.yyActions = Actions

# ifdef YYCSTree
#  include "cs_tree.h"
#  define CommonParsAttrs tCSTree Tree;
# endif

# ifdef YYGetLook

#  define GetLookahead(k)	yyGetLookahead ((k) - 1, yyTerminal)
#  define GetAttribute(k, a)	xxGetAttribute ((k) - 1, yyTerminal, a)

static int yyGetLookahead	ARGS ((int yyk, yySymbolRange yyToken));
static void xxGetAttribute	ARGS ((int yyk, yySymbolRange yyToken,
				expr_scan_tScanAttribute * yyAttribute));

# endif

/* line 8 "expr_pars.lrk" */


/* line 25 "expr.pars" */

 # include <stdio.h>
 # include "Tree.h"


/* line 17 "expr_pars.lrk" */
# ifdef CommonParsAttrs
typedef struct { CommonParsAttrs } yytCommonParsAttrs;
#  define yyCommon yytCommonParsAttrs Common;
#  define yyCommonParsAttrs CommonParsAttrs
# else
#  define yyCommon
#  define yyCommonParsAttrs
# endif

typedef struct { yyCommonParsAttrs tTree tree; } zz_program;
typedef struct { yyCommonParsAttrs tTree tree; } zz_block_scoped;
typedef struct { yyCommonParsAttrs tTree tree; } zz_block_exec;
typedef struct { yyCommonParsAttrs tTree tree; } zz_statement;
typedef struct { yyCommonParsAttrs tTree tree; } zz_declaration;
typedef struct { yyCommonParsAttrs tTree tree; } zz_assignment;
typedef struct { yyCommonParsAttrs tTree tree; } zz_computation;
typedef struct { yyCommonParsAttrs tTree tree; } zz_ttt;
typedef struct { yyCommonParsAttrs tTree tree; } zz_fff;
typedef struct { yyCommonParsAttrs tTree tree; } zz_variable;
typedef struct { yyCommonParsAttrs tTree tree; } zz_variable_;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword_if;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword_elseif;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword_else;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword_while;
typedef struct { yyCommonParsAttrs tTree tree; } zz_keyword_for;
typedef struct { yyCommonParsAttrs tTree tree; } zz_condition;

typedef union {
expr_scan_tScanAttribute Scan;
yyCommon
zz_program program;
zz_block_scoped block_scoped;
zz_block_exec block_exec;
zz_statement statement;
zz_declaration declaration;
zz_assignment assignment;
zz_computation computation;
zz_ttt ttt;
zz_fff fff;
zz_variable variable;
zz_variable_ variable_;
zz_keyword keyword;
zz_keyword_if keyword_if;
zz_keyword_elseif keyword_elseif;
zz_keyword_else keyword_else;
zz_keyword_while keyword_while;
zz_keyword_for keyword_for;
zz_condition condition;
} tParsAttribute;

/* line 201 "expr_pars.c" */

# if defined lex_interface & ! defined yylvalDef
     tParsAttribute yylval;
# endif

# ifndef yyInitStackSize
#  define yyInitStackSize	100
# endif
# define yyNoState		0
# define yystandard		1
# define yytrial		2
# define yybuffer		4
# define yyreparse		8
# define yyS			yySynAttribute
# define yyA			yyAttrStackPtr
# define YYACCEPT		goto yyAccept
# define YYABORT		goto yyAbort

# ifdef YYDEC_TABLE
#  define yyDecrement(x)
#  define yySetNT(x)
# else
#  define yyDecrement(x)	yyStateStackPtr -= x; yyAttrStackPtr -= x;
#  define yySetNT(x)		yyNonterminal = x;
# endif

# ifdef YYNDefault
#  define yytNComb yytComb
# else
#  define yytNComb yyStateRange
# endif

# if defined YYDEBUG | defined YYDCRP
static	long		yyCount		= 0;
static	FILE *		yyTrace		;

static	void		yyPrintState	ARGS ((yyStateRange yyState));
static	void		yyNl		ARGS ((void));

static	char *		yyRule		[] = { 0,
"0_intern : root _EOF_ ",
"root : program ",
"program : identifier block_scoped ",
"block_scoped : 'begin' block_exec 'end' ",
"block_exec : block_exec statement ",
"block_exec : ",
"statement : declaration ';' ",
"statement : assignment ';' ",
"statement : keyword ",
"declaration : 'int' identifier ",
"declaration : 'float' identifier ",
"declaration : 'string' identifier ",
"declaration : 'float' assignment ",
"declaration : 'int' assignment ",
"declaration : 'string' assignment ",
"assignment : identifier '=' computation ",
"computation : computation '+' ttt ",
"computation : computation '-' ttt ",
"computation : ttt ",
"ttt : ttt '*' fff ",
"ttt : ttt '/' fff ",
"ttt : fff ",
"fff : '(' computation ')' ",
"fff : variable ",
"variable : variable_ ",
"variable : '-' variable_ ",
"variable : '+' variable_ ",
"variable_ : identifier ",
"variable_ : string_const ",
"variable_ : int_const ",
"variable_ : float_const ",
"keyword : keyword_if ",
"keyword : keyword_while ",
"keyword : keyword_for ",
"keyword_if : 'if' '(' condition ')' 'then' block_scoped keyword_elseif ",
"keyword_elseif : 'elseif' '(' condition ')' 'then' block_scoped \
keyword_elseif ",
"keyword_elseif : keyword_else ",
"keyword_else : 'else' block_scoped ",
"keyword_else : ",
"keyword_while : 'while' '(' condition ')' block_scoped ",
"keyword_for : 'for' '(' declaration ';' condition ';' assignment ')' \
block_scoped ",
"condition : computation '<' computation ",
"condition : computation '>' computation ",
"condition : computation '=' computation ",
"condition : computation '!=' computation ",
""
};
# endif
	char *		expr_pars_TokenName	[yyLastTerminal + 2] = {
"_EOF_",
"string_const",
"identifier",
"int_const",
"float_const",
"begin",
"int",
"float",
"string",
"=",
"+",
"*",
"(",
")",
"-",
"/",
";",
"if",
"<",
">",
"!=",
"then",
"elseif",
"else",
"while",
"for",
"end",
0,
0,
""
};
static	yytComb		yyTComb		[yyTTableMax + 1] = {
{   3,   70}, {   0,    0}, {  61,  108}, {  52,    6}, {   9,   18}, 
{   8,   17}, {  61,  108}, {  61,  108}, {  61,  108}, {  44,   87}, 
{  44,   87}, {  44,   34}, {   7,   16}, {  44,   87}, {  44,   87}, 
{  44,   35}, {  44,   87}, {  61,  108}, {  44,   87}, {  44,   87}, 
{  44,   87}, {   1,    2}, {  61,   53}, {  61,   54}, {  61,  108}, 
{  61,  108}, {  61,  108}, {  26,   88}, {  26,   88}, {  60,    4}, 
{  48,  114}, {  26,   88}, {  26,   88}, {  48,  114}, {  26,   88}, 
{  41,    4}, {  26,   88}, {  26,   88}, {  26,   88}, {  43,   86}, 
{  43,   86}, {  57,    4}, {  45,  113}, {  43,   86}, {  43,   86}, 
{  45,  113}, {  43,   86}, {   4,   75}, {  43,   86}, {  43,   86}, 
{  43,   86}, {   4,   75}, {   4,   75}, {   4,   75}, {  27,   36}, 
{  27,   32}, {  23,   22}, {   5,    6}, {  23,   23}, {  27,   33}, 
{  23,   24}, {  49,    4}, {   4,   75}, {  27,   37}, {  27,   38}, 
{  27,   39}, {  21,    7}, {  21,    8}, {  21,    9}, {   4,   75}, 
{   4,   75}, {   4,   75}, {   5,   10}, {  22,   67}, {  22,   66}, 
{  22,   68}, {  22,   69}, {  54,    4}, {   2,    4}, {   5,   11}, 
{   5,   12}, {   5,   62}, {  31,   32}, {   6,   15}, {  47,  112}, 
{  31,   65}, {  31,   33}, {  47,  112}, {  25,   85}, {  46,  111}, 
{  10,   19}, {  25,   85}, {  46,  111}, {  12,   21}, {  53,   56}, 
{  11,   20}, {  29,   41}, {  28,   40}, {  58,   59}, {  55,   57}, 
{  16,   79}, {  17,   80}, {  18,   81}, {  30,   42}, {  13,   63}, 
{  50,   52}, {  14,   64}, {  40,   49}, {  59,   60}, {   0,    0}, 
{   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, 
{   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, 
};
static	yytNComb	yyNComb		[yyNTableMax - yyLastTerminal] = {
{   0,    0}, {   1,    3}, {   1,   71}, {   0,    0}, {   0,    0}, 
{   5,   74}, {   5,   13}, {   5,   14}, {  42,   27}, {  37,   46}, 
{  34,   89}, {  34,   93}, {  34,   94}, {   5,   78}, {   5,  101}, 
{  61,  105}, {  61,  106}, {   5,  102}, {   5,  103}, {  42,   50}, 
{  36,   45}, {  36,   26}, {  32,   43}, {  32,   91}, {  38,   47}, 
{  23,   31}, {  39,   48}, {  15,   25}, {  33,   44}, {  19,   28}, 
{  35,   90}, {  56,   58}, {  51,  104}, {  20,   29}, {   9,   84}, 
{   8,   82}, {   7,   83}, {  52,   55}, {  60,   61}, {  41,  109}, 
{  57,  110}, {  49,   51}, {  54,  107}, {   2,   72}, {   4,    5}, 
{  22,   96}, {  21,   30}, {  24,   95}, {   0,    0}, {   0,    0}, 
{   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, 
{   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, {   0,    0}, 
};
static	yytComb *	yyTBasePtr	[yyLastReadState + 1] = { 0,
& yyTComb [  19], & yyTComb [  73], & yyTComb [   0], & yyTComb [  45], 
& yyTComb [  55], & yyTComb [  74], & yyTComb [  10], & yyTComb [   3], 
& yyTComb [   2], & yyTComb [  78], & yyTComb [  83], & yyTComb [  81], 
& yyTComb [  88], & yyTComb [  90], & yyTComb [   0], & yyTComb [  84], 
& yyTComb [  85], & yyTComb [  86], & yyTComb [   0], & yyTComb [   0], 
& yyTComb [  60], & yyTComb [  72], & yyTComb [  46], & yyTComb [   0], 
& yyTComb [  75], & yyTComb [  18], & yyTComb [  45], & yyTComb [  84], 
& yyTComb [  83], & yyTComb [  87], & yyTComb [  72], & yyTComb [   0], 
& yyTComb [   0], & yyTComb [   0], & yyTComb [   0], & yyTComb [   0], 
& yyTComb [   0], & yyTComb [   0], & yyTComb [   0], & yyTComb [  86], 
& yyTComb [  30], & yyTComb [   0], & yyTComb [  30], & yyTComb [   0], 
& yyTComb [  29], & yyTComb [  76], & yyTComb [  71], & yyTComb [  17], 
& yyTComb [  56], & yyTComb [  89], & yyTComb [   0], & yyTComb [   1], 
& yyTComb [  82], & yyTComb [  72], & yyTComb [  86], & yyTComb [   0], 
& yyTComb [  36], & yyTComb [  85], & yyTComb [  87], & yyTComb [  24], 
& yyTComb [   0], 
};
static	yytNComb *	yyNBasePtr	[yyLastReadState + 1] = { 0,
& yyNComb [ -29], & yyNComb [  11], & yyNComb [ -29], & yyNComb [  11], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [   0], & yyNComb [  -1], 
& yyNComb [  -2], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -10], & yyNComb [ -29], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -19], & yyNComb [ -15], 
& yyNComb [  11], & yyNComb [   4], & yyNComb [ -12], & yyNComb [   6], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -16], 
& yyNComb [ -10], & yyNComb [ -29], & yyNComb [  -9], & yyNComb [ -17], 
& yyNComb [ -28], & yyNComb [ -13], & yyNComb [ -11], & yyNComb [ -29], 
& yyNComb [   7], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], 
& yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [ -29], 
& yyNComb [   9], & yyNComb [ -29], & yyNComb [ -12], & yyNComb [   1], 
& yyNComb [ -29], & yyNComb [  10], & yyNComb [ -29], & yyNComb [ -17], 
& yyNComb [   8], & yyNComb [ -29], & yyNComb [ -29], & yyNComb [   6], 
& yyNComb [ -29], 
};
# ifdef YYTDefault
static	unsigned short	yyTDefault	[yyLastReadState + 1] = { 0,
    0,     0,     0,     0,    21,     0,     0,     0,     0,     0, 
    0,     0,     0,     0,    23,    18,    18,     6,    23,    23, 
    0,     0,    22,    22,    45,    44,     0,     0,     0,     0, 
    0,    23,    23,    23,    23,    23,    23,    23,    23,     0, 
    0,    23,    44,     0,    31,    45,    45,    45,     0,     0, 
   61,     0,     0,     0,     0,    23,     0,     0,     0,     0, 
    0, 
};
# endif
# ifdef YYNDefault
static	unsigned short	yyNDefault	[yyLastReadState + 1] = { 0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
    0,     0,     0,     0,    36,     0,     0,     0,    42,    42, 
    0,     0,    36,     0,     0,     0,     0,     0,     0,     0, 
    0,    34,    32,     0,    34,    32,    36,    36,    36,     0, 
    0,    36,     0,     0,     0,     0,     0,     0,     0,     0, 
   61,     0,     0,     0,     0,    42,     0,     0,     0,     0, 
    0, 
};
# endif
# if ! defined NO_RECOVER | defined YYDEC_TABLE | defined YYCSTree
static	unsigned char	yyLength	[yyLastReduceState - yyFirstReduceState
							+ 1] = {
    2,     1,     2,     3,     2,     0,     2,     2,     1,     2, 
    2,     2,     2,     2,     2,     3,     3,     3,     1,     3, 
    3,     1,     3,     1,     1,     2,     2,     1,     1,     1, 
    1,     1,     1,     1,     7,     7,     1,     2,     0,     5, 
    9,     3,     3,     3,     3, 
};
# endif
# if ! defined NO_RECOVER | defined YYDEC_TABLE
static	yytNonterminal	yyLeftHandSide	[yyLastReduceState - yyFirstReduceState
							+ 1] = {
yyNT0_intern,
yyNTroot,
yyNTprogram,
yyNTblock_scoped,
yyNTblock_exec,
yyNTblock_exec,
yyNTstatement,
yyNTstatement,
yyNTstatement,
yyNTdeclaration,
yyNTdeclaration,
yyNTdeclaration,
yyNTdeclaration,
yyNTdeclaration,
yyNTdeclaration,
yyNTassignment,
yyNTcomputation,
yyNTcomputation,
yyNTcomputation,
yyNTttt,
yyNTttt,
yyNTttt,
yyNTfff,
yyNTfff,
yyNTvariable,
yyNTvariable,
yyNTvariable,
yyNTvariable_,
yyNTvariable_,
yyNTvariable_,
yyNTvariable_,
yyNTkeyword,
yyNTkeyword,
yyNTkeyword,
yyNTkeyword_if,
yyNTkeyword_elseif,
yyNTkeyword_elseif,
yyNTkeyword_else,
yyNTkeyword_else,
yyNTkeyword_while,
yyNTkeyword_for,
yyNTcondition,
yyNTcondition,
yyNTcondition,
yyNTcondition,
};
# endif
# ifndef NO_RECOVER
static	yySymbolRange	yyContinuation	[yyLastReadState + 1] = { 0,
    2,     5,     0,     2,    26,     9,     2,     2,     2,    12, 
   12,    12,    16,    16,     4,    16,    16,    16,     4,     4, 
    8,     4,     4,     4,    13,     9,    20,    13,    13,    16, 
   13,     4,     4,     4,     4,     4,     4,     4,     4,    21, 
    5,     4,     9,     9,    13,    13,    13,    13,     5,    16, 
    2,     2,    12,     5,    13,     4,     5,    13,    21,     5, 
    2, 
};
static	unsigned short	yyCondition	[yyLastState - yyLastReduceState + 1] =
{ 0,
};
# endif
static	unsigned short	yyFinalToProd	[yyLastReadReduceState -
						yyFirstReadReduceState + 2] = {
   73,    76,    77,    92,    97,    98,    99,   100, 
0
};
static	unsigned short	yyStartLine	[yyLastStopState - yyFirstReduceState
							+ 2] = { 0,
116,
};
# ifdef YYaccDefault

static	unsigned long *	yyDefaultLook	[yyLastReadState + 1] = { 0,
};
# endif


static	int	yyParse		ARGS ((yyStateRange, yySymbolRange, int));

# ifndef NO_RECOVER
static	yyStateRange yyNext	ARGS ((yyStateRange, yySymbolRange));
#  ifdef YYDEBUG
static	int	yyErrorRecovery	ARGS ((yySymbolRange, yySymbolRange *, long));
#  else
static	int	yyErrorRecovery	ARGS ((yySymbolRange, long));
#  endif
static	void	yyComputeContinuation	ARGS ((long, tSet *));
static	rbool	yyIsContinuation	ARGS ((yySymbolRange, long));
static	void	yyComputeRestartPoints	ARGS ((long, tSet *));
# endif

# if defined YYTrialParse | defined YYReParse | defined YYGetLook

# ifndef yyInitBufferSize
#  define yyInitBufferSize 100
# endif

typedef struct { yySymbolRange	yyToken;
		 expr_scan_tScanAttribute	yyAttribute;
# ifdef YYMemoParse
		 short		yyStart;
# endif
	       } yytBuffer;

static yytBuffer *	yyBuffer	= NULL;
static unsigned long	yyBufferSize	= yyInitBufferSize;
static long		yyBufferNext	= 1;
static long		yyBufferLast	= 1;
static rbool		yyBufferClear	= rtrue;
static unsigned short	yyParseLevel	= 0;

static void yyBufferSet
# ifdef HAVE_ARGS
   (yySymbolRange yyToken)
# else
   (yyToken) yySymbolRange yyToken;
# endif
{
   if (yyBufferNext == yyBufferLast) {
      if (yyBufferClear) yyBufferLast = 0;
      if (++ yyBufferLast >= (long) yyBufferSize) {
	 yyExtendArray ((char * *) & yyBuffer, & yyBufferSize,
			  (unsigned long) sizeof (yytBuffer));
# ifdef YYDEBUG
	 if (expr_pars_Debug) {
	    yyPrintState (0);
	    fprintf (yyTrace, "extend  token buffer from %ld to %ld",
		yyBufferSize / 2, yyBufferSize); yyNl ();
	 }
# endif
      }
      yyBuffer [yyBufferLast].yyToken	= yyToken;
      yyBuffer [yyBufferLast].yyAttribute= expr_scan_Attribute;
# ifdef YYMemoParse
      yyBuffer [yyBufferLast].yyStart	= 0;
# endif
      yyBufferNext = yyBufferLast;
   }
}

static int yyGetToken ARGS ((void))
{
   register yySymbolRange yyToken;

   if (yyBufferNext < yyBufferLast) {
      yyToken = yyBuffer [++ yyBufferNext].yyToken;
      expr_scan_Attribute = yyBuffer [yyBufferNext].yyAttribute;
   } else {
      yyToken = expr_scan_GetToken ();
      if ((yytrial | yybuffer) & yyControl.yyMode) {
	 if (++ yyBufferLast >= (long) yyBufferSize) {
	    yyExtendArray ((char * *) & yyBuffer, & yyBufferSize,
			     (unsigned long) sizeof (yytBuffer));
# ifdef YYDEBUG
	    if (expr_pars_Debug) {
	       yyPrintState (0);
	       fprintf (yyTrace, "extend  token buffer from %ld to %ld",
		  yyBufferSize / 2, yyBufferSize); yyNl ();
	    }
# endif
	 }
	 yyBuffer [yyBufferLast].yyToken = yyToken;
	 yyBuffer [yyBufferLast].yyAttribute = expr_scan_Attribute;
# ifdef YYMemoParse
	 yyBuffer [yyBufferLast].yyStart = 0;
# endif
	 yyBufferNext = yyBufferLast;
      }
   }
# ifdef TOKENOP
   TOKENOP
# endif
   return yyToken;
}

# else
# define yyGetToken expr_scan_GetToken
# endif

# ifdef YYGetLook

static int yyGetLookahead
# ifdef HAVE_ARGS
   (int yyk, yySymbolRange yyToken)
# else
   (yyk, yyToken) int yyk; yySymbolRange yyToken;
# endif
{
   if (yyk == 0) return yyToken;
   if (yyControl.yyMode == yystandard) yyBufferSet (yyToken);
   while (yyBufferNext + yyk > yyBufferLast) {
      if (yyBufferNext < yyBufferLast &&
	 yyBuffer [yyBufferLast].yyToken == expr_scan_EofToken)
	 return expr_scan_EofToken;
      if (++ yyBufferLast >= (long) yyBufferSize) {
	 yyExtendArray ((char * *) & yyBuffer, & yyBufferSize,
			  (unsigned long) sizeof (yytBuffer));
# ifdef YYDEBUG
	 if (expr_pars_Debug) {
	    yyPrintState (0);
	    fprintf (yyTrace, "extend  token buffer from %ld to %ld",
		yyBufferSize / 2, yyBufferSize); yyNl ();
	 }
# endif
      }
      yyBuffer [yyBufferLast].yyToken = expr_scan_GetToken ();
      yyBuffer [yyBufferLast].yyAttribute = expr_scan_Attribute;
# ifdef YYMemoParse
      yyBuffer [yyBufferLast].yyStart = 0;
# endif
   }
   expr_scan_Attribute = yyBuffer [yyBufferNext].yyAttribute;
   return yyBuffer [yyBufferNext + yyk].yyToken;
}

static void xxGetAttribute
# ifdef HAVE_ARGS
   (int yyk, yySymbolRange yyToken, expr_scan_tScanAttribute * yyAttribute)
# else
   (yyk, yyToken, yyAttribute)
   int yyk; yySymbolRange yyToken; expr_scan_tScanAttribute * yyAttribute;
# endif
{
   if (yyk == 0) * yyAttribute = expr_scan_Attribute;
   else {
      yyGetLookahead (yyk, yyToken);
      * yyAttribute =
	 yyBuffer [Min (yyBufferNext + yyk, yyBufferLast)].yyAttribute;
   }
}

# endif

# ifdef YYReParse

#  define BufferOn(Actions, Messages) yyBufferOn (Actions, Messages, yyTerminal)
#  define BufferPosition yyBufferNext

static yytControl yyPrevControl;

static long yyBufferOn
# ifdef HAVE_ARGS
   (rbool yyActions, rbool yyMessages, yySymbolRange yyToken)
# else
   (yyActions, yyMessages, yyToken)
   rbool yyActions, yyMessages; yySymbolRange yyToken;
# endif
{
   if (yyControl.yyMode == yystandard) {
      yyPrevControl		= yyControl;
      yyControl.yyMode		= yybuffer;
      yyControl.yyActions	= yyActions;
      yyControl.yyMessages	= yyMessages;
      yyBufferSet (yyToken);
      yyBufferClear		= rfalse;
   }
   return yyBufferNext;
}

static long BufferOff ARGS ((void))
{
   if (yyControl.yyMode == yybuffer) yyControl = yyPrevControl;
   return yyBufferNext;
}

static void BufferClear ARGS ((void))
{
   yyBufferClear = rtrue;
}

# endif

# if defined YYDEBUG | defined YYDCRP

static void yyNl ARGS ((void)) { putc ('\n', yyTrace); fflush (yyTrace); }

# endif

# ifdef YYDEBUG

static void yyPrintState
# ifdef HAVE_ARGS
   (yyStateRange yyState)
# else
   (yyState) yyStateRange yyState;
# endif
{
   fprintf (yyTrace, "%4ld:", ++ yyCount);
   WritePosition  (yyTrace, expr_scan_Attribute.Position);
   fprintf (yyTrace, ":%5d  %c  ", yyState, " ST-B---R" [yyControl.yyMode]);
# if defined YYTrialParse | defined YYReParse
   if (yyParseLevel > 0) {
      register int yyi = yyParseLevel;
      fprintf (yyTrace, "%2d  ", yyi);
      do fputs ("  ", yyTrace); while (-- yyi);
   } else
# endif
   fputs ("    ", yyTrace);
}

static rbool yyPrintResult
# ifdef HAVE_ARGS
   (yyStateRange yyState, int yyLine, rbool yyCondition)
# else
   (yyState, yyLine, yyCondition)
   yyStateRange	yyState;
   int		yyLine;
   rbool	yyCondition;
# endif
{
   if (expr_pars_Debug) {
      yyPrintState (yyState);
      fprintf (yyTrace, "check   predicate in line %d, result = %d",
	 yyLine, yyCondition); yyNl ();
   }
   return yyCondition;
}

# else
#  define yyPrintResult(State, Line, Condition) Condition
# endif

# if defined YYDEBUG | defined YYDEC_TABLE
#  define yyGotoReduce(State, Rule)	{ yyState = State; goto yyReduce; }
#  define yyGotoRead(State)		{ yyState = State; goto yyRead; }
# else
#  define yyGotoReduce(State, Rule)	goto Rule;
#  define yyGotoRead(State)		{ yyState = State; goto yyRead; }
# endif

static unsigned long	yyStateStackSize	= yyInitStackSize;
static yyStateRange *	yyStateStack		= NULL;
static yyStateRange *	yyEndOfStack		;
static unsigned long	yyAttrStackSize		= yyInitStackSize;
static tParsAttribute * yyAttributeStack	= NULL;
# if defined YYTrialParse | defined YYReParse
static yyStateRange *	yyStateStackPtr		;
static tParsAttribute * yyAttrStackPtr		;
# endif
# ifndef NO_RECOVER
static yyStateRange *	yyIsContStackPtr	= NULL;
static unsigned long	yyIsContStackSize	= yyInitStackSize;
static yyStateRange *	yyCompResStackPtr	= NULL;
static unsigned long	yyCompResStackSize	= yyInitStackSize;
# endif

void Resetexpr_pars ARGS ((void))
   {
      if (yyStateStack) {
	 ReleaseArray ((char * *) & yyStateStack, & yyStateStackSize,
			(unsigned long) sizeof (yyStateRange));
	 yyStateStack = NULL;
      }
      if (yyAttributeStack) {
	 ReleaseArray ((char * *) & yyAttributeStack, & yyAttrStackSize,
			(unsigned long) sizeof (tParsAttribute));
	 yyAttributeStack = NULL;
      }
# ifndef NO_RECOVER
      if (yyIsContStackPtr) {
	 ReleaseArray ((char * *) & yyIsContStackPtr, & yyIsContStackSize,
			(unsigned long) sizeof (yyStateRange));
	 yyIsContStackPtr = NULL;
      }
      if (yyCompResStackPtr) {
	 ReleaseArray ((char * *) & yyCompResStackPtr, & yyCompResStackSize,
			(unsigned long) sizeof (yyStateRange));
	 yyCompResStackPtr = NULL;
      }
# endif
# if defined YYTrialParse | defined YYReParse | defined YYGetLook
      if (yyBuffer) {
	 ReleaseArray ((char * *) & yyBuffer, & yyBufferSize,
			(unsigned long) sizeof (yytBuffer));
	 yyBuffer = NULL;
      }
# endif
   }

int expr_pars ARGS ((void))
   {
      return expr_pars2 (yyStartState);
   }

int expr_pars2
# ifdef HAVE_ARGS
   (int yyStartSymbol)
# else
   (yyStartSymbol) int yyStartSymbol;
# endif
   {
      int		yyErrorCount;
# if defined YYDEBUG | defined YYDCRP
      yyTrace		= stdout;
# endif
      Beginexpr_pars ();
      yyStateStackSize	= yyInitStackSize;
      yyMakeArray ((char * *) & yyStateStack, & yyStateStackSize,
		     (unsigned long) sizeof (yyStateRange));
      yyAttrStackSize	= yyInitStackSize;
      yyMakeArray ((char * *) & yyAttributeStack, & yyAttrStackSize,
		     (unsigned long) sizeof (tParsAttribute));
# ifndef NO_RECOVER
      yyIsContStackSize	= yyInitStackSize;
      yyMakeArray ((char * *) & yyIsContStackPtr, & yyIsContStackSize,
		     (unsigned long) sizeof (yyStateRange));
      yyCompResStackSize= yyInitStackSize;
      yyMakeArray ((char * *) & yyCompResStackPtr, & yyCompResStackSize,
		     (unsigned long) sizeof (yyStateRange));
# endif
# if defined YYTrialParse | defined YYReParse | defined YYGetLook
      yyBufferSize	= yyInitBufferSize;
      yyMakeArray ((char * *) & yyBuffer, & yyBufferSize,
		     (unsigned long) sizeof (yytBuffer));
# endif
      yyEndOfStack	= & yyStateStack [yyStateStackSize - 1];
# if defined YYTrialParse | defined YYReParse
      yyStateStackPtr	= yyStateStack;
      yyAttrStackPtr	= yyAttributeStack;
      yyBufferNext	= 1;
      yyBufferLast	= 1;
      yyBufferClear	= rtrue;
      yyParseLevel	= 0;
# endif
# ifdef YYDEBUG
      if (expr_pars_Debug) {
	 yyCount = 0;
	 fprintf (yyTrace,
      "  # |Position|State|Mod|Lev|Action |Terminal and Lookahead or Rule\n");
	 yyNl ();
      }
# endif
      yyControl.yyMode		= yystandard;
      yyControl.yyActions	= rtrue;
      yyControl.yyMessages	= rtrue;
      yyErrorCount = yyParse ((yyStateRange) yyStartSymbol,
	 (yySymbolRange) yyGetToken (), (int) yyStartLine [yyStartSymbol]);
      Resetexpr_pars ();
      return yyErrorCount;
   }

# ifdef YYTrialParse

# ifdef YYMemoParse
#  define MemoryClear(Position) yyBuffer [Position].yyStart = 0
# endif

static int yyTrialParse
# ifdef HAVE_ARGS
   (yyStateRange yyStartSymbol, yySymbolRange yyToken, int yyLine)
# else
   (yyStartSymbol, yyToken, yyLine)
   yyStateRange		yyStartSymbol	;
   yySymbolRange	yyToken		;
   int			yyLine		;
# endif
   {
      int	yyErrorCount		;
      ptrdiff_t	yyPrevStateStackPtr	= yyStateStackPtr - yyStateStack;
      ptrdiff_t	yyPrevAttrStackPtr	= yyAttrStackPtr - yyAttributeStack;
      long	yyPrevBufferNext	;
      yytControl yyPrevControl		;

# ifdef BEFORE_TRIAL
      BEFORE_TRIAL
# endif
# ifdef YYMemoParse
      if (yyBuffer [yyBufferNext].yyStart ==   yyStartSymbol) return 0;
      if (yyBuffer [yyBufferNext].yyStart == - yyStartSymbol) return 1;
# endif
      yyPrevControl		= yyControl;
      yyStateStackPtr		++;
      yyAttrStackPtr		++;
      yyParseLevel		++;
      if (yyControl.yyMode == yystandard) yyBufferSet (yyToken);
      yyPrevBufferNext		= yyBufferNext;
      yyControl.yyMode		= yytrial;
      yyControl.yyActions	= rfalse;
      yyControl.yyMessages	= rfalse;
      yyErrorCount		= yyParse (yyStartSymbol, yyToken, yyLine);
# ifdef YYMemoParse
      yyBuffer [yyPrevBufferNext].yyStart = yyErrorCount ?
					- yyStartSymbol : yyStartSymbol;
# endif
      yyStateStackPtr		= yyStateStack + yyPrevStateStackPtr;
      yyAttrStackPtr		= yyAttributeStack + yyPrevAttrStackPtr;
      yyBufferNext		= yyPrevBufferNext;
      yyControl			= yyPrevControl;
      yyParseLevel		--;
      expr_scan_Attribute		= yyBuffer [yyBufferNext].yyAttribute;
# ifdef AFTER_TRIAL
      AFTER_TRIAL
# endif
      return yyErrorCount;
   }

# endif

# ifdef YYReParse

static int ReParse
# ifdef HAVE_ARGS
   (yyStateRange yyStartSymbol, int yyFrom, int yyTo, rbool yyActions,
      rbool yyMessages)
# else
   (yyStartSymbol, yyFrom, yyTo, yyActions, yyMessages)
   yyStateRange	yyStartSymbol		;
   int		yyFrom, yyTo		;
   rbool	yyActions, yyMessages	;
# endif
   {
      int yyErrorCount = 1;

      if (1 <= yyFrom && yyFrom <= yyTo && yyTo <= yyBufferLast) {
	 ptrdiff_t yyPrevStateStackPtr	= yyStateStackPtr - yyStateStack;
	 ptrdiff_t yyPrevAttrStackPtr	= yyAttrStackPtr - yyAttributeStack;
	 long	yyPrevBufferNext	= yyBufferNext;
	 int	yyToToken		= yyBuffer [yyTo].yyToken;
	 yytControl yyPrevControl	;

	 yyPrevControl		= yyControl;
	 yyStateStackPtr	++;
	 yyAttrStackPtr		++;
	 yyParseLevel		++;
	 yyBufferNext		= yyFrom - 1;
	 yyBuffer [yyTo].yyToken= expr_scan_EofToken;
	 yyControl.yyMode	= yyreparse;
	 yyControl.yyActions	= yyActions;
	 yyControl.yyMessages	= yyMessages;
	 yyErrorCount		= yyParse (yyStartSymbol,
	    (yySymbolRange) yyGetToken (), (int) yyStartLine [yyStartSymbol]);
	 yyStateStackPtr	= yyStateStack + yyPrevStateStackPtr;
	 yyAttrStackPtr		= yyAttributeStack + yyPrevAttrStackPtr;
	 yyBufferNext		= yyPrevBufferNext;
	 yyControl		= yyPrevControl;
	 yyParseLevel		--;
	 yyBuffer [yyTo].yyToken= yyToToken;
	 expr_scan_Attribute		= yyBuffer [yyBufferNext].yyAttribute;
      } else {
      ErrorMessage (xxInvalidCallOfReParse, xxError, expr_scan_Attribute.Position);
      }
      return yyErrorCount;
   }

# endif

static char * yyGetTokenName
# ifdef HAVE_ARGS
   (yySymbolRange yyTerminal)
# else
   (yyTerminal) yySymbolRange yyTerminal;
# endif
   {
      if (yyTerminal <= yyLastTerminal && expr_pars_TokenName [yyTerminal])
	 return expr_pars_TokenName [yyTerminal];
      else
	 return "_unknown_";
   }

static void yyExtendStack
# ifdef HAVE_ARGS
   (yyStateRange * *	yyStateStackPtr,
    tParsAttribute * *	yyAttrStackPtr,
    yyStateRange	yyState)
# else
   (yyStateStackPtr, yyAttrStackPtr, yyState)
   yyStateRange * *	yyStateStackPtr;
   tParsAttribute * *	yyAttrStackPtr;
   yyStateRange		yyState;
# endif
   {
      ptrdiff_t yyyStateStackPtr = * yyStateStackPtr - yyStateStack;
      ptrdiff_t yyyAttrStackPtr = * yyAttrStackPtr - yyAttributeStack;
      yyExtendArray ((char * *) & yyStateStack, & yyStateStackSize,
		       (unsigned long) sizeof (yyStateRange));
      yyExtendArray ((char * *) & yyAttributeStack, & yyAttrStackSize,
		       (unsigned long) sizeof (tParsAttribute));
      * yyStateStackPtr	= yyStateStack + yyyStateStackPtr;
      * yyAttrStackPtr	= yyAttributeStack + yyyAttrStackPtr;
      yyEndOfStack	= & yyStateStack [yyStateStackSize - 1];
# ifdef YYDEBUG
      if (expr_pars_Debug) {
	 yyPrintState (yyState);
	 fprintf (yyTrace, "extend  stack from %ld to %ld",
	    yyStateStackSize / 2, yyStateStackSize); yyNl ();
      }
# endif
   }

static int yyParse
# ifdef HAVE_ARGS
   (yyStateRange yyStartSymbol, yySymbolRange yyToken, int yyLine)
# else
   (yyStartSymbol, yyToken, yyLine)
   yyStateRange		yyStartSymbol	;
   yySymbolRange	yyToken		;
   int			yyLine		;
# endif
   {
      register	yyStateRange	yyState		= yyStartSymbol;
      register	yySymbolRange	yyTerminal	= yyToken;
      register	rbool		yyIsRepairing	= rfalse;
		tParsAttribute	yySynAttribute	;   /* synthesized attribute */
		int		yyErrorCount	= 0;
# if ! (defined YYTrialParse | defined YYReParse)
		yyStateRange *	yyStateStackPtr	= yyStateStack;
		tParsAttribute *yyAttrStackPtr	= yyAttributeStack;
# endif
# ifdef YYDEBUG
		long		yyStartCount	= yyCount + 1;
		yySymbolRange	yyPrevTerminal	= yyToken;
# endif
# ifdef YYGetLook
		yySymbolRange	yy2;
# endif

/* line 69 "expr_pars.lrk" */


/* line 1054 "expr_pars.c" */

# ifdef YYDEBUG
      if (expr_pars_Debug) {
	 yyPrintState (yyStartSymbol);
	 fprintf (yyTrace, "parse   for predicate in line %d, lookahead: %s",
	    yyLine, yyGetTokenName (yyTerminal)); yyNl ();
      }
# endif

      memset (& yySynAttribute, 0, sizeof yySynAttribute);

      for (;;) {
	 if (yyStateStackPtr >= yyEndOfStack) {
	    yyExtendStack (& yyStateStackPtr, & yyAttrStackPtr, yyState);
	 }
	 * yyStateStackPtr = yyState;

	 for (;;) { /* SPEC State = Next (State, Terminal); terminal transit */
	    register yytComb * yyTCombPtr = yyTBasePtr [yyState] + yyTerminal;
# if defined YYTDefault & defined YYaccDefault
	    register unsigned long * yylp;
# endif
	    if (yyTCombPtr->Check == yyState) {
	       yyState = yyTCombPtr->Next; break;
	    }
# ifdef YYTDefault
#  ifdef YYaccDefault
	    if ((yylp = yyDefaultLook [yyState]) &&
	       (yylp [yyTerminal >> 5] >> (yyTerminal & 0x1f)) & 1) {
	       yyState = yyTDefault [yyState]; break;
	    }
	    yyState = yyNoState; break;
#  else
	    if ((yyState = yyTDefault [yyState]) == yyNoState) break;
#  endif
# endif
	 }

	 if (yyState == yyNoState ||			/* syntax error ? */
	    yyIsRepairing && yyState >= yyFirstReduceState) { /* repair mode */
	    yySymbolRange yyRepairToken;

	    if (yyState == yyNoState && ! yyIsRepairing) { /* syntax error */
# ifdef ERROR
	       for (;;) {		/* be compatible with error trick */
		  yySymbolRange yyyTerminal = (yySymbolRange) yyTerminal;
		  ERROR
		  goto yyRecover;
	       }
	       goto yyFinal;
   yyRecover:
# endif
# ifdef ERROR2
	       ERROR2
# endif
# ifdef YYTrialParse
	       if (yyControl.yyMode == yytrial) YYABORT;
# endif
# ifndef NO_RECOVER
	       yyErrorCount ++;				/* report and recover */
	       yyTerminal = yyErrorRecovery (yyTerminal,
#  ifdef YYDEBUG
			& yyPrevTerminal,
#  endif
			(long) (yyStateStackPtr - yyStateStack));
	       yyIsRepairing = rtrue;
	       yyState = * yyStateStackPtr;
	       continue;
# else
	       YYABORT;
# endif
	    }

# ifndef NO_RECOVER
	/* SPEC State = Next (Top (), Continuation [yyState]); repair transit */
	    yyState = * yyStateStackPtr;
	    yyRepairToken = yyContinuation [yyState];	/* repair */
	    yyState = yyNext (yyState, yyRepairToken);
	    if (yyState > yyLastReduceState) {		/* dynamic ? */
	       yyState = yyCondition [yyState - yyLastReduceState];
	    }
	    if (yyState <= yyLastReadReduceState) { /* read or read reduce ? */
	       expr_scan_tScanAttribute yyRepairAttribute;
	       expr_scan_ErrorAttribute ((int) yyRepairToken, & yyRepairAttribute);
	       if (yyControl.yyMessages)
		  ErrorMessageI (xxTokenInserted, xxRepair,
		     expr_scan_Attribute.Position, xxString,
		     yyGetTokenName (yyRepairToken));
#  ifdef YYDEBUG
	       if (expr_pars_Debug) {
		  yyPrintState (* yyStateStackPtr);
		  fprintf (yyTrace, "insert  %s",
		     yyGetTokenName (yyRepairToken)); yyNl ();
		  yyPrintState (* yyStateStackPtr);
		  fprintf (yyTrace, "shift   %s, lookahead: %s",
		     yyGetTokenName (yyRepairToken),
		     yyGetTokenName (yyTerminal)); yyNl ();
	       }
#  endif
	       if (yyStateStackPtr >= yyEndOfStack) {
		  yyExtendStack (& yyStateStackPtr, & yyAttrStackPtr, yyState);
	       }
	       yyStateStackPtr ++;
	       yyGetAttribute (yyAttrStackPtr ++, yyRepairAttribute);
	       if (yyState >= yyFirstFinalState) {	/* read reduce */
		  * yyStateStackPtr = yyStateStackPtr [-1];
		  yyState = yyFinalToProd [yyState - yyFirstReadReduceState];
	       } else {					/* read */
		  * yyStateStackPtr = yyState;
	       }
	    }
	    if (yyState <= yyLastReadState) continue;	/* read ? */
# endif
	 }

   yyFinal:
	 if (yyState >= yyFirstFinalState) {		/* final state ? */
	    if (yyState <= yyLastReadReduceState) {	/* read reduce ? */
	       yyStateStackPtr ++;
	       yyGetAttribute (yyAttrStackPtr ++, expr_scan_Attribute);
	       yyTerminal = yyGetToken ();
# ifdef YYDEBUG
	       if (expr_pars_Debug) {
		  yyStateStackPtr [0] = yyStateStackPtr [-1];
		  yyPrintState (* yyStateStackPtr);
		  fprintf (yyTrace, "shift   %s, lookahead: %s",
		     yyGetTokenName (yyPrevTerminal),
		     yyGetTokenName (yyTerminal)); yyNl ();
		  yyPrevTerminal = yyTerminal;
	       }
# endif
	       yyIsRepairing = rfalse;
	    }

	    for (;;) {
	       register yytNonterminal yyNonterminal;	/* left-hand side */

   yyReduce:
# ifdef YYDEBUG
	       if (expr_pars_Debug) {
		  if (yyState <= yyLastReadReduceState)	/* read reduce ? */
		     yyState = yyFinalToProd [yyState - yyFirstReadReduceState];
		  yyPrintState (* yyStateStackPtr);
		  if (yyState <= yyLastReduceState) {
		     fprintf (yyTrace, "reduce  %s",
			yyRule [yyState - yyLastReadReduceState]); yyNl ();
		  } else {
		     fprintf (yyTrace, "dynamic decision %d",
			yyState - yyLastReduceState); yyNl ();
		  }
	       }
# endif
# ifdef YYCSTree
	       if (yyControl.yyActions) {
		 yyStateRange yystate = yyState;
		 if (yystate <= yyLastReadReduceState) { /* read reduce ? */
		   yystate = yyFinalToProd [yystate - yyFirstReadReduceState];
		 }
		 if (yystate <= yyLastStopState) {		/* accept */
		   CSTree = NewNonterminal (yystate - yyLastReadReduceState,
		     yyAttrStackPtr [-1].Common.Tree);
		 } else if (yystate <= yyLastReduceState) {	/* reduce */
		   int yyrule = yystate - yyLastReadReduceState;
		   int yyleng = yyLength [yyrule - 1], i;
		   tCSTree yynode = NULL, yynext = NULL;
		   for (i = yyleng - 1; i >= 0; i --) {
		     unsigned short yysymbol = yyRules [yyrule] [i];
		     tParsAttribute * yyap = & yyAttrStackPtr [i - yyleng];
		     if (yysymbol < yyEpsilon) {		/* terminal */
		       yynode = NewTerminal (yyap->Scan.Position,
			 StGetCStr (yyap->Scan.Common.Text));
		     } else {					/* nonterminal*/
		       yynode = yyap->Common.Tree;
		     }
		     yynode->Next = yynext;
		     if (yynext) yynext->Previous = yynode;
		     yynext = yynode;
		   }
		   yySynAttribute.Common.Tree = NewNonterminal (yyrule, yynode);
		 }
	       }
# endif
# ifdef YYDEC_TABLE
	       if (yyLastStopState < yyState && yyState <= yyLastReduceState) {
		  register int yyd = yyLength [yyState - yyFirstReduceState];
		  yyStateStackPtr -= yyd;
		  yyAttrStackPtr  -= yyd;
		  yyNonterminal = yyLeftHandSide [yyState - yyFirstReduceState];
	       }
# endif
switch (yyState) {
case 70:
YYACCEPT;
case 71: /* root : program */
yyDecrement (1) yySetNT (yyNTroot) {
/* line 116 "expr_pars.lrk" */

/* line 37 "expr.pars" */
{  TreeRoot = ReverseTree (yyA [0].program.tree);; }
/* line 1254 "expr_pars.c" */
} break;
case 72: /* program : identifier block_scoped */
yyDecrement (2) yySetNT (yyNTprogram) {
/* line 40 "expr.pars" */

yyS.program.tree = mprogram (yyA [0].Scan.Position, yyA [0].Scan.identifier.Ident, yyA [1].block_scoped.tree);
/* line 1261 "expr_pars.c" */
} break;
case 73:
case 62: /* block_scoped : 'begin' block_exec 'end' */
yyDecrement (3) yySetNT (yyNTblock_scoped) {
/* line 45 "expr.pars" */

/* line 127 "expr_pars.lrk" */
yyS.block_scoped.tree = yyA [1].block_exec.tree;

/* line 1271 "expr_pars.c" */
} break;
case 74: /* block_exec : block_exec statement */
yyDecrement (2) yySetNT (yyNTblock_exec) {
/* line 49 "expr.pars" */

yyS.block_exec.tree = mblocklist (yyA [0].block_exec.tree, yyA [1].statement.tree);
/* line 1278 "expr_pars.c" */
} break;
case 75: /* block_exec : */
yySetNT (yyNTblock_exec) {
/* line 51 "expr.pars" */

yyS.block_exec.tree = mblocknostmt ();
/* line 1285 "expr_pars.c" */
} break;
case 76:
case 63: /* statement : declaration ';' */
yyDecrement (2) yySetNT (yyNTstatement) {
/* line 56 "expr.pars" */

yyS.statement.tree = mdeclaration (yyA [0].declaration.tree);
/* line 1293 "expr_pars.c" */
} break;
case 77:
case 64: /* statement : assignment ';' */
yyDecrement (2) yySetNT (yyNTstatement) {
/* line 58 "expr.pars" */

yyS.statement.tree = massignment (yyA [0].assignment.tree);
/* line 1301 "expr_pars.c" */
} break;
case 78: /* statement : keyword */
yyDecrement (1) yySetNT (yyNTstatement) {
/* line 60 "expr.pars" */

yyS.statement.tree = mkeyword (yyA [0].keyword.tree);
/* line 1308 "expr_pars.c" */
} break;
case 79: /* declaration : 'int' identifier */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 65 "expr.pars" */

yyS.declaration.tree = mdecl_ident (yyA [0].Scan.Position, 'int', yyA [1].Scan.identifier.Ident);
/* line 1315 "expr_pars.c" */
} break;
case 80: /* declaration : 'float' identifier */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 67 "expr.pars" */

yyS.declaration.tree = mdecl_ident (yyA [0].Scan.Position, 'float', yyA [1].Scan.identifier.Ident);
/* line 1322 "expr_pars.c" */
} break;
case 81: /* declaration : 'string' identifier */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 69 "expr.pars" */

yyS.declaration.tree = mdecl_ident (yyA [0].Scan.Position, 'string', yyA [1].Scan.identifier.Ident);
/* line 1329 "expr_pars.c" */
} break;
case 82: /* declaration : 'float' assignment */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 71 "expr.pars" */

yyS.declaration.tree = mdecl_assignm (yyA [0].Scan.Position, 'float', yyA [1].assignment.tree);
/* line 1336 "expr_pars.c" */
} break;
case 83: /* declaration : 'int' assignment */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 73 "expr.pars" */

yyS.declaration.tree = mdecl_assignm (yyA [0].Scan.Position, 'int', yyA [1].assignment.tree);
/* line 1343 "expr_pars.c" */
} break;
case 84: /* declaration : 'string' assignment */
yyDecrement (2) yySetNT (yyNTdeclaration) {
/* line 75 "expr.pars" */

yyS.declaration.tree = mdecl_assignm (yyA [0].Scan.Position, 'string', yyA [1].assignment.tree);
/* line 1350 "expr_pars.c" */
} break;
case 85: /* assignment : identifier '=' computation */
yyDecrement (3) yySetNT (yyNTassignment) {
/* line 80 "expr.pars" */

yyS.assignment.tree = massign (yyA [0].Scan.Position, yyA [0].Scan.identifier.Ident, yyA [2].computation.tree);
/* line 1357 "expr_pars.c" */
} break;
case 86: /* computation : computation '+' ttt */
yyDecrement (3) yySetNT (yyNTcomputation) {
/* line 85 "expr.pars" */

yyS.computation.tree = mbinary_comp (yyA [1].Scan.Position, '+', yyA [0].computation.tree, yyA [2].ttt.tree);
/* line 1364 "expr_pars.c" */
} break;
case 87: /* computation : computation '-' ttt */
yyDecrement (3) yySetNT (yyNTcomputation) {
/* line 87 "expr.pars" */

yyS.computation.tree = mbinary_comp (yyA [1].Scan.Position, '-', yyA [0].computation.tree, yyA [2].ttt.tree);
/* line 1371 "expr_pars.c" */
} break;
case 88: /* computation : ttt */
yyDecrement (1) yySetNT (yyNTcomputation) {
/* line 89 "expr.pars" */

/* line 169 "expr_pars.lrk" */
yyS.computation.tree = yyA [0].ttt.tree;

/* line 1380 "expr_pars.c" */
} break;
case 89: /* ttt : ttt '*' fff */
yyDecrement (3) yySetNT (yyNTttt) {
/* line 93 "expr.pars" */

yyS.ttt.tree = mbinary_comp (yyA [1].Scan.Position, '*', yyA [0].ttt.tree, yyA [2].fff.tree);
/* line 1387 "expr_pars.c" */
} break;
case 90: /* ttt : ttt '/' fff */
yyDecrement (3) yySetNT (yyNTttt) {
/* line 95 "expr.pars" */

yyS.ttt.tree = mbinary_comp (yyA [1].Scan.Position, '/', yyA [0].ttt.tree, yyA [2].fff.tree);
/* line 1394 "expr_pars.c" */
} break;
case 91: /* ttt : fff */
yyDecrement (1) yySetNT (yyNTttt) {
/* line 97 "expr.pars" */

/* line 179 "expr_pars.lrk" */
yyS.ttt.tree = yyA [0].fff.tree;

/* line 1403 "expr_pars.c" */
} break;
case 92:
case 65: /* fff : '(' computation ')' */
yyDecrement (3) yySetNT (yyNTfff) {
/* line 101 "expr.pars" */

/* line 185 "expr_pars.lrk" */
yyS.fff.tree = yyA [1].computation.tree;

/* line 1413 "expr_pars.c" */
} break;
case 93: /* fff : variable */
yyDecrement (1) yySetNT (yyNTfff) {
/* line 102 "expr.pars" */

/* line 191 "expr_pars.lrk" */
yyS.fff.tree = yyA [0].variable.tree;

/* line 1422 "expr_pars.c" */
} break;
case 94: /* variable : variable_ */
yyDecrement (1) yySetNT (yyNTvariable) {
/* line 106 "expr.pars" */

/* line 197 "expr_pars.lrk" */
yyS.variable.tree = yyA [0].variable_.tree;

/* line 1431 "expr_pars.c" */
} break;
case 95: /* variable : '-' variable_ */
yyDecrement (2) yySetNT (yyNTvariable) {
/* line 107 "expr.pars" */

yyS.variable.tree = munary_comp (yyA [0].Scan.Position, '-', yyA [1].variable_.tree);
/* line 1438 "expr_pars.c" */
} break;
case 96: /* variable : '+' variable_ */
yyDecrement (2) yySetNT (yyNTvariable) {
/* line 109 "expr.pars" */

yyS.variable.tree = munary_comp (yyA [0].Scan.Position, '+', yyA [1].variable_.tree);
/* line 1445 "expr_pars.c" */
} break;
case 97:
case 66: /* variable_ : identifier */
yyDecrement (1) yySetNT (yyNTvariable_) {
/* line 114 "expr.pars" */

yyS.variable_.tree = midentifier (yyA [0].Scan.Position, yyA [0].Scan.identifier.Ident);
/* line 1453 "expr_pars.c" */
} break;
case 98:
case 67: /* variable_ : string_const */
yyDecrement (1) yySetNT (yyNTvariable_) {
/* line 116 "expr.pars" */

yyS.variable_.tree = mstring_const (yyA [0].Scan.Position, yyA [0].Scan.string_const.Value);
/* line 1461 "expr_pars.c" */
} break;
case 99:
case 68: /* variable_ : int_const */
yyDecrement (1) yySetNT (yyNTvariable_) {
/* line 118 "expr.pars" */

yyS.variable_.tree = mint_const (yyA [0].Scan.Position, yyA [0].Scan.int_const.Value);
/* line 1469 "expr_pars.c" */
} break;
case 100:
case 69: /* variable_ : float_const */
yyDecrement (1) yySetNT (yyNTvariable_) {
/* line 120 "expr.pars" */

yyS.variable_.tree = mfloat_const (yyA [0].Scan.Position, yyA [0].Scan.float_const.Value);
/* line 1477 "expr_pars.c" */
} break;
case 101: /* keyword : keyword_if */
yyDecrement (1) yySetNT (yyNTkeyword) {
/* line 125 "expr.pars" */

/* line 219 "expr_pars.lrk" */
yyS.keyword.tree = yyA [0].keyword_if.tree;

/* line 1486 "expr_pars.c" */
} break;
case 102: /* keyword : keyword_while */
yyDecrement (1) yySetNT (yyNTkeyword) {
/* line 126 "expr.pars" */

/* line 225 "expr_pars.lrk" */
yyS.keyword.tree = yyA [0].keyword_while.tree;

/* line 1495 "expr_pars.c" */
} break;
case 103: /* keyword : keyword_for */
yyDecrement (1) yySetNT (yyNTkeyword) {
/* line 127 "expr.pars" */

/* line 231 "expr_pars.lrk" */
yyS.keyword.tree = yyA [0].keyword_for.tree;

/* line 1504 "expr_pars.c" */
} break;
case 104: /* keyword_if : 'if' '(' condition ')' 'then' block_scoped \
keyword_elseif */
yyDecrement (7) yySetNT (yyNTkeyword_if) {
/* line 131 "expr.pars" */

yyS.keyword_if.tree = mkeyword_if(yyA [2].condition.tree, yyA [5].block_scoped.tree, yyA [6].keyword_elseif.tree);
/* line 1512 "expr_pars.c" */
} break;
case 105: /* keyword_elseif : 'elseif' '(' condition ')' 'then' \
block_scoped keyword_elseif */
yyDecrement (7) yySetNT (yyNTkeyword_elseif) {
/* line 136 "expr.pars" */

yyS.keyword_elseif.tree = mkeyword_if(yyA [2].condition.tree, yyA [5].block_scoped.tree, yyA [6].keyword_elseif.tree);
/* line 1520 "expr_pars.c" */
} break;
case 106: /* keyword_elseif : keyword_else */
yyDecrement (1) yySetNT (yyNTkeyword_elseif) {
/* line 138 "expr.pars" */

/* line 243 "expr_pars.lrk" */
yyS.keyword_elseif.tree = yyA [0].keyword_else.tree;

/* line 1529 "expr_pars.c" */
} break;
case 107: /* keyword_else : 'else' block_scoped */
yyDecrement (2) yySetNT (yyNTkeyword_else) {
/* line 142 "expr.pars" */

yyS.keyword_else.tree = mkeyword_else(yyA [1].block_scoped.tree);
/* line 1536 "expr_pars.c" */
} break;
case 108: /* keyword_else : */
yySetNT (yyNTkeyword_else) {
/* line 144 "expr.pars" */

yyS.keyword_else.tree = mnokeyword();
/* line 1543 "expr_pars.c" */
} break;
case 109: /* keyword_while : 'while' '(' condition ')' block_scoped */
yyDecrement (5) yySetNT (yyNTkeyword_while) {
/* line 149 "expr.pars" */

yyS.keyword_while.tree = mkeyword_while(yyA [2].condition.tree, yyA [4].block_scoped.tree);
/* line 1550 "expr_pars.c" */
} break;
case 110: /* keyword_for : 'for' '(' declaration ';' condition ';' \
assignment ')' block_scoped */
yyDecrement (9) yySetNT (yyNTkeyword_for) {
/* line 154 "expr.pars" */

yyS.keyword_for.tree = mkeyword_for(yyA [2].declaration.tree, yyA [4].condition.tree, yyA [6].assignment.tree, yyA [8].block_scoped.tree);
/* line 1558 "expr_pars.c" */
} break;
case 111: /* condition : computation '<' computation */
yyDecrement (3) yySetNT (yyNTcondition) {
/* line 159 "expr.pars" */

yyS.condition.tree = mbinary_comp (yyA [1].Scan.Position, '<', yyA [0].computation.tree, yyA [2].computation.tree);
/* line 1565 "expr_pars.c" */
} break;
case 112: /* condition : computation '>' computation */
yyDecrement (3) yySetNT (yyNTcondition) {
/* line 161 "expr.pars" */

yyS.condition.tree = mbinary_comp (yyA [1].Scan.Position, '>', yyA [0].computation.tree, yyA [2].computation.tree);
/* line 1572 "expr_pars.c" */
} break;
case 113: /* condition : computation '=' computation */
yyDecrement (3) yySetNT (yyNTcondition) {
/* line 163 "expr.pars" */

yyS.condition.tree = mbinary_comp (yyA [1].Scan.Position, '=', yyA [0].computation.tree, yyA [2].computation.tree);
/* line 1579 "expr_pars.c" */
} break;
case 114: /* condition : computation '!=' computation */
yyDecrement (3) yySetNT (yyNTcondition) {
/* line 165 "expr.pars" */

yyS.condition.tree = mbinary_comp (yyA [1].Scan.Position, '!=', yyA [0].computation.tree, yyA [2].computation.tree);
/* line 1586 "expr_pars.c" */
} break;
default: switch (yyState) {
case 1: goto yyAbort;
case 2: goto yyRead;
case 3: goto yyReduce;
}
}

	/* SPEC State = Next (Top (), Nonterminal); nonterminal transition */
# ifdef YYNDefault
	       yyState = * yyStateStackPtr ++;
	       for (;;) {
		  register yytComb * yyNCombPtr =
				yyNBasePtr [yyState] + (int) yyNonterminal;
		  if (yyNCombPtr->Check == yyState) {
		     yyState = yyNCombPtr->Next; break;
		  }
		  yyState = yyNDefault [yyState];
	       }
# else
	       yyState = yyNBasePtr [* yyStateStackPtr ++] [yyNonterminal];
# endif
	       * yyAttrStackPtr ++ = yySynAttribute;
	       if (yyState < yyFirstFinalState) break;	/* read nonterminal ? */
# ifdef YYDEBUG
	       yyStateStackPtr [0] = yyStateStackPtr [-1];
# endif
	    }

	 } else {					/* read */
   yyRead:  yyStateStackPtr ++;
	    yyGetAttribute (yyAttrStackPtr ++, expr_scan_Attribute);
	    yyTerminal = yyGetToken ();
# ifdef YYDEBUG
	    if (expr_pars_Debug) {
	       yyPrintState (yyStateStackPtr [-1]);
	       fprintf (yyTrace, "shift   %s, lookahead: %s",
		  yyGetTokenName (yyPrevTerminal),
		  yyGetTokenName (yyTerminal)); yyNl ();
	       yyPrevTerminal = yyTerminal;
	    }
# endif
	    yyIsRepairing = rfalse;
	 }
      }

   yyAbort:
# ifdef YYDEBUG
      if (expr_pars_Debug) {
	 yyPrintState (* yyStateStackPtr);
	 fprintf (yyTrace, "fail    parse started at %ld", yyStartCount);
	 yyNl ();
      }
# endif
      return ++ yyErrorCount;

   yyAccept:
# ifdef YYDEBUG
      if (expr_pars_Debug) {
	 yyPrintState (* yyStateStackPtr);
	 fprintf (yyTrace, "accept  parse started at %ld", yyStartCount);
	 yyNl ();
      }
# endif
      return yyErrorCount;
   }

# ifndef NO_RECOVER
static int yyErrorRecovery
# ifdef HAVE_ARGS
   (yySymbolRange yyTerminal,
#  ifdef YYDEBUG
    yySymbolRange * yyPrevTerminal,
#  endif
    long yyStackPtr)
# else
   (yyTerminal,
#  ifdef YYDEBUG
    yyPrevTerminal,
#  endif
    yyStackPtr)
   yySymbolRange	yyTerminal	;
#  ifdef YYDEBUG
   yySymbolRange *	yyPrevTerminal	;
#  endif
   long			yyStackPtr	;
# endif
   {
#     define	yyContinueSize	5000
      rbool	yyTokensSkipped	;
      tSet	yyContinueSet	;
      tSet	yyRestartSet	;
      int	yyLength	;
      char	yyContinueString [yyContinueSize + 2];

      if (yyControl.yyMessages) {
   /* 1. report an error */
	 ErrorMessage (xxSyntaxError, xxError, expr_scan_Attribute.Position);

   /* 2. report the offending token */
	 strcpy (yyContinueString, yyGetTokenName (yyTerminal));
# ifdef SPELLING
	 if (strncmp (yyContinueString, expr_scan_TokenPtr, expr_scan_TokenLength)) {
	    yyContinueString [yyLength = strlen (yyContinueString)] = ' ';
	    expr_scan_GetWord (& yyContinueString [++ yyLength]);
	 }
# endif
	 ErrorMessageI (xxTokenFound, xxInformation, expr_scan_Attribute.Position,
	    xxString, yyContinueString);

   /* 3. report the set of expected terminal symbols */
	 MakeSet (& yyContinueSet, yyLastTerminal);
	 yyComputeContinuation (yyStackPtr, & yyContinueSet);
	 yyLength = 0;
	 yyContinueString [0] = '\0';
	 while (! IsEmpty (& yyContinueSet)) {
	    char * yyTokenString =
	       yyGetTokenName ((yySymbolRange) Extract (& yyContinueSet));
	    int yyl = strlen (yyTokenString);
	    if (yyLength + yyl >= yyContinueSize) break;
	    strcpy (& yyContinueString [yyLength], yyTokenString);
	    yyLength += yyl;
	    yyContinueString [yyLength ++] = ' ';
	 }
	 yyContinueString [-- yyLength] = '\0';
	 ErrorMessageI (xxExpectedTokens, xxInformation, expr_scan_Attribute.Position,
	    xxString, yyContinueString);
	 ReleaseSet (& yyContinueSet);
      }

   /* 4. compute the set of terminal symbols for restart of the parse */
      MakeSet (& yyRestartSet, yyLastTerminal);
      yyComputeRestartPoints (yyStackPtr, & yyRestartSet);

   /* 5. skip terminal symbols until a restart point is reached */
      yyTokensSkipped = rfalse;
      while (! IsElement (yyTerminal, & yyRestartSet)) {
	 yyTerminal = yyGetToken ();
	 yyTokensSkipped = rtrue;
# ifdef YYDEBUG
	 if (expr_pars_Debug) {
	    yyPrintState (yyStateStack [yyStackPtr]);
	    fprintf (yyTrace, "skip    %s, lookahead: %s",
	       yyGetTokenName (* yyPrevTerminal),
	       yyGetTokenName (yyTerminal)); yyNl ();
	    * yyPrevTerminal = yyTerminal;
	 }
# endif
      }
      ReleaseSet (& yyRestartSet);

   /* 6. report the restart point */
      if (yyTokensSkipped & yyControl.yyMessages)
	 ErrorMessage (xxRestartPoint, xxInformation, expr_scan_Attribute.Position);

      return yyTerminal;
   }

/*
   compute the set of terminal symbols that can be accepted (read)
   in a given stack configuration (eventually after reduce actions)
*/

static void yyComputeContinuation
# ifdef HAVE_ARGS
   (long yyStackPtr, tSet * yyContinueSet)
# else
   (yyStackPtr, yyContinueSet)
   long			yyStackPtr	;
   tSet *		yyContinueSet	;
# endif
   {
      register yySymbolRange	yyTerminal;
      register yyStateRange	yyState = yyStateStack [yyStackPtr];

      AssignEmpty (yyContinueSet);
      for (yyTerminal = yyFirstTerminal; yyTerminal <= yyLastTerminal;
							yyTerminal ++) {
	 yyStateRange yyNextState = yyNext (yyState, yyTerminal);
	 if (yyNextState != yyNoState && (yyNextState <= yyLastStopState ||
	    yyIsContinuation (yyTerminal, yyStackPtr))) {
	    Include (yyContinueSet, yyTerminal);
	 }
      }
   }

/*
   check whether a given terminal symbol can be accepted (read)
   in a certain stack configuration (eventually after reduce actions)
*/

static rbool yyIsContinuation
# ifdef HAVE_ARGS
   (yySymbolRange yyTerminal, long yyStackPtr)
# else
   (yyTerminal, yyStackPtr)
   yySymbolRange	yyTerminal	;
   long			yyStackPtr	;
# endif
   {
      register yyStateRange	yState		;
      register yytNonterminal	yyNonterminal	;

      while (yyStackPtr >= yyIsContStackSize)	       /* pass Stack by value */
	 yyExtendArray ((char * *) & yyIsContStackPtr, & yyIsContStackSize,
			  (unsigned long) sizeof (yyStateRange));
      memcpy ((char *) yyIsContStackPtr, (char *) yyStateStack,
		(int) sizeof (yyStateRange) * (yyStackPtr + 1));

      yState = yyIsContStackPtr [yyStackPtr];
      for (;;) {
	 yyIsContStackPtr [yyStackPtr] = yState;
	 yState = yyNext (yState, yyTerminal);
	 if (yState == yyNoState) return rfalse;

	 do {						/* reduce */
	    if (yState > yyLastReduceState) {		/* dynamic ? */
	       yState = yyCondition [yState - yyLastReduceState];
	    }
	    if (yState <= yyLastStopState) { /* read, read reduce, or accept? */
	       return rtrue;
	    } else {					/* reduce */
	       yyStackPtr -= yyLength [yState - yyFirstReduceState];
	       yyNonterminal = yyLeftHandSide [yState - yyFirstReduceState];
	    }

	    yState = yyNext (yyIsContStackPtr [yyStackPtr],
				(yySymbolRange) yyNonterminal);
	    yyStackPtr ++;
	    if (yyStackPtr >= yyIsContStackSize) {
	       yyExtendArray ((char * *) & yyIsContStackPtr,
		  & yyIsContStackSize, (unsigned long) sizeof (yyStateRange));
	       if (yyStackPtr >= 1000) return rfalse; /* EMERGENCY break !!! */
	    }
	 } while (yState >= yyFirstFinalState);
      }
   }

/*
   compute the set of terminal symbols that can be accepted (read)
   directly in a given stack configuration
*/

static void yyCompContinuation
# ifdef HAVE_ARGS
   (yyStateRange yyState, tSet * yyContinueSet)
# else
   (yyState, yyContinueSet)
   yyStateRange		yyState		;
   tSet *		yyContinueSet	;
# endif
   {
      register yySymbolRange	yyTerminal;

      AssignEmpty (yyContinueSet);
      for (yyTerminal = yyFirstTerminal; yyTerminal <= yyLastTerminal;
							yyTerminal ++) {
	 yyStateRange yyNextState = yyNext (yyState, yyTerminal);
	 if (yyNextState != yyNoState && yyNextState <= yyLastStopState) {
	    Include (yyContinueSet, yyTerminal);
	 }
      }
   }

/*
   compute a set of terminal symbols that can be used to restart
   parsing in a given stack configuration. We simulate parsing until
   end of file using a suffix program synthesized by the function (array)
   yyContinuation. All symbols acceptable in the states reached during
   the simulation can be used to restart parsing.
*/

static void yyComputeRestartPoints
# ifdef HAVE_ARGS
   (long yyStackPtr, tSet * yyRestartSet)
# else
   (yyStackPtr, yyRestartSet)
   long			yyStackPtr	;
   tSet *		yyRestartSet	;
# endif
   {
      register yyStateRange	yState		;
      register yytNonterminal	yyNonterminal	;
	       tSet		yyContinueSet	;

      while (yyStackPtr >= yyCompResStackSize)	       /* pass Stack by value */
	 yyExtendArray ((char * *) & yyCompResStackPtr, & yyCompResStackSize,
			  (unsigned long) sizeof (yyStateRange));
      memcpy ((char *) yyCompResStackPtr, (char *) yyStateStack,
		(int) sizeof (yyStateRange) * (yyStackPtr + 1));

      MakeSet (& yyContinueSet, yyLastTerminal);
      AssignEmpty (yyRestartSet);
      yState = yyCompResStackPtr [yyStackPtr];

      for (;;) {
	 if (yyStackPtr >= yyCompResStackSize)
	    yyExtendArray ((char * *) & yyCompResStackPtr, & yyCompResStackSize,
			     (unsigned long) sizeof (yyStateRange));
	 yyCompResStackPtr [yyStackPtr] = yState;
	 yyCompContinuation (yState, & yyContinueSet);
	 Union (yyRestartSet, & yyContinueSet);
# ifdef YYDCRP
	 {
	    int yyLength = 0;
	    char yyContinueString [yyContinueSize + 2];
	    yyContinueString [0] = '\0';
	    while (! IsEmpty (& yyContinueSet)) {
	       char * yyTokenString =
		  yyGetTokenName ((yySymbolRange) Extract (& yyContinueSet));
	       int yyl = strlen (yyTokenString);
	       if (yyLength + yyl >= yyContinueSize) break;
	       strcpy (& yyContinueString [yyLength], yyTokenString);
	       yyLength += yyl;
	       yyContinueString [yyLength ++] = ' ';
	    }
	    yyContinueString [-- yyLength] = '\0';
	    fprintf (yyTrace, "%5d union %s", yState, yyContinueString);
	    yyNl ();
	 }
# endif
	 yState = yyNext (yState, yyContinuation [yState]);

	 if (yState >= yyFirstFinalState) {		/* final state ? */
	    if (yState <= yyLastReadReduceState) {	/* read reduce ? */
	       yyStackPtr ++;
	       yState = yyFinalToProd [yState - yyFirstReadReduceState];
# ifdef YYDCRP
	       yyCompResStackPtr [yyStackPtr] =
					yyCompResStackPtr [yyStackPtr - 1];
	       fprintf (yyTrace, "%5d shift   %s",
		  yyCompResStackPtr [yyStackPtr], yyGetTokenName
		  (yyContinuation [yyCompResStackPtr [yyStackPtr]])); yyNl ();
# endif
	    }

	    do {					/* reduce */
	       if (yState > yyLastReduceState) {	/* dynamic ? */
# ifdef YYDCRP
		  fprintf (yyTrace, "%5d dynamic decision %d",
		    yyCompResStackPtr [yyStackPtr], yState - yyLastReduceState);
		  yyNl ();
# endif
		  yState = yyCondition [yState - yyLastReduceState];
	       }
	       if (yyFirstReduceState <= yState &&
		   yState <= yyLastStopState) {		/* accept */
# ifdef YYDCRP
		  fprintf (yyTrace, "%5d accept",
		     yyCompResStackPtr [yyStackPtr]); yyNl ();
# endif
		  ReleaseSet (& yyContinueSet);
		  return;
	       } else if (yState < yyFirstFinalState) {	/* read */
		  goto yyRead;
	       } else {					/* reduce */
# ifdef YYDCRP
		  fprintf (yyTrace, "%5d reduce  %s",
		     yyCompResStackPtr [yyStackPtr],
		     yyRule [yState - yyLastReadReduceState]); yyNl ();
# endif
		  yyStackPtr -= yyLength [yState - yyFirstReduceState];
		  yyNonterminal = yyLeftHandSide [yState - yyFirstReduceState];
	       }

	       yState = yyNext (yyCompResStackPtr [yyStackPtr],
				(yySymbolRange) yyNonterminal);
	       yyStackPtr ++;
	    } while (yState >= yyFirstFinalState);
	 } else {					/* read */
yyRead:
# ifdef YYDCRP
	    fprintf (yyTrace, "%5d shift   %s",
	       yyCompResStackPtr [yyStackPtr], yyGetTokenName
	       (yyContinuation [yyCompResStackPtr [yyStackPtr]])); yyNl ();
# endif
	    yyStackPtr ++;
	 }
      }
   }

/* access the parse table:   Next : State x Symbol -> Action */

static yyStateRange yyNext
# ifdef HAVE_ARGS
   (yyStateRange yyState, yySymbolRange yySymbol)
# else
   (yyState, yySymbol) yyStateRange yyState; yySymbolRange yySymbol;
# endif
   {
      if (yySymbol <= yyLastTerminal) {
	 for (;;) {
	    register yytComb * yyTCombPtr = yyTBasePtr [yyState] + yySymbol;
# if defined YYTDefault & defined YYaccDefault
	    register unsigned long * yylp;
# endif
	    if (yyTCombPtr->Check == yyState) return yyTCombPtr->Next;
# ifdef YYTDefault
#  ifdef YYaccDefault
	    return (yylp = yyDefaultLook [yyState]) &&
	       (yylp [yySymbol >> 5] >> (yySymbol & 0x1f)) & 1 ?
		  yyTDefault [yyState] : yyNoState;
#  else
	    if ((yyState = yyTDefault [yyState]) == yyNoState) return yyNoState;
#  endif
# else
	    return yyNoState;
# endif
	 }
      }
# ifdef YYNDefault
      for (;;) {
	 register yytComb * yyNCombPtr = yyNBasePtr [yyState] + yySymbol;
	 if (yyNCombPtr->Check == yyState) return yyNCombPtr->Next;
	 yyState = yyNDefault [yyState];
      }
# else
      return yyNBasePtr [yyState] [yySymbol];
# endif
   }
# endif

void Beginexpr_pars ARGS ((void))
   {
/* line 72 "expr_pars.lrk" */


/* line 2014 "expr_pars.c" */
   }

void Closeexpr_pars ARGS ((void))
   {
/* line 75 "expr_pars.lrk" */


/* line 2022 "expr_pars.c" */
   }

