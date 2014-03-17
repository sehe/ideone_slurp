// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-11-29 11:16:12
// status:	0
// result:	15
// memory:	38120
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
	public static void Main(string[] a)
	{
		var groups = new [] { 
			"010000100001",
			"010000100001",
			"010000100001",
			"010000100002",
			"010000100002",
			"010000100002",
			"010000200003",
			"010000200003",
			"020000300004",
			"020000300005" }
		.GroupBy(s => new {
				Subject = s.Substring(0,2),
				Chapter = s.Substring(2,6),
				Book    = s.Substring(8) });

		foreach (var g in groups)
		{
			Console.WriteLine("Subject {0}, Chapter {1}, Book {2}",
					g.Key.Subject, g.Key.Chapter, g.Key.Book);
		}
	}
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Subject 01, Chapter 000010, Book 0001
Subject 01, Chapter 000010, Book 0002
Subject 01, Chapter 000020, Book 0003
Subject 02, Chapter 000030, Book 0004
Subject 02, Chapter 000030, Book 0005

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
