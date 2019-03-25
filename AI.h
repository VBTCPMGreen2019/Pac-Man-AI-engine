#pragma once
#include "Variable_initialization.h"

void checkboard() {
	for (int i = 0; i < 14; i++) {
		for (int x = 0; x < 19; x++) {
			if (board[i][x] == 4) {
				Px = x;
				Py = i;
			}
		}
	}
	for (int i = 0; i < 14; i++) {
		for (int x = 0; x < 19; x++) {
			if (board[i][x] == 3) {
				Gx = x;
				Gy = i;
			}
		}
	}

	XL = (Gx - 2); int XR = (Gx + 2);
	YU = (Gy - 2); int YL = (Gy + 2);
	/*
	for (int i = YU; i <= YL; i++) {
		for (int x = XL; x <= XR; x++) {
			cout << board[i][x];
		}
		cout << endl;
	}
	*/
}

//logging moves
void logmoves(int Ghostx, int Ghosty) {
	if (moves == 1) {
		move1X = Ghostx;
		move1Y = Ghosty;
	}
	else if (moves == 2) {
		move2X = Ghostx;
		move2Y = Ghosty;
	}
	else if (moves == 4) {
		move4X = Ghostx;
		move4Y = Ghosty;
	}
	if (Moves >= 3) {
		checkrepeats(move2X, move2Y, move4X, move4Y);
		if (move2X != move4X) {
			repeats = 0;
		}
		else if (move2Y != move4Y) {
			repeats = 0;
		}
	}
}
//Checking repeats
void checkrepeats(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		if (y1 == y2) {
			repeats++;
			if (repeats > 4) {
				fixrepeat(x1, y1, x2, y2, move1X, move1Y);
				cout << "Repeating" << endl;
			}
		}
	}
}
//fixing repeats
void fixrepeat(int x1, int y1, int x2, int y2, int move1X, int move1Y) {
	if ((x1 == move1X) && (x2 == move1X)) {
	}
	else if ((y1 == move1Y) && (y2 == move1Y)) {
		
	}
}


void GhostMove() {


	if (SkipY) {
		SkipY = false;
		goto ChangeX;
	}

	// Move Down
	if (Gy <= 13) {
		if (Py > Gy) {
			if ((board[(Gy + 1)][Gx] == 0) || (board[(Gy + 1)][Gx] == 4)) {
				Moveup();
			}
			else {
				goto ChangeX;
			}
		}
	}
	// Move Up
	if (Gy >= 0) {
		if (Py < Gy) {
			if ((board[(Gy - 1)][Gx] == 0) || (board[(Gy - 1)][Gx] == 4)) {
				Movedown();
			}
			else {
				goto ChangeX;
			}
		}
	}
	else {
	ChangeX:
		// Move Left
		if (Gx >= 0) {
			if (Px < Gx) {
				if ((board[Gy][(Gx - 1)] == 0) || (board[Gy][(Gx - 1)] == 4)) {
					Moveleft();
				}
			}
		}
		// Move right
		if (Gx <= 18) {
			if (Px > Gx) {
				if (((board[Gy][(Gx + 1)] == 0) || (board[Gy][(Gx + 1)] == 4)) && (Gx != 18)) {
					Moveright();
				}
			}
		}

		else {
			if (board[Gy+1][Gx]==0) {
				Movedown();
				SkipY = true;
			}
			else if (board[Gy-1][Gx] == 0) {
				Moveup();
				SkipY = true;
			}
			else if (board[Gy][Gx-1] == 0) {
				Moveleft();
			}
			else if (board[Gy][Gx+1] == 0) {
				Moveright();
			}
		}

		
		// End Game
		if ((Px == Gx)&&(Py == Gy)){
//			DrawBoard();
			cout << "End Game" << endl
				<< "Total moves: " << Moves << endl;
			End = true;
		}
	}
}
void ghostMove() {
	CurrentMove = Moves;
	if (Px < Gx) {
		if (board[Gy][Gx - 1] == 0) {
			if (board[Gy][XL] == 0) {
				if (board[Gy - 1][XL] == 0) {
					Moveleft();
				}
				else { goto MoveGhost; }
			}
			else if (board[Gy - 1][Gx - 1] == 0) {
				Moveleft();
			}
			else { goto MoveGhost; }
		}
		else { goto MoveGhost; }
	}
	else {
		MoveGhost:
		GhostMove();
	}
}

void Moveright() {
	board[Gy][Gx] = 0;
	Gx++;
	board[Gy][Gx] = 3;

	if ((moves + 1) == 5)
		moves = 0;
	moves++;
	Moves++;
}
void Moveleft() {
	board[Gy][Gx] = 0;
	Gx--;
	board[Gy][Gx] = 3;

	if ((moves + 1) == 5)
		moves = 0;
	moves++;
	Moves++;
}
void Moveup() {
	board[Gy][Gx] = 0;
	Gy++;
	board[Gy][Gx] = 3;

	if ((moves + 1) == 5)
		moves = 0;
	moves++;
	Moves++;
}
void Movedown() {
	board[Gy][Gx] = 0;
	Gy--;
	board[Gy][Gx] = 3;

	if ((moves + 1) == 5)
		moves = 0;
	moves++;
	Moves++;
}

void AI() {
	for (;;) {
		if (End == false) {
			DrawBoard();
			cout << "Ghost: (" << Gx << "," << Gy << ")" << endl;
			checkboard();
			logmoves(Gx, Gy);
			if (Moves > 1) {
				ghostMove();
			}
			else {
				GhostMove();
			}
			cout << endl;
			SDL_Delay(500);
		}
		else {
			break;
		}
	}
}