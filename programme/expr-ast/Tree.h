# ifndef yyTree
# define yyTree

extern char Tree_module_does_not_match_evaluator_module_2851876;
extern char generate_Tree_module_without_option_0;

# include "ratc.h"

# include <stdio.h>
/* line 14 "expr.ast" */

  /* The target-code of this section is copied into the generated .h file
   * before the declaration of the `typedef .... tTREE'
   */


# ifndef rbool
# define rbool char
# endif
# define NoTree (tTree) 0L
# define kPROGRAM 1
# define kprogram 2
# define kBLOCKEXEC 3
# define kblocklist 4
# define kblocknostmt 5
# define kSTATEMENT 6
# define kno_stmt 7
# define kdeclaration 8
# define kassignment 9
# define kkeyword 10
# define kDECLARATION 11
# define kdecl_ident 12
# define kdecl_assignm 13
# define kASSIGNMENT 14
# define kassign 15
# define kCOMPUTATION 16
# define kbinary_comp 17
# define kint_const 18
# define kfloat_const 19
# define kunary_comp 20
# define kstring_const 21
# define kidentifier 22
# define kKEYWORD 23
# define kkeyword_if 24
# define kkeyword_else 25
# define knokeyword 26
# define kkeyword_while 27
# define kkeyword_for 28
# define kBLOCKSCOPED 29
# define yyBlockSize 20480

typedef unsigned char Tree_tKind;
typedef unsigned short Tree_tMark;
typedef unsigned short Tree_tLabel;
typedef union Tree_Node * tTree;
typedef tTree tPROGRAM;
typedef tTree tBLOCKEXEC;
typedef tTree tSTATEMENT;
typedef tTree tDECLARATION;
typedef tTree tASSIGNMENT;
typedef tTree tCOMPUTATION;
typedef tTree tKEYWORD;
typedef tTree tBLOCKSCOPED;
typedef void (* Tree_tProcTree) ARGS ((tTree));
typedef tTree * yytTreePtr;
typedef struct { tTree yyOld, yyNew; } yytTreeOldToNew;

typedef struct yysTree_Block {
 char yyBlock [yyBlockSize];
 struct yysTree_Block * yySuccessor;
} yytTree_Block, * yytTree_BlockPtr;

/* line 20 "expr.ast" */

  /* The target-code of this section is copied into the generated .h file
   * after the declaration of the `typedef .... tTREE', but before
   * the declaration of the tree nodes struct's.
   */

  # include "Position.h"
  # include "Idents.h"

  /* tIdent's for function names */


# define Tree_InitHead(ptr, kind) ptr->Kind = kind; \
   ptr->yyHead.yyMark = 0; \
   beginNodeHead (ptr)
# ifndef Tree_NodeHead
# define Tree_NodeHead unsigned short yyx, yyy; tTree yyparent;
# endif
typedef struct { Tree_tKind yyKind; Tree_tMark yyMark;
 Tree_NodeHead } Tree_tNodeHead;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; } yPROGRAM;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Ident; tTree Block; } yprogram;
typedef struct { Tree_tNodeHead yyHead;
} yBLOCKEXEC;
typedef struct { Tree_tNodeHead yyHead;
tTree Next; tTree Stmt; } yblocklist;
typedef struct { Tree_tNodeHead yyHead;
} yblocknostmt;
typedef struct { Tree_tNodeHead yyHead;
} ySTATEMENT;
typedef struct { Tree_tNodeHead yyHead;
} yno_stmt;
typedef struct { Tree_tNodeHead yyHead;
tTree Next; } ydeclaration;
typedef struct { Tree_tNodeHead yyHead;
tTree Next; } yassignment;
typedef struct { Tree_tNodeHead yyHead;
tTree Next; } ykeyword;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; } yDECLARATION;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Value; tIdent Ident; } ydecl_ident;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Value; tTree Right; } ydecl_assignm;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; } yASSIGNMENT;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Ident; tTree Right; } yassign;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; } yCOMPUTATION;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; char Op; tTree Left; tTree Right; } ybinary_comp;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; int Value; } yint_const;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; double Value; } yfloat_const;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; char Op; tTree Argument; } yunary_comp;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Value; } ystring_const;
typedef struct { Tree_tNodeHead yyHead;
tPosition Pos; tIdent Ident; } yidentifier;
typedef struct { Tree_tNodeHead yyHead;
} yKEYWORD;
typedef struct { Tree_tNodeHead yyHead;
tTree Cond; tTree Block; tTree ElseIf; } ykeyword_if;
typedef struct { Tree_tNodeHead yyHead;
tTree Block; } ykeyword_else;
typedef struct { Tree_tNodeHead yyHead;
} ynokeyword;
typedef struct { Tree_tNodeHead yyHead;
tTree Cond; tTree Block; } ykeyword_while;
typedef struct { Tree_tNodeHead yyHead;
tTree Decl; tTree Cond; tTree Ass; tTree Block; } ykeyword_for;
typedef struct { Tree_tNodeHead yyHead;
} yBLOCKSCOPED;

union Tree_Node {
 Tree_tKind Kind;
 Tree_tNodeHead yyHead;
 yPROGRAM PROGRAM;
 yprogram program;
 yBLOCKEXEC BLOCKEXEC;
 yblocklist blocklist;
 yblocknostmt blocknostmt;
 ySTATEMENT STATEMENT;
 yno_stmt no_stmt;
 ydeclaration declaration;
 yassignment assignment;
 ykeyword keyword;
 yDECLARATION DECLARATION;
 ydecl_ident decl_ident;
 ydecl_assignm decl_assignm;
 yASSIGNMENT ASSIGNMENT;
 yassign assign;
 yCOMPUTATION COMPUTATION;
 ybinary_comp binary_comp;
 yint_const int_const;
 yfloat_const float_const;
 yunary_comp unary_comp;
 ystring_const string_const;
 yidentifier identifier;
 yKEYWORD KEYWORD;
 ykeyword_if keyword_if;
 ykeyword_else keyword_else;
 ynokeyword nokeyword;
 ykeyword_while keyword_while;
 ykeyword_for keyword_for;
 yBLOCKSCOPED BLOCKSCOPED;
};

extern const unsigned short Tree_NodeSize [30];
extern const Tree_tKind Tree_TypeRange [30];
extern const char * const Tree_NodeName [];

extern rbool Tree_CheckReportNoTree, Tree_CheckReportNodes;
extern int Tree_DrawDepth;
extern int Tree_DrawLength;
extern int Tree_DrawBoxWidth;
extern int Tree_DrawBoxHeight;
extern char Tree_DrawFileName [];
# ifdef SUPPORT_TVA
extern rbool Tree_TreatTVAasChild;
# endif

extern tTree TreeRoot;
extern unsigned long Tree_HeapUsed;
extern yytTree_BlockPtr Tree_BlockList;
extern char * Tree_PoolFreePtr, * Tree_PoolStartPtr;

extern void (* Tree_Exit) ARGS ((void));
extern tTree Tree_Alloc ARGS ((unsigned long yySize));
extern tTree MakeTree ARGS ((Tree_tKind yyKind));
extern rbool Tree_IsType ARGS ((register tTree yyt,
 register Tree_tKind yyKind));

extern tTree mPROGRAM
 ARGS ((tPosition pPos));
extern tTree mprogram
 ARGS ((tPosition pPos, tIdent pIdent, tTree pBlock));
extern tTree mBLOCKEXEC
 ARGS ((void));
extern tTree mblocklist
 ARGS ((tTree pNext, tTree pStmt));
extern tTree mblocknostmt
 ARGS ((void));
extern tTree mSTATEMENT
 ARGS ((void));
extern tTree mno_stmt
 ARGS ((void));
extern tTree mdeclaration
 ARGS ((tTree pNext));
extern tTree massignment
 ARGS ((tTree pNext));
extern tTree mkeyword
 ARGS ((tTree pNext));
extern tTree mDECLARATION
 ARGS ((tPosition pPos));
extern tTree mdecl_ident
 ARGS ((tPosition pPos, tIdent pValue, tIdent pIdent));
extern tTree mdecl_assignm
 ARGS ((tPosition pPos, tIdent pValue, tTree pRight));
extern tTree mASSIGNMENT
 ARGS ((tPosition pPos));
extern tTree massign
 ARGS ((tPosition pPos, tIdent pIdent, tTree pRight));
extern tTree mCOMPUTATION
 ARGS ((tPosition pPos));
extern tTree mbinary_comp
 ARGS ((tPosition pPos, char pOp, tTree pLeft, tTree pRight));
extern tTree mint_const
 ARGS ((tPosition pPos, int pValue));
extern tTree mfloat_const
 ARGS ((tPosition pPos, double pValue));
extern tTree munary_comp
 ARGS ((tPosition pPos, char pOp, tTree pArgument));
extern tTree mstring_const
 ARGS ((tPosition pPos, tIdent pValue));
extern tTree midentifier
 ARGS ((tPosition pPos, tIdent pIdent));
extern tTree mKEYWORD
 ARGS ((void));
extern tTree mkeyword_if
 ARGS ((tTree pCond, tTree pBlock, tTree pElseIf));
extern tTree mkeyword_else
 ARGS ((tTree pBlock));
extern tTree mnokeyword
 ARGS ((void));
extern tTree mkeyword_while
 ARGS ((tTree pCond, tTree pBlock));
extern tTree mkeyword_for
 ARGS ((tTree pDecl, tTree pCond, tTree pAss, tTree pBlock));
extern tTree mBLOCKSCOPED
 ARGS ((void));

extern void ReleaseTree ARGS ((tTree yyt));
extern void ReleaseTreeModule ARGS ((void));
extern void WriteTreeNode ARGS ((FILE * yyyf, tTree yyt));
extern tTree ReadTree ARGS ((FILE * yyyf));
extern void WriteTree ARGS ((FILE * yyyf, tTree yyt));
extern void WriteTreeXML ARGS ((FILE * yyyf, tTree yyt));
extern void PutTree ARGS ((FILE * yyyf, tTree yyt));
extern tTree GetTree ARGS ((FILE * yyyf));
extern void TraverseTreeTD ARGS ((tTree yyt, Tree_tProcTree yyyProc));
extern void TraverseTreeBU ARGS ((tTree yyt, Tree_tProcTree yyProc));
extern tTree ReverseTree ARGS ((tTree yyt));
extern void ForallTree ARGS ((tTree yyt, Tree_tProcTree yyProc));
extern tTree CopyTree ARGS ((tTree yyt));
extern rbool IsEqualTree ARGS ((tTree yyt1, tTree yyt2));
extern rbool CheckTree ARGS ((tTree yyt));
extern void QueryTree ARGS ((tTree yyt));
extern void DrawTree ARGS ((tTree yyt));
extern void SetDepthTree ARGS ((int yyDepth));
extern void SetBoxTree ARGS ((int yyWidth, int yyHeight));
extern void ConfigureTree ARGS ((char * yyParameter, char * yyValue));
extern void InitTree ARGS ((register tTree yyt));
extern void BeginTree ARGS ((void));
extern void CloseTree ARGS ((void));

# endif
