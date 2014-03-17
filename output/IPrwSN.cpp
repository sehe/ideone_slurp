// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-06 23:29:08
// status:	0
// result:	15
// memory:	2988
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
11 "22"
 33 44
 55 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
