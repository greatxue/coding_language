/*
 * File: TicTacToeCheck.cpp
 * ------------------------
 * This program checks to see whether a specific player has won a game
 * of TicTacToe.
 */

#include <iostream>
#include <string>
#include "vector.h"
#include "console.h"
using namespace std;

/* Function prototypes */

bool checkForWin(Vector< Vector<char> > & board, char mark);
bool checkWinningLine(Vector< Vector<char> > & board, char mark,
                      int row, int col, int dRow, int dCol);
void displayBoard(Vector< Vector<char> > & board);
void testWin(string str);

/* Main program */

int main() {
   testWin("         ");
   testWin("XXX O  O ");
   testWin("X OXO XO ");
   testWin("OX XOX  O");
   testWin("XXO OXO  ");
   testWin("XOXOOXOXO");
   return 0;
}

/*
 * Function: checkForWin
 * Usage: if (checkForWin(board, mark)) . . .
 * ------------------------------------------
 * Checks to see whether the specified player identified by mark
 * ('X' or 'O') has won the game.  To reduce the number of special
 * cases, this implementation uses the helper function checkWinningLine
 * so that the row, column, and diagonal checks are the same.
 */

bool checkForWin(Vector< Vector<char> > & board, char mark) {
   for (int i = 0; i < 3; i++) {
      if (checkWinningLine(board, mark, i, 0, 0, 1)) return true;
      if (checkWinningLine(board, mark, 0, i, 1, 0)) return true;
   }
   if (checkWinningLine(board, mark, 0, 0, 1, 1)) return true;
   if (checkWinningLine(board, mark, 2, 0, -1, 1)) return true;
   return false;
}

/*
 * Function: checkWinningLine
 * Usage: if (checkWinningLine(board, mark, row, col, dRow, dCol)) . . .
 * ---------------------------------------------------------------------
 * Checks a line extending across the board in some direction. The
 * starting coordinates are given by the row and col parameters.  The
 * direction of motion is specified by dRow and dCol, which show how
 * to adjust the row and col values on each cycle.  For rows, dRow is
 * always 0; for columns, dCol is 0.  For diagonals, the dRow and dCol
 * values will be +1 or -1 depending on the direction of the diagonal.
 */

bool checkWinningLine(Vector< Vector<char> > & board, char mark,
                      int row, int col, int dRow, int dCol) {
   for (int i = 0; i < 3; i++) {
      if (board[row][col] != mark) return false;
      row += dRow;
      col += dCol;
   }
   return true;
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays the current board position.
 */

void displayBoard(Vector< Vector<char> > & board) {
   for (int i = 0; i < 3; i++) {
      if (i != 0) cout << "---+---+---" << endl;
      for (int j = 0; j < 3; j++) {
         if (j != 0) cout << "|";
         cout << " " << board[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

/*
 * Function: testWin
 * Usage: testWin(str);
 * --------------------
 * Runs a test of the code to check for winning lines.  The argument
 * str must be a nine-character string consisting of the characters
 * in each of the board squares.
 */

void testWin(string str) {
   Vector< Vector<char> > board(3, Vector<char>(3));
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         board[i][j] = str[3 * i + j];
      }
   }
   displayBoard(board);
   if (checkForWin(board, 'X')) cout << "X has won" << endl;
   if (checkForWin(board, 'O')) cout << "O has won" << endl;
   cout << endl;
}
