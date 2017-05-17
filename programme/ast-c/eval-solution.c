/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Auswerten des Baumes
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: eval.c.in,v 1.2 2010/04/14 16:11:12 vollmer draft $
 */
# include <stdio.h>
# include <stdlib.h>

 # include "tree-solution.h"
 # include "eval-solution.h"

static double compute (char Op, double Left, double Right)
/* Berechne Ergebnis "Left Op Right" */
{
  switch (Op) {
  case '+': return Left +  Right;
  case '-': return Left -  Right;
  case '*': return Left *  Right;
  case '/': return Left /  Right;
  case '<': return Left <  Right ? 1.0 : 0.0;
  case '=': return Left == Right ? 1.0 : 0.0;
  default:
    FATAL_ERROR();
   }
}

double eval (tTree tree)
{
  switch (tree->Kind) {
  case kint_const:
    return tree->int_const.Value;
  case kunary_expr:
    return compute (tree->unary_expr.Op,
		    0.0,
		    eval  (tree->unary_expr.Arg));
  case kbinary_expr:
    return compute (tree->binary_expr.Op,
		    eval (tree->binary_expr.Left),
		    eval (tree->binary_expr.Right));
  case kcond_expr:
    return eval (tree->cond_expr.Cond) ? eval (tree->cond_expr.Then) : eval (tree->cond_expr.Else);
  default:
    FATAL_ERROR();
  }
}

