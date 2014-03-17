// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-03-17 23:57:57
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int i;
    long double result;
    long double pi;
    int y=3;
    int loopcount=0;
    long double precision = 0;
    long double previous = 0;

    cout<<"Start\n";

    result=1-(pow(1,y)/y);

    do
    {
        y=y+2;
        result=result+(pow(1,y)/y);
        y=y+2;
        result=result-(pow(1,y)/y);

        pi=4*(result);
        precision=(pi*(pow(10,11))/10);

        loopcount++;

        if (floor(precision)==floor(previous))
            break;

        previous = precision;
    }
    while(true); //This is the problem!);

    cout<<"Final Arctan is:"<<endl;
    cout<<setprecision(20)<<result<<endl;
    cout<<"Final Pi is:"<<endl;
    cout<<setprecision(9)<<pi<<endl;
    cout<<"Times looped:"<<endl;
    cout<<loopcount<<endl;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Start
Final Arctan is:
0.78539640052495345225
Final Pi is:
3.1415856
Times looped:
70906

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
