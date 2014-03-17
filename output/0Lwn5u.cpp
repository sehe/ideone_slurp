// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-06 23:28:58
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

template <typename It, char delim='"'>
std::vector<std::string> tokenize(It f, It l)
{
    std::vector<std::string> result;
    result.emplace_back();
    while (f!=l)
    {
        switch(*f)
        {
            case delim: 
                if (*++f != delim)
                    result.emplace_back();
            default:
                result.back() += *f++;
        }
    }
    return result;
}

int main() {
    using namespace std;

    auto&& input = "11 \"\"22\"\"\" 33 44\" 55 ";

    for (auto&& tok : tokenize(begin(input), end(input)))
        cout << tok << endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:7:45: error: default template arguments may not be used in function templates without -std=c++11 or -std=gnu++11
prog.cpp: In function ‘std::vector<std::basic_string<char> > tokenize(It, It)’:
prog.cpp:10:12: error: ‘class std::vector<std::basic_string<char> >’ has no member named ‘emplace_back’
prog.cpp:17:28: error: ‘class std::vector<std::basic_string<char> >’ has no member named ‘emplace_back’
prog.cpp: In function ‘int main()’:
prog.cpp:28:5: warning: ‘auto’ changes meaning in C++11; please remove it [-Wc++0x-compat]
prog.cpp:28:9: error: expected unqualified-id before ‘&&’ token
prog.cpp:30:10: warning: ‘auto’ changes meaning in C++11; please remove it [-Wc++0x-compat]
prog.cpp:30:14: error: expected unqualified-id before ‘&&’ token
prog.cpp:30:14: error: expected ‘;’ before ‘&&’ token
prog.cpp:30:17: warning: the address of ‘tok’ will always evaluate as ‘true’ [-Waddress]
prog.cpp:30:21: error: expected ‘;’ before ‘:’ token
prog.cpp:30:21: error: expected primary-expression before ‘:’ token
prog.cpp:30:21: error: expected ‘)’ before ‘:’ token
prog.cpp:30:21: error: expected primary-expression before ‘:’ token
prog.cpp:30:21: error: expected ‘;’ before ‘:’ token
prog.cpp:30:17: error: label ‘tok’ used but not defined

#endif
