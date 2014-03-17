// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-09-05 09:54:27
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	false
// ------------------------------------------------
void foo(   int a,char* b,double c);

void bar(   int a, /* (IN) the A */
            char* b,  /* (IN) something b */
            double c  /* (OUT) the resulting value */
            );

void foo(   int a,char* b,double c)
{
}

void bar(   int a, /* (IN) the A */
            char* b,  /* (IN) something b */
            double c  /* (OUT) the resulting value */
            )
{
}

int main(int argc, const char *argv[])
{
	int a;
	char* b;
	double c;
	foo
	(
	        a,
	        b,
	        c
	);
	bar
	(
	        a, /* (IN) the A */
	        b, /* (IN) something b */
	        c /* (OUT) the resulting value */
	);
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
