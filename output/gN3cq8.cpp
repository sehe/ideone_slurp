// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-20 01:55:40
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Globalization;

public class Program
{
    public static void Main()
    {
        string ValueToParse = "2.53327490880368E+15";
        Console.WriteLine("{0:X16}", (ulong) decimal.Parse(ValueToParse, NumberStyles.Any, CultureInfo.InvariantCulture));
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
prog.cpp:1:7: error: expected nested-name-specifier before ‘System’
 using System;
       ^
prog.cpp:1:7: error: ‘System’ has not been declared
prog.cpp:2:7: error: expected nested-name-specifier before ‘System’
 using System.Globalization;
       ^
prog.cpp:2:7: error: ‘System’ has not been declared
prog.cpp:2:13: error: expected ‘;’ before ‘.’ token
 using System.Globalization;
             ^
prog.cpp:2:13: error: expected unqualified-id before ‘.’ token
prog.cpp:4:1: error: expected unqualified-id before ‘public’
 public class Program
 ^

#endif
