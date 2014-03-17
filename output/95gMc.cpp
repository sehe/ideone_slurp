// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-22 00:52:53
// status:	0
// result:	15
// memory:	2852
// signal:	0
// public:	true
// ------------------------------------------------
//Purpose: Header file for StackType. Containing all declerations and prototypes
#include <stdexcept>

struct StackException : virtual std::exception 
{  
    protected: StackException() {}
};
struct StackFullException : StackException 
{
    char const* what() const throw() { return "StackFullException"; }
};
struct StackEmptyException : StackException
{
    char const* what() const throw() { return "StackEmptyException"; }
};


template <class itemType>
class StackType
{
public:
    StackType   (int max);
    StackType   ();
    bool IsEmpty() const;
    bool IsFull () const;
    void Push   (itemType newItem);
    void Pop    ();
    itemType Top() const;
    ~StackType  (); // Destructor

private:
    int top;        // key:top of the stack
    int maxStack;   // max number of stack items
    itemType* list; // pointer to dynamically allocated memory
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*Implementation (StackStype.cpp)
StackType prototype functions*/

template <class itemType>
StackType<itemType>::StackType(int max)
{
    maxStack = max;
    top = -1;
    list = new itemType[maxStack];
}

template <class itemType>
StackType<itemType>::StackType()
{
    maxStack = 200;
    top = -1;
    list = new itemType[maxStack];
}

template <class itemType>
bool StackType<itemType>::IsEmpty() const
{
    return(top == -1);
}

template <class itemType>
bool StackType<itemType>::IsFull() const
{
    return(top == maxStack - 1);
}

template <class itemType>
void StackType<itemType>::Push(itemType newItem)
{
    if(IsFull())
    {
        throw StackFullException();
    }
    top++;
    list[top] = newItem;
}

template <class itemType>
void StackType<itemType>::Pop()
{
    if(IsEmpty())
    {
    	throw StackEmptyException();
    }
    top--;
}

template <class itemType>
itemType StackType<itemType>::Top() const
{
    if(IsEmpty())
    {
    	throw StackEmptyException();
    }
    return list[top];
}

template <class itemType>
StackType<itemType>::~StackType()
{
    delete [] list;
}

///////////////////////////////////////
// sample main.cpp

#include <iostream>
int main(void)
{
    try
    {
        StackType<int> stack(5);
        stack.Push(5);
        stack.Push(2);
        stack.Push(3);
        stack.Push(4);
        stack.Push(1);//<-----Still Ok!
        stack.Push(0);//<-----throw FullStack
    } catch (const StackException& e)
    {
        std::cerr << "Received a StackException: what()? " << e.what() << std::endl;
    }
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
