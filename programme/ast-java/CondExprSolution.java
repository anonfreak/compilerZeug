/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Klasse fuer CondExpr-Knoten
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: CondExpr.java.in,v 1.6 2012/10/20 14:01:30 vollmer Exp $
 */
class CondExpr extends EXPR
{
    public EXPR Cond;
    public EXPR Then;
    public EXPR Else;
    public CondExpr (EXPR _Cond, EXPR _Then, EXPR _Else)
    {
	Cond = _Cond;
	Then = _Then;
	Else = _Else;
    }

    public void write()
    {
	System.out.print("(");
	Cond.write();
	System.out.print(" ? ");
	Then.write();
	System.out.print(" : ");
	Else.write();
	System.out.print(")");
    }

    public double eval()
    {
	if (Cond.eval() != 0.0) {
	    return Then.eval();
	} else {
	    return Else.eval();
	}
    }
}
