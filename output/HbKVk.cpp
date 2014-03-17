// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-03-30 10:56:10
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
using namespace std;

class thing1
{
public:
    virtual void thingTest()
    {
        cout << "I AM THING 1\n";
    }
};

class thing2: public thing1
{
public:
    virtual void thingTest()
    {
        cout << "I AM THING 2\n";
    }
};

void DoStuff( thing1& temp )
{
    temp.thingTest();
}


int main()
{
    thing2 thing;
    DoStuff( thing );
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
I AM THING 2

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
