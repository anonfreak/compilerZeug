/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Typen und Konstruktoren
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: tree.c.in,v 1.3 2010/04/15 17:05:02 vollmer Exp $
 */

# include <stdlib.h>

 # include "tree.h"

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


