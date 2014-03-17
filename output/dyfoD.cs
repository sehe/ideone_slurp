// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-09-15 18:23:22
// status:	0
// result:	12
// memory:	40032
// signal:	1
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class P
{
	struct DataItem
	{
		public System.DateTime time;
		public int number;
	}

	public static void Main(string[] args)
	{
		var ItemList = new DataItem[] {} ;
		var groups = ItemList
			.GroupBy(item => new { item.time.Hour, item.time.Minute });
		var sums   = groups
			.ToDictionary(g => g.Key, g => g.Sum(item => item.number));


		// lookups now become trivially easy:

		int partialByTimeSlot = sums[new {Hour=23,Minute=10}];
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
prog.cs(24,21): warning CS0219: The variable `partialByTimeSlot' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
