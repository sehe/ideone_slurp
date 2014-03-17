// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-09-14 00:43:35
// status:	0
// result:	15
// memory:	38184
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;


public static class Program
{

	const string text = @"C12 0402 123456 90
C133 0402 123456 90
C9 0402 123456 90
C132 0603 abcd 0
C54 0603 abcd 0
R FID1 fiducial 0
R FID2 fiducial 0
R FID3 fiducial 0
R FID2 fiducial 0
C9 0402 123456 90
C9 0402 123456 90
R FID4 fiducial 0";

	private static IEnumerable<string> ReadAllLines(this string text)
	{
		string s;
		using (var r = new StringReader(text))
			while (null != (s = r.ReadLine()))
				yield return s;
	}

    public static void Main(string[] args)
    {
		var theList = ReadAllLines(text)
			.Select(l => l.Split(" ".ToCharArray()))
			.Select(fields => new {
					Field1 = fields[0],
					Field2 = fields[1],
					Field3 = fields[2],
					Field4 = fields[3] })
			.Distinct();

		foreach (var r in theList)
			Console.WriteLine("{0}, {1}, {2}, {3}", 
					r.Field1, r.Field2, r.Field3, r.Field4);
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
C12, 0402, 123456, 90
C133, 0402, 123456, 90
C9, 0402, 123456, 90
C132, 0603, abcd, 0
C54, 0603, abcd, 0
R, FID1, fiducial, 0
R, FID2, fiducial, 0
R, FID3, fiducial, 0
R, FID4, fiducial, 0

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
