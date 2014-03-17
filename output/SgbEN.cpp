// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-20 13:00:45
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	false
// ------------------------------------------------
#include <set>
#include <iostream>

struct KVP
{
    std::string key, value;

    KVP(const std::string& k, const std::string& v)
        : key(k), value(v)
    {
    }

    bool operator<(const KVP& other) const
    {
        return value < other.value;
    }
};

int main()
{
    std::set<KVP> orderedpairs;
    orderedpairs.insert(KVP("key1", "z"));
    orderedpairs.insert(KVP("key2", "k"));
    orderedpairs.insert(KVP("key3", "b"));

    for (std::set<KVP>::const_iterator it = orderedpairs.begin();
         it != orderedpairs.end();
         ++it)
    {
        std::cout << "k: '" << it->key <<   "'\n" <<
                     "v: '" << it->value << "'\n";
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
k: 'key3'
v: 'b'
k: 'key2'
v: 'k'
k: 'key1'
v: 'z'

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
