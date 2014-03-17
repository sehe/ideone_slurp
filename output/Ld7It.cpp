// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-10 13:31:15
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
struct myClass
{
    void classUDF(double* a) { };
};

// External function (tipically from an external library)
void externalFunction(int n, void (myClass::*udf)(double*) )
{
    myClass myClassObj;
	double x;
	(myClassObj.*udf)(&x); 
}

int main()
{
    externalFunction(1, &myClass::classUDF);
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
