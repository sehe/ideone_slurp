// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.06
// date:	2012-11-22 14:20:04
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
        public static void Main(string[] args)
        {
            var list1 = new int?[] { 1, 2, 3, 4, 5 };
            var list2 = new int?[] { 3, 4, 5, 6, 7 };
            var list3 = new int?[] { 6, 9, 9 };

            var lockstep = LockStepSequences(new[] { list1, list2, list3 });

            foreach (var step in lockstep)
                Console.WriteLine(string.Join("\t", step.Select(i => i.HasValue ? i.Value.ToString() : "null").ToArray()));
        }

        public static IEnumerable<IEnumerable<T>> LockStepSequences<T>(this IEnumerable<IEnumerable<T>> sequences)
        {
            var iters = sequences
                .Select((s, index) => new { active=true, index, enumerator = s.GetEnumerator() })
                .ToArray();

            var isActive = iters.Select(it => it.enumerator.MoveNext()).ToArray();
            var numactive = isActive.Count(flag => flag);

            try
            {
                while (numactive > 0)
                {
                    T min = iters
                        .Where(it => isActive[it.index])
                        .Min(it => it.enumerator.Current);

                    var row = new T[iters.Count()];

                    for (int j = 0; j < isActive.Length; j++)
                    {
                        if (!isActive[j] || !Equals(iters[j].enumerator.Current, min)) 
                            continue;

                        row[j] = min;
                        if (!iters[j].enumerator.MoveNext())
                        {
                            isActive[j] = false;
                            numactive -= 1;
                        }
                    }
                    yield return row;
                }
            }
            finally
            {
                foreach (var iter in iters) iter.enumerator.Dispose();
            }
        }
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1	null	null
2	null	null
3	3	null
4	4	null
5	5	null
null	6	6
null	7	null
null	null	9
null	null	9

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
