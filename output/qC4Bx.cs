// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-07-15 12:38:44
// status:	0
// result:	15
// memory:	37144
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
	public static void Main(string[] args)
	{
		{
			var ints = new List<int>{ 1,2,3,4,5 };
			ints[3] = 888;

			Console.WriteLine(string.Join(", ", ints.Select(i=>i.ToString()).ToArray()));
		}
		{
			var ints = new []{ 1,2,3,4,5 };
			var copy = ints[3];
			copy = 888;

			Console.WriteLine(string.Join(", ", ints.Select(i=>i.ToString()).ToArray()));
		}
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1, 2, 3, 888, 5
1, 2, 3, 4, 5

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(17,29): warning CS0168: The variable `copy' is declared but never used
Compilation succeeded - 1 warning(s)

#endif
