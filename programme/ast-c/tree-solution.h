/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Typen und Konstruktoren
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: tree.h.in,v 1.3 2010/04/15 17:05:07 vollmer Exp $
 */
# ifndef _TREE_H_
# define _TREE_H_

typedef union uTree *tTree;

typedef enum {
   kint_const
  ,kunary_expr
  ,kbinary_expr
  ,kcond_expr
  ,kno_exprs
  ,kexprs
} tTreeKind;

typedef struct sint_const {
  tTreeKind  Kind;
  int        Value;
} tint_const;

typedef struct sunary_expr {
  tTreeKind Kind;
  char     Op;
  tTree    Arg;
} tunary_expr;

typedef struct sbinary_expr {
  tTreeKind Kind;
  char     Op;
  tTree    Left;
  tTree    Right;
} tbinary_expr;

typedef struct scond_expr {
  tTreeKind Kind;
  tTree     Cond;
  tTree     Then;
  tTree     Else;
} tcond_expr;

typedef struct sno_exprs {
  tTreeKind Kind;
} tno_exprs;

typedef struct sexprs {
  tTreeKind Kind;
  tTree     Next;
  tTree     Expr;
} texprs;

union uTree {
  tTreeKind    Kind;
  tint_const   int_const;
  tunary_expr  unary_expr;
  tbinary_expr binary_expr;
  tcond_expr   cond_expr;
  tno_exprs    no_exprs;
  texprs       exprs;
};

/* Konstruktoren */
extern tTree mint_const   (int   Value);
extern tTree munary_expr  (char  Op,   tTree Arg);
extern tTree mbinary_expr (char  Op,   tTree Left, tTree Right);
extern tTree mcond_expr   (tTree Cond, tTree Then, tTree Else);
extern tTree mno_exprs    (void);
extern tTree mexprs       (tTree Next, tTree Expr);

/* Operatoren auf Listen */
extern tTree reverse (tTree tree);

/* Vereinfachung..... */
# define FATAL_ERROR() {fprintf (stderr, "FATALER FEHLER: %s:%d\n", __FILE__, __LINE__);  abort();}

# endif
