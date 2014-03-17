// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-25 03:34:52
// status:	0
// result:	11
// memory:	3024
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
 
template<typename TFuncSignature>
class Callback;
 
template<typename R, typename... Args>
class Callback<R(Args...)> {
public:
    typedef R(*TFunc)(void*, Args...);

    Callback() : obj(0), func(0) {}
    Callback(void* o, TFunc f) : obj(o), func(f) {}

    R operator()(Args... a1) const {
        return (*func)(obj, std::forward<Args>(a1)...);
    }
    typedef void* Callback::*SafeBoolType;
    operator SafeBoolType() const {
        return func? &Callback::obj : 0;
    }
    bool operator!() const {
        return func == 0;
    }
    bool operator== (const Callback& right) const {
        return obj == right.obj && func == right.func;
    }
    bool operator!= (const Callback& right) const {
        return obj != right.obj || func != right.func;
    }
private:
    void* obj;
    TFunc func;
};

namespace detail
{
    template<typename R, class T, typename... Args>
    struct DeduceMemCallback { 
        template<R(T::*Func)(Args...)> inline static Callback<R(Args...)> Bind(T* o) {
            struct _ { static R wrapper(void* o, Args... a1) { return (static_cast<T*>(o)->*Func)(std::forward<Args>(a1)...); } };
            return Callback<R(Args...)>(o, (R(*)(void*, Args...)) _::wrapper);
        }
    };

    template<typename R, typename... Args>
    struct DeduceStaticCallback { 
        template<R(*Func)(Args...)> inline static Callback<R(Args...)> Bind() { 
            struct _ { static R wrapper(void*, Args... a1) { return (*Func)(std::forward<Args>(a1)...); } };
            return Callback<R(Args...)>(0, (R(*)(void*, Args...)) _::wrapper); 
        }
    };
}
 
template<typename R, class T, typename... Args>
detail::DeduceMemCallback<R, T, Args...> DeduceCallback(R(T::*)(Args...)) {
    return detail::DeduceMemCallback<R, T, Args...>();
}

template<typename R, typename... Args>
detail::DeduceStaticCallback<R, Args...> DeduceCallback(R(*)(Args...)) {
    return detail::DeduceStaticCallback<R, Args...>();
}

template <typename... T1> class Event {
public:
    typedef void(*TSignature)(T1...);
    typedef Callback<void(T1...)> TCallback;

protected:
    typedef std::vector<TCallback> Table;
    Table invocations;

public:
    const static int ExpectedFunctorCount = 2;

    Event() : invocations() {
        invocations.reserve(ExpectedFunctorCount);
    }

    template <void (* TFunc)(T1...)> void Add() {
        TCallback c = DeduceCallback(TFunc).template Bind<TFunc>();
        invocations.push_back(c);
    }

    template <typename T, void (T::* TFunc)(T1...)> void Add(T& object) {
        Add<T, TFunc>(&object);
    }

    template <typename T, void (T::* TFunc)(T1...)> void Add(T* object) {
        TCallback c = DeduceCallback(TFunc).template Bind<TFunc>(object);
        invocations.push_back(c);
    }

    void Invoke(T1... t1) {
        for(size_t i = 0; i < invocations.size() ; ++i) invocations[i](std::forward<T1>(t1)...); 
    }

    void operator()(T1... t1) {
        Invoke(std::forward<T1>(t1)...);
    }

    size_t InvocationCount() { return invocations.size(); }

    template <void (* TFunc)(T1...)> bool Remove ()          
        { return Remove (DeduceCallback(TFunc).template Bind<TFunc>()); } 
    template <typename T, void (T::* TFunc)(T1...)> bool Remove (T& object) 
        { return Remove <T, TFunc>(&object); } 
    template <typename T, void (T::* TFunc)(T1...)> bool Remove (T* object) 
        { return Remove (DeduceCallback(TFunc).template Bind<TFunc>(object)); } 

protected:
    bool Remove(TCallback const& target) {
        auto it = std::find(invocations.begin(), invocations.end(), target);
        if (it==invocations.end()) 
            return false;
        invocations.erase(it);
        return true;
    }
};
 
struct MoveableOnly
{
    MoveableOnly()                               = default;
    MoveableOnly(MoveableOnly const&)            = delete;
    MoveableOnly(MoveableOnly&&)                 = default;
    MoveableOnly& operator=(MoveableOnly const&) = delete;
    MoveableOnly& operator=(MoveableOnly&&)      = default;
};
 
namespace Static {
           void Test1(int num)           { std::cout << "Static: " << num << "!"  << std::endl; }
           void Test9(MoveableOnly&& m)  { std::cout << "Static: MoveableOnly !"  << std::endl; }
}
struct Sink {
           void Test1(int num)  { std::cout << num        << " member function" << std::endl; }
           void Test2(std::string s, double d)  
                                { std::cout << s  << d    << " member function" << std::endl; }
    static void Test3(int snum) { std::cout << snum       << " static member"   << std::endl; }
};

int main(int argc, char* argv[]) {
    Event<int> intev;
    Sink sink;
    int count = 20; 
    intev(count++); intev.Add<Sink, &Sink::Test1>(sink);

    intev(count++); intev.Add<&Static::Test1>();
    intev(count++); intev.Add<&Static::Test1>();
    intev(count++); intev.Add<&Static::Test1>();

    intev(count++); assert(intev.Remove<&Static::Test1>());
    intev(count++); assert(intev.Remove<&Static::Test1>());
    intev(count++); assert(intev.Remove<&Static::Test1>());

    assert(!intev.Remove<&Static::Test1>());

    intev(count++); intev.Remove<Sink, &Sink::Test1>(sink);
    intev(count++);

    Event<std::string, double> complex_ev;
    complex_ev.Add<Sink, &Sink::Test2>(sink);

    complex_ev("hello world: ", 42.31415926);

    Event<MoveableOnly&&> movev;
    movev.Add<&Static::Test9>();

    movev(MoveableOnly()); // I think MSVC had a bug that requires std::move here, too?

    MoveableOnly arg;
    movev(std::move(arg));
}   
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:130:52: error: 'MoveableOnly& MoveableOnly::operator=(MoveableOnly&&)' cannot be defaulted

#endif
