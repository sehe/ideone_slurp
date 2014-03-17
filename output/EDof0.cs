// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-11-03 16:32:35
// status:	0
// result:	15
// memory:	37024
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static IEnumerable<int> SpecialIndexes()
    {
        int i=4; 
        
        while (i<Int32.MaxValue)
        {
            yield return i++;
            yield return i++;
            i += 2;
        }
    }

    public static void Main(string[] args)
    {
        var csvString = "G9999999990001800002777107050,G9999999990002777107HMNLAQKPRLLHRAQRWJ010,1,3,29,P,6.74,11.23,07,P,5.25,14.29,08,P,6.89,16.92,07,P,5,4,";

        var fields = csvString.Split(',');
        var selected = SpecialIndexes()
            .TakeWhile(i => i<fields.Length)
            .Select(i => fields[i]);

        Console.WriteLine(string.Join(" ", selected.ToArray()));
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
29 P 07 P 08 P 07 P 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
