// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.06
// date:	2012-11-22 13:05:42
// status:	0
// result:	15
// memory:	37288
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main(string[] args)
    {
        var list1 = new int?[] {1, 2, 3, 4, 5};
        var list2 = new int?[] {3, 4, 5, 6, 7};

        var joined = list1.FullOuterJoin(list2, a => a, b => b, (a, b, c) => new {list1=a, list2=b});

        joined.ToList().ForEach(Console.WriteLine);
    }
}

internal static class MyExtensions
{
    private static IDictionary<TK, IEnumerable<TV>> ToDictionary<TK,TV>(this IEnumerable<IGrouping<TK, TV>> grouping)
    {
        return grouping.ToDictionary(g => g.Key, g => g.AsEnumerable());
    }

    private static IEnumerable<TV> OuterGet<TK, TV>(this IDictionary<TK, IEnumerable<TV>> dict, TK k, TV d=default(TV))
    {
        IEnumerable<TV> result;
        return dict.TryGetValue(k, out result) ? result : new [] { d };
    }

    internal static IList<TR> FullOuterJoin<TA, TB, TK, TR>(this IEnumerable<TA> a, 
            IEnumerable<TB> b, 
            Func<TA, TK> selectKeyA, Func<TB, TK> selectKeyB, 
            Func<TA, TB, TK, TR> projection, 
            TA defaultA=default(TA), TB defaultB=default(TB))
    {
        var adict = a.GroupBy(selectKeyA).ToDictionary();
        var bdict = b.GroupBy(selectKeyB).ToDictionary();

        var keys = adict.Keys.Union(bdict.Keys);

        var join = from key in keys
            from xa in adict.OuterGet(key, defaultA)
            from xb in bdict.OuterGet(key, defaultB)
            select projection(xa, xb, key);

        return join.ToList();
    }
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
{ list1 = 1, list2 =  }
{ list1 = 2, list2 =  }
{ list1 = 3, list2 = 3 }
{ list1 = 4, list2 = 4 }
{ list1 = 5, list2 = 5 }
{ list1 = , list2 = 6 }
{ list1 = , list2 = 7 }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
