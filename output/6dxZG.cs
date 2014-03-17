// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-12-06 11:47:39
// status:	0
// result:	15
// memory:	38040
// signal:	0
// public:	false
// ------------------------------------------------
using System;

public class Program
{
    internal class A
    {
        public static implicit operator A(string s) { return new A { Value = s }; }
        public static implicit operator string(A a) { return a.Value; }

        public string Value;
        public override string ToString() { return Value; }
    }

    internal class B
    {
        public static implicit operator B(string s) { return new B { Value = s }; }
        public static implicit operator B(A a)      { return new B { Value = a }; }
        public static implicit operator A(B b)
        {
            b.Value = "clobbered"; // darn, no semantics enforced by the language
            return new Random().Next().ToString("X"); // 'basically unspecified'?
        }

        public string Value;
        public override string ToString() { return Value; }
    }
    
    public static void Main(string[] args)
    {
         B hello = "hello";
         A world = hello;

         Console.WriteLine("{0} {1}", hello, world);
    }   
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
clobbered 47453F33

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
