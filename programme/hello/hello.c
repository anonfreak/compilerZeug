/* Projekt: Das Hello-Word-Programm
 * Was:     Das Hauptprogramm.
 * Autor:   Dr. Juergen Vollmer, <juergen@informatikl-vollmer.de>
 * $Id: hello.c,v 1.5 2007/06/01 10:38:31 vollmer draft $
 */

# include <stdio.h>   /* Standard Headers   werden mit < .. > inkludiert */
# include "hello2.h"  /* Selbstgeschriebene werden mit " .. " inkludiert */

int
main (int argc, char *argv[])
     /* argc und argv sind die Parameter, die die `main' Prozedur
      * vom Betriebsystem uebergeben bekommt, wenn das Programm
      * gestarte wird.
      * argc:  Anzahl der Agrumente,
      * argv:  Vektor von Strings
      * argv[0]: Dateiname des Programmes
      */
{
  int i;
  printf ("Hello World\n");

  printf ("Die Kommandozeilenargumente:\n");
  for (i = 0; i < argc; i++) {
    hello (i, argv[i]);
  }
  return 0;
}
