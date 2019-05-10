#include<thread>
#include<iostream>
#include<string>
#include<Windows.h>

#include"Board.h"
#include"AI.h"
#include"Variable_initialization.h"
using namespace std;

void AI();
void Moveup();
void Movedown();
void Moveleft();
void Moveright();
void checkboard();
void logmoves(int Ghostx, int Ghosty);
void checkrepeats(int x1, int y1, int x2, int y2);
//void fixrepeat(int x1, int y1, int x2, int y2, int move1X, int move1Y);

int main(int argc, char* args[]){
	DrawBoard();
	AI();
	return 0;
}