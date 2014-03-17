// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-10-15 00:50:27
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include <boost/pool/object_pool.hpp>

using namespace std;

struct node
{
    unsigned int part1; // 4 bytes
    unsigned int part2; // 4 bytes
    node *next;         //pointer, 8 bytes on 64 bit system
};

boost::object_pool<node> node_pool(1, 0);

struct LinkedList
{
public:
    LinkedList();
    void insert(unsigned int data[], unsigned int data1);
    bool isEmpty() const;
    node* head;
};

LinkedList::LinkedList():
    head(NULL)
{
}

bool LinkedList::isEmpty() const
{
    return (head == NULL);
}

void LinkedList::insert(unsigned int data[], unsigned int data1)
{
    //node* add = node_pool.malloc();
    node* add = new node;
    *add = node { data[0], data1, head };
    head = add;
}

const unsigned int allocations = 30000000;
const unsigned int index_size = 43000000;//index of lists
//will be creatad on heap
LinkedList *list = NULL;

int main(int argc, char *argv[])
{
    LinkedList list_instance;
    cout << "1 LinkedList instance takes [" << sizeof(list_instance) << "] bytes in memory!"<< endl;
    node node_instance;
    cout << "1 node instance takes [" << sizeof(node_instance) <<"] bytes in memory !"<< endl;
    cout << "Before dynamic allocations: *check the baseline process size* and press ENTER to start allocating ..." << endl;
    std::string s;
    std::getline(std::cin, s);
    list = new (nothrow) LinkedList[index_size];
    if (!list)
    {
        cout << "Error allocating memory" << endl;
        return 1;
    }
    unsigned int some_data[] = {00, 01};
    cout << "Allocating nodes ..." << endl;
    for (unsigned int i=0; i<allocations; i++)
    {
        list[rand() % index_size].insert(some_data, some_data[1]);
    }
    unsigned long sk = ((allocations * sizeof(node_instance) + index_size*sizeof(list_instance))) >> 20;
    cout << "This process *should* consume around " << sk <<" MiB of memory, but does it ?"<< endl;
    cout << "Allocating done, *check the process size* and press ENTER to exit ..." << endl;
    std::getline(std::cin, s);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:14: error: no matching function for call to ‘boost::object_pool<node, boost::default_user_allocator_new_delete>::object_pool(int, int)’
/usr/include/boost/pool/object_pool.hpp:56: note: candidates are: boost::object_pool<T, UserAllocator>::object_pool(typename boost::pool<UserAllocator>::size_type) [with T = node, UserAllocator = boost::default_user_allocator_new_delete]
/usr/include/boost/pool/object_pool.hpp:39: note:                 boost::object_pool<node, boost::default_user_allocator_new_delete>::object_pool(const boost::object_pool<node, boost::default_user_allocator_new_delete>&)
prog.cpp: In member function ‘void LinkedList::insert(unsigned int*, unsigned int)’:
prog.cpp:39: error: expected primary-expression before ‘{’ token
prog.cpp:39: error: expected `;' before ‘{’ token

#endif
