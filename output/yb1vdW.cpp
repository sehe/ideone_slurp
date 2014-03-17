// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-25 12:20:44
// status:	0
// result:	15
// memory:	3344
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <time.h>
using namespace std;

enum doors { door1 = 1, door2 = 2, door3 = 4 };

static inline std::ostream& operator<<(std::ostream& os, doors val) {
    switch(val) {
	case door1: return os << "door #1";
	case door2: return os << "door #2";
	case door3: return os << "door #3";
    }
    return os << "OOPS";
}

int main()
{
    unsigned switchWin = 0;
    unsigned stayWin   = 0;
    srand((unsigned int) time(0));
    for(int count = 0; count <= 200; count++)
    {
        doors const prizeDoor  = doors(1 << rand() / ( RAND_MAX / 3 ));
        doors const doorChoice = doors(1 << rand() / ( RAND_MAX / 3 )); 
        cout << "The prize door is door number " << prizeDoor << " ." << endl;
        cout << "The door the contestant chose was door " << doorChoice << endl;
        doors const doorReveal = doors(~(prizeDoor | doorChoice));
        cout << "The host revealed door number " << doorReveal << " ." << endl;
        doors const doorSwitch = doors(~(doorChoice | doorReveal));
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
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
Great Job! You won!
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
Not this time!
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #1 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #2 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #3 .
The door the contestant chose was door door #3
The host revealed door number OOPS .
You switched and lost!
The prize door is door number door #1 .
The door the contestant chose was door door #2
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #2 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
The prize door is door number door #3 .
The door the contestant chose was door door #1
The host revealed door number OOPS .
You switched and won!
Your win percentage when staying was 39%!
Your win percentage when switching was 62%!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
