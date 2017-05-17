/* Project:  Vorlesung Übersetzerbau
 * Descr:    Aufbau AST in C
 * Kind:     Hauptprogramm
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: main.c.in,v 1.3 2010/04/15 17:04:56 vollmer Exp $
 */

# include <stdio.h>

 # include "tree.h"
 # include "write.h"
 # include "eval.h"


int main (int argc, char *argv[])
{
  printf ("Construction of an AST for expressions\n");

  /* + construct a tree for
   *    -	    1 + -2 * 3
   *    - 	    2 < 3 ? 2 : 3
   * + construct the list of expressions for those two expressions
   * + write_and_eval() that list
   * + reverse() that list and write_and_eval() it.
   */
  printf ("Still much work todo..... :-)\n");

  return 0;
}
