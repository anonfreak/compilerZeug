/* Project:  COCKTAIL training
 * Descr:    A simple pocket computer (scanner, parser, evaluator)
 * Kind:     C-main program
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: main.c,v 1.10 2010/04/26 15:41:14 vollmer Exp vollmer $
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Position.h"
# include "Errors.h"
# include "expr_scan.h"
# include "expr_pars.h"
# include "Tree.h"
# include "expr.h"

int main (int argc, char *argv[])
{
   int errors = 0;
   if (argc == 2) {
     if (strcmp (argv[1], "-h") == 0) {
       fprintf (stderr,
		"usage: %s [-h] [file]\n"
		"  expression LR based parser, reads `file' or stdin\n"
		"  -h: Help\n", argv[0]);
       exit (0);
     }

     expr_scan_Attribute.Position.FileName = MakeIdent1 (argv[1]);
     expr_scan_BeginFile (argv[1]);
     /* Read from file argv[1].
      * If this routine is not called, stdin is read.
      */
   }

   BeginTree(); /* see expr.ast, initialize id_* function names */

   errors = expr_pars ();  /* the parser */
   printf ("parser returned: %d number of errors: %d\n",
	   errors,GetCount (xxError));

   if (!CheckTree (TreeRoot)) {
     fprintf (stderr, "Der Baum ist falsch aufgebaut\n");
     exit (1);
   }

   /* ASCII output of the tree:
    * 	WriteTree (stdout, TreeRoot);
    */

   check_function_calls (TreeRoot);

   return 0;
}
