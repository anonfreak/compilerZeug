/*
   Copyright (c) 2001 Dr. Josef Grosch, CoCoLab - Datenverarbeitung

   This file contains proprietary and confidential information and
   remains the property of CoCoLab. Use, disclosure, or reproduction
   is prohibited except as permitted by express written license agreement
   with CoCoLab.

   Phone: +49-7841-669144
   Fax  : +49-7841-669145
   Email: grosch@cocolab.com
*/

/* Project:	Support for tools build by CoCoLab
 * Descr:	A simple preprocessor handling conditional text and text macros
 *              main program
 * Author:	Dr. Juergen Vollmer <vollmer@cocolab.com>
 * $Id: rPrepro.c,v 1.33 2008/11/27 14:05:42 vollmer Exp $
 */

# include <stdlib.h>
# include <time.h>
# include "rMemory.h"
# include "Errors.h"
# include "Position.h"
# include "StringM.h"
# include "Idents.h"
# include "rGetopt.h"
# include "rFsearch.h"
# include "rString.h"
# include "rPrepro_scan.h"
# include "rPrepro_pars.h"

static rbool       verbose           = rfalse;
static const char *generated_message = NULL;
static int         files_not_found   = 0;

# define OPTIONS "chlnsvVd:D:I:i:o:U:P:pt::"

# define VERSION "2008/11/27"

/* used for rFsearch */
# define USER_DIR_MARK    1       /* directories given with option -I */

static void
usage (const char *msg)
{
  if (msg != NULL) {
    fprintf (stderr, "reprepro: %s\n\n", msg);
  }
  fprintf (stderr,
  "usage: rPrepro [-chlnsvV] [-d <name>] [-D <name>] [-D <name>=<value>] \n"
  "               [-U <name>] [-I <path>] [-o <outfile>]\n"
  "               [-p] [-P <name>] [-t [<text>]] [<infile>...]\n"
  "  A simple preprocessor handling conditional text and text macros.\n"
  "  Options are:\n"
  );
  fprintf (stderr,
  "   h                : help\n"
  "   l                : emit line numbers\n"
  "   n                : do not generate #@line directives\n"
  "   c                : emit the line-directive in CPP-style, i.e\n"
  "                      '# line' instead of '#@ line'\n"
  );
  fprintf (stderr,
  "   s                : do not emit blanks and new lines for skipped text\n"
  "   V                : verbose (show filename of parsed file)\n"
  "   v                : output of version information\n"
  );
  fprintf (stderr,
  "   d <name>         : same as -D<name>=<name>\n"
  "   D <name>         : define <name> with the empty string as value\n"
  "   D <name>=<value> : define <name> to represent <value>\n"
  "   U <name>         : undefine <name>\n"
  );
  fprintf (stderr,
  "   P <name>         : enable conditional grammar rule selection\n"
  "                      and assign the empty string as value for <name>\n"
  "   P <name>=<value> : enable conditional rule selection for <name>\n"
  "                      and assign <value> to <name>\n"
  );
  fprintf (stderr,
  "   p                : all conditional grammar rules are selected\n"
  "                      Note: -p does not imply -D<name> for any <name>!\n"
  );
  fprintf (stderr,
  "   I <path>         : add <path> to the search path to find include files\n"
  "                      several path may be given\n"
  "   o <outfile>      : write output to <outfile>, default: stdout\n"
  );
  fprintf (stderr,
  "   t                : emit a default text containing the current date and\n"
  "                      time and enclosed within /* .. */\n"
  "                      as first and last line of the generated output\n"
  "   t<text>          : emit <text> as first and last line of the generated\n"
  "                      output\n"
  );
  fprintf (stderr,
  "   <infile>         : read input from <infile>,  default: stdin\n\n"
  "                      if several files are given, they run in the same\n"
  "                      \"environment\", i.e. define etc. from a first file\n"
  "                      are valid in a second file\n"
  );
  fprintf (stderr,
  "  Return codes: \n"
  "     %d no errors\n"
  "     %d syntax errors exist\n"
  "     %d source contains #ERROR directive\n"
  "     %d internal error\n\n"
  "  Version: %s\n", EXIT_OK, EXIT_ERROR, EXIT_USER, EXIT_INTERNAL, VERSION);
  exit (msg == NULL ? EXIT_OK : EXIT_ERROR);
}

static void add_generated_message (const time_t t)
{
  if (generated_message) {
    if (generated_message[0] == '\0') {
      fprintf (rPrepro_out_file,
	       "/* **** THIS FILE IS GENERATED DO NOT EDIT ****\n"
	       " * **** generated on %s"
	       " */\n",  ctime (&t));
    } else {
      fprintf (rPrepro_out_file, "%s\n", generated_message);
    }
  }
}

static void
process (const char *fn)
/* process the file with name `fn'. fn == NULL means: read from stdin */
{
  if (verbose) {
    printf ("%s ...\n", fn? fn : "<stdin>");
  }

  if (fn != NULL) {
    if (!rFileIsReadable (fn)) {
      MessageI ("cannot access file", xxError, NoPosition,
		xxString, (char*)fn);
      files_not_found++;
      goto terminate;
    }
    rPrepro_scan_Attribute.Position.FileName = MakeIdent1 (fn);
    rPrepro_scan_BeginFile ((char*)fn);
  } else {
    rPrepro_scan_Attribute.Position = NoPosition;
    rPrepro_scan_push_attr ();
  }

  rPrepro_pars ();

 terminate:;
}

int
main (int argc, char *argv [])
{
   int    option;
   time_t t = time(NULL);

   rPrepro_out_file = stdout;

# ifdef YYDEBUG
   rPrepro_pars_Debug = rtrue;
# endif

   /* REUSE initialization */
   BeginrMemory ();
   BeginStringMemory ();
   BeginIdents       ();
   BeginErrors	     ();
   StoreMessages     (rfalse);
   Begin_rFsearch    (rtrue);
   rPrepro_scan_BeginScanner ();

   rAddDir       (".", USER_DIR_MARK, rtrue);
   rAddExtension (".h");
   rAddExtension ("");

   /* parse command line options */
   rOpterr = 1; /* getopt should show an error message */
   while ((option = rGetopt (argc, argv, OPTIONS)) != EOF) {
     switch (option) {
     case 'h':
       usage(NULL);
       break;
     case 'l':
       rPrepro_scan_emit_line_numbers = rtrue;
       break;
     case 'n':
       rPrepro_scan_emit_line_directive      = rfalse;
       break;
     case 'c':
       rPrepro_scan_emit_line_directive_CPP  = rtrue;
       break;
     case 's':
       rPrepro_scan_emit_skipped_white_space = rfalse;
       break;
     case 'V':
       verbose = rtrue;
       break;
     case 'v':
       printf ("%s Version: %s\n", argv[0], VERSION);
       break;
     case 'o':
       rPrepro_out_file = fopen (rOptarg, "w");
       if (rPrepro_out_file == NULL) {
	 fprintf (stderr, "%s: can not open `%s' for writing\n",
		  argv[0], rOptarg);
	 exit (EXIT_ERROR);
       }
       break;
     case 'd':
       { tIdent id;
         id = MakeIdent1 (rOptarg);
	 rPrepro_define (id, GetCStr (id));
	 rPrepro_set_modifiable (id, rfalse);
       }
      case 'D': case 'P':
       { tIdent id;
	 char *c = strchr (rOptarg, '=');
	 if (c != NULL) {
	   *c = '\0';
	   id = MakeIdent1 (rOptarg);
	   rPrepro_define (id, c+1);
	 } else {
	   id = MakeIdent1 (rOptarg);
	   rPrepro_define (id, "");
	 }
	 rPrepro_set_modifiable (id, rfalse);
	 if (option == 'P') {
	   rPrepro_enable_grammar_rules = rtrue;
	   rPrepro_set_replaceable (id, rfalse);
	 }
       }
       break;
     case 'p':
       rPrepro_enable_grammar_rules = rtrue;
       rPrepro_all_grammar_rules    = rtrue;
       break;
     case 'U':
       { tIdent id;
         id = MakeIdent1 (rOptarg);
	 rPrepro_undef (id);
	 rPrepro_set_modifiable (id, rfalse);
       }
       break;
     case 'I':
       rAddDir (rOptarg, USER_DIR_MARK, rtrue);
       break;
     case 't':
       generated_message = rOptarg? rOptarg : "";
       break;
     default:
       usage (rOptmsg);
       break;
     }
   }

   add_generated_message (t);

   /* process the files */
   if (rOptind == argc) {
     /* no files argument given, read from stdin */
     process (NULL);
   } else {
     int i;
     for (i = rOptind; i < argc; i++) {
       process (argv[i]);
     }
   }

   add_generated_message (t);

   if (rPrepro_out_file != stdout) {
     fclose (rPrepro_out_file);
   }

   WriteMessages             (stderr);
   rPrepro_scan_CloseScanner ();
   CloseIdents               ();
   CloseStringMemory         ();
   Close_rFsearch            ();
   CloserMemory              ();

   if (GetCount (xxError) > 0) return EXIT_ERROR;
   return EXIT_OK;
}

/**********************   e n d   ********************************************/

