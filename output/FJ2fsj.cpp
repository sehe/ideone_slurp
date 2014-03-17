// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-24 13:33:50
// status:	0
// result:	0
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
#include <stdlib.h>
#include <time.h>
#include "ncurses/ncurses.h"
extern "C"
 {
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>
 }

using namespace std;

int kolumny = 0;
int rzedy = 0;

unsigned _licznik[30];
bool _cout[30];

//printw("tekst") - Wyswietla napis na ekranie. W tym wypadku efekt jest podobny jak w cout
//funkcja getch() znana z conio.h, oczekuje ona na wcisniecie przycisku i ew. go zwraca

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

void Legenda()
{
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
    move( 0, 0 );
    clrtoeol();
    printw( tekst.c_str() );
    refresh();
}

void WypiszNaEkran(string tekst,int i, bool b)
{
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
    int farba=0;
    start_color();
    switch(color)
    {
        case 1:
            farba =1;
            init_pair(1, COLOR_YELLOW, COLOR_BLACK);
            break;
        case 2:
            farba =2;
            init_pair(2, COLOR_RED, COLOR_BLACK);
            break;
        case 3:
            farba =3;
            init_pair(3, COLOR_WHITE, COLOR_BLACK);
            break;
        case 4:
            farba =4;
            init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
            break;
        default:
            farba =0;
            init_pair(0, COLOR_CYAN, COLOR_BLACK);
            break;
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

deque < int > kolejka0;
deque < int > kolejka1;
deque < int > kolejka2;
deque < int > kolejka3;

pthread_mutex_t mutex_iostream     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex0     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3     = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t space_available = PTHREAD_COND_INITIALIZER;


void * Profesor(void * arg);
void * Portier(void * arg);
void * Wyjscie(void * arg);

pthread_t *profesorTab=NULL;
pthread_t *portierTab=NULL;
pthread_t  wyjscieExit;

int main()
{
    initscr();// ktora musimy zawsze użyc przed rozpoczeciem pracy z biblioteka New Curses. 
    getmaxyx( stdscr, rzedy, kolumny ); //Pobieranie wartości okna do zmiennych

    for(int i=0; i<30; i++)
    {
        _licznik[i]=0;
        _cout[i]=false;
    }
    srand (time(NULL));
    //ustawiamy atrybuty na domyslna wartosc
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_mutex_init(&mutex_iostream, NULL);
    pthread_mutex_init(&mutex0, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_mutex_init(&mutex3, NULL);

    pthread_mutex_lock(&mutex_iostream);
    Legenda();
    pthread_mutex_unlock(&mutex_iostream);

    //pthread_create( &wyjscieExit, NULL, &Wyjscie, NULL);

    portierTab=new pthread_t[5];
    for(int i=0; i<5; i++)
    {
        int _i = i+15;
        pthread_create( &portierTab[i], NULL, &Portier, &_i);
    }
    //inicjalizujemy 10 watkow studentow
    profesorTab=new pthread_t[10];
    for(int i=0; i<10; i++)
    {
        pthread_create( &profesorTab[i], NULL, &Profesor, &i);
    }
    pthread_mutex_lock(&mutex_iostream);
    WypiszNaEkran("Dzialanie watkow");
    pthread_mutex_unlock(&mutex_iostream);
    //Rozpoczynamy dzialanie watkow

    //pthread_join( wyjscieExit, NULL);

    for(int i=0; i<5; i++)
    {
        pthread_join( portierTab[i], NULL);
    }
    for(int i=0; i<10; i++)
    {
        pthread_join( profesorTab[i], NULL);
    }

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex_iostream);
    pthread_mutex_destroy(&mutex0);
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    pthread_mutex_destroy(&mutex3);
    delete [] profesorTab;
    pthread_exit(NULL);
    pthread_mutex_lock(&mutex_iostream);
    WypiszNaEkran("Koniec Programu");
    pthread_mutex_unlock(&mutex_iostream);
    endwin();// Konczy prace biblioteki New Curses. 
    return 0;
}

/*
 * Kod Profesora.
 *
 * Profesor przeszukuje kolejki w kolejności 3,2,1 
 * w poszukiwaniu studenta który potrzebuje jego podpisu.
 * Jeżeli znajduje to wyciąga go z tej kolejki, dodaje swój podpis(odznaczając się z rekordu)
 * wrzuca do kolejnej (o ile nie wyciągnął z 3-ciej) wyżej 
 */
void *Profesor(void * arg)
{
    int id=0;
    id=*(int*)arg;
    unsigned sz;
    while (1) 
    {
        pthread_mutex_lock(&mutex3);
        // Sprawdzenie kolejki ze studentami, ktorzy maja juz trzy wpisy
        sz= kolejka3.size();
        if(!kolejka3.empty())
        {
            pthread_mutex_lock(&mutex_iostream);
            WypiszNaEkran("Profesor sprawdza kolejke3",id,1); //YELLOW
            pthread_mutex_unlock(&mutex_iostream);
            usleep(100);
            for (unsigned j=0; j<sz; j++)
            {
                    if(kolejka3[j]&(1<<id))
                    {
                        kolejka3[j]&=~(1<<id); // odznaczamy profesora
                        kolejka3.erase(kolejka3.begin()+j);
                        pthread_mutex_lock(&mutex_iostream);
                        WypiszNaEkran("Profesor dodal swoj wpis(kolejka3)",id, true);
                        pthread_mutex_unlock(&mutex_iostream);
                        usleep(10);
                    }           
            }
        }
        pthread_mutex_unlock(&mutex3);
        sleep(1);
        pthread_mutex_lock(&mutex2);
        // Sprawdzenie kolejki ze studentami, ktorzy maja dwa wpisy
        sz= kolejka2.size();
        if(!kolejka2.empty())
        {
            pthread_mutex_lock(&mutex_iostream);
            WypiszNaEkran("Profesor sprawdza kolejke2",id,2);//RED
            pthread_mutex_unlock(&mutex_iostream);
            usleep(100);
            for (unsigned j=0; j<sz; j++)
            {
                    if(kolejka2[j]&(1<<id))
                    {
                        kolejka2[j]&=~(1<<id); // odznaczamy profesora
                        pthread_mutex_lock(&mutex3);
                        kolejka3.push_back(kolejka2[j]);
                        pthread_mutex_unlock(&mutex3);
                        kolejka2.erase(kolejka2.begin()+j);
                        pthread_mutex_lock(&mutex_iostream);
                        WypiszNaEkran("Profesor dodal swoj wpis(kolejka2)",id,true);
                        pthread_mutex_unlock(&mutex_iostream);
                        usleep(100);
                    }               
            }
        }
        pthread_mutex_unlock(&mutex2);
        sleep(1);
        pthread_mutex_lock(&mutex1);
        // Sprawdzenie kolejki ze studentami, ktorzy maja jeden wpisy
        sz= kolejka1.size();
        if(!kolejka1.empty())
        {
            pthread_mutex_lock(&mutex_iostream);
            WypiszNaEkran("Profesor sprawdza kolejke1",id,3); // BLUE
            pthread_mutex_unlock(&mutex_iostream);
            usleep(100);
            for (unsigned j=0; j<sz; j++)
            {

                    if(kolejka1[j]&(1<<id))
                    {
                        kolejka1[j]&=~(1<<id); // odznaczamy profesora
                        pthread_mutex_lock(&mutex2);
                        kolejka2.push_back(kolejka1[j]);
                        pthread_mutex_unlock(&mutex2);
                        kolejka1.erase(kolejka1.begin()+j);
                        pthread_mutex_lock(&mutex_iostream);
                        WypiszNaEkran("Profesor dodal swoj wpis(kolejka2)",id,true);
                        pthread_mutex_unlock(&mutex_iostream);
                        usleep(100);
                    }   
            }
        }
        pthread_mutex_unlock(&mutex1);
        sleep(1);
        pthread_mutex_lock(&mutex0);
        // Sprawdzenie kolejki ze studentami, ktorzy nie maja wpisow
        sz= kolejka0.size();
        if(!kolejka0.empty())
        {
            pthread_mutex_lock(&mutex_iostream);
            WypiszNaEkran("Profesor sprawdza kolejke0",id,4); // MAGENDA
            pthread_mutex_unlock(&mutex_iostream);
            usleep(100);
            for (unsigned j=0; j<sz; j++)
            {

                    if(kolejka0[j]&(1<<id))
                    {
                        kolejka0[j]&=~(1<<id); // odznaczamy profesora
                        pthread_mutex_lock(&mutex1);
                        kolejka1.push_back(kolejka0[j]);
                        pthread_mutex_unlock(&mutex1);
                        kolejka0.erase(kolejka0.begin()+j);
                        pthread_mutex_lock(&mutex_iostream);
                        WypiszNaEkran("Profesor dodal swoj wpis(kolejka0)",id,true);
                        pthread_mutex_unlock(&mutex_iostream);
                        usleep(100);
                    }   

            }
        }
        pthread_mutex_unlock(&mutex0);
        sleep(1);
    }
}
/*
 * Kod Portiera.
 *
 * Utrzymuje kolejke zerowa by bylo w niej przynajmnie 10 studentów
 * Jezeli jest mniej niz 10 studentow dorabia 10 nowych
 */
void *Portier(void * arg)
{
    int id=0;
    id=*(int*)arg;
    int abc;
    while(1)
    {
        pthread_mutex_lock(&mutex0);
        if(kolejka0.size()<10)
        {
            for(int i=0;i<10;i++)
            {
                abc=UtworzStudenta();
                kolejka0.push_back(abc);
            }
        }
        pthread_mutex_unlock(&mutex0);
        usleep(1000000);
    }
}


void *Wyjscie(void * arg)
{
    char txt;
    do 
    {
        txt = getch();
        sleep(1);
    }
    while( txt != 27 );
    exit(1);
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
