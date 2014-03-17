// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-25 09:12:20
// status:	0
// result:	15
// memory:	3300
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    unsigned switchWin = 0;
    unsigned stayWin   = 0;
    srand((unsigned int) time(0));
    for(int count = 0; count <= 200; count++)
    {
        int const prizeDoor  = rand() / ( RAND_MAX / 3 ) + 1;
        int const doorChoice = rand() / ( RAND_MAX / 3 ) + 1;
        cout << "The prize door is door number " << prizeDoor << " ." << endl;
        cout << "The door the contestant chose was door " << doorChoice << endl;
        int const doorReveal = !(prizeDoor || doorChoice);
        cout << "The host revealed door number " << doorReveal << " ." << endl;
        int const doorSwitch = !(doorChoice || doorReveal);
        if(count < 101)
        {
            if(doorChoice == prizeDoor)
            {
                cout << "Great Job! You won!" << endl;
            }
            else
            {
                cout << "Not this time!" << endl;
            }
        };
        if(count < 201)
        {
            if(doorSwitch == prizeDoor)
            {
                cout << "You switched and won!" << endl;
            }
            else
            {
                cout << "You switched and lost!" << endl;
            }
        };
        if(doorChoice == prizeDoor)
        {
            stayWin++;
        }
        if(doorSwitch == prizeDoor)
        {
            switchWin++;
        };
        count++;
    }
    cout << "Your win percentage when staying was " << stayWin << "%!" << endl;
    cout << "Your win percentage when switching was " << switchWin << "%!" << endl;
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
Great Job! You won!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
Not this time!
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 1 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 1
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 2
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 2 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
The prize door is door number 3 .
The door the contestant chose was door 3
The host revealed door number 0 .
You switched and lost!
Your win percentage when staying was 37%!
Your win percentage when switching was 0%!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
