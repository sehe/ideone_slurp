// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.06
// date:	2012-11-22 13:57:37
// status:	0
// result:	15
// memory:	37320
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
            var list1 = new int?[] {1, 2, 3, 4, 5};
            var list2 = new int?[] {3, 4, 5, 6, 7};
            var list3 = new int?[] {6, 9, 9};

            var lockstep = LockStepSequences(new[] {list1, list2, list3});

            foreach (var step in lockstep)
                Console.WriteLine(string.Join("\t", step.Select(i => i.HasValue? i.Value.ToString() : "null").ToArray()));
        }

        public static IEnumerable<IEnumerable<T>> LockStepSequences<T>(this IEnumerable<IEnumerable<T>> sequences)
        {
            var iters = sequences
                .Select((s, index) => new {index, enumerator = s.GetEnumerator()})
                .Where(it => it.enumerator.MoveNext())
                .ToArray();

            try
            {
                for(var active = iters.ToList(); active.Any();)
                {
                    T min = active.Min(it => it.enumerator.Current);
                    var corresponding = active.Where(it => Equals(it.enumerator.Current, min));

                    yield return iters.Select((el, i) => corresponding.Any(it => it.index == i)
                        ? el.enumerator.Current 
                        : default(T));

                    active = active.Except(corresponding.Where(it => !it.enumerator.MoveNext())).ToList();
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
