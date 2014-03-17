// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2011-12-18 14:41:05
// status:	0
// result:	15
// memory:	2872
// signal:	0
// public:	false
// ------------------------------------------------
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>

std::vector<std::string> split(const std::string& str)
{
    std::istringstream iss(str);
    std::vector<std::string> result;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(result));

    return result;
}

// find all the lines that refer to each word in the input
template <typename OutIt>
OutIt xref(std::istream& in,
        OutIt out,
        std::vector<std::string> find_words(const std::string&) = split)
{
    std::string line;
    int line_number = 0;

    // read the next line
    while (getline(in, line)) {
        ++line_number;

        // break the input line into words
        std::vector<std::string> words = find_words(line);

        // remember that each word occurs on the current line
        for (std::vector<std::string>::const_iterator it = words.begin();
             it != words.end(); ++it)
            *out++ = std::make_pair(*it, line_number);
    }
    
    return out;
}

int main(int argc, const char *argv[])
{
    std::map<std::string, int> index;

    xref(std::cin, std::inserter(index, index.end()));

#if __GXX_EXPERIMENTAL_CXX0X__
    for(auto& entry: index)
        std::cout << entry.first << " first found on line " << entry.second << std::endl;
#else
    for(std::map<std::string, int>::const_iterator it = index.begin();
        it != index.end();
        ++it)
    {
        std::cout << it->first << " first found on line " << it->second << std::endl;
    }
#endif
    
    return 0;
}

// ------------------------------------------------
#if 0 // stdin
hospitalizations
empiricism
watchband
Bostonians
contouring
mitt
Castor's
avenue
employes
Legendre
Tannhäuser
Cassie's
Hatteras
vibrator's
cottaged
unaccountably
deposing
biped's
underpinned
Bialystok

#endif
#if 0 // stdout
Bialystok first found on line 20
Bostonians first found on line 4
Cassie's first found on line 12
Castor's first found on line 7
Hatteras first found on line 13
Legendre first found on line 10
Tannhäuser first found on line 11
avenue first found on line 8
biped's first found on line 18
contouring first found on line 5
cottaged first found on line 15
deposing first found on line 17
empiricism first found on line 2
employes first found on line 9
hospitalizations first found on line 1
mitt first found on line 6
unaccountably first found on line 16
underpinned first found on line 19
vibrator's first found on line 14
watchband first found on line 3

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
