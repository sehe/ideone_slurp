// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.14
// date:	2012-10-30 01:37:28
// status:	0
// result:	15
// memory:	43456
// signal:	0
// public:	false
// ------------------------------------------------
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Linq;
using System.IO;
using System;

public class Program
{
    public static void Main(string[] args)
    {
        ReplyH doc;
        using (var reader = new StringReader(xml))
            doc = (ReplyH) new XmlSerializer(typeof(ReplyH)).Deserialize(reader);

        var Rs = doc.FPs
            .SelectMany(fp => fp.Rs.Select(r => new { Parent = fp            , R=r }))
            .Concat    (     doc.Rs.Select(r => new { Parent = (ReplyFP) null, R=r }));

        var Os = Rs.SelectMany(r => r.R.Os.Select(o => new { Parent = r, O=o }));

        var lastO = Os.Last();
        Console.WriteLine(lastO.O.Name);

        if (lastO != null)
        {
            Console.WriteLine("Parent R has name '{0}'", lastO.Parent.R.Name);

            var granddad = lastO.Parent.Parent;
            if (granddad != null)
                Console.WriteLine("Parent FP has name '{0}'", granddad.Name);
        }
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

[XmlRoot("H")] public class ReplyH {
    [XmlElement("FP")] public List<ReplyFP> FPs = new List<ReplyFP>();
    [XmlElement("R")] public List<ReplyR> Rs = new List<ReplyR>();
}

public class ReplyFP {
    [XmlAttribute("Name")] public string Name; 
    [XmlElement("R")] public List<ReplyR> Rs = new List<ReplyR>();
}

public class ReplyR {
    [XmlAttribute("Name")] public string Name; 
    [XmlElement("O")] public List<ReplyO> Os = new List<ReplyO>();
}

public class ReplyO {
    [XmlAttribute("Name")] public string Name;
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
O6
Parent R has name 'R3'
Parent FP has name 'FP2'

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
