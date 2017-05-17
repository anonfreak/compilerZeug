/* Project:  COCKTAIL training
 * Descr:    simple expr-parser and calculator using scanf etc.
 * Kind:     C-main program
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: main.c,v 1.2 2009/11/14 14:33:33 vollmer Exp $
 */

# include <stdlib.h>
# include <stdio.h>

void usage (char *cmd)
{
  printf ("usage: %s [-h]\n", cmd);
  printf ("This program implements a simple pocket calulator, acceptting only the following language:\n"
	  "   E ::= E + E | i\n"
	  "where the token i stands for an usual integer value.\n"
	  "The program reads stdin and writes the resulting sum or an error message to stdout.\n"
	  "Options:\n"
	  " -h:  show this help text\n"
	  "Return code:  0 everything is ok.\n"
	  "              1 an error occured.\n");
  exit (1);
} /* usage() */

int parse(void)
{
  int sum = 0;
  int value;

  while (1) {
    if (scanf ("%d", &value) == 1) {
      /* Zahl gelesen */
      sum += value;
    } else
  }

} /* parse() */

int main (int argc, char *argv[])
{
  int exit_code;

  if (argc > 1) {

  if (exit_code > 0) {
    printf ("an error occurred\n");
  }

  return exit_code;
} /* main() */
