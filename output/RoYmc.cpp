// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-12 17:59:07
// status:	0
// result:	15
// memory:	2728
// signal:	0
// public:	true
// ------------------------------------------------
#include <cmath>
#include <limits>
#include <iostream>

#define MAX_DECIMAL_FRACTION 5
#define DEBUGTRACE(x) // do { std::cerr << x; } while (false)

template <typename T, bool is_integer> struct reverse_impl;

template <typename T>
	struct reverse_impl<T, true>
{
	static T reverse(T input)
	{
		T output;

		for (output = 0; input; input/=10)
			output = (output * 10) + input % 10;

		return output;
	}
};

template <typename T>
	struct reverse_impl<T, false>
{
	static T reverse(T input)
	{
		if (std::abs(input) <= std::numeric_limits<T>::epsilon())
			return T(0);

		// scale input
		int log10 = (int) (std::log(input)/std::log(T(10)));
		input *= std::pow(10, MAX_DECIMAL_FRACTION);
		input = std::floor(input);
		input /= std::pow(10, log10+MAX_DECIMAL_FRACTION);

		DEBUGTRACE("debug: scaled " << input << " digits: ");

		int iteration = std::max(log10+MAX_DECIMAL_FRACTION, MAX_DECIMAL_FRACTION);

		if (std::floor(input) < 1)
		{
			input *= 10;
			iteration--;
		}

		T output;
		for (output = T(0); 
			 iteration-- && std::floor(input) >= 1; 
			 input-=std::floor(input), input*=T(10))
		{
			output = (output / T(10)) + std::floor(input);
			DEBUGTRACE(std::floor(input));
		}

		DEBUGTRACE(std::endl);
		return output * std::pow(10, log10);
	}
};

template <typename T>
    T reverse(T input)
{ 
	return reverse_impl<T, std::numeric_limits<T>::is_integer>::reverse(input); 
}

int main()
{
	std::cout << reverse(-123l) << std::endl;
	std::cout << reverse(123ul) << std::endl;

	std::cout << reverse(123456.0) << std::endl;
	std::cout << reverse(0.027f) << std::endl;

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
-321
321
654321
0.72

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
