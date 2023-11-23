# 11. Algorithm

*Last Update: 23-11-20*

In this approach called ***backtracking algorithms***, there consists of a sequence of decision points, and you have to backtrack to a previous decision point and try a different path if you reach a dead end.

## 11.1 Backtracking Algorithms

**Solving a Maze**

The most widely known strategy for solving a maze is called the *right-hand rule*, but will be invalid if there are **loops** in the maze surrounding either the starting position or the goal.

![image-20231122105250138](pictures/11-1.png)

It is also possible to solve a maze recursively. A maze is solvable only if it is possible to solve **one of the simpler mazes** that results from shifting the starting location to an adjacent square and taking the current square out of the maze completely.

![image-20231122110213112](pictures/11-2.png)

Here is a detailed implementation:

```cpp
/*
 * Class: Maze
 * -----------
 * This class represents a two-dimensional maze contained in a rectangular
 * grid of squares.  The maze is read in from a data file in which the
 * characters '+', '-', and '|' represent corners, horizontal walls, and
 * vertical walls, respectively; spaces represent open passageway squares.
 * The starting position is indicated by the character 'S'.  For example,
 * the following data file defines a simple maze:
 *
 *       +-+-+-+-+-+
 *       |     |
 *       + +-+ + +-+
 *       |S  |     |
 *       +-+-+-+-+-+
 */

class Maze {
public:
  
/*
 * Constructor: Maze
 * Usage: Maze maze(filename);
 *        Maze maze(filename, gw);
 * -------------------------------
 * Constructs a new maze by reading the specified data file.  If the
 * second argument is supplied, the maze is displayed in the center
 * of the graphics window.
 */

   Maze(std::string filename);
   Maze(std::string filename, GWindow & gw);

/*
 * Method: getStartPosition
 * Usage: Point start = maze.getStartPosition();
 * ---------------------------------------------
 * Returns a Point indicating the coordinates of the start square.
 */

   Point getStartPosition();
  
/*
 * Method: isOutside
 * Usage: if (maze.isOutside(pt)) ...
 * ------------------------------------
 * Returns true if the specified point is outside the boundary of the maze.
 */

   bool isOutside(Point pt);

/*
 * Method: wallExists
 * Usage: if (maze.wallExists(pt, dir)) ...
 * ------------------------------------------
 * Returns true if there is a wall in direction dir from the square at pt.
 */

   bool wallExists(Point pt, Direction dir);

/*
 * Method: markSquare
 * Usage: maze.markSquare(pt);
 * ---------------------------
 * Marks the specified square in the maze.
 */

   void markSquare(Point pt);
  
/*
 * Method: unmarkSquare
 * Usage: maze.unmarkSquare(pt);
 * -----------------------------
 * Unmarks the specified square in the maze.
 */

   void unmarkSquare(Point pt);

/*
 * Method: isMarked
 * Usage: if (maze.isMarked(pt)) ...
 * -----------------------------------
 * Returns true if the specified square is marked.
 */

   bool isMarked(Point pt);
};

private:

/* Structure representing a single square */
   struct Square {
      bool marked;
      bool walls[4];
   };

/* Instance variables */
   Grid<Square> maze;
   Point startSquare;
   bool mazeShown;
   double x0;
   double y0;
   int rows;
   int cols;

/* Private Implementation */

/*
 * Function: solveMaze
 * Usage: solveMaze(maze, start);
 * ------------------------------
 * Attempts to generate a solution to the current maze from the specified
 * start point.  The solveMaze function returns true if the maze has a
 * solution and false otherwise.  The implementation uses recursion
 * to solve the submazes that result from marking the current square
 * and moving one step along each open passage.
 */

bool solveMaze(Maze & maze, Point start) {
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   maze.markSquare(start);
   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         if (solveMaze(maze, (start, dir))) {
            return true;
         }
      }
   }
   maze.unmarkSquare(start);
   return false;
}
```

**Recursion and Concurrency**

The recursive decomposition of a maze generates a series of **independent** submazes; the goal is to solve any one of them.

If you had a *multiprocessor* computer, you could try to solve each of these submazes **in parallel**. 

Refer to **P vs. NP** problem for reference.

![image-20231123091206903](pictures/11-3.png)

**Searching in a Branching Structure**

The primary advantage of using recursion in these problems is that doing so dramatically **simplifies the bookkeeping**. Each level of the recursive algorithm considers one choice point. The historical knowledge of what choices have already been tested and which ones remain for further exploration is maintained automatically in the *execution stack*.

**The N Queen Problem**

![image-20231123155537264](pictures/11-4.png)

Instead of traversing acouss all the possibilities, we try to solve it *recursively*. First we implement the function `solveQueens()`:

```cpp
bool solveQueens(Grid<char> & board, int nPlaced = 0) {
   int n = board.numRows();
   if (nPlaced == n) return true;
   for (int row = 0; row < n; row++) {
      if (queenIsLegal(board, row, nPlaced)) {
         board[row][nPlaced] = 'Q';
         if (solveQueens(board, nPlaced + 1)) return true;
         board[row][nPlaced] = ' ';
      }
   }
   return false;
}
```

Then we implement the `main()` function:

```cpp
int main() {
   int n = getInteger("Enter size of board: ");
   Grid<char> board(n, n);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         board[i][j] = ' ';
      }
   }
   if (solveQueens(board)) {
      displayBoard(board);
   } else {
      cout << "There is no solution for this board" << endl;
   }
   return 0;
}
```

