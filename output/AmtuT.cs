// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-10-25 21:20:35
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Dynamic;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    using church = Func<dynamic, dynamic, dynamic>;

    class Program
    {
        static void Main(string[] args)
        {
            church True = (a, b) => a;
            church False = (a, b) => b;

            Func<church, church, church> And = (x, y) => x(y(True, False), False);
        }
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(2,14): error CS0234: The type or namespace name `Dynamic' does not exist in the namespace `System'. Are you missing an assembly reference?
prog.cs(2,14): error CS0234: The type or namespace name `Dynamic' does not exist in the namespace `System'. Are you missing an assembly reference?
prog.cs(9,25): error CS1980: Dynamic keyword requires `System.Runtime.CompilerServices.DynamicAttribute' to be defined. Are you missing System.Core.dll assembly reference?
prog.cs(9,34): error CS1980: Dynamic keyword requires `System.Runtime.CompilerServices.DynamicAttribute' to be defined. Are you missing System.Core.dll assembly reference?
prog.cs(9,43): error CS1980: Dynamic keyword requires `System.Runtime.CompilerServices.DynamicAttribute' to be defined. Are you missing System.Core.dll assembly reference?
Compilation failed: 5 error(s), 0 warnings

#endif
