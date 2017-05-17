/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Hauptprogramm
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: main.c.in,v 1.3 2010/04/15 17:04:56 vollmer Exp $
 */

# include <stdio.h>

 # include "tree-solution.h"
 # include "write-solution.h"
 # include "eval-solution.h"

void write_and_eval (tTree tree)
{
  while (tree->Kind == kexprs) {
    write (tree->exprs.Expr);
    printf ("= %5.2f\n", eval(tree->exprs.Expr));
    tree = tree->exprs.Next;
  }
}

int main (int argc, char *argv[])
{
  tTree tree1, tree2, list;
  printf ("Construction of an AST for expressions\n");

  tree1 = mbinary_expr (
           '+',
	   mint_const (1),
	   mbinary_expr (
   	     '*',
	     mint_const (2),
	     mint_const (3)));
  write (tree1); printf ("= %5.2f\n", eval(tree1));

  tree2 = mcond_expr (
	  mbinary_expr (
            '<',
	    mint_const (2),
	    mint_const (3)),
	  mint_const (2),
	  mint_const (3));
  write (tree2); printf ("= %5.2f\n", eval(tree2));

  printf ("List of expressions:\n");
  list = mexprs (
          mexprs (
	   mno_exprs (),
           tree2),
         tree1);
  write_and_eval(list);

  printf ("Reverted list of expressions:\n");
  list = reverse (list);
  write_and_eval(list);

  return 0;
}
