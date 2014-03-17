// error:	OK
// langId:	28
// langName:	Bash
// langVersion:	bash 4.0.35
// time:	0
// date:	2013-07-03 22:03:54
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#!/bin/bash -e

goodfifo=/tmp/my$RANDOM.fifo
badfifo=/tmp/my$RANDOM.fifo

trap "unlink '$goodfifo'; unlink '$badfifo'" ERR EXIT QUIT INT

if ({ trap "" PIPE INT; tee $badfifo; } | gofmt -s) > $goodfifo 2>/dev/null
then
    #cat $badfifo 2>&1 > /dev/null&
    cat $goodfifo
else
    #cat $goodfifo 2>&1 > /dev/null&
    cat $badfifo
fi

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
