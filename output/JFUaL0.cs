// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.07
// date:	2012-11-22 15:10:37
// status:	0
// result:	15
// memory:	37456
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
        public static IDictionary<TK, IEnumerable<TV>> ToDictionary<TK,TV>(this IEnumerable<IGrouping<TK, TV>> grouping)
        {
            return grouping.ToDictionary(g => g.Key, g => g.AsEnumerable());
        }

        internal static IEnumerable<TV> OuterGet<TK, TV>(this IDictionary<TK, IEnumerable<TV>> dict, TK k)
        {
            IEnumerable<TV> result;
            if (!dict.TryGetValue(k, out result))
                yield break;
            
            foreach (var v in result) 
                yield return v;
        }

        internal static IList<TR> FullOuterGroupJoin<TA, TB, TK, TR>(
            this IEnumerable<TA> a,
            IEnumerable<TB> b,
            Func<TA, TK> selectKeyA, Func<TB, TK> selectKeyB,
            Func<IEnumerable<TA>, IEnumerable<TB>, TK, TR> projection)
        {
            var adict = a.GroupBy(selectKeyA).ToDictionary();
            var bdict = b.GroupBy(selectKeyB).ToDictionary();

            var keys = new HashSet<TK>(adict.Keys);
            keys.UnionWith(bdict.Keys);

            var join = from key in keys
                       let xa = adict.OuterGet(key)
                       let xb = bdict.OuterGet(key)
                       select projection(xa, xb, key);

            return join.ToList();
        }

        internal static IList<TR> FullOuterJoin<TA, TB, TK, TR>(
            this IEnumerable<TA> a,
            IEnumerable<TB> b,
            Func<TA, TK> selectKeyA, Func<TB, TK> selectKeyB,
            Func<TA, TB, TK, TR> projection,
            TA defaultA = default(TA), TB defaultB = default(TB))
        {
            var adict = a.GroupBy(selectKeyA).ToDictionary();
            var bdict = b.GroupBy(selectKeyB).ToDictionary();

            var keys = new HashSet<TK>(adict.Keys);
            keys.UnionWith(bdict.Keys);

            var join = from key in keys
                       from xa in adict.OuterGet(key).DefaultIfEmpty(defaultA)
                       from xb in bdict.OuterGet(key).DefaultIfEmpty(defaultB)
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
