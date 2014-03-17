// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-26 12:03:35
// status:	0
// result:	15
// memory:	5000
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>

std::string xfrm(std::string const& input)
{
    std::string result(1+std::strxfrm(nullptr, input.c_str(), 0), '\0');
    std::strxfrm(&result[0], input.c_str(), result.size());

    return result;
}

int main()
{
    using namespace std;
    setlocale(LC_ALL, "es_ES.UTF-8");
 
    const string aba    = "aba";
    const string rabano = "rábano";

    cout << "Without xfrm: " << aba << " in " << rabano << " == " << 
        boolalpha << (string::npos != rabano.find(aba)) << "\n";

    cout << "Using xfrm:   " << aba << " in " << rabano << " == " << 
        boolalpha << (string::npos != xfrm(rabano).find(xfrm(aba))) << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Without xfrm: aba in rábano == false
Using xfrm:   aba in rábano == false

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
