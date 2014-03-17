// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.68
// date:	2011-11-11 02:15:40
// status:	0
// result:	15
// memory:	38352
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Text;
using System.Diagnostics;

public class Program
{
    static void Main(string[] args)
    {
        int max = 10000;
        for (int times = 0; times < 5; times++)
        {
            {
                Console.WriteLine("\ntime: {0}", (times+1).ToString());
                Stopwatch sw = Stopwatch.StartNew();
                for (int i = 0; i < max; i++)
                {
                    string msg = "Your total is ";
                    msg += "$500 ";
                    msg += DateTime.Now;
                }
                sw.Stop();
                Console.WriteLine("String +\t: {0}ms", ((int)sw.ElapsedMilliseconds).ToString().PadLeft(6));
            }

            {
                Stopwatch sw = Stopwatch.StartNew();
                StringBuilder msg = new StringBuilder();
                for (int j = 0; j < max; j++)
                {
                    // msg.Clear(); // .NET 4.0
                    msg.Remove(0, msg.Length);
                    msg.Append("Your total is ");
                    msg.Append("$500 ");
                    msg.Append(DateTime.Now);
                }
                sw.Stop();
                Console.WriteLine("StringBuilder\t: {0}ms", ((int)sw.ElapsedMilliseconds).ToString().PadLeft(6));
            }
        }
        Console.Read();
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

time: 1
String +	:     68ms
StringBuilder	:     62ms

time: 2
String +	:     66ms
StringBuilder	:     62ms

time: 3
String +	:     66ms
StringBuilder	:     63ms

time: 4
String +	:     67ms
StringBuilder	:     61ms

time: 5
String +	:     65ms
StringBuilder	:     61ms

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
