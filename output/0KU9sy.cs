// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2013-08-02 15:59:51
// status:	0
// result:	15
// memory:	33832
// signal:	0
// public:	false
// ------------------------------------------------
struct X
{
    public static void Main()
    {
        bool x = false;
        x ^= true;
        System.Console.WriteLine(x);
        x ^= true;
        System.Console.WriteLine(x);
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
True
False

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
