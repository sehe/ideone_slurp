// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.06
// date:	2013-08-20 22:24:18
// status:	0
// result:	15
// memory:	34096
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Text.RegularExpressions;
using System.Globalization;

public class Program
{
    private static Regex _re = new Regex("[abc].", RegexOptions.Compiled);

    public static void Main()
    {
        var textbox1 = "some strange text containing syllables";
        var textbox2 = _re.Replace(textbox1, m => new String(new [] {m.Value[1], m.Value[0]}));
        Console.WriteLine(textbox2);
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
some strnage text ocntianing syllbales

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
