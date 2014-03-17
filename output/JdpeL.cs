// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.07
// date:	2014-01-30 00:06:19
// status:	0
// result:	15
// memory:	34232
// signal:	0
// public:	false
// ------------------------------------------------
using System;
using System.Text;
using System.Security.Cryptography;

public class Program
{
    private const string key = "key";
    private const string message = "message";
    private static readonly Encoding encoding = Encoding.UTF8; 

    static void Main(string[] args)
    {
        var keyByte = encoding.GetBytes(key);
        using (var hmacsha256 = new HMACSHA256(keyByte))
        {
            hmacsha256.ComputeHash(encoding.GetBytes(message));

            Console.WriteLine("Result: {0}", ByteToString(hmacsha256.Hash));
         }
    }
    static string ByteToString(byte[] buff)
    {
        string sbinary = "";
        for (int i = 0; i < buff.Length; i++)
            sbinary += buff[i].ToString("X2"); /* hex format */
        return sbinary;
    }    
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Result: 6E9EF29B75FFFC5B7ABAE527D58FDADB2FE42E7219011976917343065F58ED4A

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
