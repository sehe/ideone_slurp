// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.06
// date:	2011-08-31 21:09:32
// status:	0
// result:	15
// memory:	38360
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Text.RegularExpressions;

namespace TestThat
{
    class MainClass
    {
        public static void Main (string[] args)
        {
			Console.WriteLine(Regex.Replace(
						@"HelloWORld",
						@"(?<!^)(?<wordstart>\p{Lu}{1,2})", 
						@" ${wordstart}",
						RegexOptions.Compiled));
			Console.WriteLine(Regex.Replace(
						@"ÉclaireürfØÑJßå",
						@"(?<!^)(?<wordstart>\p{Lu}{1,2})", 
						@" ${wordstart}",
						RegexOptions.Compiled));
        }
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Hello WO Rld
?claire?rf ?? J??

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
