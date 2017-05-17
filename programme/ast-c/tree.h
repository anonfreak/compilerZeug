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


union uTree {
  tTreeKind    Kind;
  tint_const   int_const;
  tunary_expr  unary_expr;
  tbinary_expr binary_expr;
};

/* Konstruktoren */
extern tTree mint_const   (int   Value);
extern tTree munary_expr  (char  Op,   tTree Arg);
extern tTree mbinary_expr (char  Op,   tTree Left, tTree Right);

/* Vereinfachung..... */
# define FATAL_ERROR() {fprintf (stderr, "FATALER FEHLER: %s:%d\n", __FILE__, __LINE__);  abort();}

# endif
