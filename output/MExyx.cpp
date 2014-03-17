// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-12 23:27:40
// status:	0
// result:	15
// memory:	3016
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>

struct StratA {
    enum gender { male, female, unknown };
    double price(std::string name, int age, gender g) const
    { return 42; }
};

struct StratB {
    double price(int age, int volume, double historic_rate) const
    { return (age*age*historic_rate)/volume; }
};

template <typename PricingStrategy=StratA>
struct SomeEngine
{
    template <typename... Args>
    void doSomethingInvolvingPricing(std::string logmessage,
            Args... args) // involving pricing
    {
        std::cout << logmessage << ": " << PricingStrategy().price(std::forward<Args>(args)...) << '\n';
    }
};

int main()
{
    SomeEngine<>().doSomethingInvolvingPricing("default", "name", 18, StratA::female);
    SomeEngine<StratB>().doSomethingInvolvingPricing("overridden", 18, 3000, 4.5);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
default: 42
overridden: 0.486

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
