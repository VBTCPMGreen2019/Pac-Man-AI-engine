#pragma once
//player location
int Px;
int Py;
//ghost location
int Gx;
int Gy;
//5x5 box around ghost
int XL; // left
int XR; // right
int YU; // upper
int YL; // lower

bool SkipY = false;
bool End = false;

int repeats = 0; // amount of repeats
int CurrentMove = 0; // current move
int Moves = 0; // amount of total moves
int moves = 0; // cycle for move choices (1-4)

// movement logs
int move1X = NULL; int move1Y = NULL; // move 1: X & Y
int move2X = NULL; int move2Y = NULL; // move 2: X & Y
int move4X = NULL; int move4Y = NULL; // move 4: X & Y

// Functions
// movements
void GhostMove();
void ghostMove();

void Moveup();
void Movedown();
void Moveleft();
void Moveright();
// checking board
void checkboard();
// logging movement
void logmoves(int Ghostx, int Ghosty);
// checking and fixing repeating movements
void checkrepeats(int x1, int y1, int x2, int y2);
void fixrepeat(int x1, int y1, int x2, int y2, int move1X, int move1Y);
