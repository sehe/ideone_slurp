// error:	OK
// langId:	41
// langName:	C++ 4.3.2
// langVersion:	gcc-4.3.2
// time:	0
// date:	2013-08-01 21:57:48
// status:	0
// result:	12
// memory:	2816
// signal:	6
// public:	true
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <tr1/array>

template <typename T, size_t N> T* begin(T(&arr)[N]) { return arr;   }
template <typename T, size_t N> T* end(T(&arr)[N])   { return arr+N; }

int main(int argc, char ** argv)
{
    const int scores[] = {76, 89, 150, 135, 200, 76, 12, 100, 150, 28, 178, 189,
                                     167, 200, 175, 150, 87, 99, 129, 149, 176, 200, 87,
                                     35, 157, 189
                                    };
    std::tr1::array<int, 8> scoreCount;
    std::fill(scoreCount.begin(), scoreCount.end(), 0);

    int const *f(begin(scores)), *l(end(scores));
    const size_t num_scores = std::distance(f,l);
    std::cout << "Number of Scores: " << num_scores << "\n";

    for(int const* it=begin(scores); it!=end(scores); ++it)
    {
        scoreCount.at(*it/25) ++;
        std::cout <<  *it << " - scoreCount Index: " << (*it/25) << "\n";
    }

    size_t sum = 0;
    for(size_t i=0; i<scoreCount.size(); ++i)
    {
        int low   = i*25;
        int high  = low+24;
        int count = scoreCount.at(i);
        std::cout << "Range " << low << "-" << high << ": " << count << "\n";

        sum += count;
    }

    if(sum != num_scores)
    {
        std::cout << sum << ": Wrong number of scores counted.\n";
    }
    else
    {
        std::cout << "\nAll students accounted for.\n";
    }
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

#endif
#if 0 // stderr
terminate called after throwing an instance of 'std::out_of_range'
  what():  array::at

#endif
#if 0 // cmpinfo

#endif
