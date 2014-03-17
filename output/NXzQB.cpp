// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-09-04 21:41:33
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
    T a;
    const T &x = ((*argv[0]=='x') ? (T&&)T() : (T&&)a);
    std::cout << "done\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
default
move
done
hola
hola

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
