/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Klasse fuer BinaryExpr-Knoten
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: BinaryExpr.java.in,v 1.6 2012/10/20 14:01:39 vollmer Exp $
 */
class BinaryExpr extends EXPR
{
    public char Op;
    public EXPR Left;
    public EXPR Right;
    public BinaryExpr (char _Op, EXPR _Left, EXPR _Right)
    {
	Op    = _Op;
	Left  = _Left;
	Right = _Right;
    }

    public void write()
    {
	System.out.print("(");
	Left.write();
	System.out.print(Op);
	Right.write();
	System.out.print(")");
    }

}