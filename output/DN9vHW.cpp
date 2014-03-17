// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-23 21:00:38
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
/*
    *shial
    *g++ -Wall -lpthread -o threads.exe thread.cpp -lncurses
    */

#include <iostream>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "ncurses.h"

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int columns = 0;
int rows   = 0;

unsigned _licznik[30];
bool _cout[30];

/*
 * Kod Studenta.
 * Student jest rekordem
 * Posiadajacym int'a do którego wrzucamy 4 profesorów
 */
int UtworzStudenta()
{
    int StudentRekord=0;
    for(int i=0;i<4;i++)
        StudentRekord|=(1<<(rand()%10)); // dodajemy losowych prowadzacych;
    return StudentRekord;
}

std::mutex mutex_iostream;

void Legenda()
{
    std::lock_guard<std::mutex> lk(mutex_iostream);
    move( 22, 0 );
    start_color();
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(7)); 
    printw( "LEGENDA: " );
    attroff(COLOR_PAIR(7));
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(5)); 
    printw( "WPIS, " );
    attroff(COLOR_PAIR(5));
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1)); 
    printw( "QUEUE3, " );
    attroff(COLOR_PAIR(1));
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(2)); 
    printw( "QUEUE2, " );
    attroff(COLOR_PAIR(2));
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(3)); 
    printw( "QUEUE1, " );
    attroff(COLOR_PAIR(3));
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(4)); 
    printw( "QUEUE0, " );
    attroff(COLOR_PAIR(4));
    refresh();
}

void WypiszNaEkran(string tekst)
{
    std::lock_guard<std::mutex> lk(mutex_iostream);
    move( 0, 0 );
    clrtoeol();
    printw( tekst.c_str() );
    refresh();
}

void WypiszNaEkran(string tekst,int i, bool b)
{
    std::lock_guard<std::mutex> lk(mutex_iostream);
    start_color();
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(5)); 
    if(_licznik[i]>75)
    {
        _licznik[i]=0;
        move( 2*i, _licznik[i] );
        clrtoeol();
    }
    move( 2*i, _licznik[i] );
    _licznik[i]++;
    //clrtoeol();
    printw( "%c",232 );//tekst.c_str()
    attroff(COLOR_PAIR(5)); 
    refresh();
}
void WypiszNaEkran(string tekst,int i, int color)
{
    std::lock_guard<std::mutex> lk(mutex_iostream);
    int farba=0;
    start_color();
    switch(color)
    {
        case     1: farba =1; init_pair(1, COLOR_YELLOW,  COLOR_BLACK); break;
        case     2: farba =2; init_pair(2, COLOR_RED,     COLOR_BLACK); break;
        case     3: farba =3; init_pair(3, COLOR_WHITE,   COLOR_BLACK); break;
        case     4: farba =4; init_pair(4, COLOR_MAGENTA, COLOR_BLACK); break;
        default:    farba =0; init_pair(0, COLOR_CYAN,    COLOR_BLACK); break;
    }
    attron(COLOR_PAIR(farba));
    if(_licznik[i]>75)
    {
        _licznik[i]=0;
        move( 2*i, _licznik[i] );
        clrtoeol();
    }
    move( 2*i, _licznik[i] );
    _licznik[i]++;
    printw( "%c",232 );//tekst.c_str()
    attroff(COLOR_PAIR(farba)); 
    refresh();
}

deque <int> kolejka0;
deque <int> kolejka1;
deque <int> kolejka2;
deque <int> kolejka3;

struct Task
{
    std::mutex mutex;
} task0, task1, task2, task3;

//pthread_cond_t space_available = PTHREAD_COND_INITIALIZER;

void Profesor(int id);
void Portier(int id);

std::vector<std::thread> profesorTab, portierTab;

int main()
{
    srand (time(NULL));
    initscr();// ktora musimy zawsze użyc przed rozpoczeciem pracy z biblioteka New Curses. 
    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych

    for(int i=0; i<30; i++)
    {
        _licznik[i]=0;
        _cout[i]=false;
    }
    //ustawiamy atrybuty na domyslna wartosc

    Legenda();

    for(int i=0; i<5;  i++) portierTab.emplace_back(Portier,   i+15);
    for(int i=0; i<10; i++) profesorTab.emplace_back(Profesor, i);

    WypiszNaEkran("Dzialanie watkow");

    //Rozpoczynamy dzialanie watkow

    for(auto& th : portierTab)
        if (th.joinable()) th.join();
    for(auto& th : profesorTab)
        if (th.joinable()) th.join();

    profesorTab.clear();
    WypiszNaEkran("Koniec Programu");
    endwin();// Konczy prace biblioteki New Curses. 
}

void foo1(int id)
{
    std::lock_guard<std::mutex> lk(task3.mutex);
    // Sprawdzenie kolejki ze studentami, ktorzy maja juz trzy wpisy
    auto sz= kolejka3.size();
    if(!kolejka3.empty())
    {
        WypiszNaEkran("Profesor sprawdza kolejke3",id,1); //YELLOW
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (unsigned j=0; j<sz; j++)
        {
            if(kolejka3[j]&(1<<id))
            {
                kolejka3[j]&=~(1<<id); // odznaczamy profesora
                kolejka3.erase(kolejka3.begin()+j);
                WypiszNaEkran("Profesor dodal swoj wpis(kolejka3)",id, true);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }           
        }
    }
}

void foo2(int id)
{
    std::lock_guard<std::mutex> lk(task2.mutex);
    // Sprawdzenie kolejki ze studentami, ktorzy maja dwa wpisy
    auto sz= kolejka2.size();
    if(!kolejka2.empty())
    {
        WypiszNaEkran("Profesor sprawdza kolejke2",id,2);//RED
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (unsigned j=0; j<sz; j++)
        {
            if(kolejka2[j]&(1<<id))
            {
                kolejka2[j]&=~(1<<id); // odznaczamy profesora
                {
                    std::lock_guard<std::mutex> lk(task3.mutex);
                    kolejka3.push_back(kolejka2[j]);
                }
                kolejka2.erase(kolejka2.begin()+j);
                WypiszNaEkran("Profesor dodal swoj wpis(kolejka2)",id,true);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }               
        }
    }
}

void foo3(int id)
{
    std::lock_guard<std::mutex> lk(task1.mutex);
    // Sprawdzenie kolejki ze studentami, ktorzy maja jeden wpisy
    auto sz= kolejka1.size();
    if(!kolejka1.empty())
    {
        WypiszNaEkran("Profesor sprawdza kolejke1",id,3); // BLUE
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (unsigned j=0; j<sz; j++)
        {

            if(kolejka1[j]&(1<<id))
            {
                kolejka1[j]&=~(1<<id); // odznaczamy profesora
                {
                    std::lock_guard<std::mutex> lk(task2.mutex);
                    kolejka2.push_back(kolejka1[j]);
                }
                kolejka1.erase(kolejka1.begin()+j);
                WypiszNaEkran("Profesor dodal swoj wpis(kolejka2)",id,true);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }   
        }
    }
}

void foo4(int id)
{
    std::lock_guard<std::mutex> lk(task0.mutex);
    // Sprawdzenie kolejki ze studentami, ktorzy nie maja wpisow
    auto sz= kolejka0.size();
    if(!kolejka0.empty())
    {
        WypiszNaEkran("Profesor sprawdza kolejke0",id,4); // MAGENDA
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (unsigned j=0; j<sz; j++)
        {

            if(kolejka0[j]&(1<<id))
            {
                kolejka0[j]&=~(1<<id); // odznaczamy profesora
                {
                    std::lock_guard<std::mutex> lk(task1.mutex);
                    kolejka1.push_back(kolejka0[j]);
                }
                kolejka0.erase(kolejka0.begin()+j);
                WypiszNaEkran("Profesor dodal swoj wpis(kolejka0)",id,true);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }   

        }
    }
}

/*
 * Kod Profesora.
 *
 * Profesor przeszukuje kolejki w kolejności 3,2,1 
 * w poszukiwaniu studenta który potrzebuje jego podpisu.
 * Jeżeli znajduje to wyciąga go z tej kolejki, dodaje swój podpis(odznaczając się z rekordu)
 * wrzuca do kolejnej (o ile nie wyciągnął z 3-ciej) wyżej 
 */
void Profesor(int id)
{
    while (1) 
    {
        foo1(id); std::this_thread::sleep_for(std::chrono::seconds(1));
        foo2(id); std::this_thread::sleep_for(std::chrono::seconds(1));
        foo3(id); std::this_thread::sleep_for(std::chrono::seconds(1));
        foo4(id); std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

/*
 * Kod Portiera.
 *
 * Utrzymuje kolejke zerowa by bylo w niej przynajmnie 10 studentów
 * Jezeli jest mniej niz 10 studentow dorabia 10 nowych
 */
void Portier(int id)
{
    while(1)
    {
        {
            std::lock_guard<std::mutex> lk(task0.mutex);
            if(kolejka0.size()<10)
            {
                for(int i=0;i<10;i++)
                {
                    kolejka0.push_back(UtworzStudenta());
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:11:21: fatal error: ncurses.h: No such file or directory
compilation terminated.

#endif
