// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-03 10:30:16
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

template <typename T>
class A
{
private:
    T val1;
    T val2;

public:
    T getVal1()
    {
        return val1;
    }
    void setVal1(T aVal)
    {
        val1 = aVal;
    }
    T getVal2()
    {
        return val2;
    }
    void setVal2(T aVal)
    {
        val2 = aVal;
    }
};

template <typename T>
class B
{
private:
    A<T>* aPtr;

    B(const B&);            // TODO , disallow for now
    B& operator=(const B&); // TODO , disallow for now

public:
	B() : aPtr(new A<T>()) {}
	~B() { delete aPtr; }

    A<T>* getAPtr()
    {
        return aPtr;
    }
    T operator[](const int& key)
    {
        if(key == 0)
        {
            T res = getAPtr()->getVal1();
            return res;
        }
        else
        {
            T res = getAPtr()->getVal2();
            return res;
        }
    }
};

int main()
{
    B<int> foo;
    foo.getAPtr()->setVal1(1);
    int x = foo[0];
    std::cout << foo[0] << " " << x << std::endl; // 1 1
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1 1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
