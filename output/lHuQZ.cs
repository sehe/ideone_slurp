// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2011-07-14 16:11:11
// status:	0
// result:	15
// memory:	37600
// signal:	0
// public:	true
// ------------------------------------------------
class Program
{
[System.Flags]
enum Fruit
{
    None,
    Apple  /* = 1*/,
    Orange    = Apple << 1,
    Banana    = Orange << 1,
 
    All       = (Banana << 1) -1
}
public static void Main(string[] s)
{
     Fruit value = Fruit.Orange;
     bool ok = value == Fruit.None;
     ok = value == Fruit.All;
     ok = (value & ~Fruit.All) != 0;
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
prog.cs(16,11): warning CS0219: The variable `ok' is assigned but its value is never used
Compilation succeeded - 1 warning(s)

#endif
