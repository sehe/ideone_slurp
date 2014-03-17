// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-10 00:34:41
// status:	0
// result:	15
// memory:	2900
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    long double pi = atan(1.)*4;

    int input;
    while(true)
    {
        std::cout << "Please enter how many digits of PI you would like to see (Max 20): ";

        if (!(std::cin >> input))
            return 255;

        if(input > 0 && input <= 20)
            break;

        std::cout << "That's not a valid number! Try again." << std::endl;
    }

    std::cout << std::setprecision(input);
    std::cout << "Pi approximated: " << pi << std::endl;
}

// ------------------------------------------------
#if 0 // stdin
18
#endif
#if 0 // stdout
Please enter how many digits of PI you would like to see (Max 20): Pi approximated: 3.14159265358979312

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
