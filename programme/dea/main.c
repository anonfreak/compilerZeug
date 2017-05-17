/* Project:  COCKTAIL training
 * Descr:    DFA: Deterministic Finite Automaton
 * Kind:     C-main program
 * Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: main.c,v 1.2 2009/11/14 14:33:33 vollmer Exp $
 */

# include <stdio.h>
# include "state.h"
# include "accept.h"

int
main (int argc, char *argv[])
{
  init_state();

  if (argc == 2) {
    if (accept (argv[1])) {
      printf ("ok\n");
      return 0;
    } else {
      printf ("Fehler\n");
      return 1;
    }
  } else {
    /* error message should be emitted to 'stderr'. */
    fprintf (stderr, "usage: %s word\n", argv[0]);
    fprintf (stderr,
   "This program implements a Deterministic Finite Automaton (DFA).\n"
   "'word' is the word to be checked.\n"
   "The DFA implemented accepts \"simplified floating point literals\",\n"
   "where a sequence of digit 0, 1, .. 9 are represnted by the single\n"
   "character 'n'. The exponentation symbol is the character 'e'.\n"
   "Return code:  0 'word' is part of the language.\n"
   "              1 'word is not part of the language.\n"
   "              2 any other error.\n");
    return 2;
  }
}
