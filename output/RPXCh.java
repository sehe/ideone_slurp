// error:	OK
// langId:	10
// langName:	Java
// langVersion:	sun-jdk-1.7.0_25
// time:	0
// date:	2012-02-15 22:59:04
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
import java.io.*;
import java.text.MessageFormat;
import java.util.*;

public class PolynomialAddition {
	static File dataInpt;
	static Scanner inFile;

	public static void main(String[] args) throws IOException {
		dataInpt = new File("/tmp/input.txt");
		inFile = new Scanner(dataInpt);

		while (inFile.hasNextLine()) {
			Node first = readPolynomial();
			printList(first);

			Node second = readPolynomial();
			printList(second);
			
			Node merged = addPolynomials(first, second);

			System.out.println("Really crude, next two lines\n\n");
		}
	}

	private static Node addPolynomials(Node first, Node second) {
		return null;
	}

	private static Node readPolynomial() {
		String line = inFile.nextLine();
		StringTokenizer myTokens = new StringTokenizer(line);

		Node head = null, previous = null;
		while (myTokens.hasMoreTokens()) {
			Node current = new Node();
			String term = myTokens.nextToken();

			current.factor = Integer.valueOf(
					term.substring(0, term.indexOf("x")));
			current.exponent = Integer.valueOf(
					term.substring(term.indexOf("^") + 1));

			if (previous == null)
			{
				head = current;
				previous = head;
			} else
			{
		        previous.next = current;
			    previous = current;
			}
		}
		return head;
	}

	public static void printList(Node head) {
		for (Node ptr = head; ptr != null; ptr = ptr.next)
			System.out.print(MessageFormat.format("{0}  {1}  ", ptr.factor,
					ptr.exponent));
		System.out.println();
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
Main.java:5: class PolynomialAddition is public, should be declared in a file named PolynomialAddition.java
public class PolynomialAddition {
       ^
Main.java:26: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	                                   ^
Main.java:26: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	                                               ^
Main.java:26: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	               ^
Main.java:30: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node readPolynomial() {
	               ^
Main.java:57: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	public static void printList(Node head) {
	                             ^
Main.java:14: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node first = readPolynomial();
			^
Main.java:17: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node second = readPolynomial();
			^
Main.java:20: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node merged = addPolynomials(first, second);
			^
Main.java:34: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
		Node head = null, previous = null;
		^
Main.java:36: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node current = new Node();
			^
Main.java:36: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node current = new Node();
			                   ^
Main.java:58: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
		for (Node ptr = head; ptr != null; ptr = ptr.next)
		     ^
Main.java:59: non-static method format(java.lang.Object,java.lang.StringBuffer,java.text.FieldPosition) cannot be referenced from a static context
			System.out.print(MessageFormat.format("{0}  {1}  ", ptr.factor,
			                              ^
14 errors

#endif
