/*
 * ideone.com
 * API sample
 * 
 * This program shows how to use ideone api.
 * 
 * How to run it?
 *  1. Create C# Windows Console Application project in the Visual Studio;
 *  2. Include Program.cs and Ideone_ServiceService.cs files to the project
 *      (you can generate the stub - Ideone_ServiceService.cs - by yourself 
 *      using wsdl.exe tool from Microsoft SDK);
 *  3. Add System.Web.Services reference to the project (right click on the
 *      project name in the Solution Explorer -> click Add Reference ...);
 *  4. Run the project.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;

namespace csharp_test
{
    class Program
    {
        static readonly IDictionary<string, string> extensions = new Dictionary<string, string> {
            { "Assembler", ".asm" },
            { "Bash", ".sh" },
            { "C", ".c" },
            { "C#", ".cs" },
            { "C++ 4.3.2", ".cpp" },
            { "C++ 4.8.1", ".cpp" },
            { "C++11", ".cpp" },
            { "C99 strict", ".c" },
            { "Haskell", ".hs" },
            { "Java", ".java" },
            { "Perl", ".pl" },
            { "PHP", ".php" },
            { "Python", ".py" },
            { "VB.NET", ".vb" },
        };

        static void Main(string[] args)
        {
            Ideone_ServiceService client = new Ideone_ServiceService(); // instantiating the stub

            foreach (var id in new [] {
                    //"1KIzOL", "PmstIn", "vTCS6V", "J5aKuR", "zsmHjG", "ZWYuCd", "1GjkVJ", "Um5cuU",
                    //"GDkGWi", "dq78eM", "IwAISf", "uNFYYD", "Owcvfm", "agA3YC", "JOxcSM", "1qI6Mp",
                    //"QFBPJK", "ZTNvne", "yb1vdW", "x219r7", "BwIhEE", "6nd6tW", "htr6iA", "Dsce2d",
                    //"pa1Ycy", "HMsaVl", "pwo5Cu", "t9zLM6", "aznLR0", "7U7dkh", "0PpOs8", "EsK6W8",
                    //"lBiDxD", "a7XWek", "Yrp3ib", "SZX2u6", "WA6nwg", "qJcqKJ", "vvQFLX", "u29r9G",
                    //"HD4Vj8", "4pyUR1", "EXKtCo", "4hmQ2P", "8N152n", "938hcO", "BkCPAT", 
                    "UrmlpR",
                    "xAlPzv", "myOqav", "Bnt6m6", "PNENMv", "4RcIrD", "YUKZv2", "VVVTYe", "8lL0C3",
                    "c9xw3J", "37hhY3", "gN3cq8", "wzgSXX", "0KU9sy", "ZY9qBm", "30zoCA", "DxRNUa",
                    "lmq26i", "ifp0NC", "f2Mxg6", "hdnRYx", "rBTi42", "elp3IF", "Hacgcy", "tRC6Cj",
                    "eP8VRX", "FJ2fsj", "DN9vHW", "9guFEF", "fSobD8", "4k83TJ", "rBdyaH", "THsjaL",
                    "1YS14N", "8AmATI", "Q87JsV", "PZKYEP", "AsufUo", "15z5Zm", "GZNQxS", "ZeLt1E",
                    "yFBlpF", "0sJCs4", "rNlQj7", "oWfYPZ", "h4Fx4y", "0vjeKE", "butnkS", "3qSbwo",
                    "w9tqHD", "cvHDxK", "8dEy87", "imoRNF",
                    // page 2
                    "ZlWcMR", "E4G9Fp", "ExnufJ", "Zz1pRI", "pB7aIE", "0eTr7F", "1tYfs2", "MEZY3k",
                    "kS7XqB", "GuPZwt", "zFrJa8", "7DYSSn", "seovl5", "U2geNF", "quxac2", "odqhBz",
                    "e8GjMg", "1NCTFT", "O5sLIS", "wvcEX6", "Zvadwf", "BGXH9W", "ki14GO", "IPrwSN",
                    "0Lwn5u", "54Fzco", "NbEPJR", "k2VsIx", "GKee9u", "uxCwLQ", "Q89e6A", "3R5hCX",
                    "gutPFv", "ZbzCZe", "Mt0DFR", "MfOqYC", "EgW6t5", "eLZVdW", "3Jqwpc", "dcNhPI",
                    "A2aM3R", "juYQ7U", "Evgdz1", "POt5gp", "VPtLbT", "tq9DaY", "Jwxr2a", "Rmbyf7",
                    "hxlkZF", "c2cHgZ", "RBqEnb", "DVCyE9", "PlkpqK", "120Ezs", "G9Kzfy", "zrXcwH",
                    "Xv9IH1", "AghZ0k", "iYk4IM", "wcI872", "00DMux", "JFUaL0", "FuZIDy", "NaFrzG",
                    "H4gCoE", "mFLYhT", "kG4kqO", "O36nWc", "Qk56aF", "Ex4119", "JIzpml", "GlWHsk",
                    "vjdagA", "QEO0zu", "5QKGwt", "UWb3dg", "6rAj7k", "NVlRWC", "urdLP2", "DUPWwb",
                    "N6Zu0a", "Y24ErF", "uvhIBd", "Dr5f3W", "xLqPV6", "aHuB8", "IV2w9", "Tx1kz",
                    "l23He", "lyUdE", "ItgNG", "K5WJ4", "0ZHx0", "Wtzwv", "XLuFy", "I47R8",
                    "xO4lz", "JdpeL", "GB3Hd", "0YNiG",
                    // page 3
                    "pIawu", "d3YvR", "3NylI", "we1o2", "9MmE9", "c45oC", "z6jYY", "VPOTF",
                    "cZyyD", "NXzQB", "XpzHE", "LgAgs", "WE6WN", "KmkI6", "BuM8t", "9dCvr",
                    "R1bWq", "H8Prh", "fwJx5", "UKgzg", "MExyx", "MXjkh", "YqoDo", "seZTa",
                    "jVGg6", "yqrOH", "NzSD4", "QJMiF", "pm8Oz", "1CA3e", "IYorg", "rMVXy",
                    "97x29", "XZrh9", "w7lii", "jk9yl", "i3gnn", "IBziN", "1EZ2Y", "6LPK9",
                    "awWAb", "s7Vrd", "7LXW0", "DuIkZ", "1HCvu", "CzJDX", "GEIrq", "jwHo2",
                    "4VnEU", "E5ICn", "FAQSm", "HbKVk", "jZQJq", "UWgQe", "aDkhW", "PYWpq",
                    "KdAhO", "X0GRx", "z2Y0A", "lzhBr", "fVmh4", "7qJjU", "vhBnZ", "aKLt9",
                    "i695R", "zCj3v", "Azse6", "4xfkE", "RPXCh", "IlxFD", "tlQWI", "IzDAj",
                    "ROJy9", "ZkJEk", "aRvus", "WN5qQ", "aK23U", "0ncl1", "S2WUC", "ib7zi",
                    "6f4pf", "uuqcV", "nwO7w", "H5z0d", "p46mO", "26nqr", "h08ZS", "i4ygJ",
                    "Hsw6C", "1HRlZ", "DsQOZ", "6dbIU", "8KIsW", "pPWZk", "Ci4eo", "6MaHJ",
                    "F0rC3", "6dxZG", "yFm9P", "AUrXy",
                    // page 4
                    "A6RQU", "CrL4z", "VHcEC", "JILEA", "8AkSQ", "wZB8F", "5nc3m", "mXoGQ",
                    "SgbEN", "te49B", "WuqFf", "W8c66", "YsG7V", "yApYp", "QldXV", "8uU01",
                    "xr55F", "N20xU", "3Uz2m", "NJ4yk", "ZMNb1", "nTTvE", "5y9mR", "h5y7R",
                    "LlCPh", "AqmsL", "YuaqY", "Ld7It", "6IQBZ", "ATY4q", "zZHuS", "rukw4",
                    "yhK9t", "w8pHg", "TgtZK", "VEEQa", "J6pl4", "TDufv", "chti1", "EDof0",
                    "sXM7b", "kkB86", "eRniK", "ddjGX", "BELNc", "rpWGS", "WwI87", "amImX",
                    "WFo4g", "FVtlk", "AmtuT", "TTuBP", "Ly38P", "95gMc", "H6SAd", "9Zj58",
                    "5T4fZ", "084uD", "NsjfM", "mut9V", "lfmDq", "467Aj", "FC4xm", "g6GJv",
                    "41rpZ", "5Lya6", "iLDJo", "1mfsm", "zs9Ar", "oxslQ", "6zJJp", "02pdJ",
                    "45fCX", "7Oa5n", "Kf2du", "lvsEi", "C39R6", "2uSZT", "P4HM4", "k94en",
                    "LQk8U", "0fmy0", "KQj1G", "99sKB", "HtAAg", "YKq3d", "b0m7T", "fz36y",
                    "C5HTR", "U4w7j", "Omkue", "1qmYk", "1ODS5", "3GiWA", "bamvZ", "dyfoD",
                    "E6QJy", "fLHvg", "YsVRE", "5qlyU",
                    // page 5
                    "OQVN6", "Z3Yat", "xevL0", "2BlsK", "RoYmc", "5BDKr", "zHbUh", "gfi2C",
                    "TvJZd", "h1IqP", "9MuW3", "TpgLw", "LIawL", "0k1wE", "WUipr", "bYhq9",
                    "P6uI2", "qTVI5", "eONEp", "uEvmE", "qC4Bx", "lHuQZ", "tTdgt",
                    })
            try
            {
                var ret = client.getSubmissionDetails("sehe", "K1ERN1CzJhyCkigUB8UZwPHqq", id, true, true, true, true, true);

                // filling result with data returned by testFunction
                var result =  ret.OfType<XmlElement>()
                    .Select(o => o.ChildNodes)
                    .ToDictionary(x => x.Item(0).InnerText, x => x.Item(1).InnerText);

                var fname = "output/" + id + extensions[result["langName"]];
                Console.WriteLine("Slurping to {0}", fname);
                using (var fs = new StreamWriter(fname))
                {
                    // checking if everything went ok
                    if ("OK" == result["error"])
                    {
                        foreach (var kvp in result)
                        {
                            if (kvp.Key == "source" || 
                                kvp.Key == "input"  ||
                                kvp.Key == "output" ||
                                kvp.Key == "stderr" || 
                                kvp.Key == "cmpinfo")
                            {
                                continue;
                            }

                            fs.WriteLine("// {0}:\t{1}", kvp.Key, kvp.Value);
                        }
                        fs.WriteLine("// ------------------------------------------------");
                        fs.WriteLine(result["source"]);
                        fs.WriteLine("// ------------------------------------------------");
                        fs.WriteLine("#if 0 // stdin");   fs.WriteLine(result["input"]);   fs.WriteLine("#endif");
                        fs.WriteLine("#if 0 // stdout");  fs.WriteLine(result["output"]);  fs.WriteLine("#endif");
                        fs.WriteLine("#if 0 // stderr");  fs.WriteLine(result["stderr"]);  fs.WriteLine("#endif");
                        fs.WriteLine("#if 0 // cmpinfo"); fs.WriteLine(result["cmpinfo"]); fs.WriteLine("#endif");
                    }
                    else
                    {
                        Console.Error.WriteLine("Error occured: " + result["error"]);
                    }
                }
            } catch(Exception e)
            {
                Console.Error.WriteLine(e.ToString());
            }
        }
    }
}
