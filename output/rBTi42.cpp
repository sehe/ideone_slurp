// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-01 18:27:38
// status:	0
// result:	15
// memory:	3432
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <map>
#include <iostream>

int main(int argc, char ** argv)
{
    const std::vector<int> scores = {76, 89, 150, 135, 200, 76, 12, 100, 150, 28, 178, 189,
                                     167, 200, 175, 150, 87, 99, 129, 149, 176, 200, 87,
                                     35, 157, 189
                                    };
    std::map<int, int> scoreCount;
    std::cout << "Number of Scores: " << scores.size() << "\n";

    for(auto score : scores)
    {
        scoreCount[score/25] ++;
        std::cout <<  score << " - scoreCount Index: " << score/25 << "\n";
    }

    for(auto const& slot : scoreCount)
    {
        auto low  = slot.first*25;
        auto high = low+24;
        std::cout << "Range " << low << "-" << high << ": " << slot.second << "\n";
    }
    
    int sum = 0;
    for(auto const& slot : scoreCount)
        sum += slot.second;
    
    if(sum < 26)
        printf("\n%d: Wrong number of scores counted.\n", sum);
    else
        printf("\nAll students accounted for.\n");
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Number of Scores: 26
76 - scoreCount Index: 3
89 - scoreCount Index: 3
150 - scoreCount Index: 6
135 - scoreCount Index: 5
200 - scoreCount Index: 8
76 - scoreCount Index: 3
12 - scoreCount Index: 0
100 - scoreCount Index: 4
150 - scoreCount Index: 6
28 - scoreCount Index: 1
178 - scoreCount Index: 7
189 - scoreCount Index: 7
167 - scoreCount Index: 6
200 - scoreCount Index: 8
175 - scoreCount Index: 7
150 - scoreCount Index: 6
87 - scoreCount Index: 3
99 - scoreCount Index: 3
129 - scoreCount Index: 5
149 - scoreCount Index: 5
176 - scoreCount Index: 7
200 - scoreCount Index: 8
87 - scoreCount Index: 3
35 - scoreCount Index: 1
157 - scoreCount Index: 6
189 - scoreCount Index: 7
Range 0-24: 1
Range 25-49: 2
Range 75-99: 6
Range 100-124: 1
Range 125-149: 3
Range 150-174: 5
Range 175-199: 5
Range 200-224: 3

All students accounted for.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
