// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-06-22 09:05:13
// status:	0
// result:	15
// memory:	2880
// signal:	0
// public:	false
// ------------------------------------------------
struct Y
{
     explicit operator bool() const { return true; } // explicit requires std=c++0x
};

int main()
{
    Y a,b,c;

    bool x = (bool) b;   // cast required

    if (a && b || c) { } // cast not required
    if (a) { }           // cast not required

    for (;c;) { break; }
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
