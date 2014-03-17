// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-18 22:17:21
// status:	0
// result:	15
// memory:	2852
// signal:	0
// public:	true
// ------------------------------------------------
struct A
{
    unsigned int m_uiField;
};

struct B : A
{
    virtual void VirtualMethod() { }
};

int main()
{
    A instance_a;
    B instance_b;

    unsigned int A::*  ptrA = &A::m_uiField;
    unsigned int B::*  ptrB = &B::m_uiField;

    // application:
    unsigned int value = instance_a.*ptrA;
                 value = instance_b.*ptrA;
               //value = instance_a.*ptrB; // incompatible types
                 value = instance_b.*ptrB;

    // also:
    A* dynamic = new B();
    value = dynamic->*ptrA; // etc
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
