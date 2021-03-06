// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-09-04 22:04:19
// status:	0
// result:	15
// memory:	2928
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

struct T
{
    T()         { std::cout << "default\n"; }
    T(T&&)      { std::cout << "move\n"; }
    T(T const&) { std::cout << "copy\n"; }
    ~T(){ std::cout << "hola\n"; }
};

int main(int argc, const char *argv[])
{
    {
        T a;
        const T &x = ((*argv[0]=='?') ? (T&&)T() : (T&&)a);
        std::cout << "done: " << &x << "\n";
    }
    std::cout << "exit\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
default
move
done: 0xbf909a1f
hola
hola
exit

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
