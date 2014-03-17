// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-23 01:40:18
// status:	0
// result:	15
// memory:	3336
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
struct Field;
using std::string;

class Unit
{
    Field* place;
    Unit* unit;
    int name;
public:
    Unit(int n = 0) {}
    void move(Field* x) {}
    int getname();
};

//and Player
#define UNITS_NUMBER 10
struct Board
{
    Field* getF(int)
    {
        return nullptr;
    }
};

struct Player
{
    string imie;
    int number;
    Unit units[UNITS_NUMBER];
    Player(string Playername, int nr , Board*x);
};

Player::Player(string Playername, int nr , Board* x)
{
    imie = Playername;
    number = nr;
    int k;
    if(nr == 1)
    {
        k = 0;
    }
    else
    {
        k = 24;
    }
    for(int i = 0; i < UNITS_NUMBER; i++)
    {
        Unit figure(i);
        units[i] = figure;
        units[i].move(x->getF(k));
        if(nr == 1)
        {
            k++;
        }
        else
        {
            k--;
        }
    }
}

int main()
{
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
