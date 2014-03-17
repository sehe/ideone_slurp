// error:	OK
// langId:	41
// langName:	C++ 4.3.2
// langVersion:	gcc-4.3.2
// time:	0
// date:	2013-06-30 02:12:34
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
namespace parsers
{
    int rule;

    void initialize()
    {
        static bool done = false;
        if (!done)
        {
            rule %= 1;
            done = true;
        }
    }
}

void doParse(...)
{
    using namespace parsers;
    initialize(); // **this** is the initialization step
}

int main()
{
     doParse(1, 2, "something", "bye");
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
