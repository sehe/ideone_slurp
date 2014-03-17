// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.01
// date:	2011-09-03 00:18:15
// status:	0
// result:	15
// memory:	36936
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

namespace TestThat
{
    class MainClass
    {
        public static void Main (string[] args)
        {
			var theList = new [] {
				new { PartNumber="FID34" }
			};
			
			var result = theList
				.Where (line => line.PartNumber.StartsWith("FID", StringComparison.CurrentCultureIgnoreCase))
				.OrderBy (line =>
					{	
						int pnumber;
						return Int32.TryParse(line.PartNumber.Substring(3), out pnumber)
							? pnumber 
							: 0;
					});

        }
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
prog.cs(15,29): warning CS0168: The variable `result' is declared but never used
Compilation succeeded - 1 warning(s)

#endif
