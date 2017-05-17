/* Projekt: Das Hello-Word-Programm
 * Was:     Bearbeitung der Kommandozeilen argumente.
 * Autor:   Dr. Juergen Vollmer, <juergen@informatikl-vollmer.de>
 * $Id: hello2.c,v 1.4 2007/06/01 10:38:31 vollmer draft $
 */

# include <stdio.h>
# include "hello2.h"

void hello (int nr, char *argument)
{
  DPRINTF ("Aufruf von hello");
  printf (" - %2d: %s\n", nr, argument);
}

