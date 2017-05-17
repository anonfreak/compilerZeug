/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Ausgeben des Baumes
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: write.c.in,v 1.2 2010/04/14 16:11:12 vollmer draft $
 */
# include <stdio.h>
# include <stdlib.h>

 # include "tree.h"
 # include "write.h"

void write (tTree tree)
{
  switch (tree->Kind) {
  case kint_const:
    printf ("%d", tree->int_const.Value);
    break;
  case kunary_expr:
    printf ("%c", tree->unary_expr.Op);
    write  (tree->unary_expr.Arg);
    break;
  case kbinary_expr:
    printf ("(");
    write  (tree->binary_expr.Left);
    printf ("%c", tree->binary_expr.Op);
    write  (tree->binary_expr.Right);
    printf (")");
    break;
  default:
    FATAL_ERROR();
  }
}

