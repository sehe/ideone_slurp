// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.08
// date:	2012-04-10 00:11:27
// status:	0
// result:	15
// memory:	37288
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Globalization;

namespace SODemo
{
	class MainClass
	{
		private static readonly CultureInfo CInfo = CultureInfo.CreateSpecificCulture("en-US");
		
		public static void Main (string[] args)
		{
			string segment = "51.54398, -0.27585;51.55175, -0.29631;51.56233, -0.30369;51.57035, -0.30856;51.58157, -0.31672;51.59233, -0.3354";
			
			var re = new Regex(@"\s*(?<lat>[-+]?[0-9.]+),\s*(?<lon>[-+]?[0-9.]+)\s*;", RegexOptions.Compiled | RegexOptions.CultureInvariant | RegexOptions.IgnoreCase);
			
			var locations = re.Matches(segment).Cast<Match>().Select(m => new 
			{
				Lat  = decimal.Parse(m.Groups["lat"].Value, CInfo),
				Long = decimal.Parse(m.Groups["lon"].Value, CInfo),
			});
				
			foreach (var l in locations)
			    Console.WriteLine(l);
		}
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
{ Lat = 51.54398, Long = -0.27585 }
{ Lat = 51.55175, Long = -0.29631 }
{ Lat = 51.56233, Long = -0.30369 }
{ Lat = 51.57035, Long = -0.30856 }
{ Lat = 51.58157, Long = -0.31672 }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
