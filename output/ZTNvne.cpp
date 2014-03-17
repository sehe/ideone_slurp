// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-26 09:47:02
// status:	0
// result:	15
// memory:	3296
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
struct ITimer {
    virtual void createTimer() = 0;
};
class A : public virtual ITimer
{
    public:
        void showA() {
            printf("showA\n");
            createTimer();
        }
};

class B : public virtual ITimer
{
    public:
        void showB() {
            printf("showB\n");
        }
        virtual void createTimer() {
            printf("createTimer");
        }
};

class C: public A, public B
{
    public:
        void test() {
            showA();
            showB();
        }
};

int main()
{
    C c;
    c.test();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
showA
createTimershowB

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
