// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-20 17:38:28
// status:	0
// result:	15
// memory:	3024
// signal:	0
// public:	false
// ------------------------------------------------
//////////// CEditBox.hpp header file
#include <memory>
#include <string>

class CLabel;


class CEditBox
{
  public:
    CEditBox(std::string);
  private:
    std::unique_ptr<CLabel> _label;
};

//////////// CLabel.hpp header file

#include <string>
//#include "CLabel.hpp"

class CLabel
{
  public:
    CLabel(std::string name) : _name(std::move(name)) {}
  private:
    std::string _name;
};

///////////// CEditBox.cpp source file

//#include "CEditBox.hpp"
//#include "CLabel.hpp"

CEditBox::CEditBox(std::string name)
    : _label(new CLabel(std::move(name))) 
{
}

///////////// main.cpp source file

//#include "CEditBox.hpp"

int main()
{
    CEditBox box("Hello world"); // no need to 'know' CLabel here   
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
