// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.02
// date:	2011-10-14 14:12:40
// status:	0
// result:	15
// memory:	38016
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
	struct QA { public string Q, A; }

    static Random _r = new Random();        
    static int Quiz()
    {
        var QAndA = new QA[] {
            new QA { Q = "What is the capital of France"  , A = "Paris"}, 
            new QA { Q = "What is the capital of Spain"   , A = "Madrid"}, 
            //  ...
            new QA { Q = "What is the captial of Russia"  , A = "Moscow"}, 
            new QA { Q = "What is the capital of Ukraine" , A = "Kiev"}, 
        };

		foreach (var qa in QAndA.OrderBy(i => _r.Next()))
		{
            Question(qa.Q, qa.A);
		}

		return 0;
    }

	public static void Main(string[] args)
	{
		int n = Quiz();
	}

	private static void Question(string q, string a)
	{
		Console.WriteLine("Q. {0}", q);
		Console.WriteLine("A. {0}", a);
	}

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Q. What is the captial of Russia
A. Moscow
Q. What is the capital of Ukraine
A. Kiev
Q. What is the capital of Spain
A. Madrid
Q. What is the capital of France
A. Paris

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(30,21): warning CS0219: The variable `n' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
