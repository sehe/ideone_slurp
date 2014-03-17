// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.03
// date:	2013-06-21 14:39:41
// status:	0
// result:	15
// memory:	33976
// signal:	0
// public:	false
// ------------------------------------------------
using System.Collections.Generic; 
using System.Linq;

public class Q
{
    public static void Main(string[]args)
    {
        var hs = new HashSet<string> { "aap", "noot", "mies" };
        hs.SymmetricExceptWith(new [] { "broer", "noot", "mies" });
        
        System.Console.WriteLine(string.Join("\n", hs.ToArray()));
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
aap
broer

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
