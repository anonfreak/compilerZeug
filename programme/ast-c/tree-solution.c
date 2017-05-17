/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Typen und Konstruktoren
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: tree.c.in,v 1.3 2010/04/15 17:05:02 vollmer Exp $
 */

# include <stdlib.h>

 # include "tree-solution.h"

tTree mint_const (int Value)
{
  tTree t = (tTree) malloc (sizeof (tint_const));
  t->int_const.Kind  = kint_const;
  t->int_const.Value = Value;
  return t;
}

tTree munary_expr (char Op, tTree Arg)
{
  tTree t = (tTree) malloc (sizeof (tunary_expr));
  t->unary_expr.Kind  = kunary_expr;
  t->unary_expr.Op    = Op;
  t->unary_expr.Arg   = Arg;
  return t;
}

tTree mbinary_expr (char Op, tTree Left, tTree Right)
{
  tTree t = (tTree) malloc (sizeof (tbinary_expr));
  t->binary_expr.Kind  = kbinary_expr;
  t->binary_expr.Op    = Op;
  t->binary_expr.Left  = Left;
  t->binary_expr.Right = Right;
  return t;
}

tTree mcond_expr (tTree Cond, tTree Then, tTree Else)
{
  tTree t = (tTree) malloc (sizeof (tcond_expr));
  t->cond_expr.Kind  = kcond_expr;
  t->cond_expr.Cond  = Cond;
  t->cond_expr.Then  = Then;
  t->cond_expr.Else  = Else;
  return t;
}

tTree mno_exprs (void)
{
  tTree t = (tTree) malloc (sizeof (tno_exprs));
  t->no_exprs.Kind = kno_exprs;
  return t;
}

tTree mexprs (tTree Next, tTree Expr)
{
  tTree t = (tTree) malloc (sizeof (texprs));
  t->exprs.Kind = kexprs;
  t->exprs.Next = Next;
  t->exprs.Expr = Expr;
  return t;
}

tTree reverse (tTree tree)
{
  tTree end  = tree;
  tTree prev = tree;

  /* check for empty list */
  if (tree->Kind == kno_exprs) return tree;

  while (tree->Kind == kexprs) {
    tTree next = tree->exprs.Next;
    tree->exprs.Next = prev;
    prev = tree;
    tree = next;
  }
  end->exprs.Next = tree;
  return prev;
}


