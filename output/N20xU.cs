// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-11-14 00:11:56
// status:	0
// result:	15
// memory:	37600
// signal:	0
// public:	false
// ------------------------------------------------
public interface IInterface1 {};
public interface IEtcetera {};

public struct CanUseThis : IEtcetera, IInterface1 {}
public class  OrThat     : IEtcetera, IInterface1 {}

public class Foo
{
    private IInterface1 _object; // just pick one

    public void setObject<T>(T obj)
        where T : IInterface1, IEtcetera
    {
        // you now *know* that object supports all the interfaces
        // you don't need the compiler to remind you
        _object = obj; 
    }

    public void ExerciseObject()
    { 
        // completely safe due to the constraints on setObject<T>
        IEtcetera itf = (IEtcetera) _object;

        // ....
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        var foo = new Foo();

        foo.setObject(new CanUseThis());
        foo.ExerciseObject();

        foo.setObject(new OrThat());
        foo.ExerciseObject();
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
prog.cs(22,19): warning CS0219: The variable `itf' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
