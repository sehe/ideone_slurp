// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-20 07:04:15
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
struct L1 {
    struct L2 {
        int i[4];
    } l2[3];
};

L1::L2 l2 = { {1,2,3,4} };

L1::L2 l2_a[] = { {{1,2,3}}, {{1,2}}, {{1,2,3,4}}};

L1 l1 = {
    {{{1,2,3}}, {{1,2}}, {{1,2,3,4}}}
};

L1 l1_a0 = 	{};
L1 l1_a1 = {{{{0}}}};

L1 l1_a[] = {
    {{{{1,2,3}}, {{1,2}}, {{1,2,3,4}}}},
    {{{{1,2,3}}, {{1,2}}, {{1,2,3,4}}}}	
}; // ... sweet potatoes!


int main()
{
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
