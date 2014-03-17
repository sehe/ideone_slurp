// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-11-06 22:53:42
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

public class Program
{
    static readonly IEnumerable<int> OtherLanguages = Enumerable.Range(1,100).ToArray();

    volatile StringBuilder result = null;

    void Magic()
    {
        //for (int i=10000; i>=0; i--)
        {
            result = new StringBuilder();

            Parallel.ForEach(OtherLanguages, toLanguage =>
                {
                    var resultIn = result;
                    var txt = toLanguage;

                    do Thread.SpinWait(25); while (Interlocked.CompareExchange(ref result, result.AppendFormat("lang {0}\r\n", txt), resultIn) != result);
                });

            //if (i==3)
            Console.WriteLine(result);
        }
    }

    public static void Main(string[] args)
    {
        new Program().Magic();
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
prog.cs(6,24): error CS0234: The type or namespace name `Tasks' does not exist in the namespace `System.Threading'. Are you missing an assembly reference?
prog.cs(6,24): error CS0234: The type or namespace name `Tasks' does not exist in the namespace `System.Threading'. Are you missing an assembly reference?
Compilation failed: 2 error(s), 0 warnings

#endif
