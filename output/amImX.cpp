// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-28 01:04:50
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>
#include <list>
#include <vector>

template <template <typename, typename> class Container,
          template <typename> class Alloc = std::allocator>
struct ContainerTests 
{
    typedef Container<int, Alloc<int> > IntContainer;
    typedef Container<std::string, Alloc<int> > StringContainer;
    //
    void DoTests()
    {
        IntContainer ints;
        StringContainer strings;
        // ... etc
    }
};

int main()
{
    ContainerTests<std::vector> t1;
    ContainerTests<std::list>   t2;

    t1.DoTests();
    t2.DoTests();
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
