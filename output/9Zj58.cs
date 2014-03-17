// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-10-20 00:48:34
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System.Dynamic;
using System.Collections.Generic;

using System;

public class Program
{
    public static void Main(string[] args)
    {
        dynamic x = new ExpandoObject();
        x.Data ="test";
        x.Arr = new [] { "test1","test2"};
        x.Lst = new List<string> { "aap", "noot", "mies" };
        
        Console.WriteLine(x);
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
prog.cs(1,14): error CS0234: The type or namespace name `Dynamic' does not exist in the namespace `System'. Are you missing an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
