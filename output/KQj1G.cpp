// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-26 14:50:32
// status:	0
// result:	15
// memory:	2864
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<std::string> vExt;
	vExt.push_back("*.JPG;*.TGA;*.TIF");
	vExt.push_back("*.PNG;*.RAW");
	vExt.push_back("*.BMP;*.HDF");
	vExt.push_back("*.GIF");
	vExt.push_back("*.JPG");
	vExt.push_back("*.BMP");

	std::ostringstream oss;
	std::unique_copy(vExt.begin(), vExt.end(),
        std::ostream_iterator<std::string>(oss, ";"));

    std::cout << oss.str() << std::endl;

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
*.JPG;*.TGA;*.TIF;*.PNG;*.RAW;*.BMP;*.HDF;*.GIF;*.JPG;*.BMP;

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
