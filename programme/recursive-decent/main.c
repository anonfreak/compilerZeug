/* Project:  COCKTAIL training
 * Descr:    A recursive Decent Parser for expressions
 * Kind:     C-main function
 * Author:   Dr. Juergen Vollmer <juergen.vollmer@informatik-vollmer.de>
 * $Id: main.c,v 1.3 2014/11/26 13:08:43 vollmer Exp $
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Position.h"
# include "expr_scan.h"
# include "parser.h"

int
main (int argc, char *argv[])
{
   if (argc == 2) {
     if (strcmp (argv[1], "-h") == 0) {
       fprintf (stderr,
		"usage: parser [-h] [file]\n"
		"  parser for expressions, reads `file' or stdin\n"
		"  -h: Help.\n"
		"Exit-codes:  0 : no Syntaxerrors\n"
		"            -1 : Syntaxerrors found\n");
       exit (0);
     }
     expr_scan_Attribute.Position.FileName = MakeIdent (argv[1], strlen (argv[1]));
     expr_scan_BeginFile (argv[1]);
     /* Read form file, if this is not called the scanner reads form stdin */
   }

   /* get the first token */
   CurToken = expr_scan_GetToken();

   /* Call the parser with the grammar root symbol */
   if (f_E() && match (expr_scan_EofToken)) {
     printf ("*** ok\n");
     return 0;
   } else {
     printf ("*** error\n");
     return -1;
   }
}
