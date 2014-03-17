// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-10-06 13:58:52
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
	public static void Main(string[] args)
	{
		for (int i=0; i<20; i++)
			System.Console.WriteLine(Fib(i));
	}

	static long Fib(int n)
	{
	    double sqrt5 = Math.Sqrt(5);
	    double p1 = (1 + sqrt5) / 2; 
	    double p2 = -1 * (p1 - 1);          
	
	
	    double n1 = 1.0;
	    double n2 = 1.0;
            n1 = Math.Pow(p1, n+1);
            n2 = Math.Pow(p2, n+1);
	    // Parallel.For(0,n+1,(x)=>{ n1*=p1; n2*=p2; });
	    return (long)((n1-n2)/sqrt5);
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
prog.cs(3,24): error CS0234: The type or namespace name `Tasks' does not exist in the namespace `System.Threading'. Are you missing an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
