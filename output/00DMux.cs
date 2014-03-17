// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.04
// date:	2012-11-22 19:02:11
// status:	0
// result:	15
// memory:	37136
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

public class Test
{
    public static void Main()
    {
        var list1 = new List<int>() { 1, 2, 3, 4 };
        var list2 = new List<int>() { 2, 3, 5, 6, 7, 8 };
        var list3 = new List<int>() { 3, 4, 5 };
        var all = new HashSet<int>(list1.Concat(list2).Concat(list3));

        int?[] l1Result = new int?[all.Count];
        int?[] l2Result = new int?[all.Count];
        int?[] l3Result = new int?[all.Count];
        
        int idx = 0;
        foreach (int val in all)
        {
            if (list1.BinarySearch(val) >= 0) l1Result[idx] = val;
            if (list2.BinarySearch(val) >= 0) l2Result[idx] = val;
            if (list3.BinarySearch(val) >= 0) l3Result[idx] = val;

            idx += 1;
        }

        Console.WriteLine(string.Join("\t", l1Result.Select(i => !i.HasValue ? "NULL" : i.Value.ToString()).ToArray()));
        Console.WriteLine(string.Join("\t", l2Result.Select(i => !i.HasValue ? "NULL" : i.Value.ToString()).ToArray()));
        Console.WriteLine(string.Join("\t", l3Result.Select(i => !i.HasValue ? "NULL" : i.Value.ToString()).ToArray()));
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
