// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.03
// date:	2012-09-17 12:41:25
// status:	0
// result:	15
// memory:	36720
// signal:	0
// public:	true
// ------------------------------------------------
class Program
{
    static void Main(string[] args)
    {
        // The MyClass type has a Finalize method defined for it
        // Creating a MyClass places a reference to obj on the finalization table.
        var myClass = new MyClass();

        // Append another 2 references for myClass onto the finalization table.
        System.GC.ReRegisterForFinalize(myClass);
        System.GC.ReRegisterForFinalize(myClass);
        // There are now 3 references to myClass on the finalization table.

        System.GC.SuppressFinalize(myClass);
        System.GC.SuppressFinalize(myClass);
        System.GC.SuppressFinalize(myClass);

        // Remove the reference to the object.
        myClass = null;

        // Force the GC to collect the object.
        System.GC.Collect(2, System.GCCollectionMode.Forced);

        // The first call to obj's Finalize method will be discarded but
        // two calls to Finalize are still performed.
    }
}

class MyClass
{
    ~MyClass()
    {
        System.Console.WriteLine("Finalise() called");
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

#endif
