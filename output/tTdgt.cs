// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.04
// date:	2011-07-09 22:23:19
// status:	0
// result:	15
// memory:	37184
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Text.RegularExpressions;

public class MainClass
{
	public static void Main (string[] args)
	{
		var dbName = "DB_COLUMN_NAME";
		Console.WriteLine (CamelCase(dbName));
	}

	static private readonly Regex _camelHump = new Regex("_[^_]", RegexOptions.Compiled);
	static private string CamelCase(string dbname)
	{
		return _camelHump.Replace(dbname.ToLower(), match => match.Value[1].ToString().ToUpper());
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
dbColumnName

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
