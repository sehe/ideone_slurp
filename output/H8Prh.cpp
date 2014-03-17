// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-13 15:10:21
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
/////////////////////////////////////
// Simple ASCII Console World
// Author: Muhammad Ahmad Tirmazi
// Date: 12 July 2012
// License: BSD 4-Clause
/////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <cstdio>

#define _WIN32_WINNT 0x0500
#include <windows.h>

/* Standard error macro for reporting API errors */ 
 #define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s \
    on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

 void cls( HANDLE hConsole )
 {
    COORD coordScreen = { 0, 0 };    /* here's where we'll home the
                                        cursor */ 
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
    DWORD dwConSize;                 /* number of character cells in
                                        the current buffer */ 

    /* get the number of character cells in the current buffer */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "GetConsoleScreenBufferInfo" );
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    /* fill the entire screen with blanks */ 

    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputCharacter" );

    /* get the current text attribute */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "ConsoleScreenBufferInfo" );

    /* now set the buffer's attributes accordingly */ 

    bSuccess = FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputAttribute" );

    /* put the cursor at (0, 0) */ 

    bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
    return;
 }

// Our Custom Namespace
namespace pro {

///////////////////////////////
// Just a typedef for 'char'
///////////////////////////////
typedef char GameTile;

///////////////////////////////
// Simple Point Class
// Holds the X and Y values
// of a 2D Object
//////////////////////////////
template< typename T > struct Point
{
    Point(void) : X(0), Y(0) {}
    Point(T x, T y) : X(x), Y(y) {}
    T X;
    T Y;
};

/////////////////////////////
// Simple GamePlayer Class
// For controlling the
// Main Character
/////////////////////////////
struct GamePlayer
{
    Point< int > Position;
    GameTile Tile;

    GamePlayer(std::vector< std::string >& map);

    void MoveLeft(std::vector< std::string >& map);
    void MoveRight(std::vector< std::string >& map);
    void MoveUp(std::vector< std::string >& map);
    void MoveDown(std::vector< std::string >& map);

    void Draw(void);
};

//////////////////////////////////////////
// Constructor
// Sets the Player's original position
// 1 is the code for a happy face
/////////////////////////////////////////
GamePlayer::GamePlayer(std::vector< std::string >& map)
    : Position(2, 2), Tile(1)
{
    if (map[Position.X][Position.Y] == ' ')
    {
        map[Position.X][Position.Y] = Tile;
    }
    else
    {
        std::cerr << "Player's Tile is Occupied" << std::endl;
    }
}

//////////////////////////////////////////
// Moves the Player 1 Tile To the Left
/////////////////////////////////////////
void GamePlayer::MoveLeft(std::vector< std::string >& map)
{
    // If the tile is empty
    if (map[Position.Y][Position.X - 1] == ' ')
    {
        // Remove our player's tile from it's original position
        map[Position.Y][Position.X] = ' ';

        Position.X --;
        // Fill it with our player's tile
        map[Position.Y][Position.X] = Tile;
    }
}

//////////////////////////////////////////
// Moves the Player 1 Tile To the Right
/////////////////////////////////////////
void GamePlayer::MoveRight(std::vector< std::string >& map)
{
    // If the tile is empty
    if (map[Position.Y][Position.X + 1] == ' ')
    {
        // Remove our player's tile from it's original position
        map[Position.Y][Position.X] = ' ';

        Position.X ++;
        // Fill it with our player's tile
        map[Position.Y][Position.X] = Tile;
    }
}

//////////////////////////////////////////
// Moves the Player 1 Tile Upwards
/////////////////////////////////////////
void GamePlayer::MoveUp(std::vector< std::string >& map)
{
    // If the tile is empty
    if (map[Position.Y - 1][Position.X] == ' ')
    {
        // Remove our player's tile from it's original position
        map[Position.Y][Position.X] = ' ';

        Position.Y --;
        // Fill it with our player's tile
        map[Position.Y][Position.X] = Tile;
    }
}

//////////////////////////////////////////
// Moves the Player 1 Tile Downwards
/////////////////////////////////////////
void GamePlayer::MoveDown(std::vector< std::string >& map)
{
    // If the tile is empty
    if (map[Position.Y + 1][Position.X] == ' ')
    {
        // Remove our player's tile from it's original position
        map[Position.Y][Position.X] = ' ';

        Position.Y ++;
        // Fill it with our player's tile
        map[Position.Y][Position.X] = Tile;
    }
}

} // namespace pro

////////////////////////////////
// A Character Representation
// Of Our Tile Map
///////////////////////////////
static std::string tileMap[] = {

"==========",
"=        =",
"=        =",
"=        =",
"=        =",
"=        =",
"=        =",
"=========="
};

/** Not recommended, but works for simple stuff... **/

///////////////////////////////////////////////////
// Calculates the vertical length of the tile map
//////////////////////////////////////////////////
static int mapLenght = sizeof(tileMap) / sizeof(tileMap[0]);

///////////////////////////////////////////////////
// Calculates the horizontal width of the tile map
///////////////////////////////////////////////////
static int mapWidth = tileMap[0].size();

///////////////////////////////////////////////////////////////
// Vector, to prevent us from dealing with the lousy pointer
// arithmetic that comes with arrays
///////////////////////////////////////////////////////////////
static std::vector< std::string > tileVector(tileMap, tileMap + mapLenght);

//////////////
// The player
//////////////
static pro::GamePlayer player(tileVector);

////////////////////////
// Draws the Tile Map
///////////////////////
void Draw(void)
{
	cls(::GetStdHandle(STD_OUTPUT_HANDLE));

    for (int y = 0; y < mapLenght; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            std::cout << tileVector[y][x];
        }

        std::cout << "\n";
    }
}

//////////////////////////////////////
// Gets and Responds to user input
// from the keyboard
/////////////////////////////////////
bool GetInput(void)
{
    if (GetAsyncKeyState(VK_UP))
    {
        player.MoveUp(tileVector);
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        player.MoveDown(tileVector);
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        player.MoveLeft(tileVector);
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        player.MoveRight(tileVector);
    }
    else
    {
        return false;
    }
    return true;
}

//////////////////////////////////////////
// Exit when the player presses 'Escape'
/////////////////////////////////////////
bool CheckExit()
{
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        return true;
    }

    return false;
}

//////////////////////////////////
// The main entrypoint function
/////////////////////////////////
int main()
{
    bool open = true;

    Draw();

    /////////////////////////
    // The Main Game Loop
    ////////////////////////
    while (open)
    {
        ////////////////////////////////////////////
        // Redraw if the player's position changes
        ////////////////////////////////////////////
        if (GetInput()) Draw();

        if (CheckExit()) open = false;
    }

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
