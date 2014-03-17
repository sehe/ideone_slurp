// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-05 22:48:34
// status:	0
// result:	15
// memory:	2872
// signal:	0
// public:	true
// ------------------------------------------------
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <map>

struct SillyJob
{
    std::string description;
    std::string priority;

    SillyJob(const std::string& d, const std::string& p)
        : description(d), priority(p) { }

    bool operator<(const SillyJob& sj) const { return description.size() < sj.description.size(); }

    friend std::ostream& operator<<(std::ostream& os, const SillyJob& sj)
    { return os << sj.priority << ": " << sj.description; }
};

static bool by_priority(const SillyJob& a, const SillyJob& b)
{
    static std::map<std::string, int> prio_map;
    if (prio_map.empty())
    {
        prio_map["HIGH"]   = 3;
        prio_map["MEDIUM"] = 2;
        prio_map["LOW"]    = 1;
    }

    return prio_map[a.priority] < prio_map[b.priority];
}

int main()
{
    std::cout << "Silly: (by description length)" << std::endl;
    {
        // by description length (member operator<)
        std::priority_queue<SillyJob> silly_queue;

        silly_queue.push(SillyJob("short", "HIGH"));
        silly_queue.push(SillyJob("very very long description", "LOW"));

        while (!silly_queue.empty())
        {
            std::cout << silly_queue.top() << std::endl;
            silly_queue.pop();
        }
    }

    std::cout << std::string(60, '-') << "\nNot so silly: (by priority value)" << std::endl;
    {
        // by description length (member operator<)
        typedef bool (*cmpf)(const SillyJob&, const SillyJob&);
        typedef std::priority_queue<SillyJob, std::vector<SillyJob>, cmpf> not_so_silly_queue;

        not_so_silly_queue queue(by_priority);

        queue.push(SillyJob("short", "HIGH"));
        queue.push(SillyJob("very very long description", "LOW"));

        while (!queue.empty())
        {
            std::cout << queue.top() << std::endl;
            queue.pop();
        }
    }

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Silly: (by description length)
LOW: very very long description
HIGH: short
------------------------------------------------------------
Not so silly: (by priority value)
HIGH: short
LOW: very very long description

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
