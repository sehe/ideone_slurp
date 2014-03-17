// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-02 01:01:19
// status:	0
// result:	15
// memory:	3340
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

using namespace std;

class lineType
{
public:

    lineType();

    lineType(int x, int y, int z);


    void getSlope(int p, int q, int r);

    bool equalLines(const lineType& otherline);
    bool equalParallel(const lineType& otherline);
    bool equalPerpendicular(const lineType& otherline);

private:
    int a, b, c;
};

lineType::lineType()
{
    a = 0;
    b = 0;
    c = 0;
}

lineType::lineType(int x, int y, int z)
{
    a=x;
    b=y;
    c=z;
}

void lineType::getSlope(int p, int q, int r)

{
    a = p;
    b = q;
    c = r;
    if(a == 0)
    {
        cout<<"The slope of the line is a horizontal line"<<endl;
    }
    else if(b == 0)
    {
        cout<<"The slope of the line is a vertical line and slope of a vertical line is is undefined"<<endl;
    }
}



int main()

{
    lineType line1(1,2,4);
    line1.getSlope(1,0,0);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
The slope of the line is a vertical line and slope of a vertical line is is undefined

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
