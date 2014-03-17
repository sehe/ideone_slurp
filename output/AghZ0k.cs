// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2012-11-23 12:27:35
// status:	0
// result:	15
// memory:	38312
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

public class Test
{
    public static IEnumerable<T?>[] Aligned<T>(params List<T>[] lists)
        where T : struct
    {
        var all = new HashSet<T>();
        foreach (var list in lists)
            all.UnionWith(list);

        return lists.Select(list => all.Select(val => 
                list.BinarySearch(val) >= 0? val : default(T?)
            )).ToArray();
    }

    public static void Main()
    {
        var list1 = new List<int>() { 1, 2, 3, 4 };
        var list2 = new List<int>() { 2, 3, 5, 6, 7, 8 };
        var list3 = new List<int>() { 3, 4, 5 };

        var aligned = Aligned(list1, list2, list3);

        Console.WriteLine("new list1[5]: {0}", aligned[0].ElementAt(5));
        Console.WriteLine("new list2[8]: {0}", aligned[1].ElementAt(7));

        var newlist3 = aligned[2].ToList();
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
new list1[5]: 
new list2[8]: 8

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
