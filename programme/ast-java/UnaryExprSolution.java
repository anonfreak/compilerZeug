/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Klasse fuer UnaryExpr-Knoten
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: UnaryExpr.java.in,v 1.6 2012/10/20 14:02:11 vollmer Exp $
 */
class UnaryExpr extends EXPR
{
    public char Op;
    public EXPR Arg;
    public UnaryExpr (char _Op, EXPR _Arg)
    {
	Op    = _Op;
	Arg   = _Arg;
    }

    public void write()
    {
	System.out.print("(");
	System.out.print(Op);
	Arg.write();
	System.out.print(")");
    }

    public double eval()
    {
	switch (Op) {
	case '-': return - Arg.eval();
	case '+': return   Arg.eval();
	default:  return 0;
	}
    }

}
