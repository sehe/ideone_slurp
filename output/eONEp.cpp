// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-08-23 09:41:38
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	false
// ------------------------------------------------
#include <sstream>
#include <fstream>

int main()
{
  std::stringstream in_memory(std::ios::binary);

  {   
      // reading whole file into memory
      std::ifstream ifs("input.exe", std::ios::in | std::ios::binary);
      in_memory << ifs.rdbuf();
  }

  // optionally write it out
   


  return 0;
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
