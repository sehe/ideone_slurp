// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-13 23:46:52
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int i;
    for (i=10; i >= 0; i = i - 1)
    {
        for (int j = 0; j <=20; j++)
        {
            if (i > 5)
            {
                if ((j== i*2-10) || (j == 20 - (i*2-10)) || j==10)
                    std::cout << "X";
                else
                    cout << ".";
            }
            else if (i==5)
                cout << "X";
            else
            {
                if ((j == i*2+10) || (j== 20 - (i*2+10)) || j == 10)
                    cout << "X";
                else
                    cout << ".";
            }
        }
        cout << endl;
    }
    for (i = 5; i > 0; i = i - 1)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (j == 10)
                cout << "X";
            else
                cout << ".";
        };
        cout << endl;
    };

    cout << "All Done!" << endl;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
..........X..........
........X.X.X........
......X...X...X......
....X.....X.....X....
..X.......X.......X..
XXXXXXXXXXXXXXXXXXXXX
..X.......X.......X..
....X.....X.....X....
......X...X...X......
........X.X.X........
..........X..........
..........X..........
..........X..........
..........X..........
..........X..........
..........X..........
All Done!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
