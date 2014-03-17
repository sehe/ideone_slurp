// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.04
// date:	2011-11-04 11:50:34
// status:	0
// result:	15
// memory:	38136
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Text.RegularExpressions;

public class Program
{
	public static void Main(string[] args)
	{
		string input = "§1.1 This is nøt okæ bÿ any ßtandard¶Period.";

		Console.WriteLine(Regex.Replace(input, "[\\u007f-\\uffff]", "!"));
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
!1.1 This is n!t ok! b! any !tandard!Period.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
