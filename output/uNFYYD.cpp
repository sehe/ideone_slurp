// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-15 13:31:25
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
// function compositions with bind
      BOOST_CHECK(bind(&sum_of_args_3, bind(&sum_of_args_2, _1, 2), 2, 3)(i)==8); 
      BOOST_CHECK(
        bind(&sum_of_args_9,
           bind(&sum_of_args_0),                             // 0
           bind(&sum_of_args_1, _1),                         // 1
           bind(&sum_of_args_2, _1, _2),                     // 3   
           bind(&sum_of_args_3, _1, _2, _3),                 // 6 
           bind(&sum_of_args_4, _1, _2, _3, 4),              // 10
           bind(&sum_of_args_5, _1, _2, _3, 4, 5),           // 15
           bind(&sum_of_args_6, _1, _2, _3, 4, 5, 6),        // 21
           bind(&sum_of_args_7, _1, _2, _3, 4, 5, 6, 7),     // 28
           bind(&sum_of_args_8, _1, _2, _3, 4, 5, 6, 7, 8)   // 36
        )(i, j, k) == 120);
    
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:2:18: error: expected constructor, destructor, or type conversion before ‘(’ token
       BOOST_CHECK(bind(&sum_of_args_3, bind(&sum_of_args_2, _1, 2), 2, 3)(i)==8); 
                  ^
prog.cpp:3:18: error: expected constructor, destructor, or type conversion before ‘(’ token
       BOOST_CHECK(
                  ^

#endif
