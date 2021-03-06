/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Liste von Ausdruecken: EXPRS abstrakte Klasse
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: EXPRS.java.in,v 1.5 2012/10/20 14:02:38 vollmer Exp $
 */
abstract class EXPRS
{
    abstract public void write_and_eval();
    // Die Element der Liste werden besucht, ausgegeben und ausgewertet.
    // Implementieren Sie diese Funktion.

    public EXPRS reverse ()
    // Ergebnis: die Liste mit Elementen in umgekehrter Reihenfolge
    // Achtung:  Die Operation ist destruktiv, d.h. die Aendert den
    //           Wert des Next-Members eines jeden Exprs Objektes!
    // Aufwand:  Linear in der Anzahl der Listenelemente.
    {
    // Implementieren Sie diese Funktion!
    return this;
    }
}
