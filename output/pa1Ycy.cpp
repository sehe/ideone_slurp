// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-24 22:05:31
// status:	0
// result:	15
// memory:	3484
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct entry {
    string name;
    unsigned quantity;
};

vector<entry> readData()
{
    vector<entry> data;

    string line, name;
    unsigned quantity;

    while (getline(cin, line) && istringstream(line) >> name >> quantity)
        data.push_back({name,quantity});

    return data;
}

void consolidate(vector<entry>& data)
{
    auto f = data.begin(), l = data.end();
    while (f!=l)
    {
        auto match = find_if(begin(data), f, [&](entry const& a) { return a.name == f->name; });
        if (match != f)
        {
            match->quantity += f->quantity;
            f = data.erase(f);
            l = data.end();
        } else
        {
            f++;
        }
    }
}

int main()
{
    vector<entry> data = readData();
    
    consolidate(data);

    for (auto it = data.begin(); it != data.end(); ++it)
        cout << it->name << " " << it->quantity << "\n";
}

// ------------------------------------------------
#if 0 // stdin
apple 5
pear 2
grape 6
mangoes 3
apple 2
mangoes 9

#endif
#if 0 // stdout
apple 7
pear 2
grape 6
mangoes 12

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
