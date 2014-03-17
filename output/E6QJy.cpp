// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-15 15:27:08
// status:	0
// result:	15
// memory:	4912
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>   // avoid old style MSVC++ header!
#include <algorithm>
#include <iterator>
#include <locale>
#include <string>

template <typename T=char>
	struct isvowel
{
	bool operator()(T ch) const
	{
		static int _init = 0; // not thread safe :)
		static std::basic_string<T> vowels("aeiouäëïöüáéíóúàèìòùâêîôûã°øªº"); // etc. for specific languages...

		while (!_init++)
		{
			vowels.reserve(vowels.size()*2);
			// upper case dynamically based on locale, e.g. AEIOUÄËÏÖÜÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÃ°Øªº
			std::transform(vowels.begin(), vowels.end(), std::back_inserter(vowels), (int(*)(int)) std::toupper);
		}
		return vowels.end() != std::find(vowels.begin(), vowels.end(), ch);
	}
};

int main()
{
	std::setlocale(LC_ALL, "German"); // set relevant locale for case conversions
        // some recommend: std::locale::global(std::locale("de_DE"));
	std::cout << "Enter a name: ";

	std::string name;

	while (std::cin >> name) // handle errors?
	{
		size_t vow_cnt = std::count_if(name.begin(), name.end(), isvowel<char>());
		std::cout << "vow_cnt: " << vow_cnt << std::endl;
	}

	return 0;
}

// ------------------------------------------------
#if 0 // stdin
krk#!@#^&*
AEIOUÄËÏÖÜÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÃ°Øªº
aeiouäëïöüáéíóúàèìòùâêîôûã°øªº
#endif
#if 0 // stdout
Enter a name: vow_cnt: 0
vow_cnt: 33
vow_cnt: 55

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
