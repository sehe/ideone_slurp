// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.03
// date:	2013-08-02 02:00:06
// status:	0
// result:	15
// memory:	34752
// signal:	0
// public:	true
// ------------------------------------------------
using System;

class Program
{
    static void Main()
    {
        decimal change    = 0.92m;

        var coins = new [] {
            new { name = "quarter", nominal   = 0.25m },
            new { name = "dime", nominal      = 0.10m },
            new { name = "nickel", nominal    = 0.05m },
            new { name = "pennies", nominal   = 0.01m }
        };

        foreach (var coin in coins)
        {
            int count = (int) (change / coin.nominal);
            change -= count * coin.nominal;

            Console.WriteLine("{0} {1}", count, coin.name);
        }
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
3 quarter
1 dime
1 nickel
2 pennies

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
