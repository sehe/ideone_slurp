// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-02-22 14:15:59
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
using System;
class MainClass {
	unsafe public static void Main (string[] args) {
		fixed (char* r = "helloworld".ToCharArray()) {
			char* p = r;
			while (*p != 0)
				Console.WriteLine("{0:X}", (int) *p++);
		}
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
prog.cs(3,9): error CS0227: Unsafe code requires the `unsafe' command line option to be specified
Compilation failed: 1 error(s), 0 warnings

#endif
