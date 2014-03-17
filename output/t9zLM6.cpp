// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-17 22:53:12
// status:	0
// result:	15
// memory:	3292
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
using namespace std;
int main_menu();
bool rules();
int difficulty();
int combat_main();
int combat_hero(int,int,int,int);
int combat_nemesis(int,int,int,int);
int combat_resolve(int,int,int&,int&,int&,int&);
int combat_end(int,int);
int main_menu();
bool rules();
int combat_main()
{
    int play_again=0;
    do
    {
        bool active_battle=1;
        cout << "Let the battle begin! Show no mercy!\n" << '\n';
        int round_number=0;
        int hero_health=5;
        int hero_energy=2;
        int nemesis_health=5;
        int nemesis_energy=2;
        do
        {
            if((hero_health<1)||(nemesis_health<1))
            {
                active_battle=0;
            }
            //recognizes that battle has ended
            else
            {
                ++round_number;
                cout << "Round " << round_number << '\n' << '\n';
                int hero_action= combat_hero(hero_health,hero_energy,nemesis_health,nemesis_energy);
                //receives player's choice of action
                int nemesis_action= combat_nemesis(hero_health,hero_energy,nemesis_health,nemesis_energy);
                //decides AI's choice of action
                combat_resolve(hero_action,nemesis_action,hero_health,hero_energy,nemesis_health,nemesis_energy);
                //decides round outcome from hero_action and nemesis_action
                if(hero_action==0)
                {
                    hero_health=0;
                    //automatically ends battle if player opts to concede defeat
                }
            }
        }
        while(active_battle==1);
        //cycles combat rounds until one opponent loses
        play_again=combat_end(hero_health,nemesis_health);
        //prompts player with option to play again at end of battle
    }
    while(play_again==1);
    //repeats if "play again" selected after battle ends
    return play_again;
}
int main()
{
}
int combat_hero(int hero_health,int hero_energy,int nemesis_health,int nemesis_energy) { return 42; }
int combat_nemesis(int hero_health,int hero_energy,int nemesis_health,int nemesis_energy) { return 42; }
int combat_resolve(int hero_action,int nemesis_action,int &hero_health,int &hero_energy,int &nemesis_health,int &nemesis_energy) { return 42; }
int combat_end(int hero_health,int nemesis_health) { return 42; }

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
