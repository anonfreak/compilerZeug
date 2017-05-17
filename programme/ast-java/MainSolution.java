/* Project:  Vorlesung Uebersetzerbau
 * Descr:    Aufbau AST in JAVA
 * Kind:     Hauptprogramm
 * Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
 * $Id: Main.java.in,v 1.8 2012/10/20 13:58:23 vollmer Exp $
 */
public class MainSolution
{
    public static void main(String argv[])
    {
	System.out.println("Construction of an AST for expressions");
	EXPR tree1 =
	     new BinaryExpr (
	 	 '+',
		 new IntConst (1),
		 new BinaryExpr (
		     '*',
		     new UnaryExpr (
                         '-',
		 	 new IntConst (2)),
		     new IntConst (3)));
	tree1.write();
	System.out.println("=" + tree1.eval());

	EXPR tree2 =
             new CondExpr (
	         new BinaryExpr (
	 	     '<',
		     new IntConst (2),
		     new IntConst (3)),
                 new IntConst (2),
                 new IntConst (3));
	tree2.write();
	System.out.println("=" + tree2.eval());

	System.out.println("List of expressions:");
	EXPRS list =
	      new Exprs (
		  new Exprs (
		      new NoExprs (),
		      tree2),
                  tree1);
	list.write_and_eval();

	System.out.println("Reverted list of expressions:");
	EXPRS r = list.reverse();
	r.write_and_eval();
    }
}


