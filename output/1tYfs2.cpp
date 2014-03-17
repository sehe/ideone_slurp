// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-21 23:52:35
// status:	0
// result:	15
// memory:	3036
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename It>
bool has_vowel(It begin, It end)
{
    while (begin!=end)
    {
        char lower = std::tolower(static_cast<unsigned char>(*begin));

        if (lower == 'a' || lower == 'e' ||
            lower == 'i' || lower == 'o' || lower == 'u')
            return true;

        ++begin;
    }
    return false;
}

int main()
{
    std::istream_iterator<std::string> f(std::cin), l;

    for (auto& s : std::vector<std::string>(f, l))
    {
        if (!has_vowel(s.begin(), s.end()))
            std::cout << s << " ";
    }
}

// ------------------------------------------------
#if 0 // stdin
my friends klmr and family
#endif
#if 0 // stdout
my klmr 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
