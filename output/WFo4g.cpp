// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-27 23:33:35
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
using namespace std;

enum Status{Idle, Busy};

std::ostream& operator<<(std::ostream& os, const Status status)
{
    switch (status)
    {
        case Idle: return os << "Idle";
        case Busy: return os << "Busy";
        default:   return os << "Status:" << status;
    }

    return os << "<error>";
}

class text
{
    public:
        void SetStatus(Status s);
        Status getStatus();
    private:
        Status s;       
};
void text::SetStatus(Status s)
{
    this->s = s;
}
Status text::getStatus()
{
    return this->s;
}

int main()
{
    text myText;
    myText.SetStatus(Busy);
    cout << myText.getStatus() << endl; //	should output "Busy"
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Busy

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
