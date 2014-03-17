// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-09-26 12:03:43
// status:	0
// result:	15
// memory:	38056
// signal:	0
// public:	true
// ------------------------------------------------
using System;

class Test
{
    static void Main(string[] args)
    {
        try
        {
            Top();
        }
        catch (Exception e)
        {
            Console.WriteLine(e);
        }
    }

    static void Top()
    {
        try
        {
            Middle();
        }
        catch (Exception e)
        {
            throw new Exception("Exception from top", e);
        }
    }

    static void Middle()
    {
        try
        {
            Bottom();
        }
        catch (Exception e)
        {
            throw new Exception("Exception from middle", e);
        }
    }

    static void Bottom()
    {
        throw new Exception("Exception from bottom");
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
System.Exception: Exception from top ---> System.Exception: Exception from middle ---> System.Exception: Exception from bottom
  at Test.Middle () [0x00000] in <filename unknown>:0 
  --- End of inner exception stack trace ---
  at Test.Middle () [0x00000] in <filename unknown>:0 
  at Test.Top () [0x00000] in <filename unknown>:0 
  --- End of inner exception stack trace ---
  at Test.Top () [0x00000] in <filename unknown>:0 
  at Test.Main (System.String[] args) [0x00000] in <filename unknown>:0 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
