/* Project:  COCKTAIL training
 * Descr:    DFA: Deterministic Finite Automaton
 * Kind:     implementation of the accept-routine
 * Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: accept.h,v 1.2 2009/11/14 14:30:18 vollmer Exp $
 */

# ifndef accept_H
# define accept_H

# include "state.h"

extern int accept (char *word);
/* Returns 1 if 'word' is part of our language, else return 0.
 * The DFA is implemented in terms of next_state() and is_final()
 * see file state.c
 */
# endif
