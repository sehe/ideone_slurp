// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-21 23:40:14
// status:	0
// result:	15
// memory:	3036
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

template <typename It>
bool has_vowel(It begin, It end)
{
    for (auto it = begin; it != end; ++it)
    {
        char lower = std::tolower(*it);

        if (lower == 'a' || lower == 'e' ||
            lower == 'i' || lower == 'o' || lower == 'u')
            return true;
    }
    return false;
}

struct _
{
    bool operator()(std::string const& s) const
    { return !has_vowel(s.begin(), s.end()); }
} callback;

int main()
{
    std::vector<std::string> v;
    std::string str;

    while (std::cin >> str)
    {
        v.push_back(str);
    }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (!has_vowel(it->begin(), it->end()))
            std::cout << *it << " ";
    }
}

// ------------------------------------------------
#if 0 // stdin
aap
noot
mies
klmr
broer
zus
jet

#endif
#if 0 // stdout
klmr 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
