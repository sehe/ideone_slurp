// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-07 09:06:34
// status:	0
// result:	15
// memory:	2728
// signal:	0
// public:	true
// ------------------------------------------------
#include <boost/random.hpp>
#include <boost/random/uniform_int.hpp>

int main()
{
    boost::mt19937 engine1(1234);
    boost::mt19937 engine2(1234);
    boost::uniform_int<> dist(100,200);

    for (int i=0; i<20; i++)
    {
         std::cout << dist(engine1) << " is equal to " << dist(engine2) << std::endl;
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
108 is equal to 108
168 is equal to 168
168 is equal to 168
169 is equal to 169
111 is equal to 111
173 is equal to 173
139 is equal to 139
105 is equal to 105
141 is equal to 141
186 is equal to 186
151 is equal to 151
198 is equal to 198
156 is equal to 156
125 is equal to 125
124 is equal to 124
175 is equal to 175
184 is equal to 184
120 is equal to 120
147 is equal to 147
143 is equal to 143

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
