/* Project:  COCKTAIL training
 * Descr:    Build an AST for an expression language, compute end-positions
 * Kind:     C-main program
 * Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: main.c,v 1.2 2014/12/14 14:51:17 vollmer Exp $
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Position.h"
# include "Errors.h"
# include "expr_scan.h"
# include "expr_pars.h"
# include "expr_tree.h"

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

     /* Note: have to define the EPos.FileName field too! */
     expr_scan_Attribute.Position.FileName =
     expr_scan_Attribute.identifier.EPos.FileName = MakeIdent1 (argv[1]);
     expr_scan_BeginFile (argv[1]);
     /* Read from file argv[1].
      * If this routine is not called, stdin is read.
      */
   }

   errors = expr_pars ();  /* the parser */

   /* check if the AST is constructed correctly */
   if (!Checkexpr_tree (expr_treeRoot)) {
     Message ("the abstract syntax tree is wrong", xxFatal, NoPosition);
   }

   /* call graphical AST browser */
   Drawexpr_tree (expr_treeRoot);

   printf ("parser returned: %d number of errors: %d\n",
	   errors,GetCount (xxError));

   return (errors == 0)? 0 : 1;
}
