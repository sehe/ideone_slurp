// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-03-13 10:54:13
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
    [TestClass]
    public class RegConversionsTests : UnitTestsBase
    {
        [TestMethod] public void PositiveToChar()
        {
            Assert.AreEqual("99999999999999999999999999" , ((decimal?) 99999999999999999999999999M).ToWerChar());
            Assert.AreEqual("999999999999999999999999999", ((decimal?) 999999999999999999999999999M).ToWerChar());

            Assert.AreEqual("9999999999999999999999999.9", ((decimal?) 9999999999999999999999999.9M).ToWerChar());
            Assert.AreEqual("999999999999999999999999.99", ((decimal?) 999999999999999999999999.99M).ToWerChar());
            Assert.AreEqual("99999999999999999999999.999", ((decimal?) 99999999999999999999999.999M).ToWerChar());
            Assert.AreEqual("9999999999999999999999.9999", ((decimal?) 9999999999999999999999.9999M).ToWerChar());
            Assert.AreEqual("999999999999999999999.99999", ((decimal?) 999999999999999999999.99999M).ToWerChar());
            Assert.AreEqual("99999999999999999999.999999", ((decimal?) 99999999999999999999.999999M).ToWerChar());
            Assert.AreEqual("9999999999999999999.9999999", ((decimal?) 9999999999999999999.9999999M).ToWerChar());
            Assert.AreEqual("999999999999999999.99999999", ((decimal?) 999999999999999999.99999999M).ToWerChar());

            Assert.AreEqual("100000000000000000"         , ((decimal?) 99999999999999999.999999999M).ToWerChar());
            Assert.AreEqual("10000000000000000"          , ((decimal?) 9999999999999999.9999999999M).ToWerChar());
            Assert.AreEqual("1000000000000000"           , ((decimal?) 999999999999999.99999999999M).ToWerChar());

            Assert.AreEqual("100000000000000"            , ((decimal?) 99999999999999.999999999999999M).ToWerChar());

            Assert.AreEqual("0"                          , ((decimal?) 0M).ToWerChar());
            Assert.AreEqual("0.1"                        , ((decimal?) 0.1M).ToWerChar());
            Assert.AreEqual("0.01"                       , ((decimal?) 0.01M).ToWerChar());
            Assert.AreEqual("0.001"                      , ((decimal?) 0.001M).ToWerChar());
            Assert.AreEqual("0.0001"                     , ((decimal?) 0.0001M).ToWerChar());
            Assert.AreEqual("0.00001"                    , ((decimal?) 0.00001M).ToWerChar());
            Assert.AreEqual("0.000001"                   , ((decimal?) 0.000001M).ToWerChar());
            Assert.AreEqual("0.0000001"                  , ((decimal?) 0.0000001M).ToWerChar());
            Assert.AreEqual("0.00000001"                 , ((decimal?) 0.00000001M).ToWerChar());
            Assert.AreEqual("0"                          , ((decimal?) 0.000000001M).ToWerChar());
            Assert.AreEqual("3.14159265"                 , ((decimal?) 3.14159265359M).ToWerChar());
            Assert.AreEqual("3.14159265"                 , ((decimal?) 3.1415926535M).ToWerChar());
            Assert.AreEqual("3.14159265"                 , ((decimal?) 3.141592653M).ToWerChar());
            Assert.AreEqual("3.14159265"                 , ((decimal?) 3.14159265M).ToWerChar());
            Assert.AreEqual("3.1415926"                  , ((decimal?) 3.1415926M).ToWerChar());
            Assert.AreEqual("3.141592"                   , ((decimal?) 3.141592M).ToWerChar());
            Assert.AreEqual("3.14159"                    , ((decimal?) 3.14159M).ToWerChar());
            Assert.AreEqual("3.1415"                     , ((decimal?) 3.1415M).ToWerChar());
            Assert.AreEqual("3.141"                      , ((decimal?) 3.141M).ToWerChar());
            Assert.AreEqual("3.14"                       , ((decimal?) 3.14M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.0M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.0000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.00000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.000000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.0000000M).ToWerChar());
            Assert.AreEqual("3"                          , ((decimal?) 3.00000000M).ToWerChar());
        }

        [TestMethod] public void NegativeToChar()
        {

            Assert.AreEqual("-99999999999999999999999999" , ((decimal?) -99999999999999999999999999M).ToWerChar());
            Assert.AreEqual("-999999999999999999999999999", ((decimal?) -999999999999999999999999999M).ToWerChar());

            Assert.AreEqual("-9999999999999999999999999.9", ((decimal?) -9999999999999999999999999.9M).ToWerChar());
            Assert.AreEqual("-999999999999999999999999.99", ((decimal?) -999999999999999999999999.99M).ToWerChar());
            Assert.AreEqual("-99999999999999999999999.999", ((decimal?) -99999999999999999999999.999M).ToWerChar());
            Assert.AreEqual("-9999999999999999999999.9999", ((decimal?) -9999999999999999999999.9999M).ToWerChar());
            Assert.AreEqual("-999999999999999999999.99999", ((decimal?) -999999999999999999999.99999M).ToWerChar());
            Assert.AreEqual("-99999999999999999999.999999", ((decimal?) -99999999999999999999.999999M).ToWerChar());
            Assert.AreEqual("-9999999999999999999.9999999", ((decimal?) -9999999999999999999.9999999M).ToWerChar());
            Assert.AreEqual("-999999999999999999.99999999", ((decimal?) -999999999999999999.99999999M).ToWerChar());

            Assert.AreEqual("-100000000000000000"         , ((decimal?) -99999999999999999.999999999M).ToWerChar());
            Assert.AreEqual("-10000000000000000"          , ((decimal?) -9999999999999999.9999999999M).ToWerChar());
            Assert.AreEqual("-1000000000000000"           , ((decimal?) -999999999999999.99999999999M).ToWerChar());

            Assert.AreEqual("-100000000000000"            , ((decimal?) -99999999999999.999999999999999M).ToWerChar());

            Assert.AreEqual("0"                           , ((decimal?) -0M).ToWerChar());
            Assert.AreEqual("-0.1"                        , ((decimal?) -0.1M).ToWerChar());
            Assert.AreEqual("-0.01"                       , ((decimal?) -0.01M).ToWerChar());
            Assert.AreEqual("-0.001"                      , ((decimal?) -0.001M).ToWerChar());
            Assert.AreEqual("-0.0001"                     , ((decimal?) -0.0001M).ToWerChar());
            Assert.AreEqual("-0.00001"                    , ((decimal?) -0.00001M).ToWerChar());
            Assert.AreEqual("-0.000001"                   , ((decimal?) -0.000001M).ToWerChar());
            Assert.AreEqual("-0.0000001"                  , ((decimal?) -0.0000001M).ToWerChar());
            Assert.AreEqual("-0.00000001"                 , ((decimal?) -0.00000001M).ToWerChar());
            Assert.AreEqual("0"                           , ((decimal?) -0.000000001M).ToWerChar());
            Assert.AreEqual("-3.14159265"                 , ((decimal?) -3.14159265359M).ToWerChar());
            Assert.AreEqual("-3.14159265"                 , ((decimal?) -3.1415926535M).ToWerChar());
            Assert.AreEqual("-3.14159265"                 , ((decimal?) -3.141592653M).ToWerChar());
            Assert.AreEqual("-3.14159265"                 , ((decimal?) -3.14159265M).ToWerChar());
            Assert.AreEqual("-3.1415926"                  , ((decimal?) -3.1415926M).ToWerChar());
            Assert.AreEqual("-3.141592"                   , ((decimal?) -3.141592M).ToWerChar());
            Assert.AreEqual("-3.14159"                    , ((decimal?) -3.14159M).ToWerChar());
            Assert.AreEqual("-3.1415"                     , ((decimal?) -3.1415M).ToWerChar());
            Assert.AreEqual("-3.141"                      , ((decimal?) -3.141M).ToWerChar());
            Assert.AreEqual("-3.14"                       , ((decimal?) -3.14M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.0M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.0000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.00000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.000000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.0000000M).ToWerChar());
            Assert.AreEqual("-3"                          , ((decimal?) -3.00000000M).ToWerChar());
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
prog.cs(2,40): error CS0246: The type or namespace name `UnitTestsBase' could not be found. Are you missing a using directive or an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
