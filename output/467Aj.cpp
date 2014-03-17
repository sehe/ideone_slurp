// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-07 09:11:52
// status:	0
// result:	15
// memory:	2828
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <random>
#include <functional>

int main()
{
    std::mt19937 engine1(1234);
    std::mt19937 engine2(1234);
    std::uniform_int_distribution<> dist(100,200);

    for (int i=0; i<20; i++)
    {
         std::cout << dist(engine1) << " is equal to " << dist(engine2) << std::endl;
    }

    auto gen1 = std::bind(dist, engine1);
    auto gen2 = std::bind(dist, engine1);

    for (int i=0; i<20; i++)
    {
         std::cout << gen1() << " is equal to " << gen2() << std::endl;
    }

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
119 is equal to 119
150 is equal to 150
162 is equal to 162
182 is equal to 182
144 is equal to 144
161 is equal to 161
179 is equal to 179
177 is equal to 177
178 is equal to 178
186 is equal to 186
127 is equal to 127
115 is equal to 115
127 is equal to 127
120 is equal to 120
180 is equal to 180
182 is equal to 182
196 is equal to 196
116 is equal to 116
188 is equal to 188
111 is equal to 111
136 is equal to 136
101 is equal to 101
150 is equal to 150
149 is equal to 149
169 is equal to 169
133 is equal to 133
171 is equal to 171
181 is equal to 181
137 is equal to 137
109 is equal to 109
156 is equal to 156
105 is equal to 105
150 is equal to 150
144 is equal to 144
101 is equal to 101
102 is equal to 102
178 is equal to 178
129 is equal to 129
189 is equal to 189
124 is equal to 124

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
