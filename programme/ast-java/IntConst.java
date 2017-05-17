/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Klasse fuer IntConst-Knoten
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: IntConst.java.in,v 1.5 2012/10/20 14:01:57 vollmer Exp $
 */
class IntConst extends EXPR
{
    public int Value;
    public IntConst (int _Value)
    {
	Value = _Value;
    }

    public void write()
    {
	System.out.print(Value);
    }

}