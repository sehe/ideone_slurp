// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-11-13 12:30:41
// status:	0
// result:	15
// memory:	36840
// signal:	0
// public:	true
// ------------------------------------------------
using System;

public class Program
{
    public static void ExampleSub(string Test, System.Nullable<DateTime> fromDate = null)
    {
        fromDate = fromDate?? System.DateTime.Now;
        //An Even Greater sub!
    }

    public static void Main(string[] args)
    {
        ExampleSub("Test");
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

#endif
