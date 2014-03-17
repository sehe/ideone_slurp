// error:	OK
// langId:	10
// langName:	Java
// langVersion:	sun-jdk-1.7.0_25
// time:	0
// date:	2013-09-25 12:20:26
// status:	0
// result:	11
// memory:	0
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

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
Main.java:1: error: illegal character: \35
#include <iostream>
^
Main.java:1: error: class, interface, or enum expected
#include <iostream>
         ^
Main.java:2: error: illegal character: \35
#include <time.h>
^
Main.java:5: error: ',', '}', or ';' expected
enum doors { door1 = 1, door2 = 2, door3 = 4 };
                   ^
Main.java:5: error: '}' expected
enum doors { door1 = 1, door2 = 2, door3 = 4 };
                    ^
Main.java:7: error: class, interface, or enum expected
static inline std::ostream& operator<<(std::ostream& os, doors val) {
       ^
Main.java:10: error: class, interface, or enum expected
	case door2: return os << "door #2";
	^
Main.java:11: error: class, interface, or enum expected
	case door3: return os << "door #3";
	^
Main.java:12: error: class, interface, or enum expected
    }
    ^
Main.java:14: error: class, interface, or enum expected
}
^
Main.java:19: error: class, interface, or enum expected
    unsigned stayWin   = 0;
    ^
Main.java:20: error: class, interface, or enum expected
    srand((unsigned int) time(0));
    ^
Main.java:21: error: class, interface, or enum expected
    for(int count = 0; count <= 200; count++)
    ^
Main.java:21: error: class, interface, or enum expected
    for(int count = 0; count <= 200; count++)
                       ^
Main.java:21: error: class, interface, or enum expected
    for(int count = 0; count <= 200; count++)
                                     ^
Main.java:24: error: class, interface, or enum expected
        doors const doorChoice = doors(1 << rand() / ( RAND_MAX / 3 )); 
        ^
Main.java:25: error: class, interface, or enum expected
        cout << "The prize door is door number " << prizeDoor << " ." << endl;
        ^
Main.java:26: error: class, interface, or enum expected
        cout << "The door the contestant chose was door " << doorChoice << endl;
        ^
Main.java:27: error: class, interface, or enum expected
        doors const doorReveal = doors(~(prizeDoor | doorChoice));
        ^
Main.java:28: error: class, interface, or enum expected
        cout << "The host revealed door number " << doorReveal << " ." << endl;
        ^
Main.java:29: error: class, interface, or enum expected
        doors const doorSwitch = doors(~(doorChoice | doorReveal));
        ^
Main.java:30: error: class, interface, or enum expected
        if(count < 101)
        ^
Main.java:35: error: class, interface, or enum expected
            }
            ^
Main.java:39: error: class, interface, or enum expected
            }
            ^
Main.java:41: error: class, interface, or enum expected
        if(count < 201)
        ^
Main.java:46: error: class, interface, or enum expected
            }
            ^
Main.java:50: error: class, interface, or enum expected
            }
            ^
Main.java:52: error: class, interface, or enum expected
        if(doorChoice == prizeDoor)
        ^
Main.java:55: error: class, interface, or enum expected
        }
        ^
Main.java:59: error: class, interface, or enum expected
        };
        ^
Main.java:60: error: class, interface, or enum expected
        count++;
        ^
Main.java:61: error: class, interface, or enum expected
    }
    ^
Main.java:63: error: class, interface, or enum expected
    cout << "Your win percentage when switching was " << switchWin << "%!" << endl;
    ^
Main.java:64: error: class, interface, or enum expected
    return 0;
    ^
Main.java:65: error: class, interface, or enum expected
}
^
35 errors

#endif
