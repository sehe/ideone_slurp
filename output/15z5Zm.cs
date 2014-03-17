// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.08
// date:	2013-07-09 22:34:17
// status:	0
// result:	15
// memory:	34168
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Program
{
    public static void Main(string[] args)
    {
        var s = new string(Enumerable.Range('a', 26).Select(i => (char)i).ToArray());

        var re = new Regex("(?![h-j])[a-z]");

        // replace all matches by #
        s = re.Replace(s, "#");

        Console.WriteLine(s);

        foreach(char c in s)
            Console.WriteLine("{0:X} '{1}'", (int) c, c);
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
#######hij################
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
68 'h'
69 'i'
6A 'j'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'
23 '#'

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
