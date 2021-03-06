// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-30 11:34:05
// status:	0
// result:	15
// memory:	3428
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <random>
#include <functional>

#include <iostream>

int main()
{
    std::mt19937                        twister(91210);
    std::uniform_int_distribution<int>  distribution(0,255);
    
    // fill a vector ith [0..255]:
    std::vector<int> vNumbers(256);
    std::iota(vNumbers.begin(), vNumbers.end(), 0);
    
    // shuffle it
    std::random_shuffle(vNumbers.begin(), vNumbers.end(), std::bind(distribution, twister));
    
    for(auto n : vNumbers)
       std::cout << n << " ";
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
68 29 163 130 95 72 97 143 24 10 147 96 137 187 133 77 47 228 230 154 169 44 33 46 162 11 156 232 13 78 141 194 131 136 23 204 237 0 120 245 183 193 116 164 173 113 202 122 57 159 161 38 153 128 106 242 48 160 144 14 229 105 80 91 51 205 198 234 185 52 208 17 93 70 255 92 82 98 75 213 114 88 212 223 15 166 129 86 174 199 118 249 165 74 110 65 196 149 109 219 217 218 4 18 73 134 45 171 231 115 25 247 186 99 20 203 56 139 155 26 2 127 191 8 81 246 54 140 244 168 49 43 195 90 221 123 34 145 227 67 157 126 132 69 150 184 5 152 101 32 94 167 158 225 235 135 61 148 76 172 189 254 9 66 108 19 233 177 226 12 125 215 121 250 36 35 21 210 111 85 222 253 22 41 31 79 142 1 40 87 224 59 209 179 197 64 6 112 240 3 83 104 89 60 53 7 42 63 16 107 27 207 200 238 62 206 214 220 201 192 188 181 71 178 241 100 103 176 243 39 84 119 55 124 216 58 180 37 170 211 146 28 117 252 151 239 182 102 30 190 248 251 175 50 138 236 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
