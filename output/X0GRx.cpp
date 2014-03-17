// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-03-15 00:22:44
// status:	0
// result:	15
// memory:	2968
// signal:	0
// public:	false
// ------------------------------------------------
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

struct X 
{ 
    std::string airport, location; 
    X(const std::string& a, const std::string& l) :
        airport(a), location(l) {}

    friend std::ostream& operator<<(std::ostream& os, const X& x)
    { return os << "X { airport: '" << x.airport << "', location: '" << x.location << "' }"; }
};

int main()
{
    std::vector<X> data;

    std::string line;
    while(std::getline(std::cin, line))
    {
        auto f1 = line.substr(0, line.find("  "));
        auto f2 = line.substr(std::min(f1.length()+2, line.length()));
        data.emplace_back(std::move(f1), std::move(f2));
    }

    std::copy(data.begin(), data.end(), std::ostream_iterator<X>(std::cout, "\n"));
}

// ------------------------------------------------
#if 0 // stdin
Airport 1  SomeLocation
NoLocation
  UnnamedAirportLocation
#endif
#if 0 // stdout
X { airport: 'Airport 1', location: 'SomeLocation' }
X { airport: 'NoLocation', location: '' }
X { airport: '', location: 'UnnamedAirportLocation' }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
