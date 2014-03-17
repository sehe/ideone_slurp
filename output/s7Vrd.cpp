// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-04-11 11:49:40
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
struct X { static X j,bit,ow,goo; X *co,*mp,*ly,*gl; } t = {&t,&t,&t,&t};

int main()
{
    t.co -> j.mp -> bit.ly -> ow.ly -> goo.gl;
}

// for the conscience-troubled:
X X::j = {&t,&t,&t,&t}, X::bit = {&t,&t,&t,&t}, X::ow = {&t,&t,&t,&t}, X::goo = {&t,&t,&t,&t};

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
