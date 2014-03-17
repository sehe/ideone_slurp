// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2011-10-05 23:12:37
// status:	0
// result:	15
// memory:	38688
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Linq;


namespace Assembler
{
    internal class State
    {
        public readonly IDictionary<string, ulong> SymbolTable = new Dictionary<string, ulong>();

        public void Clear() 
        {
            SymbolTable.Clear();
        }
    }

    internal interface IReference
    {
        ulong EvalAddress(State s); // evaluate reference to address
    }

    internal abstract class ReferenceBase : IReference
    {
        public static IndexedReference operator+(long directOffset, ReferenceBase baseRef) { return new IndexedReference(baseRef, directOffset); }
        public static IndexedReference operator+(ReferenceBase baseRef, long directOffset) { return new IndexedReference(baseRef, directOffset); }

        public abstract ulong EvalAddress(State s);
    }

    internal class SymbolicReference : ReferenceBase
    {
        public static explicit operator SymbolicReference(string symbol)    { return new SymbolicReference(symbol); }
        public SymbolicReference(string symbol) { _symbol = symbol; }

        private readonly string _symbol;

        public override ulong EvalAddress(State s) 
        {
            return s.SymbolTable[_symbol];
        }

        public override string ToString() { return string.Format("Sym({0})", _symbol); }
    }

    internal class IndexedReference : ReferenceBase
    {
        public IndexedReference(IReference baseRef, long directOffset) 
        {
            _baseRef = baseRef;
            _directOffset = directOffset;
        }

        private readonly IReference _baseRef;
        private readonly long _directOffset;

        public override ulong EvalAddress(State s) 
        {
            return (_directOffset<0)
                ? _baseRef.EvalAddress(s) - (ulong) Math.Abs(_directOffset)
                : _baseRef.EvalAddress(s) + (ulong) Math.Abs(_directOffset);
        }

        public override string ToString() { return string.Format("{0} + {1}", _directOffset, _baseRef); }
    }
}

namespace Program
{
    using Assembler;

    public static class Program
    {
        public static void Main(string[] args)
        {
            var myBaseRef1 = new SymbolicReference("mystring1");
           
            Expression<Func<IReference>> anyRefExpr = () => 64 + myBaseRef1;
            Console.WriteLine(anyRefExpr);

            var myBaseRef2 = (SymbolicReference) "mystring2"; // uses explicit conversion operator
           
            Expression<Func<IndexedReference>> indexedRefExpr = () => 64 + myBaseRef2;
            Console.WriteLine(indexedRefExpr);

            Console.WriteLine(Console.Out.NewLine + "=== show compiletime types of returned values:");
            Console.WriteLine("myBaseRef1     -> {0}", myBaseRef1);
            Console.WriteLine("myBaseRef2     -> {0}", myBaseRef2);
            Console.WriteLine("anyRefExpr     -> {0}", anyRefExpr.Compile().Method.ReturnType);
            Console.WriteLine("indexedRefExpr -> {0}", indexedRefExpr.Compile().Method.ReturnType);

            Console.WriteLine(Console.Out.NewLine + "=== show runtime types of returned values:");
            Console.WriteLine("myBaseRef1     -> {0}", myBaseRef1);
            Console.WriteLine("myBaseRef2     -> {0}", myBaseRef2);
            Console.WriteLine("anyRefExpr     -> {0}", anyRefExpr.Compile()());     // compile() returns Func<...>
            Console.WriteLine("indexedRefExpr -> {0}", indexedRefExpr.Compile()());

            Console.WriteLine(Console.Out.NewLine + "=== observe how you could add an evaluation model using some kind of symbol table:");
            var compilerState = new State();
            compilerState.SymbolTable.Add("mystring1", 0xdeadbeef); // raw addresses
            compilerState.SymbolTable.Add("mystring2", 0xfeedface);

            Console.WriteLine("myBaseRef1 evaluates to     0x{0:x8}", myBaseRef1.EvalAddress(compilerState));
            Console.WriteLine("myBaseRef2 evaluates to     0x{0:x8}", myBaseRef2.EvalAddress(compilerState));
            Console.WriteLine("anyRefExpr displays as      {0:x8}",   anyRefExpr.Compile()());
            Console.WriteLine("indexedRefExpr displays as  {0:x8}",   indexedRefExpr.Compile()());
            Console.WriteLine("anyRefExpr evaluates to     0x{0:x8}", anyRefExpr.Compile()().EvalAddress(compilerState));
            Console.WriteLine("indexedRefExpr evaluates to 0x{0:x8}", indexedRefExpr.Compile()().EvalAddress(compilerState));
        }
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
() => (64 + value(Program.Program+<Main>c__AnonStorey0).myBaseRef1)
() => (64 + value(Program.Program+<Main>c__AnonStorey0).myBaseRef2)

=== show compiletime types of returned values:
myBaseRef1     -> Sym(mystring1)
myBaseRef2     -> Sym(mystring2)
anyRefExpr     -> Assembler.IReference
indexedRefExpr -> Assembler.IndexedReference

=== show runtime types of returned values:
myBaseRef1     -> Sym(mystring1)
myBaseRef2     -> Sym(mystring2)
anyRefExpr     -> 64 + Sym(mystring1)
indexedRefExpr -> 64 + Sym(mystring2)

=== observe how you could add an evaluation model using some kind of symbol table:
myBaseRef1 evaluates to     0xdeadbeef
myBaseRef2 evaluates to     0xfeedface
anyRefExpr displays as      64 + Sym(mystring1)
indexedRefExpr displays as  64 + Sym(mystring2)
anyRefExpr evaluates to     0xdeadbf2f
indexedRefExpr evaluates to 0xfeedfb0e

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
