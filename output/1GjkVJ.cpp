// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-23 02:20:13
// status:	0
// result:	15
// memory:	3304
// signal:	0
// public:	false
// ------------------------------------------------
/* 
 * Okay, so I need to create a Pentagon Project and I'm kind of Confused here.
 * I mean, it works great but I'm missing one class that must have some code in
 * it.
 * 
 * Assignment is:
 * 
 * Write a program and call it PentagonProject. Besides the file containing the
 * main() funct. there should be two other classes, each in its own pair of
 * files (.h; .cpp). One of the classes should be class MenuClass, and the
 * other should be called Pentagon. There should be a user loop in main() that
 * invokes MenuClass member-function DisplayMenu and so forth. The menu should
 * allow the user to specify, as well as change, the dimensions of the instance
 * of the Pentagon class, also known as an object. A pentagon shall be a
 * regular (all sides are the same). A pentagon has five sides. We shall denote
 * the length of the sides by s. Then perimeter, P, and area, A, of a pentagon
 * are as follows.
 * 
 * Equations:
 * 
 *     P = 5s 
 * 
 *     A = s^2 sqrt ( of 25 + 10 sqrt (5) ) / (over) 4
 * 
 * The menu should allow the user to calculate the perimeter and the area of an
 * instance of the Pentagon Class.  Your program should have a single Pentagon
 * Object.
 */

#include <string>
#include <vector>
#include <iostream>

/*#include "MenuClass.h"*/
#include <cmath>

using namespace std;

enum MenuChoices {
    Quit,
    Perimeter,
    Area
};

struct Menu
{
    Menu();
    ~Menu();
    MenuChoices Get();
    void Set(MenuChoices newValue);

    MenuChoices userMenuSelection;

    void Display(); 
    void QueryUser();
    bool Continue();

    void ProcessCommand();
};

Menu::Menu(void)
{
    userMenuSelection = Quit;
} // Constructor Menu

Menu::~Menu(void)
{
    cout << "====================================" << endl;
} // Destructor ~Menu

MenuChoices Menu::Get()
{
    return userMenuSelection;
} // Accessor Method Get

void Menu::Set(MenuChoices newValue)
{
    userMenuSelection = newValue;
} // Mutator Method Set

void Menu::Display()
{
    cout << "======================================" << endl;
    cout << "             MENU SELECTION           " << endl;
    cout << "======================================" << endl;
    cout << "1: Calculate the Perimeter of Pentagon" << endl;
    cout << "2: Calculate the Area of Pentagon" << endl;
    cout << "3: Quit" << endl;
    cout << "======================================" << endl;
    cout << endl;
} // Member-Function Display

void Menu::QueryUser()
{
    int selection;
    cout << "Enter Menu Selection: ";
    cin >> selection;
    switch(selection)
    {
    case 1:
        userMenuSelection = Perimeter;
        break;
    case 2:
        userMenuSelection = Area;
        break;
    case 3:
        userMenuSelection = Quit;
    default:
        userMenuSelection = Quit;
    } // switch
    //          ===========
    cout << endl;
} // Method QueryUser()

bool Menu::Continue()
{
    return userMenuSelection != Quit;
} // Method Continue

void Menu::ProcessCommand()
{
    int numberA; // Length of Sides
    if(userMenuSelection == Quit)
    {
        cout << "Thank you for using this type of program. Have a nice day!" << endl;
    }
    else if(userMenuSelection != Quit)
    {
        cout << "Please enter an integer value for the length of the sides: ";
        cin >> numberA;
        //              ==============================
        switch(userMenuSelection)
        {
        case Perimeter:
            cout << "Perimeter = " << (5 * numberA) << endl;
            break;
        case Area:
            cout << "Area = " << numberA * numberA * sqrt(25.0 + 10.0 * sqrt(5.0)) / 4.0;
            break;
        default:
            cout << "Warning: error state encountered." << endl;
        }
        cout << endl;
    }
}

// PentagonProject.cpp : Defines the entry point for the console application.

#include <iostream>
//#include "MenuClass.h"

using namespace std;

int main()
{
    Menu menu;
    do
    {
        menu.Display();
        menu.QueryUser();
        menu.ProcessCommand();
    }
    while(menu.Continue());
    return 0;
}




// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
======================================
             MENU SELECTION           
======================================
1: Calculate the Perimeter of Pentagon
2: Calculate the Area of Pentagon
3: Quit
======================================

Enter Menu Selection: 
Thank you for using this type of program. Have a nice day!
====================================

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
