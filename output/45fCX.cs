// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-09-30 00:54:15
// status:	0
// result:	15
// memory:	37600
// signal:	0
// public:	true
// ------------------------------------------------
using System;

internal class NiceAttribute : Attribute
{
    private string _stuff;

    public string Stuff
    {
        set { _stuff = value; }
    }
}

public static class Program
{
    [Nice]
    public static void Main(string[] args)
    {
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
prog.cs(5,20): warning CS0414: The private field `NiceAttribute._stuff' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
