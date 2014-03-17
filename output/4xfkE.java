// error:	OK
// langId:	10
// langName:	Java
// langVersion:	sun-jdk-1.7.0_25
// time:	0
// date:	2012-02-16 01:38:16
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
import java.io.*;
import java.util.*;

public class PolynomialAddition {
	static File dataInpt;
	static Scanner inFile;

	public static void main(String[] args) throws IOException {
		dataInpt = new File("/tmp/input.txt");
		inFile = new Scanner(dataInpt);

		while (inFile.hasNextLine()) {
			Node first = readPolynomial();
//			printList(first);

			Node second = readPolynomial();
//			printList(second);
			
			Node addition = addPolynomials(first, second);
//			printList(addition);
			
			printTabulated(first, second, addition);

			System.out.println("\n");
		}
	}

	private static Node addPolynomials(Node first, Node second) {
		Node head = null, current = null;
		while (null!=first || null!=second)
		{
			boolean haveBoth = (null!=first && null!=second);

			Node node;
			if (haveBoth && first.exponent == second.exponent)
			{
				node = new Node(first.factor + second.factor, first.exponent, null);
				first = first.next;
				second = second.next;
			} else
			{
				boolean pickfirst = first!=null && 
					((second == null) || first.exponent > second.exponent);
			
				if (pickfirst)
				{
				    node = new Node(first.factor, first.exponent, null);
				    first = first.next;
				} else
				{
					node = new Node(second.factor, second.exponent, null);
				    second = second.next;
				}
			}
				
			if (current == null)
			{
				head = node;
				current = head;
			} else
			{
				current.next = node;
				current = node;
			}
		}
		
		return head;
	}

	private static void printTabulated(Node first, Node second, Node addition) {
		String line1="", line2="", barline="", line3="";
		while (addition != null)
		{
			String 
			     part1 = "           ", 
			     part2 = "           ", 
			     part3 = "           ";
			
	        if (null!=first && first.exponent == addition.exponent) 
	        {
				part1 = first.toString();
				first = first.next;
			} 
	        if (null!=second && second.exponent == addition.exponent) 
	        {
				part2 = second.toString();
				second = second.next;
			}
	       	part3 = addition.toString();
			addition = addition.next;
			
			line1 += part1;
			line2 += part2;
			barline += "-----------";
			line3 += part3;
		}
		
		System.out.println(line1);
		System.out.println(line2);
		System.out.println(barline);
		System.out.println(line3);
	}

	private static Node readPolynomial() {
		String line = inFile.nextLine();
		StringTokenizer myTokens = new StringTokenizer(line);

		Node head = null, previous = null;
		while (myTokens.hasMoreTokens()) {
			Node current = new Node();
			String term = myTokens.nextToken();
			
			if (term.startsWith("+"))
				term = term.substring(1);

			current.factor = Integer.parseInt(
					term.substring(0, term.indexOf("x")));
			current.exponent = Integer.parseInt(
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

	private static void printList(Node head) {
		for (Node ptr = head; ptr != null; ptr = ptr.next)
			System.out.print(ptr);
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
Main.java:4: class PolynomialAddition is public, should be declared in a file named PolynomialAddition.java
public class PolynomialAddition {
       ^
Main.java:28: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	                                   ^
Main.java:28: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	                                               ^
Main.java:28: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node addPolynomials(Node first, Node second) {
	               ^
Main.java:70: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static void printTabulated(Node first, Node second, Node addition) {
	                                   ^
Main.java:70: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static void printTabulated(Node first, Node second, Node addition) {
	                                               ^
Main.java:70: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static void printTabulated(Node first, Node second, Node addition) {
	                                                            ^
Main.java:104: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static Node readPolynomial() {
	               ^
Main.java:134: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
	private static void printList(Node head) {
	                              ^
Main.java:13: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node first = readPolynomial();
			^
Main.java:16: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node second = readPolynomial();
			^
Main.java:19: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node addition = addPolynomials(first, second);
			^
Main.java:29: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
		Node head = null, current = null;
		^
Main.java:34: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node node;
			^
Main.java:37: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
				node = new Node(first.factor + second.factor, first.exponent, null);
				           ^
Main.java:47: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
				    node = new Node(first.factor, first.exponent, null);
				               ^
Main.java:51: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
					node = new Node(second.factor, second.exponent, null);
					           ^
Main.java:108: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
		Node head = null, previous = null;
		^
Main.java:110: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node current = new Node();
			^
Main.java:110: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
			Node current = new Node();
			                   ^
Main.java:135: cannot find symbol
symbol  : class Node
location: class PolynomialAddition
		for (Node ptr = head; ptr != null; ptr = ptr.next)
		     ^
21 errors

#endif
