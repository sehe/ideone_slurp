// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-09-19 16:32:58
// status:	0
// result:	15
// memory:	38000
// signal:	0
// public:	true
// ------------------------------------------------
using System;

public class Test
{
    private class Wrap<T> where T : struct
    {
        public T Value;

        public static implicit operator Wrap<T>(T v) { return new Wrap<T> { Value = v }; }
        public static implicit operator T(Wrap<T> w) { return w.Value; }

        public override string ToString() { return Value.ToString(); }
        public override int GetHashCode() { return Value.GetHashCode(); }
        // TODO other delegating operators/overloads
    }

    private static void assign(ref int i)
    {
        i = 42;
    }

    public static void Main()
    {
        Wrap<int> element = 7;
        var vars = new Wrap<int>[] {1, 2, element, 3, 4};
        Console.WriteLine(vars[2]);
        assign(ref vars[2].Value);
        Console.WriteLine(element);
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
7
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
