/* Projekt: Das Hello-Word-Programm
 * Was:     Bearbeitung der Kommandozeilen argumente.
 * Autor:   Dr. Juergen Vollmer, <juergen@informatikl-vollmer.de>
 * $Id: hello2.h,v 1.4 2007/06/01 10:38:31 vollmer draft $
 */


/* Die folgenden 2 Zeilen (zusammen mit #endif) erlauben es,
 * dass `hello2.h' mehrfach inkludiert werden darf, ohne dass
 * der C-Compiler etwas anmeckert.
 */
# ifndef hello2_H
# define hello2_H

extern void hello (int nr, char *argument);

# ifdef DEBUG
# define DPRINTF(str) fprintf (stderr, "Datei %s, Zeile %d: %s\n", \
				__FILE__, __LINE__, str);
/* __FILE__ und __LINE__ sind vordefinierte Macros, die den
 * Namen der übersetzten Datei und die Zeilennumer an der das Macro benutzt
 * wird enthalten
 */
# else
# define DPRINTF(str) /* ignored */
# endif
# endif
