// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-01-02 17:19:23
// status:	0
// result:	15
// memory:	2968
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <type_traits>
#include <memory>
using namespace std;

template<typename T> struct foo {
    virtual foo& operator<<(const T& e) const { std::cout << "check foo\n"; }
};

struct derived : foo<int> {
    virtual derived& operator<<(const int& e) const { std::cout << "check derived\n"; }
};

template<typename T> struct genericDerived : foo<T> {
    virtual derived& operator<<(const T& e) const { std::cout << "check genericDerived\n"; }
};

//////

namespace detail
{
	template<typename Foo, typename T>
		const std::shared_ptr<Foo>& dispatch_lshift(const std::shared_ptr<Foo>& o, const T& e, const std::true_type& enabler)
		{
			*o << e;
			return o;
		}
}

template<typename Foo, typename T>
const std::shared_ptr<Foo>& operator<<(const std::shared_ptr<Foo>& o, const T& e)
{
	return detail::dispatch_lshift(o, e, std::is_convertible<Foo*, foo<T>* >());
}

int main()
{
	auto f = make_shared<foo<int>>();
	f << 1;

	auto d = make_shared<derived>();
	d << 2;

	auto g = make_shared<genericDerived<int>>();
	g << 3;

	auto x = make_shared<int>();
	// x << 4; // correctly FAILS to compile
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
check foo
check derived
check genericDerived

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
