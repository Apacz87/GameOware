#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

//Prototypy klas i funkcji
class C_Player;
class C_Board;
class C_Game;
int fnTargetField(int, int);
void fnMakeAMove(int, C_Board*);
void fnArbiter(int,char, C_Board*);
void fnClearScrean();
bool fnGameWillStartPlayer1();
bool fnIsItOver(C_Board*);

//Definicje Klas
//Definicja klasy Plansza
class C_Board{
public:
    int mGameBoarder[12];
    int mnBoxA,mnBoxB;
    void DrawPlayground(C_Player*, C_Player*);
    C_Board();
    C_Board(const C_Board & org_plansza); //konstruktor kopiujacy
};
//Definicja klasy Gracza
class C_Player{
public:
    string msPlayerName;
    int mCollectedSeeds;
    bool mfIsHisTurn;
    void MakeAMove(int, C_Board*);
    int AImove(C_Board, int);
};
//Definicja klasy Gra
class C_Game{
public:
	int AIlevel=4;
    C_Board OwarePlayground;
    C_Player mPlayer_A;
    C_Player mPlayer_B;
    bool mfFirstTurn, mfItTakes;

    void Move();
    void End();
    void Arbiter(int, C_Board*);
    bool IsItOver();
    C_Game(int);
};

