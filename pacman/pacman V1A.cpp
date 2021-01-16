
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
using namespace std;


class Creature {
int row; // position of creature object (Pacman) in maze
int col;
int type; // 1 indicate pacman
int points = 0;
public:
Creature() {}
Creature(int a_row, int a_col , int a_type) {
row = a_row;
col = a_col;
type = a_type;
}
void getPosition(int& a_row, int& a_col); // get pacman position in maze and store in a_row, a_col
void showCreaturePosition();
void setPosition(int a_row, int a_col);
void updateCreaturePosition(int nrow, int ncol);// update based on new position nrow, ncol
void addPoints(int a_point); // add points collected
void showCurrentPoints(); // show collected reward points
};
class Maze {
int numRow;
int numCol;
int** mat; // 2D matrix that stores the maze
public:
Maze() {}
void showMazeProperty(); // display the maze 2D matrix stored in mat
void readMaze(); // read maze from text file and populate mat
void drawMaze();
void deleteMaze(); // release memory
// update maze based on location of pacman object p and its previous location
void updateMaze(Creature p, int row_, int col_);
bool isValidMove(int nrow, int ncol); // Check if the move to new location (nrow,ncol) is valid
void placeCreatureInMaze(Creature p); // Position pacman object p into the maze
// return points as reward if move into food at location (r,c)
int getReward(Maze a_maze, int r, int c);
};
class CGame {
public:
// check if the move by creature is valid or not
void checkMove(char move, Maze& a_maze , Creature& a_creature);
};

int main() {
CGame game1;
Maze m1; // init and allocate memory
m1.readMaze();
m1.showMazeProperty();
m1.drawMaze();
Creature p(1, 3, 1); // starting position of pacman in maze at(1,3) where type=1 is pacman
m1.placeCreatureInMaze(p);
m1.drawMaze();
bool status;
char move='y';
while (move != 'q') {
m1.drawMaze();
m1.showMazeProperty();
p.showCurrentPoints();
p.showCreaturePosition();
cout << endl << "enter move >> ";
cin >> move;
// check if move is valid in the maze
game1.checkMove(move, m1, p); // if it is valid, update the pacman position and update maze
m1.showMazeProperty();

}
m1.deleteMaze();
system("pause");
return 1;
}