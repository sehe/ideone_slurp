// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2012-11-22 19:16:02
// status:	0
// result:	15
// memory:	37216
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

        foreach (var list in aligned)
            Console.WriteLine(string.Join("\t", list.Select(i => !i.HasValue ? "NULL" : i.Value.ToString()).ToArray()));
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1	2	3	4	NULL	NULL	NULL	NULL
NULL	2	3	NULL	5	6	7	8
NULL	NULL	3	4	5	NULL	NULL	NULL

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
