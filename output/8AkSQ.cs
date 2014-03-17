// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-11-23 14:24:36
// status:	0
// result:	15
// memory:	38120
// signal:	0
// public:	false
// ------------------------------------------------
using System;

[Flags] enum Colors { None=0, Red = 1, Green = 2, Blue = 4 };

public class Example
{
   public static void Main()
   {
      string[] colorStrings = { "0", "2", "8", "blue", "Blue", "Yellow", "Red, Green" };
      foreach (string colorString in colorStrings)
      {
         try {
            Colors colorValue = (Colors) Enum.Parse(typeof(Colors), colorString);        
            if (Enum.IsDefined(typeof(Colors), colorValue) | colorValue.ToString().Contains(","))  
               Console.WriteLine("Converted '{0}' to {1}.", colorString, colorValue.ToString());
            else
               Console.WriteLine("{0} is not an underlying value of the Colors enumeration.", colorString);
         }
         catch (ArgumentException) {
            Console.WriteLine("'{0}' is not a member of the Colors enumeration.", colorString);
         }
      }
   }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Converted '0' to None.
Converted '2' to Green.
8 is not an underlying value of the Colors enumeration.
'blue' is not a member of the Colors enumeration.
Converted 'Blue' to Blue.
'Yellow' is not a member of the Colors enumeration.
Converted 'Red, Green' to Red, Green.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
