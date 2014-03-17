// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2011-12-23 16:16:16
// status:	0
// result:	12
// memory:	3820
// signal:	11
// public:	false
// ------------------------------------------------
#include <iostream>

struct Button { virtual void paint() = 0; };

struct OSXButton: Button { int data[123123]; void paint() { std::cout << "I'm an OSXButton\n"; } };
struct WinButton: Button { void paint() { std::cout << "I'm a WinButton\n"; } };

struct GUIFactory {
    virtual Button * createButtons() = 0;
    virtual ~GUIFactory(){}
};

struct WinFactory: GUIFactory {
    WinButton* createButtons() { return new WinButton[2]; }
};

struct OSXFactory: GUIFactory {
    OSXButton* createButtons() { return new OSXButton[2]; } 
};

int main()
{
    GUIFactory* factory = new WinFactory();

    Button* buttons = factory->createButtons();
    buttons[0].paint();
    buttons[1].paint();
    delete[]buttons;
    delete factory;

    // ====
    factory = new OSXFactory();

    buttons = factory->createButtons();
    buttons[0].paint();
    buttons[1].paint();
    delete[]buttons;
    delete factory;
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
