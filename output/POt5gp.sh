// error:	OK
// langId:	28
// langName:	Bash
// langVersion:	bash 4.0.35
// time:	0.03
// date:	2013-03-04 17:23:35
// status:	0
// result:	15
// memory:	5268
// signal:	0
// public:	false
// ------------------------------------------------
for ((i=0; i<5; i++))
do
    net=$(($RANDOM % 253 + 1))
    echo "--- let's say net=$net"
    echo "----"
    echo "network=10.1.$(($net/8*8)).0"
    echo "netmask=255.255.248.0"
    echo "gateway=10.1.$(($net/8*8)).1"
    echo "----"
done

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
--- let's say net=116
----
network=10.1.112.0
netmask=255.255.248.0
gateway=10.1.112.1
----
--- let's say net=160
----
network=10.1.160.0
netmask=255.255.248.0
gateway=10.1.160.1
----
--- let's say net=45
----
network=10.1.40.0
netmask=255.255.248.0
gateway=10.1.40.1
----
--- let's say net=9
----
network=10.1.8.0
netmask=255.255.248.0
gateway=10.1.8.1
----
--- let's say net=177
----
network=10.1.176.0
netmask=255.255.248.0
gateway=10.1.176.1
----

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
