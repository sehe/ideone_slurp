// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2013-07-17 21:09:15
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
public class X { 
    const int mMax = 5, nMax = 5, oMax = 5;
    void process1(float x) { }
    void process2(float x) { }
    
    public static void Main(string[] args) {
float arr[mMax,nMax,oMax];

for (int m = 0; m < mMax; m++)
  for (int n = 0; n < nMax; n++)
    for (int o = 0; o < oMax; o++)
      { process1(arr[m,n,o]); }

for (int o = 0; o < oMax; o++)
  for (int n = 0; n < nMax; n++)
    for (int m = 0; m < mMax; m++)
      { process2(arr[m,n,o]); }
} }
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
