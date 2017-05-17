/* Project:  COCKTAIL training
 * Descr:    DFA: Deterministic Finite Automaton
 * Kind:     implementation of the state transition of the DFA
 * Author:   Dr. Juergen Vollmer <vollmer@cocolab.de>
 * $Id: state.h,v 1.6 2013/04/17 12:42:36 vollmer Exp $
 */

# ifndef state_H
# define state_H

typedef short tState;    /* states are coded as positive integers            */
# define MAX_STATE   100 /* maximum number of states                         */
# define START_STATE   0 /* valid state numbers are START_STATE..ERROR_STATE */
# define ERROR_STATE (MAX_STATE-1)

extern void init_state (void);
/* Initialize the module; must be called once before next_state() is called first */

extern tState next_state (tState q, char s);
/* returns the follow-up state for the pair (q, s).
 * If there is no such valid state for our language, return ERROR_STATE
 * For all symbols s the following holds:
 *       next_state (ERROR_STATE, s) == ERROR_STATE
 */

extern int is_final (tState q);
/* If 'q' is a final state, return 1 else 0
 * ERROR_STATE is not treated as finals state!
 */
# endif
