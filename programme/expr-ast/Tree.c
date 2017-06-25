# include "Tree.h"

# ifndef EXTERN_C_BEGIN
# define EXTERN_C_BEGIN
# define EXTERN_C_END
# endif

EXTERN_C_BEGIN
# include <stdlib.h>
# include <stddef.h>
# include "rString.h"
# include "rSystem.h"
# include "General.h"
# include "rMemory.h"
# include "DynArray.h"
# include "Idents.h"
# include "Position.h"
# include "Errors.h"
EXTERN_C_END

# ifdef _MSC_VER
#  pragma warning (disable: 4100 4505 4514)
# endif

char Tree_module_does_not_match_evaluator_module_2851876;
char generate_Tree_module_without_option_0;

static FILE * yyf;

/* line 32 "expr.ast" */

  /* The target-code of this section is copied into the generated .c file */

# ifdef __cplusplus
#  ifndef yyALLOC
#   define yyALLOC(size1, size2) yyALLOCi (size1, size2)
#  endif
static inline tTree yyALLOCi (unsigned long yysize1, unsigned long yysize2)
{ return Tree_PoolFreePtr >= Tree_PoolStartPtr + yysize1 ?
  (tTree) (Tree_PoolFreePtr -= yysize1) : Tree_Alloc (yysize2); }
static inline tTree yyALLOCk (unsigned long yysize)
{ return yyALLOC (yysize, yysize); }
static inline tTree yyALLOCt (unsigned long yysize)
{ return yyALLOC (yyAlignedSize (yysize), yysize); }
# else
#  define yyALLOCk(size) yyALLOC (size, size)
#  define yyALLOCt(size) yyALLOC (yyAlignedSize (size), size)
#  ifndef yyALLOC
#   define yyALLOC(size1, size2) (Tree_PoolFreePtr -= (long) size1) >= \
     Tree_PoolStartPtr ? (tTree) Tree_PoolFreePtr : Tree_Alloc (size2)
#  endif
# endif
# ifndef yyFREE
# define yyFREE(ptr, size) 
# endif
# ifdef getchar
# undef getchar
# endif
# ifdef putchar
# undef putchar
# endif
# include "yyTree.h"

static void yyExit ARGS ((void)) { rExit (1); }

void (* Tree_Exit) ARGS ((void)) = yyExit;

tTree TreeRoot;
unsigned long Tree_HeapUsed = 0;

yytTree_BlockPtr Tree_BlockList	= (yytTree_BlockPtr) NoTree;
char * Tree_PoolFreePtr = (char *) & Tree_BlockList;
char * Tree_PoolStartPtr = (char *) & Tree_BlockList;
rbool Tree_CheckReportNoTree = rtrue, Tree_CheckReportNodes = rtrue;
int Tree_DrawBoxHeight = 20;
int Tree_DrawBoxWidth  = 60;
int Tree_DrawDepth     = 6;
int Tree_DrawLength    = 256;
char Tree_DrawFileName [256] = "";
# ifdef SUPPORT_TVA
rbool Tree_TreatTVAasChild = rfalse;
# endif

const unsigned short Tree_NodeSize [30] = { 0,
 yyAlignedSize (sizeof (yPROGRAM)),
 yyAlignedSize (sizeof (yprogram)),
 yyAlignedSize (sizeof (yBLOCKEXEC)),
 yyAlignedSize (sizeof (yblocklist)),
 yyAlignedSize (sizeof (yblocknostmt)),
 yyAlignedSize (sizeof (ySTATEMENT)),
 yyAlignedSize (sizeof (yno_stmt)),
 yyAlignedSize (sizeof (ydeclaration)),
 yyAlignedSize (sizeof (yassignment)),
 yyAlignedSize (sizeof (ykeyword)),
 yyAlignedSize (sizeof (yDECLARATION)),
 yyAlignedSize (sizeof (ydecl_ident)),
 yyAlignedSize (sizeof (ydecl_assignm)),
 yyAlignedSize (sizeof (yASSIGNMENT)),
 yyAlignedSize (sizeof (yassign)),
 yyAlignedSize (sizeof (yCOMPUTATION)),
 yyAlignedSize (sizeof (ybinary_comp)),
 yyAlignedSize (sizeof (yint_const)),
 yyAlignedSize (sizeof (yfloat_const)),
 yyAlignedSize (sizeof (yunary_comp)),
 yyAlignedSize (sizeof (ystring_const)),
 yyAlignedSize (sizeof (yidentifier)),
 yyAlignedSize (sizeof (yKEYWORD)),
 yyAlignedSize (sizeof (ykeyword_if)),
 yyAlignedSize (sizeof (ykeyword_else)),
 yyAlignedSize (sizeof (ynokeyword)),
 yyAlignedSize (sizeof (ykeyword_while)),
 yyAlignedSize (sizeof (ykeyword_for)),
 yyAlignedSize (sizeof (yBLOCKSCOPED)),
};
const Tree_tKind Tree_TypeRange [30] = { 0,
 kprogram,
 kprogram,
 kblocknostmt,
 kblocklist,
 kblocknostmt,
 kkeyword,
 kno_stmt,
 kdeclaration,
 kassignment,
 kkeyword,
 kdecl_assignm,
 kdecl_ident,
 kdecl_assignm,
 kassign,
 kassign,
 kidentifier,
 kbinary_comp,
 kint_const,
 kfloat_const,
 kunary_comp,
 kstring_const,
 kidentifier,
 kkeyword_for,
 kkeyword_if,
 kkeyword_else,
 knokeyword,
 kkeyword_while,
 kkeyword_for,
 kBLOCKSCOPED,
};
const char * const Tree_NodeName [30] = {
 "NoTree",
 "PROGRAM",
 "program",
 "BLOCKEXEC",
 "blocklist",
 "blocknostmt",
 "STATEMENT",
 "no_stmt",
 "declaration",
 "assignment",
 "keyword",
 "DECLARATION",
 "decl_ident",
 "decl_assignm",
 "ASSIGNMENT",
 "assign",
 "COMPUTATION",
 "binary_comp",
 "int_const",
 "float_const",
 "unary_comp",
 "string_const",
 "identifier",
 "KEYWORD",
 "keyword_if",
 "keyword_else",
 "nokeyword",
 "keyword_while",
 "keyword_for",
 "BLOCKSCOPED",
};

tTree Tree_Alloc
# ifdef HAVE_ARGS
 (unsigned long yySize)
# else
 (yySize) unsigned long yySize;
# endif
{
 register yytTree_BlockPtr yyBlockPtr = Tree_BlockList;
 Tree_BlockList = (yytTree_BlockPtr) Alloc ((unsigned long) sizeof (yytTree_Block));
 if ((tTree) Tree_BlockList == NoTree) {
  ErrorMessageI (xxTreeOutOfMemory, xxFatal, NoPosition, xxString, "Tree");
  Tree_Exit ();
 }
 Tree_BlockList->yySuccessor = yyBlockPtr;
 Tree_PoolStartPtr = (char *) Tree_BlockList;
 Tree_HeapUsed += sizeof (yytTree_Block);
 return (tTree) (Tree_PoolFreePtr = Tree_PoolStartPtr +
  (yyBlockSize - yyAlignedSize (yySize)));
}

tTree MakeTree
# ifdef HAVE_ARGS
 (Tree_tKind yyKind)
# else
 (yyKind) Tree_tKind yyKind;
# endif
{
 register tTree yyt = yyALLOCk (Tree_NodeSize [yyKind]);
 Tree_InitHead (yyt, yyKind)
 return yyt;
}

rbool Tree_IsType
# ifdef HAVE_ARGS
 (register tTree yyt, register Tree_tKind yyKind)
# else
 (yyt, yyKind) register tTree yyt; register Tree_tKind yyKind;
# endif
{
 return yyt != NoTree && yyKind <= yyt->Kind &&
  yyt->Kind <= Tree_TypeRange [yyKind];
}


tTree mPROGRAM
# ifdef HAVE_ARGS
(tPosition pPos)
# else
(pPos)
tPosition pPos;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yPROGRAM));
 Tree_InitHead (yyt, kPROGRAM)
 yyt->PROGRAM.Pos = pPos;
 return yyt;
}

tTree mprogram
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pIdent, tTree pBlock)
# else
(pPos, pIdent, pBlock)
tPosition pPos;
tIdent pIdent;
tTree pBlock;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yprogram));
 Tree_InitHead (yyt, kprogram)
 yyt->program.Pos = pPos;
 yyt->program.Ident = pIdent;
 yyt->program.Block = pBlock;
 return yyt;
}

tTree mBLOCKEXEC
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yBLOCKEXEC));
 Tree_InitHead (yyt, kBLOCKEXEC)
 return yyt;
}

tTree mblocklist
# ifdef HAVE_ARGS
(tTree pNext, tTree pStmt)
# else
(pNext, pStmt)
tTree pNext;
tTree pStmt;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yblocklist));
 Tree_InitHead (yyt, kblocklist)
 yyt->blocklist.Next = pNext;
 yyt->blocklist.Stmt = pStmt;
 return yyt;
}

tTree mblocknostmt
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yblocknostmt));
 Tree_InitHead (yyt, kblocknostmt)
 return yyt;
}

tTree mSTATEMENT
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ySTATEMENT));
 Tree_InitHead (yyt, kSTATEMENT)
 return yyt;
}

tTree mno_stmt
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yno_stmt));
 Tree_InitHead (yyt, kno_stmt)
 return yyt;
}

tTree mdeclaration
# ifdef HAVE_ARGS
(tTree pNext)
# else
(pNext)
tTree pNext;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ydeclaration));
 Tree_InitHead (yyt, kdeclaration)
 yyt->declaration.Next = pNext;
 return yyt;
}

tTree massignment
# ifdef HAVE_ARGS
(tTree pNext)
# else
(pNext)
tTree pNext;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yassignment));
 Tree_InitHead (yyt, kassignment)
 yyt->assignment.Next = pNext;
 return yyt;
}

tTree mkeyword
# ifdef HAVE_ARGS
(tTree pNext)
# else
(pNext)
tTree pNext;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ykeyword));
 Tree_InitHead (yyt, kkeyword)
 yyt->keyword.Next = pNext;
 return yyt;
}

tTree mDECLARATION
# ifdef HAVE_ARGS
(tPosition pPos)
# else
(pPos)
tPosition pPos;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yDECLARATION));
 Tree_InitHead (yyt, kDECLARATION)
 yyt->DECLARATION.Pos = pPos;
 return yyt;
}

tTree mdecl_ident
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pValue, tIdent pIdent)
# else
(pPos, pValue, pIdent)
tPosition pPos;
tIdent pValue;
tIdent pIdent;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ydecl_ident));
 Tree_InitHead (yyt, kdecl_ident)
 yyt->decl_ident.Pos = pPos;
 yyt->decl_ident.Value = pValue;
 yyt->decl_ident.Ident = pIdent;
 return yyt;
}

tTree mdecl_assignm
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pValue, tTree pRight)
# else
(pPos, pValue, pRight)
tPosition pPos;
tIdent pValue;
tTree pRight;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ydecl_assignm));
 Tree_InitHead (yyt, kdecl_assignm)
 yyt->decl_assignm.Pos = pPos;
 yyt->decl_assignm.Value = pValue;
 yyt->decl_assignm.Right = pRight;
 return yyt;
}

tTree mASSIGNMENT
# ifdef HAVE_ARGS
(tPosition pPos)
# else
(pPos)
tPosition pPos;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yASSIGNMENT));
 Tree_InitHead (yyt, kASSIGNMENT)
 yyt->ASSIGNMENT.Pos = pPos;
 return yyt;
}

tTree massign
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pIdent, tTree pRight)
# else
(pPos, pIdent, pRight)
tPosition pPos;
tIdent pIdent;
tTree pRight;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yassign));
 Tree_InitHead (yyt, kassign)
 yyt->assign.Pos = pPos;
 yyt->assign.Ident = pIdent;
 yyt->assign.Right = pRight;
 return yyt;
}

tTree mCOMPUTATION
# ifdef HAVE_ARGS
(tPosition pPos)
# else
(pPos)
tPosition pPos;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yCOMPUTATION));
 Tree_InitHead (yyt, kCOMPUTATION)
 yyt->COMPUTATION.Pos = pPos;
 return yyt;
}

tTree mbinary_comp
# ifdef HAVE_ARGS
(tPosition pPos, char pOp, tTree pLeft, tTree pRight)
# else
(pPos, pOp, pLeft, pRight)
tPosition pPos;
char pOp;
tTree pLeft;
tTree pRight;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ybinary_comp));
 Tree_InitHead (yyt, kbinary_comp)
 yyt->binary_comp.Pos = pPos;
 yyt->binary_comp.Op = pOp;
 yyt->binary_comp.Left = pLeft;
 yyt->binary_comp.Right = pRight;
 return yyt;
}

tTree mint_const
# ifdef HAVE_ARGS
(tPosition pPos, int pValue)
# else
(pPos, pValue)
tPosition pPos;
int pValue;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yint_const));
 Tree_InitHead (yyt, kint_const)
 yyt->int_const.Pos = pPos;
 yyt->int_const.Value = pValue;
 return yyt;
}

tTree mfloat_const
# ifdef HAVE_ARGS
(tPosition pPos, double pValue)
# else
(pPos, pValue)
tPosition pPos;
double pValue;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yfloat_const));
 Tree_InitHead (yyt, kfloat_const)
 yyt->float_const.Pos = pPos;
 yyt->float_const.Value = pValue;
 return yyt;
}

tTree munary_comp
# ifdef HAVE_ARGS
(tPosition pPos, char pOp, tTree pArgument)
# else
(pPos, pOp, pArgument)
tPosition pPos;
char pOp;
tTree pArgument;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yunary_comp));
 Tree_InitHead (yyt, kunary_comp)
 yyt->unary_comp.Pos = pPos;
 yyt->unary_comp.Op = pOp;
 yyt->unary_comp.Argument = pArgument;
 return yyt;
}

tTree mstring_const
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pValue)
# else
(pPos, pValue)
tPosition pPos;
tIdent pValue;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ystring_const));
 Tree_InitHead (yyt, kstring_const)
 yyt->string_const.Pos = pPos;
 yyt->string_const.Value = pValue;
 return yyt;
}

tTree midentifier
# ifdef HAVE_ARGS
(tPosition pPos, tIdent pIdent)
# else
(pPos, pIdent)
tPosition pPos;
tIdent pIdent;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yidentifier));
 Tree_InitHead (yyt, kidentifier)
 yyt->identifier.Pos = pPos;
 yyt->identifier.Ident = pIdent;
 return yyt;
}

tTree mKEYWORD
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yKEYWORD));
 Tree_InitHead (yyt, kKEYWORD)
 return yyt;
}

tTree mkeyword_if
# ifdef HAVE_ARGS
(tTree pCond, tTree pBlock, tTree pElseIf)
# else
(pCond, pBlock, pElseIf)
tTree pCond;
tTree pBlock;
tTree pElseIf;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ykeyword_if));
 Tree_InitHead (yyt, kkeyword_if)
 yyt->keyword_if.Cond = pCond;
 yyt->keyword_if.Block = pBlock;
 yyt->keyword_if.ElseIf = pElseIf;
 return yyt;
}

tTree mkeyword_else
# ifdef HAVE_ARGS
(tTree pBlock)
# else
(pBlock)
tTree pBlock;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ykeyword_else));
 Tree_InitHead (yyt, kkeyword_else)
 yyt->keyword_else.Block = pBlock;
 return yyt;
}

tTree mnokeyword
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ynokeyword));
 Tree_InitHead (yyt, knokeyword)
 return yyt;
}

tTree mkeyword_while
# ifdef HAVE_ARGS
(tTree pCond, tTree pBlock)
# else
(pCond, pBlock)
tTree pCond;
tTree pBlock;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ykeyword_while));
 Tree_InitHead (yyt, kkeyword_while)
 yyt->keyword_while.Cond = pCond;
 yyt->keyword_while.Block = pBlock;
 return yyt;
}

tTree mkeyword_for
# ifdef HAVE_ARGS
(tTree pDecl, tTree pCond, tTree pAss, tTree pBlock)
# else
(pDecl, pCond, pAss, pBlock)
tTree pDecl;
tTree pCond;
tTree pAss;
tTree pBlock;
# endif
{
 register tTree yyt = yyALLOCt (sizeof (ykeyword_for));
 Tree_InitHead (yyt, kkeyword_for)
 yyt->keyword_for.Decl = pDecl;
 yyt->keyword_for.Cond = pCond;
 yyt->keyword_for.Ass = pAss;
 yyt->keyword_for.Block = pBlock;
 return yyt;
}

tTree mBLOCKSCOPED
# ifdef HAVE_ARGS
(void)
# else
()
# endif
{
 register tTree yyt = yyALLOCt (sizeof (yBLOCKSCOPED));
 Tree_InitHead (yyt, kBLOCKSCOPED)
 return yyt;
}

static void yyMark
# ifdef HAVE_ARGS
 (register tTree yyt)
# else
 (yyt) register tTree yyt;
# endif
{
 for (;;) {
  if (yyt == NoTree || ++ yyt->yyHead.yyMark > 1) return;

  switch (yyt->Kind) {
case kprogram:
yyt = yyt->program.Block; break;
case kblocklist:
yyMark (yyt->blocklist.Next);
yyt = yyt->blocklist.Stmt; break;
case kdeclaration:
yyt = yyt->declaration.Next; break;
case kassignment:
yyt = yyt->assignment.Next; break;
case kkeyword:
yyt = yyt->keyword.Next; break;
case kdecl_assignm:
yyt = yyt->decl_assignm.Right; break;
case kassign:
yyt = yyt->assign.Right; break;
case kbinary_comp:
yyMark (yyt->binary_comp.Left);
yyt = yyt->binary_comp.Right; break;
case kunary_comp:
yyt = yyt->unary_comp.Argument; break;
case kkeyword_if:
yyMark (yyt->keyword_if.Cond);
yyMark (yyt->keyword_if.Block);
yyt = yyt->keyword_if.ElseIf; break;
case kkeyword_else:
yyt = yyt->keyword_else.Block; break;
case kkeyword_while:
yyMark (yyt->keyword_while.Cond);
yyt = yyt->keyword_while.Block; break;
case kkeyword_for:
yyMark (yyt->keyword_for.Decl);
yyMark (yyt->keyword_for.Cond);
yyMark (yyt->keyword_for.Ass);
yyt = yyt->keyword_for.Block; break;
  default: return;
  }
 }
}

# define yyInitTreeStoreSize 64

# define yyTreeStoreHashSize 256

typedef struct { tTree yyPtr; Tree_tLabel yyNext; } yytTreeStore;
static unsigned long yyTreeStoreSize = yyInitTreeStoreSize;
static yytTreeStore * yyTreeStorePtr;
static Tree_tLabel yyLabelCount;
static short yyRecursionLevel = 0;
static Tree_tLabel yyTreeStoreHash [yyTreeStoreHashSize];

static void yyBeginTreeStore ARGS ((void))
{
 register int yyi;
 if (yyRecursionLevel ++ == 0) {
  MakeArray ((char * *) & yyTreeStorePtr, & yyTreeStoreSize,
   (unsigned long) sizeof (yytTreeStore)); yyLabelCount = 0;
  for (yyi = 0; yyi < yyTreeStoreHashSize; yyi ++)
   yyTreeStoreHash [yyi] = 0;
 }
}

static void yyCloseTreeStore ARGS ((void))
{
 if (-- yyRecursionLevel == 0) {
  ReleaseArray ((char * *) & yyTreeStorePtr, & yyTreeStoreSize,
   (unsigned long) sizeof (yytTreeStore));
 }
}

static Tree_tLabel yyMapToLabel
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 long yyhash = (((ptrdiff_t) yyt) >> 4) & (yyTreeStoreHashSize - 1);
 register Tree_tLabel yyi = yyTreeStoreHash [yyhash];
 for (; yyi; yyi = yyTreeStorePtr [yyi].yyNext)
  if (yyTreeStorePtr [yyi].yyPtr == yyt) return yyi;
 if (++ yyLabelCount == (Tree_tLabel) yyTreeStoreSize)
  ExtendArray ((char * *) & yyTreeStorePtr, & yyTreeStoreSize,
   (unsigned long) sizeof (yytTreeStore));
 yyTreeStorePtr [yyLabelCount].yyPtr = yyt;
 yyTreeStorePtr [yyLabelCount].yyNext = yyTreeStoreHash [yyhash];
 yyTreeStoreHash [yyhash] = yyLabelCount;
 return yyLabelCount;
}

static void yyWriteTree ARGS ((tTree yyt));
static void yyWriteTreeXML ARGS ((tTree yyt));

static void xxWriteNl ARGS ((void)) { putc ('\n', yyf); }

static void yyWriteSelector
# ifdef HAVE_ARGS
 (char * yys)
# else
 (yys) char * yys;
# endif
{
 register int yyi = 16 - strlen (yys);
 fputs (yys, yyf);
 while (yyi -- > 0) putc (' ', yyf);
 fputs (" = ", yyf);
}

static void yyWriteHex
# ifdef HAVE_ARGS
 (unsigned char * yyx, int yysize)
# else
 (yyx, yysize) unsigned char * yyx; int yysize;
# endif
{ register int yyi; for (yyi = 0; yyi < yysize; yyi ++)
   fprintf (yyf, "%02x ", yyx [yyi]); }

static void yyWriteAddr
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 if (yyt == NoTree) fputs ("NoTree", yyf);
 else fprintf (yyf, "%p *", (void *) yyt);
 xxWriteNl ();
}

static void yWriteNodePROGRAM
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Pos");
 writetPosition (yyt->PROGRAM.Pos) xxWriteNl ();
}

static void yWriteNodeprogram
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodePROGRAM (yyt);
 yyWriteSelector ("Ident");
 writetIdent (yyt->program.Ident) xxWriteNl ();
 yyWriteSelector ("Block");
 yyWriteAddr (yyt->program.Block);
}

static void yWriteNodeblocklist
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Next");
 yyWriteAddr (yyt->blocklist.Next);
 yyWriteSelector ("Stmt");
 yyWriteAddr (yyt->blocklist.Stmt);
}

static void yWriteNodedeclaration
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Next");
 yyWriteAddr (yyt->declaration.Next);
}

static void yWriteNodeassignment
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Next");
 yyWriteAddr (yyt->assignment.Next);
}

static void yWriteNodekeyword
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Next");
 yyWriteAddr (yyt->keyword.Next);
}

static void yWriteNodeDECLARATION
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Pos");
 writetPosition (yyt->DECLARATION.Pos) xxWriteNl ();
}

static void yWriteNodedecl_ident
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeDECLARATION (yyt);
 yyWriteSelector ("Value");
 writetIdent (yyt->decl_ident.Value) xxWriteNl ();
 yyWriteSelector ("Ident");
 writetIdent (yyt->decl_ident.Ident) xxWriteNl ();
}

static void yWriteNodedecl_assignm
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeDECLARATION (yyt);
 yyWriteSelector ("Value");
 writetIdent (yyt->decl_assignm.Value) xxWriteNl ();
 yyWriteSelector ("Right");
 yyWriteAddr (yyt->decl_assignm.Right);
}

static void yWriteNodeASSIGNMENT
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Pos");
 writetPosition (yyt->ASSIGNMENT.Pos) xxWriteNl ();
}

static void yWriteNodeassign
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeASSIGNMENT (yyt);
 yyWriteSelector ("Ident");
 writetIdent (yyt->assign.Ident) xxWriteNl ();
 yyWriteSelector ("Right");
 yyWriteAddr (yyt->assign.Right);
}

static void yWriteNodeCOMPUTATION
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Pos");
 writetPosition (yyt->COMPUTATION.Pos) xxWriteNl ();
}

static void yWriteNodebinary_comp
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Op");
 writechar (yyt->binary_comp.Op) xxWriteNl ();
 yyWriteSelector ("Left");
 yyWriteAddr (yyt->binary_comp.Left);
 yyWriteSelector ("Right");
 yyWriteAddr (yyt->binary_comp.Right);
}

static void yWriteNodeint_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Value");
 writeint (yyt->int_const.Value) xxWriteNl ();
}

static void yWriteNodefloat_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Value");
 writedouble (yyt->float_const.Value) xxWriteNl ();
}

static void yWriteNodeunary_comp
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Op");
 writechar (yyt->unary_comp.Op) xxWriteNl ();
 yyWriteSelector ("Argument");
 yyWriteAddr (yyt->unary_comp.Argument);
}

static void yWriteNodestring_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Value");
 writetIdent (yyt->string_const.Value) xxWriteNl ();
}

static void yWriteNodeidentifier
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteNodeCOMPUTATION (yyt);
 yyWriteSelector ("Ident");
 writetIdent (yyt->identifier.Ident) xxWriteNl ();
}

static void yWriteNodekeyword_if
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Cond");
 yyWriteAddr (yyt->keyword_if.Cond);
 yyWriteSelector ("Block");
 yyWriteAddr (yyt->keyword_if.Block);
 yyWriteSelector ("ElseIf");
 yyWriteAddr (yyt->keyword_if.ElseIf);
}

static void yWriteNodekeyword_else
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Block");
 yyWriteAddr (yyt->keyword_else.Block);
}

static void yWriteNodekeyword_while
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Cond");
 yyWriteAddr (yyt->keyword_while.Cond);
 yyWriteSelector ("Block");
 yyWriteAddr (yyt->keyword_while.Block);
}

static void yWriteNodekeyword_for
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyWriteSelector ("Decl");
 yyWriteAddr (yyt->keyword_for.Decl);
 yyWriteSelector ("Cond");
 yyWriteAddr (yyt->keyword_for.Cond);
 yyWriteSelector ("Ass");
 yyWriteAddr (yyt->keyword_for.Ass);
 yyWriteSelector ("Block");
 yyWriteAddr (yyt->keyword_for.Block);
}

void WriteTreeNode
# ifdef HAVE_ARGS
 (FILE * yyyf, tTree yyt)
# else
 (yyyf, yyt) FILE * yyyf; tTree yyt;
# endif
{
 yyf = yyyf;
 if (yyt == NoTree) { fputs ("NoTree\n", yyf); return; }

 fputs (Tree_NodeName [yyt->Kind], yyf); fputc ('\n', yyf);
 writeNodeHead (yyt)
 switch (yyt->Kind) {
case kPROGRAM:
 yWriteNodePROGRAM (yyt); break;
case kprogram:
 yWriteNodeprogram (yyt); break;
case kblocklist:
 yWriteNodeblocklist (yyt); break;
case kdeclaration:
 yWriteNodedeclaration (yyt); break;
case kassignment:
 yWriteNodeassignment (yyt); break;
case kkeyword:
 yWriteNodekeyword (yyt); break;
case kDECLARATION:
 yWriteNodeDECLARATION (yyt); break;
case kdecl_ident:
 yWriteNodedecl_ident (yyt); break;
case kdecl_assignm:
 yWriteNodedecl_assignm (yyt); break;
case kASSIGNMENT:
 yWriteNodeASSIGNMENT (yyt); break;
case kassign:
 yWriteNodeassign (yyt); break;
case kCOMPUTATION:
 yWriteNodeCOMPUTATION (yyt); break;
case kbinary_comp:
 yWriteNodebinary_comp (yyt); break;
case kint_const:
 yWriteNodeint_const (yyt); break;
case kfloat_const:
 yWriteNodefloat_const (yyt); break;
case kunary_comp:
 yWriteNodeunary_comp (yyt); break;
case kstring_const:
 yWriteNodestring_const (yyt); break;
case kidentifier:
 yWriteNodeidentifier (yyt); break;
case kkeyword_if:
 yWriteNodekeyword_if (yyt); break;
case kkeyword_else:
 yWriteNodekeyword_else (yyt); break;
case kkeyword_while:
 yWriteNodekeyword_while (yyt); break;
case kkeyword_for:
 yWriteNodekeyword_for (yyt); break;
 default: ;
 }
}

static short yyIndentLevel;

void WriteTree
# ifdef HAVE_ARGS
 (FILE * yyyf, tTree yyt)
# else
 (yyyf, yyt) FILE * yyyf; tTree yyt;
# endif
{
 short yySaveLevel = yyIndentLevel;
 yyf = yyyf;
 yyMark (yyt);
 yyIndentLevel = 0;
 yyBeginTreeStore ();
 yyWriteTree (yyt);
 yyCloseTreeStore ();
 yyIndentLevel = yySaveLevel;
 if (ferror (yyyf)) {
  ErrorMessageI (xxTreeIOError, xxFatal, NoPosition, xxString, "Tree.WriteTree");
  Tree_Exit ();
 }
}

static void yyIndentSelector
# ifdef HAVE_ARGS
 (char * yys)
# else
 (yys) char * yys;
# endif
{
 register int yyi;
 for (yyi = 1; yyi <= yyIndentLevel; yyi ++) putc (' ', yyf);
 yyWriteSelector (yys);
}

static void yyIndentSelectorTree
# ifdef HAVE_ARGS
 (char * yys, tTree yyt)
# else
 (yys, yyt) char * yys; tTree yyt;
# endif
{ writeSELECTOR (yys); yyWriteTree (yyt); }

static void yWritePROGRAM
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
{ writeSELECTOR ("Pos");
writetPosition (yyt->PROGRAM.Pos) xxWriteNl (); }
}

static void yWriteprogram
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWritePROGRAM (yyt);
{ writeSELECTOR ("Ident");
writetIdent (yyt->program.Ident) xxWriteNl (); }
}

static void yWriteblocklist
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyIndentSelectorTree ("Next", yyt->blocklist.Next);
}

static void yWritedeclaration
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
}

static void yWriteassignment
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
}

static void yWritekeyword
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
}

static void yWriteDECLARATION
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
{ writeSELECTOR ("Pos");
writetPosition (yyt->DECLARATION.Pos) xxWriteNl (); }
}

static void yWritedecl_ident
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteDECLARATION (yyt);
{ writeSELECTOR ("Value");
writetIdent (yyt->decl_ident.Value) xxWriteNl (); }
{ writeSELECTOR ("Ident");
writetIdent (yyt->decl_ident.Ident) xxWriteNl (); }
}

static void yWritedecl_assignm
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteDECLARATION (yyt);
{ writeSELECTOR ("Value");
writetIdent (yyt->decl_assignm.Value) xxWriteNl (); }
}

static void yWriteASSIGNMENT
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
{ writeSELECTOR ("Pos");
writetPosition (yyt->ASSIGNMENT.Pos) xxWriteNl (); }
}

static void yWriteassign
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteASSIGNMENT (yyt);
{ writeSELECTOR ("Ident");
writetIdent (yyt->assign.Ident) xxWriteNl (); }
}

static void yWriteCOMPUTATION
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
{ writeSELECTOR ("Pos");
writetPosition (yyt->COMPUTATION.Pos) xxWriteNl (); }
}

static void yWritebinary_comp
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Op");
writechar (yyt->binary_comp.Op) xxWriteNl (); }
 yyIndentSelectorTree ("Left", yyt->binary_comp.Left);
}

static void yWriteint_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Value");
writeint (yyt->int_const.Value) xxWriteNl (); }
}

static void yWritefloat_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Value");
writedouble (yyt->float_const.Value) xxWriteNl (); }
}

static void yWriteunary_comp
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Op");
writechar (yyt->unary_comp.Op) xxWriteNl (); }
}

static void yWritestring_const
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Value");
writetIdent (yyt->string_const.Value) xxWriteNl (); }
}

static void yWriteidentifier
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yWriteCOMPUTATION (yyt);
{ writeSELECTOR ("Ident");
writetIdent (yyt->identifier.Ident) xxWriteNl (); }
}

static void yWritekeyword_if
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyIndentSelectorTree ("Cond", yyt->keyword_if.Cond);
 yyIndentSelectorTree ("Block", yyt->keyword_if.Block);
}

static void yWritekeyword_else
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
}

static void yWritekeyword_while
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyIndentSelectorTree ("Cond", yyt->keyword_while.Cond);
}

static void yWritekeyword_for
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 yyIndentSelectorTree ("Decl", yyt->keyword_for.Decl);
 yyIndentSelectorTree ("Cond", yyt->keyword_for.Cond);
 yyIndentSelectorTree ("Ass", yyt->keyword_for.Ass);
}

static void yyWriteTree
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{ unsigned short yyLevel = yyIndentLevel;
 for (;;) {
  if (yyt == NoTree) { fputs (" NoTree\n", yyf); goto yyExit;
  } else if (yyt->yyHead.yyMark == 0) {
   fprintf (yyf, "^%d\n", yyMapToLabel (yyt)); goto yyExit;
  } else if (yyt->yyHead.yyMark > 1) {
   register int yyi;
   fprintf (yyf, "\n%06d:", yyMapToLabel (yyt));
   for (yyi = 8; yyi <= yyIndentLevel; yyi ++) putc (' ', yyf);
  } else putc (' ', yyf);
  yyt->yyHead.yyMark = 0;
  yyIndentLevel += 2;

  fputs (Tree_NodeName [yyt->Kind], yyf); fputc ('\n', yyf);
  writeNodeHead (yyt)
  switch (yyt->Kind) {
case kPROGRAM: yWritePROGRAM (yyt); goto yyExit;
case kprogram: yWriteprogram (yyt);
writeSELECTOR ("Block");
yyt = yyt->program.Block; break;
case kblocklist: yWriteblocklist (yyt);
writeSELECTOR ("Stmt");
yyt = yyt->blocklist.Stmt; break;
case kdeclaration: yWritedeclaration (yyt);
writeSELECTOR ("Next");
yyt = yyt->declaration.Next; break;
case kassignment: yWriteassignment (yyt);
writeSELECTOR ("Next");
yyt = yyt->assignment.Next; break;
case kkeyword: yWritekeyword (yyt);
writeSELECTOR ("Next");
yyt = yyt->keyword.Next; break;
case kDECLARATION: yWriteDECLARATION (yyt); goto yyExit;
case kdecl_ident: yWritedecl_ident (yyt); goto yyExit;
case kdecl_assignm: yWritedecl_assignm (yyt);
writeSELECTOR ("Right");
yyt = yyt->decl_assignm.Right; break;
case kASSIGNMENT: yWriteASSIGNMENT (yyt); goto yyExit;
case kassign: yWriteassign (yyt);
writeSELECTOR ("Right");
yyt = yyt->assign.Right; break;
case kCOMPUTATION: yWriteCOMPUTATION (yyt); goto yyExit;
case kbinary_comp: yWritebinary_comp (yyt);
writeSELECTOR ("Right");
yyt = yyt->binary_comp.Right; break;
case kint_const: yWriteint_const (yyt); goto yyExit;
case kfloat_const: yWritefloat_const (yyt); goto yyExit;
case kunary_comp: yWriteunary_comp (yyt);
writeSELECTOR ("Argument");
yyt = yyt->unary_comp.Argument; break;
case kstring_const: yWritestring_const (yyt); goto yyExit;
case kidentifier: yWriteidentifier (yyt); goto yyExit;
case kkeyword_if: yWritekeyword_if (yyt);
writeSELECTOR ("ElseIf");
yyt = yyt->keyword_if.ElseIf; break;
case kkeyword_else: yWritekeyword_else (yyt);
writeSELECTOR ("Block");
yyt = yyt->keyword_else.Block; break;
case kkeyword_while: yWritekeyword_while (yyt);
writeSELECTOR ("Block");
yyt = yyt->keyword_while.Block; break;
case kkeyword_for: yWritekeyword_for (yyt);
writeSELECTOR ("Block");
yyt = yyt->keyword_for.Block; break;
  default: goto yyExit;
  }
 }
yyExit:
 yyIndentLevel = yyLevel;
}

static Tree_tProcTree yyProc;

static void yyTraverseTreeTD
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 for (;;) {
  if (yyt == NoTree || yyt->yyHead.yyMark == 0) return;
  yyProc (yyt);
  yyt->yyHead.yyMark = 0;

  switch (yyt->Kind) {
case kprogram:
yyt = yyt->program.Block; break;
case kblocklist:
yyTraverseTreeTD (yyt->blocklist.Next);
yyt = yyt->blocklist.Stmt; break;
case kdeclaration:
yyt = yyt->declaration.Next; break;
case kassignment:
yyt = yyt->assignment.Next; break;
case kkeyword:
yyt = yyt->keyword.Next; break;
case kdecl_assignm:
yyt = yyt->decl_assignm.Right; break;
case kassign:
yyt = yyt->assign.Right; break;
case kbinary_comp:
yyTraverseTreeTD (yyt->binary_comp.Left);
yyt = yyt->binary_comp.Right; break;
case kunary_comp:
yyt = yyt->unary_comp.Argument; break;
case kkeyword_if:
yyTraverseTreeTD (yyt->keyword_if.Cond);
yyTraverseTreeTD (yyt->keyword_if.Block);
yyt = yyt->keyword_if.ElseIf; break;
case kkeyword_else:
yyt = yyt->keyword_else.Block; break;
case kkeyword_while:
yyTraverseTreeTD (yyt->keyword_while.Cond);
yyt = yyt->keyword_while.Block; break;
case kkeyword_for:
yyTraverseTreeTD (yyt->keyword_for.Decl);
yyTraverseTreeTD (yyt->keyword_for.Cond);
yyTraverseTreeTD (yyt->keyword_for.Ass);
yyt = yyt->keyword_for.Block; break;
  default: return;
  }
 }
}

void TraverseTreeTD
# ifdef HAVE_ARGS
 (tTree yyt, Tree_tProcTree yyyProc)
# else
 (yyt, yyyProc) tTree yyt; Tree_tProcTree yyyProc;
# endif
{
# ifdef SUPPORT_TVA
 rbool yyPrevTreatTVAasChild = Tree_TreatTVAasChild;
 Tree_TreatTVAasChild = rfalse;
 yyMark (yyt);
 Tree_TreatTVAasChild = yyPrevTreatTVAasChild;
# else
 yyMark (yyt);
# endif
 yyProc = yyyProc;
 yyTraverseTreeTD (yyt);
}

tTree ReverseTree
# ifdef HAVE_ARGS
 (tTree yyOld)
# else
 (yyOld) tTree yyOld;
# endif
{
 register tTree yyNew, yyNext, yyTail;
 yyNew = yyOld;
 yyTail = yyOld;
 for (;;) {
  switch (yyOld->Kind) {
  default: goto yyExit;
  }
  yyNew = yyOld;
  yyOld = yyNext;
 }
yyExit:
 switch (yyTail->Kind) {
 default: ;
 }
 return yyNew;
}

void ForallTree
# ifdef HAVE_ARGS
 (tTree yyt, Tree_tProcTree yyProc)
# else
 (yyt, yyProc) tTree yyt; Tree_tProcTree yyProc;
# endif
{
 for (;;) {
  tTree yyyt;
  if ((yyyt = yyt) == NoTree) return;
  switch (yyt->Kind) {
  default: return;
  }
  yyProc (yyyt);
 }
}

static rbool yyResult;

static void yyCheckTree ARGS ((tTree yyt));

rbool CheckTree
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
# ifdef SUPPORT_TVA
 rbool yyPrevTreatTVAasChild = Tree_TreatTVAasChild;
 Tree_TreatTVAasChild = rfalse;
 yyMark (yyt);
 Tree_TreatTVAasChild = yyPrevTreatTVAasChild;
# else
 yyMark (yyt);
# endif
 yyResult = rtrue;
 yyCheckTree (yyt);
 return yyResult;
}

static void yyCheckChild2
# ifdef HAVE_ARGS
 (tTree yyParent, tTree yyChild, Tree_tKind yyType, char * yySelector)
# else
 (yyParent, yyChild, yyType, yySelector)
 tTree yyParent, yyChild;
 Tree_tKind yyType;
 char * yySelector;
# endif
{
 if (yyChild == NoTree) {
  if (Tree_CheckReportNoTree) goto yyReport;
 } else if (yyType > yyChild->Kind || yyChild->Kind > Tree_TypeRange [yyType]) {
yyReport: yyResult = rfalse;
  fprintf (stderr, "%s\n", CodeToText (xxCheckTreeError));
  fprintf (stderr, "   %s %p\n", CodeToText (xxCheckTreeAddrOfParent), (void *) yyParent);
  fprintf (stderr, "   %s %s\n", CodeToText (xxCheckTreeTypeOfParent), Tree_NodeName [yyParent->Kind]);
  fprintf (stderr, "   %s %s\n", CodeToText (xxCheckTreeNameOfChild), yySelector);
  if (yyChild == NoTree)
   fprintf (stderr, "   %s NoTree\n", CodeToText (xxCheckTreeValueOfChild));
  else {
   fprintf (stderr, "   %s %p\n", CodeToText (xxCheckTreeAddrOfChild), (void *) yyChild);
   fprintf (stderr, "   %s %s\n", CodeToText (xxCheckTreeTypeOfChild), Tree_NodeName [yyChild->Kind]);
  }
  fprintf (stderr, "   %s %s\n", CodeToText (xxCheckTreeExpectedType), Tree_NodeName [yyType]);
  if (Tree_CheckReportNodes) {
   fprintf (stderr, "   %s\n", CodeToText (xxCheckTreeParentNode));
   WriteTreeNode (stderr, yyParent);
   fprintf (stderr, "   %s\n", CodeToText (xxCheckTreeChildNode));
   WriteTreeNode (stderr, yyChild);
  }
  fputc ('\n', stderr);
 }
}

static void yyCheckChild
# ifdef HAVE_ARGS
 (tTree yyParent, tTree yyChild, Tree_tKind yyType, char * yySelector)
# else
 (yyParent, yyChild, yyType, yySelector)
 tTree yyParent, yyChild;
 Tree_tKind yyType;
 char * yySelector;
# endif
{
 yyCheckChild2 (yyParent, yyChild, yyType, yySelector);
 yyCheckTree (yyChild);
}

static void yyCheckTree
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 for (;;) {
  if (yyt == NoTree) { if (Tree_CheckReportNoTree) yyResult = rfalse; return; }
  if (yyt->yyHead.yyMark == 0) return;
  yyt->yyHead.yyMark = 0;

  switch (yyt->Kind) {
case kprogram:
yyCheckChild2 (yyt, yyt->program.Block,
kBLOCKEXEC, "Block");
yyt = yyt->program.Block; break;
case kblocklist:
yyCheckChild (yyt, yyt->blocklist.Next,
kBLOCKEXEC, "Next");
yyCheckChild2 (yyt, yyt->blocklist.Stmt,
kSTATEMENT, "Stmt");
yyt = yyt->blocklist.Stmt; break;
case kdeclaration:
yyCheckChild2 (yyt, yyt->declaration.Next,
kDECLARATION, "Next");
yyt = yyt->declaration.Next; break;
case kassignment:
yyCheckChild2 (yyt, yyt->assignment.Next,
kASSIGNMENT, "Next");
yyt = yyt->assignment.Next; break;
case kkeyword:
yyCheckChild2 (yyt, yyt->keyword.Next,
kKEYWORD, "Next");
yyt = yyt->keyword.Next; break;
case kdecl_assignm:
yyCheckChild2 (yyt, yyt->decl_assignm.Right,
kASSIGNMENT, "Right");
yyt = yyt->decl_assignm.Right; break;
case kassign:
yyCheckChild2 (yyt, yyt->assign.Right,
kCOMPUTATION, "Right");
yyt = yyt->assign.Right; break;
case kbinary_comp:
yyCheckChild (yyt, yyt->binary_comp.Left,
kCOMPUTATION, "Left");
yyCheckChild2 (yyt, yyt->binary_comp.Right,
kCOMPUTATION, "Right");
yyt = yyt->binary_comp.Right; break;
case kunary_comp:
yyCheckChild2 (yyt, yyt->unary_comp.Argument,
kCOMPUTATION, "Argument");
yyt = yyt->unary_comp.Argument; break;
case kkeyword_if:
yyCheckChild (yyt, yyt->keyword_if.Cond,
kCOMPUTATION, "Cond");
yyCheckChild (yyt, yyt->keyword_if.Block,
kBLOCKEXEC, "Block");
yyCheckChild2 (yyt, yyt->keyword_if.ElseIf,
kKEYWORD, "ElseIf");
yyt = yyt->keyword_if.ElseIf; break;
case kkeyword_else:
yyCheckChild2 (yyt, yyt->keyword_else.Block,
kBLOCKSCOPED, "Block");
yyt = yyt->keyword_else.Block; break;
case kkeyword_while:
yyCheckChild (yyt, yyt->keyword_while.Cond,
kCOMPUTATION, "Cond");
yyCheckChild2 (yyt, yyt->keyword_while.Block,
kBLOCKEXEC, "Block");
yyt = yyt->keyword_while.Block; break;
case kkeyword_for:
yyCheckChild (yyt, yyt->keyword_for.Decl,
kDECLARATION, "Decl");
yyCheckChild (yyt, yyt->keyword_for.Cond,
kCOMPUTATION, "Cond");
yyCheckChild (yyt, yyt->keyword_for.Ass,
kASSIGNMENT, "Ass");
yyCheckChild2 (yyt, yyt->keyword_for.Block,
kBLOCKEXEC, "Block");
yyt = yyt->keyword_for.Block; break;
  default: return;
  }
 }
}

# ifndef EXTERN_C_BEGIN
# define EXTERN_C_BEGIN
# define EXTERN_C_END
# endif

EXTERN_C_BEGIN
# include "Position.h"
EXTERN_C_END

static unsigned long yyLine, yyCurLine;
static tTree yyTheTree, yyNode;
static tIdent yyFile;

static void yySearch4
# ifdef HAVE_ARGS
 (tTree yyt, tPosition yyp)
# else
 (yyt, yyp) tTree yyt; tPosition yyp;
# endif
{
 if ((yyFile == NoIdent || yyFile == yyp.FileName) &&
   yyLine <= yyp.Line && yyp.Line < yyCurLine)
  { yyNode = yyt; yyCurLine = yyp.Line; }
}

static void yySearch2
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 switch (yyt->Kind) {
case kPROGRAM:
yySearch4 (yyt, yyt->PROGRAM.Pos);
break;
case kprogram:
yySearch4 (yyt, yyt->program.Pos);
break;
case kDECLARATION:
yySearch4 (yyt, yyt->DECLARATION.Pos);
break;
case kdecl_ident:
yySearch4 (yyt, yyt->decl_ident.Pos);
break;
case kdecl_assignm:
yySearch4 (yyt, yyt->decl_assignm.Pos);
break;
case kASSIGNMENT:
yySearch4 (yyt, yyt->ASSIGNMENT.Pos);
break;
case kassign:
yySearch4 (yyt, yyt->assign.Pos);
break;
case kCOMPUTATION:
yySearch4 (yyt, yyt->COMPUTATION.Pos);
break;
case kbinary_comp:
yySearch4 (yyt, yyt->binary_comp.Pos);
break;
case kint_const:
yySearch4 (yyt, yyt->int_const.Pos);
break;
case kfloat_const:
yySearch4 (yyt, yyt->float_const.Pos);
break;
case kunary_comp:
yySearch4 (yyt, yyt->unary_comp.Pos);
break;
case kstring_const:
yySearch4 (yyt, yyt->string_const.Pos);
break;
case kidentifier:
yySearch4 (yyt, yyt->identifier.Pos);
break;
 }
}

# include <tcl.h>
# include <tk.h>

# if (TCL_MAJOR_VERSION >= 8) && (TCL_MINOR_VERSION >= 4)
#  define AST_CONST const
# else
#  define AST_CONST
# endif

# define yyMaxCoord		65535
# define yyIsBusy		65535
# define yyTruncByDepth	65535
# define yyTruncByLength	65534
static Tcl_Interp * yygInterp;

static int yySearch
# ifdef HAVE_ARGS
 (ClientData yyclass, Tcl_Interp * yyinterp, int yyargc, AST_CONST char * yyargv [])
# else
 (yyclass, yyinterp, yyargc, yyargv)
 ClientData	yyclass;
 Tcl_Interp *	yyinterp;
 int		yyargc;
 char *	yyargv [];
# endif
{
 tTree yyTheTree = (tTree) atol (yyargv [1]);
 char yyArray [32];
 yyLine = atol (yyargv [2]);
 yyFile = yyargv [3][0] == '\0' ? NoIdent : MakeIdent1 (yyargv [3]);
 yyCurLine = 1000000;
 yyNode = yyTheTree;
 TraverseTreeTD (yyTheTree, yySearch2);
 sprintf (yyArray, "%lu", (unsigned long) yyNode);
 Tcl_SetResult (yyinterp, yyArray, TCL_VOLATILE);
 return TCL_OK;
}

static rbool yyphase1;
static int yymaxx, yymaxy;

static int yySetY
# ifdef HAVE_ARGS
 (tTree yyp, tTree yyt, int yyy, int yyk, int yyl)
# else
 (yyp, yyt, yyy, yyk, yyl) tTree yyp, yyt; int yyy, yyk, yyl;
# endif
{
 int yy, yymax = ++ yyy;
 if (yyphase1) {
  if (yyt == NoTree || (yyt->yyHead.yyMark == 0 &&
   (yyt->yyHead.yyx == yyIsBusy || yyt->yyHead.yyy >= (unsigned short) yyy ||
    yyp->yyHead.yyy >= yyTruncByLength)))
   return yymax;
  yyt->yyHead.yyparent = yyp;
  yyt->yyHead.yyx = yyIsBusy;
 } else {
  if (yyt == NoTree ||
   yyt->yyHead.yyMark == 0 || yyt->yyHead.yyparent != yyp) return yymax;
 }
 yyt->yyHead.yyMark = 0;
 if (++ yyl > Tree_DrawLength) yyk = Tree_DrawDepth;
 yyk ++;
 yyt->yyHead.yyy = (unsigned short) (yyk <= Tree_DrawDepth ? 0 : yyTruncByDepth);
 switch (yyt->Kind) {
case kprogram:
yy = yySetY (yyt, yyt->program.Block, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kblocklist:
yy = yySetY (yyt, yyt->blocklist.Next, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->blocklist.Stmt, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kdeclaration:
yy = yySetY (yyt, yyt->declaration.Next, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kassignment:
yy = yySetY (yyt, yyt->assignment.Next, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kkeyword:
yy = yySetY (yyt, yyt->keyword.Next, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kdecl_assignm:
yy = yySetY (yyt, yyt->decl_assignm.Right, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kassign:
yy = yySetY (yyt, yyt->assign.Right, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kbinary_comp:
yy = yySetY (yyt, yyt->binary_comp.Left, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->binary_comp.Right, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kunary_comp:
yy = yySetY (yyt, yyt->unary_comp.Argument, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kkeyword_if:
yy = yySetY (yyt, yyt->keyword_if.Cond, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_if.Block, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_if.ElseIf, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kkeyword_else:
yy = yySetY (yyt, yyt->keyword_else.Block, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kkeyword_while:
yy = yySetY (yyt, yyt->keyword_while.Cond, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_while.Block, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
case kkeyword_for:
yy = yySetY (yyt, yyt->keyword_for.Decl, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_for.Cond, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_for.Ass, yyy, yyk, 0);
yymax = Max (yymax, yy);
yy = yySetY (yyt, yyt->keyword_for.Block, yyy, yyk, 0);
yymax = Max (yymax, yy);
break;
 }
 yyt->yyHead.yyx = 0;
 if (yyl > Tree_DrawLength) {
  yyt->yyHead.yyy = yyTruncByLength;
  return yyy;
 } else if (yyk > Tree_DrawDepth) {
  yyt->yyHead.yyy = yyTruncByDepth;
  return yyy;
 } else {
  yyt->yyHead.yyy = (unsigned short) yyy;
  yymaxy = Max (yymaxy, yyy);
  return yymax;
 }
}

typedef struct { unsigned short yyfirst, yylast; } yytFirstLast;

static int yySetX
# ifdef HAVE_ARGS
 (tTree yyp, tTree yyt, int yyx, yytFirstLast * yyout)
# else
 (yyp, yyt, yyx, yyout) tTree yyp, yyt; int yyx; yytFirstLast * yyout;
# endif
{
 int yyxin = yyx, yyw;
 yytFirstLast yyFirstLast;
 if (yyt == NoTree || yyt->yyHead.yyMark == 0 ||
  yyt->yyHead.yyparent != yyp) return yyx;
 yyt->yyHead.yyMark = 0;
 yyFirstLast.yyfirst = yyMaxCoord;
 yyFirstLast.yylast = 0;
 switch (yyt->Kind) {
case kprogram:
yyx = yySetX (yyt, yyt->program.Block, yyx, & yyFirstLast);
break;
case kblocklist:
yyx = yySetX (yyt, yyt->blocklist.Next, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->blocklist.Stmt, yyx, & yyFirstLast);
break;
case kdeclaration:
yyx = yySetX (yyt, yyt->declaration.Next, yyx, & yyFirstLast);
break;
case kassignment:
yyx = yySetX (yyt, yyt->assignment.Next, yyx, & yyFirstLast);
break;
case kkeyword:
yyx = yySetX (yyt, yyt->keyword.Next, yyx, & yyFirstLast);
break;
case kdecl_assignm:
yyx = yySetX (yyt, yyt->decl_assignm.Right, yyx, & yyFirstLast);
break;
case kassign:
yyx = yySetX (yyt, yyt->assign.Right, yyx, & yyFirstLast);
break;
case kbinary_comp:
yyx = yySetX (yyt, yyt->binary_comp.Left, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->binary_comp.Right, yyx, & yyFirstLast);
break;
case kunary_comp:
yyx = yySetX (yyt, yyt->unary_comp.Argument, yyx, & yyFirstLast);
break;
case kkeyword_if:
yyx = yySetX (yyt, yyt->keyword_if.Cond, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_if.Block, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_if.ElseIf, yyx, & yyFirstLast);
break;
case kkeyword_else:
yyx = yySetX (yyt, yyt->keyword_else.Block, yyx, & yyFirstLast);
break;
case kkeyword_while:
yyx = yySetX (yyt, yyt->keyword_while.Cond, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_while.Block, yyx, & yyFirstLast);
break;
case kkeyword_for:
yyx = yySetX (yyt, yyt->keyword_for.Decl, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_for.Cond, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_for.Ass, yyx, & yyFirstLast);
yyx = yySetX (yyt, yyt->keyword_for.Block, yyx, & yyFirstLast);
break;
 }
 if (yyt->yyHead.yyy >= yyTruncByLength) {
  return yyxin;
 } else {
  yyt->yyHead.yyx = (unsigned short) (yyFirstLast.yyfirst == yyMaxCoord ? yyx :
   (yyFirstLast.yyfirst + yyFirstLast.yylast) / 2);
  yymaxx = Max ((unsigned short) yymaxx, yyt->yyHead.yyx);
  if (yyt->yyHead.yyparent == yyp) {
   if (yyout->yyfirst == yyMaxCoord) yyout->yyfirst = yyt->yyHead.yyx;
   yyout->yylast = yyt->yyHead.yyx;
  }
  yyxin ++;
  return Max (yyx, yyxin);
 }
yyList:
 if (yyt->yyHead.yyy >= yyTruncByLength) {
  return yyxin;
 } else {
  yyt->yyHead.yyx = (unsigned short) yyxin;
  yymaxx = Max (yymaxx, yyxin);
  if (yyt->yyHead.yyparent == yyp) {
   if (yyout->yyfirst == yyMaxCoord) yyout->yyfirst = yyt->yyHead.yyx;
   yyout->yylast = yyt->yyHead.yyx;
  }
  return Max (yyx, yyw);
 }
}

static void yyDrawEdge
# ifdef HAVE_ARGS
 (tTree yyfrom, tTree yyto)
# else
 (yyfrom, yyto) tTree yyfrom, yyto;
# endif
{
 char yyCoord [32];
 if (yyto == NoTree) return;
 if (yyto->yyHead.yyy < yyTruncByLength)
  sprintf (yyCoord, "%d %d %d %d", yyfrom->yyHead.yyx, yyfrom->yyHead.yyy,
   yyto->yyHead.yyx, yyto->yyHead.yyy);
 else if (yyto->yyHead.yyy == yyTruncByDepth)
  sprintf (yyCoord, "%d %d %d %d 1", yyfrom->yyHead.yyx, yyfrom->yyHead.yyy,
   yyfrom->yyHead.yyx + 1, yyfrom->yyHead.yyy);
 else
  sprintf (yyCoord, "%d %d %d %d 1", yyfrom->yyHead.yyx, yyfrom->yyHead.yyy,
   yyfrom->yyHead.yyx, yyfrom->yyHead.yyy + 1);
 Tcl_VarEval (yygInterp, "draw_edge ", yyCoord, NULL);
}

static void yyDrawNode
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 char yyCoord [32];
 if (yyt->yyHead.yyy >= yyTruncByLength) return;
 sprintf (yyCoord, "%d %d %lu ", yyt->yyHead.yyx, yyt->yyHead.yyy, (unsigned long) yyt);
 Tcl_VarEval (yygInterp, "draw_node ", yyCoord,
  Tree_NodeName [yyt->Kind], NULL);
 switch (yyt->Kind) {
case kprogram:
yyDrawEdge (yyt, yyt->program.Block);
break;
case kblocklist:
yyDrawEdge (yyt, yyt->blocklist.Next);
yyDrawEdge (yyt, yyt->blocklist.Stmt);
break;
case kdeclaration:
yyDrawEdge (yyt, yyt->declaration.Next);
break;
case kassignment:
yyDrawEdge (yyt, yyt->assignment.Next);
break;
case kkeyword:
yyDrawEdge (yyt, yyt->keyword.Next);
break;
case kdecl_assignm:
yyDrawEdge (yyt, yyt->decl_assignm.Right);
break;
case kassign:
yyDrawEdge (yyt, yyt->assign.Right);
break;
case kbinary_comp:
yyDrawEdge (yyt, yyt->binary_comp.Left);
yyDrawEdge (yyt, yyt->binary_comp.Right);
break;
case kunary_comp:
yyDrawEdge (yyt, yyt->unary_comp.Argument);
break;
case kkeyword_if:
yyDrawEdge (yyt, yyt->keyword_if.Cond);
yyDrawEdge (yyt, yyt->keyword_if.Block);
yyDrawEdge (yyt, yyt->keyword_if.ElseIf);
break;
case kkeyword_else:
yyDrawEdge (yyt, yyt->keyword_else.Block);
break;
case kkeyword_while:
yyDrawEdge (yyt, yyt->keyword_while.Cond);
yyDrawEdge (yyt, yyt->keyword_while.Block);
break;
case kkeyword_for:
yyDrawEdge (yyt, yyt->keyword_for.Decl);
yyDrawEdge (yyt, yyt->keyword_for.Cond);
yyDrawEdge (yyt, yyt->keyword_for.Ass);
yyDrawEdge (yyt, yyt->keyword_for.Block);
break;
 }
}

static int yyPutAttr
# ifdef HAVE_ARGS
 (ClientData yyclass, Tcl_Interp * yyinterp, int yyargc, AST_CONST char * yyargv [])
# else
 (yyclass, yyinterp, yyargc, yyargv)
 ClientData	yyclass;
 Tcl_Interp *	yyinterp;
 int		yyargc;
 char *	yyargv [];
# endif
{
 FILE * yyf = fopen ("yyNode", "w");
 if (yyf) {
  WriteTreeNode (yyf, (tTree) atol (yyargv [1]));
  fclose (yyf);
 } else {
  Tcl_SetResult (yyinterp, CodeToText (xxDrawTreeyyNode), TCL_STATIC);
 }
 return TCL_OK;
}

static void yyDrawTree (tTree yyt, ClientData yyclass);

static int yyDrawSubTree
# ifdef HAVE_ARGS
 (ClientData yyclass, Tcl_Interp * yyinterp, int yyargc, AST_CONST char * yyargv [])
# else
 (yyclass, yyinterp, yyargc, yyargv)
 ClientData	yyclass;
 Tcl_Interp *	yyinterp;
 int		yyargc;
 char *	yyargv [];
# endif
{
 DrawTree ((tTree) atol (yyargv [1]));
 return TCL_OK;
}

# ifndef DrawAttr
# define DrawAttr(x, y)
# endif

static int yyCallAttr
# ifdef HAVE_ARGS
 (ClientData yyclass, Tcl_Interp * yyinterp, int yyargc, AST_CONST char * yyargv [])
# else
 (yyclass, yyinterp, yyargc, yyargv)
 ClientData	yyclass;
 Tcl_Interp *	yyinterp;
 int		yyargc;
 char *	yyargv [];
# endif
{
 DrawAttr ((tTree) atol (yyargv [1]), (char *) yyargv [2]);
 return TCL_OK;
}

static int yySetParam
# ifdef HAVE_ARGS
 (ClientData yyclass, Tcl_Interp * yyinterp, int yyargc, AST_CONST char * yyargv [])
# else
 (yyclass, yyinterp, yyargc, yyargv)
 ClientData	yyclass;
 Tcl_Interp *	yyinterp;
 int		yyargc;
 char *	yyargv [];
# endif
{
 Tree_DrawDepth     = atoi (yyargv [1]);
 Tree_DrawLength    = atoi (yyargv [2]);
 Tree_DrawBoxWidth  = atoi (yyargv [3]);
 Tree_DrawBoxHeight = atoi (yyargv [4]);
 strncpy (Tree_DrawFileName, yyargv [5], 256);
 Tree_DrawFileName [255] = '\0';
 return TCL_OK;
}

void SetDepthTree
# ifdef HAVE_ARGS
 (int yyDepth)
# else
 (yyDepth) int yyDepth;
# endif
{
 Tree_DrawDepth = yyDepth;
}

void SetBoxTree
# ifdef HAVE_ARGS
 (int yyWidth, int yyHeight)
# else
 (yyWidth, yyHeight) int yyWidth, yyHeight;
# endif
{
 Tree_DrawBoxWidth  = yyWidth;
 Tree_DrawBoxHeight = yyHeight;
}

static void yyDrawTree
# ifdef HAVE_ARGS
 (tTree yyt, ClientData yyclass)
# else
 (yyt, yyclass) tTree yyt; ClientData yyclass;
# endif
{
 char yyString [128];
 yytFirstLast yyDummy;
# ifdef SUPPORT_TVA
 rbool yyPrevTreatTVAasChild = Tree_TreatTVAasChild;
 Tree_TreatTVAasChild = rfalse;
# endif
 yyDummy.yyfirst = yyMaxCoord;
 yymaxx = yymaxy = 0;
 yyMark (yyt); yyphase1 = rtrue ;
 yySetY ((tTree) & yyt, yyt, 0, 0, 0);
 yyMark (yyt); yyphase1 = rfalse;
 yySetY ((tTree) & yyt, yyt, 0, 0, 0);
 yyMark (yyt);
 yySetX ((tTree) & yyt, yyt, 0, & yyDummy);
 yymaxx = Max (yymaxx, 16);
 yymaxy = Max (yymaxy, 16);
 sprintf (yyString, "%d %d %d %d %d %d {%s}", yymaxx, yymaxy, Tree_DrawBoxWidth, Tree_DrawBoxHeight, Tree_DrawDepth, Tree_DrawLength, Tree_DrawFileName);
 Tcl_VarEval (yygInterp, "draw_tree ", yyString, NULL);
 TraverseTreeTD (yyt, yyDrawNode);
# ifdef SUPPORT_TVA
 Tree_TreatTVAasChild = yyPrevTreatTVAasChild;
# endif
}

void DrawTree
# ifdef HAVE_ARGS
 (tTree yyt)
# else
 (yyt) tTree yyt;
# endif
{
 int yyCode;
 Tcl_Interp * yyInterp;
 char yyPath [256], * yyp;

 Tcl_FindExecutable ("");
 yygInterp = yyInterp = Tcl_CreateInterp ();
 yyCode = Tcl_Init (yyInterp);
 if (yyCode != TCL_OK) {
  ErrorMessageI (xxTclTkError, xxError, NoPosition, xxString, Tcl_GetStringResult (yyInterp));
  goto yyReturn;
 }
 yyCode = Tk_Init (yyInterp);
 if (yyCode != TCL_OK) {
  ErrorMessageI (xxTclTkError, xxError, NoPosition, xxString, Tcl_GetStringResult (yyInterp));
  goto yyReturn;
 }
 Tcl_StaticPackage (yyInterp, "Tk", Tk_Init, (Tcl_PackageInitProc *) NULL);

 Tcl_CreateCommand (yyInterp, "put_attr", yyPutAttr, (ClientData) NULL, NULL);
 Tcl_CreateCommand (yyInterp, "search_pos", yySearch, (ClientData) NULL, NULL);
 Tcl_CreateCommand (yyInterp, "draw_subtree", yyDrawSubTree, (ClientData) NULL, NULL);
 Tcl_CreateCommand (yyInterp, "call_attr", yyCallAttr, (ClientData) NULL, NULL);
 Tcl_CreateCommand (yyInterp, "set_param", yySetParam, (ClientData) NULL, NULL);
 yyCode = Tcl_EvalFile (yyInterp, "Tree.tcl");
 if (yyCode != TCL_OK) {
  yyp = (char *) getenv ("HOME");
  if (yyp) {
   strcat (strcpy (yyPath, yyp), "/.Tree.tcl");
   yyCode = Tcl_EvalFile (yyInterp, yyPath);
  }
 }
 if (yyCode != TCL_OK) {
  yyp = (char *) getenv ("CT_DIR");
  if (yyp) {
   strcat (strcpy (yyPath, yyp), "/lib/cg/Tree.tcl");
   yyCode = Tcl_EvalFile (yyInterp, yyPath);
  }
 }
 if (yyCode != TCL_OK) {
  yyCode = Tcl_EvalFile (yyInterp, "/home/cocktail/lib/cocktail/cg/Tree.tcl");
 }
 if (yyCode != TCL_OK) {
  ErrorMessageI (xxTclTkError, xxError, NoPosition, xxString, Tcl_GetStringResult (yyInterp));
  goto yyReturn;
 }
 yyDrawTree (yyt, NULL);
 Tk_MainLoop ();
yyReturn: Tcl_DeleteInterp (yyInterp);
}

void ConfigureTree
# ifdef HAVE_ARGS
 (char * yyParameter, char * yyValue)
# else
 (yyParameter, yyValue) char * yyParameter; char * yyValue;
# endif
{
 if (yyParameter == NULL || yyValue == NULL) return;
        if (strcmp (yyParameter, "CheckReportNoTree") == 0) {
  Tree_CheckReportNoTree = atoi (yyValue) != 0;
 } else if (strcmp (yyParameter, "CheckReportNodes") == 0) {
  Tree_CheckReportNodes = atoi (yyValue) != 0;
 } else if (strcmp (yyParameter, "DrawBoxHeight") == 0) {
  Tree_DrawBoxHeight = atoi (yyValue);
 } else if (strcmp (yyParameter, "DrawBoxWidth") == 0) {
  Tree_DrawBoxWidth = atoi (yyValue);
 } else if (strcmp (yyParameter, "DrawDepth") == 0) {
  Tree_DrawDepth = atoi (yyValue);
 } else if (strcmp (yyParameter, "DrawLength") == 0) {
  Tree_DrawLength = atoi (yyValue);
 } else if (strcmp (yyParameter, "DrawFileName") == 0) {
  strncpy (Tree_DrawFileName, yyValue, 256);
  Tree_DrawFileName [255] = '\0';
 } else if (strcmp (yyParameter, "TreatTVAasChild") == 0) {
# ifdef SUPPORT_TVA
  Tree_TreatTVAasChild = atoi (yyValue) != 0;
# endif
 } else {
  ErrorMessageI (xxConfigureUnknownParam, xxError, NoPosition, xxString, yyParameter);
 }
}

void BeginTree ARGS ((void))
{
/* line 36 "expr.ast" */

  /* Target code to be placerd in the BeginTREE() function */

}

void CloseTree ARGS ((void))
{
/* line 40 "expr.ast" */

  /* Target code to be placerd in the CloseTREE() function */

}
