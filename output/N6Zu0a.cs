// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-10-30 08:37:00
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
using System.Linq;
using System.Xml.Linq;
using System;

public class stuff
{
    public static void Main(string[] args)
    {
        var doc = XDocument.Parse(xml);

        var last = doc.Root
            .XPathSelectElements("//H/FP/R/O | //H/R/O")
            .Last();

        Console.WriteLine(last);
        Console.WriteLine("Parent R has name '{0}'", last.Parent.Attribute("Name").Value);

        var granddad = last.Parent.Parent;
        if (granddad.Name == "FP")
            Console.WriteLine("Parent FP has name '{0}'", granddad.Attribute("Name").Value);
    }

    const string xml = @"<H>
        <FP Name=""FP1"">
            <R Name=""R1""> 
                <O Name=""O1""/>
                <O Name=""O2""/>
            </R>       
            <R Name=""R2"">
                <O Name=""O4""/>
            </R>
        </FP>
        <FP Name=""FP2"">
            <R Name=""R3"">
                <O Name=""O5""/>
                <O Name=""O6""/>
            </R>
        </FP>
    <!--
        <R Name=""R4"">
            <O Name=""O7""/>
            <O Name=""O8""/>
        </R>
        <R Name=""R5"">
            <O Name=""O9""/>
        </R>
    -->
        </H>";
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(2,18): error CS0234: The type or namespace name `Linq' does not exist in the namespace `System.Xml'. Are you missing an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
