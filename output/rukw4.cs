// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2011-11-07 12:31:11
// status:	0
// result:	15
// memory:	38104
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Text;
using System.Text.RegularExpressions;

struct MyDate 
{ 
	public int? Year, Month, Day, Hour, Minute; 

	private static readonly Regex dtRegex = new Regex(
		@"^(?<year>\d{4})?-(?<month>\d\d)?-(?<day>\d\d)?"
	+   @"(?:T(?<hour>\d\d)?:(?<minute>\d\d)?)?$",
		RegexOptions.Compiled | RegexOptions.IgnoreCase | RegexOptions.CultureInvariant);

	public static bool TryParse(string input, out MyDate result)
	{
		Match match = dtRegex.Match(input);
		result = default(MyDate);

		if (match.Success)
		{
			if (match.Groups["year"].Success)
				result.Year = Int32.Parse(match.Groups["year"].Value);
			if (match.Groups["month"].Success)
				result.Month = Int32.Parse(match.Groups["month"].Value);
			if (match.Groups["day"].Success)
				result.Day = Int32.Parse(match.Groups["day"].Value);
			if (match.Groups["hour"].Success)
				result.Hour = Int32.Parse(match.Groups["hour"].Value);
			if (match.Groups["minute"].Success)
				result.Minute = Int32.Parse(match.Groups["minute"].Value);
		}

		return match.Success;
	}

	public static MyDate Parse(string input)
	{
		MyDate result;
		if (!TryParse(input, out result))
			throw new ArgumentException(string.Format("Unable to parse MyDate: '{0}'", input));

		return result;
	}

	public override string ToString()
	{
		return string.Format("{0:0000}-{1:00}-{2:00}T{3:00}:{4:00}", Year, Month, Day, Hour, Minute);
	}

	public static implicit operator MyDate(string input)
	{
		return Parse(input);
	}
}

class Program
{
    static void Main(string[] args)
    {
		foreach (var testcase in new [] { 
				"2011-11-07T11:17",
				"-11-07T11:17",
				"2011--07T11:17",
				"2011-11-T11:17",
				"2011-11-07T:17",
				"2011-11-07T11:",
				// extra:
				"--T11:17", // (11:17 am, no date, only time)
				"-11-07", // (november the 7th, no year, no time)
				// failures:
				"2011/11/07 T 11:17",
				"no match" })
		{
			MyDate parsed;
			if (MyDate.TryParse(testcase, out parsed))
				Console.WriteLine("'{0}' -> Parsed into '{1}'", testcase, parsed);
			else
				Console.WriteLine("'{0}' -> Parse failure", testcase);
		}
	}
}
 

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
'2011-11-07T11:17' -> Parsed into '2011-11-07T11:17'
'-11-07T11:17' -> Parsed into '-11-07T11:17'
'2011--07T11:17' -> Parsed into '2011--07T11:17'
'2011-11-T11:17' -> Parsed into '2011-11-T11:17'
'2011-11-07T:17' -> Parsed into '2011-11-07T:17'
'2011-11-07T11:' -> Parsed into '2011-11-07T11:'
'--T11:17' -> Parsed into '--T11:17'
'-11-07' -> Parsed into '-11-07T:'
'2011/11/07 T 11:17' -> Parse failure
'no match' -> Parse failure

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
