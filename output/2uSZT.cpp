// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-28 21:23:56
// status:	0
// result:	15
// memory:	2728
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
    int score;
    char grade;
    cout << "Enter your score:" << endl;
    cin >> score;
    if (score >= 90)
        grade = 'a';
    else if (score >= 80)
        grade = 'b';
    else if (score >= 70)
        grade = 'c';
    else if (score >= 60)
        grade = 'd';
    else
        grade = 'f';

    cout << grade << endl;
    switch (grade)
    {
    case 'a':
        cout << "Good job" << endl;
        break;
    case 'c':
        cout << "Fair job" << endl;
        break;
    case 'f':
        cout << "Failure" << endl;
        break;
    default:
        cout << "invalid" << endl;
    }
    cin.get();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin
95
#endif
#if 0 // stdout
Enter your score:
a
Good job

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
