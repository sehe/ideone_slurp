// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-04 08:49:34
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

struct Library { /*    */ };

template <typename Signature>
struct Function
{
    Function(Library& library, std::string name) {}
    operator Signature *() { return stub; /* TODO */ }
  private:
    static int stub(int i, double d) { return i*d; }
};

int main()
{
    Library library;
    Function<int (int, double)> foo(library, "foo");
    int i = foo(42, 2.0);

    std::cout << "value: " << i << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
value: 84

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
