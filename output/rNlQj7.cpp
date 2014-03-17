// error:	OK
// langId:	41
// langName:	C++ 4.3.2
// langVersion:	gcc-4.3.2
// time:	0
// date:	2013-06-30 02:15:07
// status:	0
// result:	15
// memory:	2680
// signal:	0
// public:	false
// ------------------------------------------------
struct grammar
{
    int rule;

    grammar() : rule(0)
    {
        rule %= 1; // you can do whatever you please here.
    }
};

void doParse(...)
{
    static const grammar p;
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
