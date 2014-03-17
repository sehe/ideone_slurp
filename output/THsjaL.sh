// error:	OK
// langId:	28
// langName:	Bash
// langVersion:	bash 4.0.35
// time:	0.02
// date:	2013-07-18 00:29:58
// status:	0
// result:	15
// memory:	5268
// signal:	0
// public:	true
// ------------------------------------------------
#!/bin/bash
declare -A groups

groups["apple"]="FRUIT"
groups["banana"]="FRUIT"
groups["kiwi"]="FRUIT"
groups["melon"]="FRUIT"

groups["radish"]="VEGETABLE"
groups["lettuce"]="VEGETABLE"
groups["potato"]="VEGETABLE"

groups["blue"]="COLOR"
groups["red"]="COLOR"
groups["yellow"]="COLOR"
groups["green"]="COLOR"
groups["brown"]="COLOR"

MY_CHOICE="kiwi"
MY_CHOICE_GROUP=${groups[$MY_CHOICE]}

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
