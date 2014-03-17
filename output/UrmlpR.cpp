// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-01 13:12:36
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <atomic>
#include <vector>

std::atomic<unsigned int> taskIDCounter;

class Task
{
    Task(Task const&) = delete;
    Task& operator=(Task const&) = delete;
protected:
    Task() : 
        taskID(++taskIDCounter),
        parentID(),
        started(false),
        unfinishedTasks(1),
        dependencies()
    {};

    Task(unsigned int parentID_) : 
            taskID(++taskIDCounter), 
            parentID(parentID_),
            started(false), 
            unfinishedTasks(1),
            dependencies()/*, taken(0)*/
    {};

public:
    virtual ~Task() {}

    virtual void execute() final
    {
        this->doActualWork();
        unfinishedTasks--;
    }

    virtual void doActualWork() = 0;
private:
    unsigned int taskID;                       // ID of this task
    unsigned int parentID;                     // ID of the parent of this task
    bool started;
    std::atomic<unsigned int> unfinishedTasks; // Number of child tasks that are still unfinished
    std::vector<unsigned int> dependencies;    // list of IDs of all tasks that this task depends on
};

#include <cds/container/michael_deque.h>
//#include "task.hpp"
#include <iostream>
#include <cds/init.h>  // for cds::Initialize and cds::Terminate
#include <cds/gc/hp.h> // for cds::HP (Hazard Pointer) garbage collector
#include <memory>      // for unique_ptr

struct A : public Task
{
    A()                 { std::cout << "constructing A()" << std::endl; }
    ~A()                { std::cout << "destructing A()"  << std::endl; }
    void doActualWork() { std::cout << "whatever"         << std::endl; }
};

int main()
{
    cds::Initialize();

    std::unique_ptr<A> demo(new A());

    {
        cds::gc::HP hpGC;                  // hazard pointer GC
        cds::gc::HP::thread_gc myThreadGC; // register main thread with GC

        cds::container::MichaelDeque<cds::gc::HP,Task*> tasks;
        tasks.push_back(demo.get());
    }

    cds::Terminate();
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
