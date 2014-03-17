// error:	OK
// langId:	41
// langName:	C++ 4.3.2
// langVersion:	gcc-4.3.2
// time:	0
// date:	2013-08-01 22:01:32
// status:	0
// result:	12
// memory:	2816
// signal:	6
// public:	true
// ------------------------------------------------
#include <tr1/array>
#include <cstdio>

template <typename T, size_t N> size_t arr_size(T(&arr)[N]) { return N; }

int main(int argc, char ** argv) {
  const int scores[] = {76, 89, 150, 135, 200, 76, 12, 100, 150, 28, 178, 189,
                  167, 200, 175, 150, 87, 99, 129, 149, 176, 200, 87,
                  35, 157, 189};
  int size = arr_size(scores);
  std::tr1::array<int, 8> scoreCount;
  std::fill(scoreCount.begin(), scoreCount.end(), 0);

  printf("Number of Scores: %d\n\n", size);

  for(int i = 0; i < size; i++) {
    scoreCount.at(((int)(scores[i]/25))) += 1;
    printf("%d - scoreCount Index: %d\n", i, ((int)(scores[i]/25)));
  }

  printf("\n");

  int low = 0;
  int high = 24;

  size = scoreCount.size();

  for(int i = 0; i < size; i++) {
    printf("Range %d-%d: %d\n", low, high, scoreCount[i]);
    low += 25;
    high += 25;
    if(high == 199) high = 200;
  }

  int sum = 0;

  for(int i = 0; i < size; i++) {
    sum += scoreCount[i];
  }

  if(sum < 26) printf("\n%d: Wrong number of scores counted.\n", sum);
  else printf("\nAll students accounted for.\n");

  return 0;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Number of Scores: 26

0 - scoreCount Index: 3
1 - scoreCount Index: 3
2 - scoreCount Index: 6
3 - scoreCount Index: 5

#endif
#if 0 // stderr
terminate called after throwing an instance of 'std::out_of_range'
  what():  array::at

#endif
#if 0 // cmpinfo

#endif
