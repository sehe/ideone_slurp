// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-11-17 23:21:02
// status:	0
// result:	15
// memory:	36984
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public interface ITaggable {}

    public struct TagStruct : ITaggable {}
    public class  TagObject : ITaggable {}

    public static IEnumerable<T> DoSomething<T>(IEnumerable<T> input) 
        where T: ITaggable
    {
        foreach (var i in input) yield return i;
    }

    public static void Main(string[] args)
    {
        var structs = new [] { new TagStruct() };
        var objects = new [] { new TagObject() };

        Console.WriteLine(DoSomething(structs).First().GetType());
        Console.WriteLine(DoSomething(objects).First().GetType());


        
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Program+TagStruct
Program+TagObject

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
