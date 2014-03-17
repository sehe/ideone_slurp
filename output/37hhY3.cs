// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2013-08-20 01:55:56
// status:	0
// result:	15
// memory:	34024
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Globalization;

public class Program
{
    public static void Main()
    {
        string ValueToParse = "2.53327490880368E+15";
        Console.WriteLine("{0:X16}", (ulong) decimal.Parse(ValueToParse, NumberStyles.Any, CultureInfo.InvariantCulture));
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
00090000070EC260

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
