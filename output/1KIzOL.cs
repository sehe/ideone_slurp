// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2014-01-21 02:40:48
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
public class Test
{
	private static void Foo() {}
	public static void Main()
	{
		int x = (Foo(), 42);
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
prog.cs(6,30): error CS1026: Unexpected symbol `,', expecting `)'
prog.cs(6,32): error CS1026: Unexpected symbol `42', expecting `)'
Compilation failed: 2 error(s), 0 warnings

#endif
