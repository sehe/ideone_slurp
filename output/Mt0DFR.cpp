// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-18 13:02:11
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#if 0
template<template<typename...> class Container>
struct ContainerTests
{
    template<typename T, typename U, typename... Ts> 
        static void run()
    {
        run<T>();
        run<U, Ts...>();
    }

    template<typename T> 
        static void run()
    {
        auto data = generate<Container, T>();
        std::cout << "\n=========== " << typeid(data).name() << "\n";
        for (auto i : data)
            std::cout << i << " ";
    }
};
#else
template<template<typename...> class Container>
struct ContainerTests
{
    template<typename... Ts> 
        static void run()
    {
        do_run(types<Ts...>());
    }

  private:
    template<typename...> struct types{};

    template<typename T, typename... Ts> 
        static void do_run(types<T,Ts...>)
    {
        auto data = generate<Container, T>();
        std::cout << "\n=========== " << typeid(data).name() << "\n";
        for (auto i : data)
            std::cout << i << " ";
        
        do_run(types<Ts...>());
    }

    static void do_run(types<>) { }
};
#endif

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
