// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-09 14:04:06
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	false
// ------------------------------------------------
#include <random>
#include <string>
#include <iostream>

int main()
{
	std::mt19937 random;

	std::string s = "string is strange";
	std::uniform_int_distribution<size_t> gen(0,s.size()-1);

	for (int i=0; i<20; i++)
	{
		std::swap(s[gen(random)], s[gen(random)]);
		std::cout << s << "\n";
	}

	return 0;
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
staing is strrnge
staing is strrgne
steing is strrgna
stenng is strrgia
stenns is gtrrgia
s enns istgtrrgia
s enns istgtrrgia
s enns isagtrrgit
s enns isagtrrgit
s enns isagtrrgit
s rnns isagtergit
s rnns isagtergit
strnns isagtergi 
strnns iragtesgi 
strnns iragtesgi 
rtsnns iragtesgi 
risnns tragtesgi 
risnns traitesgg 
risnns traitegsg 
risnns t aitegsgr

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
