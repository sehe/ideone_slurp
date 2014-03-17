// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-09 09:08:47
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	false
// ------------------------------------------------
struct A { };

class B : public A {
public:
    B& operator=(const A&) {
            return *this;
    }

    B& operator=(const B& other) {
        return *this = static_cast<const A&>(other);
    }
};

int main()
{
     B b;
     A a;

     b = a;
     b = b;

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

#endif
