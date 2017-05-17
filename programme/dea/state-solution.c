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

  /* initialize the table, so staht for all states q and symbols s holds:
   *   StateTabel[s][q] = ERROR_STATE
   */
  for (q = 0; q < MAX_STATE; q++) {
    for (s = 0; s <= LAST_SYMBOL; s++) {
      StateTable[q][s] = ERROR_STATE;
    }
  }

  /* now initialize the table with the valid state transitions. */
  StateTable[0]['n'] = 1;
  StateTable[0]['.'] = 2;
  StateTable[1]['.'] = 2;
  StateTable[1]['e'] = 3;
  StateTable[2]['n'] = 4;
  StateTable[3]['n'] = 5;
  StateTable[3]['+'] = 6;
  StateTable[3]['-'] = 6;
  StateTable[4]['e'] = 3;
  StateTable[6]['n'] = 5;
}

tState
next_state (tState q, char s)
{
  return StateTable[q][(int)s];
}

int
is_final (tState q)
{
  return q == 1 || q == 4 || q == 5;
}
