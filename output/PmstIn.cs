// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2014-01-09 23:25:07
// status:	0
// result:	15
// memory:	33632
// signal:	0
// public:	false
// ------------------------------------------------
struct Z
{
    public static void Main()
    {
        var have_fun = Y(T<Z>)<42;
    }

    public static bool operator>(Z _, int __) { return false; }
    public static bool operator<(Z _, int __) { return true;  }
    static int Y(System.Func<Z,Z,Z> _) { return 0; }
    static U T<U>(U _, U __)           { return _; }
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
