// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-09-19 16:21:27
// status:	0
// result:	15
// memory:	37056
// signal:	0
// public:	true
// ------------------------------------------------
	using System;

	public class Test
	{
	        private static void assign(ref int i)
	        {
	             i = 42;
	        }
	
	        public static void Main()
	        {
	              var vars = new [] { 1,2,3,4 };
	              Console.WriteLine(vars[2]);
	              assign(ref vars[2]);
	              Console.WriteLine(vars[2]);
	        }
	}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
3
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
