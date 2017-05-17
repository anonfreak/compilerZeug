/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Liste von Ausdruecken: Listenknoten
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: Exprs.java.in,v 1.3 2012/10/20 14:00:50 vollmer Exp $
 */
class Exprs extends EXPRS
{
    EXPRS Next;
    EXPR  Expr;

    public Exprs (EXPRS _Next, EXPR _Expr)
    {
	Next = _Next;
	Expr = _Expr;
    }

    public void write_and_eval ()
    {
	Expr.write();
	System.out.println ("=" + Expr.eval());
	Next.write_and_eval();
    }
}
