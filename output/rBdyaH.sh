// error:	OK
// langId:	28
// langName:	Bash
// langVersion:	bash 4.0.35
// time:	0.02
// date:	2013-07-18 00:40:05
// status:	0
// result:	15
// memory:	5312
// signal:	0
// public:	true
// ------------------------------------------------
#!/bin/bash
function lookup()
{
    case "$1" in
        apple|banana|kiwi|melon)
            echo "FRUIT"
            ;;

        radish|lettuce|potato)  
            echo "VEGETABLE"
            ;;

        blue|red|yellow|green|brown)   
            echo "COLOR"
            ;;
    esac
}

MY_CHOICE="kiwi"
MY_CHOICE_GROUP=$(lookup "$MY_CHOICE")

echo $MY_CHOICE: $MY_CHOICE_GROUP

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
kiwi: FRUIT

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
