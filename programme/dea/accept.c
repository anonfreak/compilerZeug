/* Project:  COCKTAIL training
 * Descr:    DFA: Deterministic Finite Automaton
 * Kind:     implementation of the accept-routine
 * Author:    Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: accept.c,v 1.3 2009/11/14 14:34:00 vollmer Exp $
 */

# include <stdio.h>
# include "state.h"
# include "accept.h"

int
accept (char *word)
{
  tState  q = START_STATE;
  char    s = *word++;

  while (s != '\0') { /* The ASCII-character '\0' denotes the "end of word" */
# ifdef DEBUG
    printf ("      q = %3d, s = `%c'\n", q, s);
# endif
    q = next_state (q,s);
    s = *word++;
  }

# ifdef DEBUG
    printf ("Ende: q = %3d, s = `%c'\n", q, s);
# endif

  return is_final (q);
}
