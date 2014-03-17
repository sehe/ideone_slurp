// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.08
// date:	2012-10-08 23:56:27
// status:	0
// result:	15
// memory:	37280
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

public class Program
{
    private static readonly Regex _clRegex = new Regex(
            @"^(?<command>blah)((\s+(?<option>--.+?))*(\s+(?<fspec>.*?))*)+$",
            RegexOptions.Compiled | RegexOptions.CultureInvariant | RegexOptions.IgnoreCase);

    public static void Main(string[] args)
    {
        string demo = "blah --arg1 --arg2 --etc doh";

        var sb = new StringBuilder();
        foreach (Match m in _clRegex.Matches(demo))
        {
            foreach (var kind in new [] {"command", "option", "fspec"})
            {
                var g = m.Groups[kind];
                if (g.Success) foreach (Capture cap in g.Captures)
                {
                    switch(kind)
                    {
                        case "command": sb.Append(cap); break;
                        case "fspec":   sb.Append(" " + Path.Combine(Directory.GetCurrentDirectory(), cap.Value)); break;
                        case "option":  sb.Append(" " + cap); break;
                    }
                }
            }
        }

        Console.WriteLine(sb.ToString().Trim());
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
blah --arg1 --arg2 --etc /home/9IjzeN/doh

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
