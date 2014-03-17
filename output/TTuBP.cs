// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-10-25 13:13:42
// status:	0
// result:	15
// memory:	38056
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

//public interface IThing {} 
public class MachineClass /* : IThing */ { }
public class AnimalClass  /* : IThing */ { }
public class Plane        /* : IThing */ { }

public class Program
{
     public enum Things
     {
         Car,
         Animal,
         Plane
     }

     private static readonly IDictionary<Things, string> _classNameMap = 
         new Dictionary<Things, string> {
          { Things.Car,    "MachineClass" },
          { Things.Animal, "AnimalClass"  },
          { Things.Plane,  "FlyClass"     }  };

     public static void Main(string[] args)
     {
         var realtypes = _classNameMap.ToDictionary(
                 kvp => kvp.Key,
                 kvp => System.Type.GetType(/*"Namespace." +*/ kvp.Value));

         Type dynamicType = realtypes[Things.Plane]; // typeof(Namespace.FlyClass)

         foreach (var realtype in realtypes)
             Console.WriteLine("{0}, class {1}", 
                     realtype.Key, realtype.Value);
     }

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Car, class MachineClass
Animal, class AnimalClass
Plane, class 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(31,15): warning CS0219: The variable `dynamicType' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
