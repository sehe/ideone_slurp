// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-10-06 12:27:38
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System.Linq;
using System.Threading.Tasks;

public class Program
{
	public static void Main(string[] args)
	{
		for (int i=0; i<20; i++)
			System.Console.WriteLine(fibonacci(i));
	}

	private static ulong fibonacci(int n)
	{
	    ulong u = 0;
	    ulong v = 1;
	    ulong t;
#if true
	    Parallel.For(2, n + 1, i =>
#else
		Enumerable.Range(2, n+1).ToList().ForEach(i =>
#endif
	    {
	        t = u + v;
	        u = v;
	        v = t;
	    });
	    return v;
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
prog.cs(2,24): error CS0234: The type or namespace name `Tasks' does not exist in the namespace `System.Threading'. Are you missing an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
