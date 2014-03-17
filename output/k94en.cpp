// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-28 00:05:12
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <type_traits>

template <typename T>
    typename std::enable_if<std::is_pod<T>::value>::type* FeedFace(T& v)
{
    static const unsigned char MAGIC[] = { 0xFE, 0xED, 0xFA, 0xCE };
    unsigned char *me = reinterpret_cast<unsigned char *>(&v);
    for( size_t ii = 0; ii < sizeof(T)/sizeof(unsigned char); ++ii ) 
        me[ii] = MAGIC[ii % sizeof(MAGIC)/sizeof(unsigned char)];
}

struct Pod { char data[37]; };
struct  NonPod : Pod { virtual ~NonPod() { } };

int main()
{
    Pod pod;
    FeedFace(pod);

    NonPod nonpod;
    FeedFace(nonpod);

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'int main()':
prog.cpp:22:20: error: no matching function for call to 'FeedFace(NonPod&)'

#endif
