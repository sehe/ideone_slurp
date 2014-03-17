// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-18 01:14:07
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <memory>

template <class DataType>
class Queue
{
public:
    Queue() : front(), end(/*nullptr*/) {}
    bool isEmpty   () const { return !front; }
    void push      (const DataType& parameter);
    bool peek      (DataType& parameter) const;
    bool pop       (DataType& parameter);
    void makeEmpty ();

private:
    struct Node;
    typedef std::unique_ptr<Node> Ptr;
    struct Node
    {
        Node(DataType data) : data(std::move(data)), next() {}
        DataType data;
        Ptr      next;
    };
    Ptr front;
    Node* end;
};

template <class DataType>
void Queue<DataType>::push(const DataType& parameter) {
    auto&& node = Ptr(new Node(parameter));
    end = ((end? end->next : front) = std::move(node)).get();
}

template <class DataType>
bool Queue<DataType>::peek(DataType& parameter) const
{
    if(front) parameter = front->data;
    return front.get();
}

template <class DataType>
bool Queue<DataType>::pop(DataType& parameter)
{
    if(!front)
        return false;

    parameter = front->data;
    front = std::move(front->next);
    if (!front) 
        end = 0/*nullptr*/;

    return true;
}

template <class DataType>
void Queue<DataType>::makeEmpty()
{
    end = 0/*nullptr*/;
    while(front)
        front = std::move(front->next);
}

#include <iostream>
int main(int argc, const char *argv[])
{
    Queue<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(5);
    test.makeEmpty();
    test.push(32028);
    test.push(10842);
    test.push(1839);
    test.push(23493);
    test.push(9857);

    int x;
    test.peek(x);
    while (test.pop(x))
        std::cout << x << '\n';
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/unique_ptr.h: In member function 'void Queue<DataType>::push(const DataType&) [with DataType = int]':
prog.cpp:66:16:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/unique_ptr.h:208:19: error: deleted function 'std::unique_ptr<_Tp, _Tp_Deleter>& std::unique_ptr<_Tp, _Tp_Deleter>::operator=(const std::unique_ptr<_Tp, _Tp_Deleter>&) [with _Tp = Queue<int>::Node, _Tp_Deleter = std::default_delete<Queue<int>::Node>, std::unique_ptr<_Tp, _Tp_Deleter> = std::unique_ptr<Queue<int>::Node, std::default_delete<Queue<int>::Node> >]'
prog.cpp:30:5: error: used here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/unique_ptr.h:208:19: error: deleted function 'std::unique_ptr<_Tp, _Tp_Deleter>& std::unique_ptr<_Tp, _Tp_Deleter>::operator=(const std::unique_ptr<_Tp, _Tp_Deleter>&) [with _Tp = Queue<int>::Node, _Tp_Deleter = std::default_delete<Queue<int>::Node>, std::unique_ptr<_Tp, _Tp_Deleter> = std::unique_ptr<Queue<int>::Node, std::default_delete<Queue<int>::Node> >]'
prog.cpp:30:5: error: used here

#endif
