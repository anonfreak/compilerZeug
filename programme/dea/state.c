/* Project:  COCKTAIL training
 * Descr:    DFA: Deterministic Finite Automaton
 * Kind:     implementation of the state transition of the DFA
 * Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: state.c.in,v 1.10 2013/04/17 12:44:35 vollmer Exp $
 */

# include "state.h"

# define LAST_SYMBOL 127
/* we use 7bit ASCII letters as symbols, ASCII codes range from 0 .. 127
 * ASCII code 0 denotes "end of word"
 */

/* the state transition function is implemented by a table:
 * StateTable[ <state-number> ][ <ASCII-code> ] = <following state-number>
 */
typedef tState tStateTable[MAX_STATE][LAST_SYMBOL+1];
static  tStateTable StateTable;

void
init_state (void)
{
  int    s;  /* Note: s is declared as an int, since char is signed, and therefore
	      *       ranging from -128 .. 127
	      * so a loop increment s++ will increment 127 to -128!
	      */
  tState q;
  /* please fill in */
}

tState
next_state (tState q, char s)
{
  /* please fill in */
}

int
is_final (tState q)
{
  /* please fill in */
}
