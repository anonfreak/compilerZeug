/* Project:  COCKTAIL training
 * Descr:    Code generation for an expression language and a stack machine
 * Kind:     C-main program
 * Author:   Dr. Juergen Vollmer <juergen.vollmer@informatik-vollmer.de>
 * $Id: main.c,v 1.2 2007/06/03 15:15:34 vollmer draft $
 */

# include <stdlib.h>
# include <stdio.h>
# include "Position.h"
# include "Errors.h"
# include "rGetopt.h"
# include "expr_scan.h"
# include "expr_pars.h"
# include "expr_tree.h"
# include "stack.h"

/*---------------------------------------------------------------------------*/

static int   do_ShowTree  = 0;      /* >= 1, if tree should be shown        */
static int   do_WriteTree = 0;
static rbool do_GenStack  = rtrue;

/*---------------------------------------------------------------------------*/

static void usage (void)
{
  fprintf (stderr,
	   "usage: expr [-h] [-g] [-w] [file...]\n"
	   "  compiler for an expression language, reads `file' or stdin\n"
	   "  -h:   Help\n"
	   "  -g:   AST output\n"
	   "  -gg:  AST output after transformation\n"
           "  -w:   write ASCII output of the AST\n"
	   " Exit exprs: 0: no error, > 0: number of errors\n"
	   " Dr. Jürgen Vollmer, <vollmer@cocolab.de>\n"
	   );
  exit (0);
}

/*---------------------------------------------------------------------------*/

static void ShowTree (texpr_tree tree)
/* call either DrawTREE or WriteTREE, depending on what is compiled in */
{
# ifdef DRAWTREE
  if (do_ShowTree) {
    /* If Tcl/Tk is installed, the compile with -DDRAWTREE */
    Drawexpr_tree (tree);
  }
# endif
# ifdef WRITETREE
  if (do_WriteTree) {
    /*  ASCII-Output of the AST */
    fprintf (stdout, "=================================================\n");
    Writeexpr_tree (stdout, tree);
    fprintf (stdout, "=================================================\n");
  }
# endif
}

/*---------------------------------------------------------------------------*/

static void process (char *filename)
{
  /* initialize the reuse */
  BeginStringMemory ();
  BeginErrors	    ();
  BeginIdents       ();

  /* initialize others */
  Beginexpr_tree    ();
  if (filename != NULL) {
    expr_scan_BeginFile (filename);  /* Read from file, if not called,
				      * the scanner reads stdin.
				      */
    expr_scan_Attribute.Position.FileName = MakeIdent1 (filename);
  }

  Beginexpr_pars ();
  expr_pars      ();
  Closeexpr_pars ();

# ifdef CHECKTREE
  Checkexpr_tree (expr_treeRoot);
# endif

  if (do_ShowTree == 1 || do_WriteTree == 1) {
    ShowTree (expr_treeRoot);
  }

  if (GetCount (xxError) > 0) {
    printf ("Number of errors: %d\n", GetCount (xxError));
  } else {
    if (do_GenStack) {
      fprintf (stdout, "=================================================\n");
      fprintf (stdout, "Expr for the stack machine: `%s'\n",
	               (filename != NULL)? filename: "");
      stack_gen (expr_treeRoot);
      fprintf (stdout, "=================================================\n");
    }
  }
  if (do_ShowTree == 2 || do_WriteTree == 2) {
    ShowTree (expr_treeRoot);
  }


  Closeexpr_tree    ();

  /* reset Reuse */
  CloseIdents       ();
  CloseErrors	    ();
  CloseStringMemory ();
}

/*---------------------------------------------------------------------------*/

int main (int argc, char *argv[])
{
   int opt;

   /* read command line arguments */
   while ((opt = rGetopt (argc, argv, "hrRsgw")) > 0) {
     switch (opt) {
     case 'g':
       do_ShowTree++;
       break;
     case 'w':
       do_WriteTree++;
       break;
     default : usage();
       break;
     }
   }

   # ifdef DRAWTREE
   /* set some parameters of the DrawTREE output */
     SetDepthexpr_tree (20);
     SetBoxexpr_tree   (100, 20);
   # endif

   /* process input files */
   if (rOptind == argc) {
     /* No file given, read from stdin */
     process (NULL);
   } else {
     int i;
     for (i = rOptind; i < argc; i++) {
       process (argv[i]);  /* Read from file */
     }
   }

   return GetCount (xxError);
}

/*---------------------------------------------------------------------------*/
