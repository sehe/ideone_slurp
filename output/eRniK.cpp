// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-02 00:49:46
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

enum type { soft, brittle, hard };

std::ostream& operator<<(std::ostream& os, const type v)
{
    switch (v)
    {
        case soft: return os << "soft";
        case brittle: return os << "brittle";
        case hard: return os << "hard";
        default:   return os << "#" << v;
    }

    return os << "<error>";
}

int main()
{
    type a = hard;
    std::cout << a << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
hard

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
