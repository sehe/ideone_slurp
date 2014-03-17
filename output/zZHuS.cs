// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-11-09 15:03:21
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
public class Program
{
    public static void Main(string[] args)
    {
        // commented for IdeOne fair use :)
        // for (int i=int.MinValue; i<int.MaxValue; i++)
        {
            string dummy = "really a dummy " + i.ToString();
        }

/*
 *        // method line 2
 *        .method public static hidebysig 
 *               default void Main (string[] args)  cil managed 
 *        {
 *                // Method begins at RVA 0x20f4
 *            .entrypoint
 *            // Code size 45 (0x2d)
 *            .maxstack 6
 *            .locals init (
 *                int32	V_0,
 *                string	V_1)
 *            IL_0000:  ldc.i4 -2147483648
 *            IL_0005:  stloc.0 
 *            IL_0006:  br IL_0021
 *
 *            IL_000b:  ldstr "really a dummy "
 *            IL_0010:  ldloca.s 0
 *            IL_0012:  call instance string int32::ToString()
 *            IL_0017:  call string string::Concat(string, string)
 *            IL_001c:  stloc.1 
 *            IL_001d:  ldloc.0 
 *            IL_001e:  ldc.i4.1 
 *            IL_001f:  add 
 *            IL_0020:  stloc.0 
 *            IL_0021:  ldloc.0 
 *            IL_0022:  ldc.i4 2147483647
 *            IL_0027:  blt IL_000b
 *
 *            IL_002c:  ret 
 *        } // end of method Program::Main
 */

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
prog.cs(8,48): error CS0103: The name `i' does not exist in the current context
Compilation failed: 1 error(s), 0 warnings

#endif
