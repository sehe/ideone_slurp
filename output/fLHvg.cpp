// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-15 12:34:39
// status:	0
// result:	15
// memory:	2728
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>   // avoid old style MSVC++ header!
#include <algorithm>
#include <string>

static inline bool isvowel(char ch)
{
	static const std::string vowels("aeiouEAIOU");
	return vowels.end() != std::find(vowels.begin(), vowels.end(), ch);
}

int main()
{
	std::cout << "Enter a name: ";

	std::string name;

	if (std::cin >> name) // handle errors
	{
		size_t vow_cnt = std::count_if(name.begin(), name.end(), isvowel);
		std::cout << "vow_cnt: " << vow_cnt << std::endl;
	}

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Enter a name: 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
