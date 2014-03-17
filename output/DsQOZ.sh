// error:	OK
// langId:	28
// langName:	Bash
// langVersion:	bash 4.0.35
// time:	0.02
// date:	2011-12-18 21:01:22
// status:	0
// result:	15
// memory:	5312
// signal:	0
// public:	false
// ------------------------------------------------
declare -a array

function dump()
{
    echo elements: ${#array[@]}
    for item in "${array[@]}"
    do echo "$item"
    done
}

array=( sg sg sg sg sg sg sg sg sg sg )
dump

# ----

array=( $(yes "dummy" | head -n10) )
dump

# ----

array=( {1..10} )
dump


# ----

readarray array -t -n 10 < <(yes "whole lines in array" | head -n 10)
dump

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
elements: 10
sg
sg
sg
sg
sg
sg
sg
sg
sg
sg
elements: 10
dummy
dummy
dummy
dummy
dummy
dummy
dummy
dummy
dummy
dummy
elements: 10
1
2
3
4
5
6
7
8
9
10
elements: 10
whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array

whole lines in array


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
