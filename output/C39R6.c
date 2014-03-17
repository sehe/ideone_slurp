// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-29 00:04:53
// status:	0
// result:	15
// memory:	1852
// signal:	0
// public:	true
// ------------------------------------------------
#include <string.h>
#include <stdio.h>

void replace_char(char str[], int n, char c)
{
  str[n] = c;
}

int main (void)
{  
  char* string = "Hello World!";

  printf ("%s\n", string);
  replace_char(string, 10, 'a');
  printf ("%s\n", string);

  string = strdup("Hello World!");

  printf ("%s\n", string);
  replace_char(string, 10, 'a');
  printf ("%s\n", string);

  return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Hello World!
Hello World!
Hello World!
Hello Worla!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
