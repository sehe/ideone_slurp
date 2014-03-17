// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.07
// date:	2013-07-19 15:49:39
// status:	0
// result:	15
// memory:	34376
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
		var ax = new[] { 
			new { id = 1, name = "John" },
			new { id = 2, name = "Sue" } };
		var bx = new[] { 
			new { id = 1, surname = "Doe" },
			new { id = 3, surname = "Smith" } };

		ax.FullOuterJoin(bx, a => a.id, b => b.id, (a, b, id) => new {a, b})
			.ToList().ForEach(Console.WriteLine);
	}
}

internal static class MyExtensions
{
    internal static IList<TR> FullOuterGroupJoin<TA, TB, TK, TR>(
        this IEnumerable<TA> a,
        IEnumerable<TB> b,
        Func<TA, TK> selectKeyA, 
        Func<TB, TK> selectKeyB,
        Func<IEnumerable<TA>, IEnumerable<TB>, TK, TR> projection,
        IEqualityComparer<TK> cmp = null)
    {
        cmp = cmp?? EqualityComparer<TK>.Default;
        var alookup = a.ToLookup(selectKeyA, cmp);
        var blookup = b.ToLookup(selectKeyB, cmp);

        var keys = new HashSet<TK>(alookup.Select(p => p.Key), cmp);
        keys.UnionWith(blookup.Select(p => p.Key));

        var join = from key in keys
                   let xa = alookup[key]
                   let xb = blookup[key]
                   select projection(xa, xb, key);

        return join.ToList();
    }

    internal static IList<TR> FullOuterJoin<TA, TB, TK, TR>(
        this IEnumerable<TA> a,
        IEnumerable<TB> b,
        Func<TA, TK> selectKeyA, 
        Func<TB, TK> selectKeyB,
        Func<TA, TB, TK, TR> projection,
        TA defaultA = default(TA), 
        TB defaultB = default(TB),
        IEqualityComparer<TK> cmp = null)
    {
        cmp = cmp?? EqualityComparer<TK>.Default;
        var alookup = a.ToLookup(selectKeyA, cmp);
        var blookup = b.ToLookup(selectKeyB, cmp);

        var keys = new HashSet<TK>(alookup.Select(p => p.Key), cmp);
        keys.UnionWith(blookup.Select(p => p.Key));

        var join = from key in keys
                   from xa in alookup[key].DefaultIfEmpty(defaultA)
                   from xb in blookup[key].DefaultIfEmpty(defaultB)
                   select projection(xa, xb, key);

        return join.ToList();
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
{ a = { id = 1, name = John }, b = { id = 1, surname = Doe } }
{ a = { id = 2, name = Sue }, b =  }
{ a = , b = { id = 3, surname = Smith } }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
