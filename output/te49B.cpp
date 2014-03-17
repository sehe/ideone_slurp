// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-20 01:38:33
// status:	0
// result:	15
// memory:	2956
// signal:	0
// public:	false
// ------------------------------------------------
# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cpp"
# 1 "B.h" 1
# 1 "A.h" 1
# 1 "pimpl.h" 1

#include <memory>       

template<typename T>
class pimpl
{
    template <typename> friend class pimpl;

    pimpl(const pimpl& other);
    pimpl(pimpl&& other);
    pimpl& operator=(const pimpl& other);
    pimpl& operator=(pimpl&& other);
protected:

    ~pimpl();

    struct implementation;
    std::unique_ptr<implementation> impl_;
public:
    pimpl();

    template<typename P0>
    pimpl(P0&& p0);

    pimpl(const T& other);
    pimpl(T&& other);

    void swap(T& other);
};
# 2 "A.h" 2

struct A : public pimpl<A>
{
    A();
    A(const A& other);
    A(A&& other);
    virtual ~A();
    void foo();
};
# 2 "B.h" 2

class B : public pimpl<B>, public A
{
  public:
    B();
    B(const B& other);
    B(B&& other);
    virtual ~B();
    void bar();
};

/////////////////////
// pimpl_impl.h

template<typename T>
pimpl<T>::pimpl() : impl_(new implementation()){}

template<typename T>
template<typename P0>
pimpl<T>::pimpl(P0&& p0) : impl_(new implementation(std::forward<P0>(p0))){}

template<typename T>
pimpl<T>::~pimpl(){}

template<typename T>
pimpl<T>::pimpl(const T& other) : impl_(new implementation(*((pimpl&)other).impl_)){}

template<typename T>
pimpl<T>::pimpl(T&& other) : impl_(std::move(((pimpl&)other).impl_)){}

template<typename T>
void pimpl<T>::swap(T& other)
{
    impl_.swap(other.impl_);
}

/////////////////////
// A.cpp

template<>
struct pimpl<A>::implementation
{
     void foo()
     {
     }
};

A::A() : pimpl(){}
A::A(const A& other) : pimpl(other){}
A::A(A&& other) : pimpl(std::move(other)){}
A::~A(){}
void A::foo(){impl_->foo();}

/////////////////////
// B.cpp

template<>
struct pimpl<B>::implementation
{
     void bar()
     {
     }
};

B::B() : pimpl<B>(){}
B::B(const B& other) : pimpl<B>(other){}
B::B(B&& other) : pimpl<B>(std::move(other)){}
B::~B(){}
void B::bar(){ pimpl<B>::impl_->bar();}


# 2 "main.cpp" 2

int main()
{
    A a;
    B b;
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
