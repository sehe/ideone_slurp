// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-09-22 01:03:09
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
using System.Linq;
using System.Xml.Linq;
using System.Xml.XPath;
using System.IO;
using System;

public class Program
{
    public static void Main(string[] args)
    {
        using (var fs = new StreamReader("./test.xml"))
        {
            var doc = XDocument.Parse(data);

            var parms = doc.Root.XPathSelectElements("params/tp")
                .ToDictionary(el => el.Attribute("name").Value, el => el.Value);

            var nits = doc.Root.XPathSelectElements("nits/tn")
                .Select(el => new {
                        Name = el.Attribute("name").Value,
                        Min  = (int) el.Element("min"),
                        Max  = (int) el.Element("max")
                    }).ToList();

            foreach (var kvp in parms)
                Console.WriteLine("{0}: {1}", kvp.Key, kvp.Value);

            foreach (var nit in nits
                    .OrderBy(nit => nit.Name)
                    .ThenBy(nit => nit.Max))
            {
                Console.WriteLine("{0}: {1} {2}", nit.Name, nit.Min, nit.Max);
            }
        }
    }

    public const string data = @"
        <config>

        <params>
          <tp name=""abc"">yes</tp>
          <tp name=""aee"">no</tp>
          <tp name=""bbc"">no</tp>
          <tp name=""ccb"">yes</tp>
        </params>

        <nits>
          <tn name=""kjh"">
            <min>44</min>
            <max>98</max> 
          </tn>

          <tn name=""klm"">
            <min>55</min>
            <max>88</max> 
          </tn>

          <tn name=""hhh"">
            <min>44</min>
            <max>98</max> 
          </tn>
        </nits>

        <params>
          <tp name=""lml"">no</tp>
          <tp name=""rre"">yes</tp>
          <tp name=""rst"">no</tp>
          <tp name=""wee"">yes</tp>
        </params>

        <nits>
          <tn name=""adf"">
            <min>44</min>
            <max>98</max> 
          </tn>

          <tn name=""ddd"">
            <min>42</min>
            <max>92</max> 
          </tn>

          <tn name=""kjj"">
            <min>92</min>
            <max>98</max> 
          </tn>
        </nits>

        </config>
        ";
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
