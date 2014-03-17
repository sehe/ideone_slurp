// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-01 20:02:55
// status:	0
// result:	12
// memory:	3472
// signal:	6
// public:	true
// ------------------------------------------------
#include <cstdio>
#include <array>

int main(int argc, char ** argv) {
  int scores[] = {76, 89, 150, 135, 200, 76, 12, 100, 150, 28, 178, 189,
                  167, 200, 175, 150, 87, 99, 129, 149, 176, 200, 87,
                  35, 157, 189};
  int size = sizeof(scores) / sizeof(scores[0]);
  std::array<int, 8> scoreCount = {0, 0, 0, 0, 0, 0, 0, 0};

  printf("Number of Scores: %d\n\n", size);

  for(int i = 0; i < size; i++) {
    scoreCount.at(scores[i]/25) += 1;
    printf("%d - scoreCount Index: %d\n", i, scores[i]/25);
  }

  printf("\n");

  int low = 0;
  int high = 24;

  size = sizeof(scoreCount) / sizeof(scoreCount[0]);

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
