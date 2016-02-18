/**
* Author: Matt McColeman
* Date: 03/15/2015
* Title: BattleShip
* Description: The classic game of battle ship to be played against the CPU.
		FEATURE: boats are randomly placed on board
		FEATURE: boats are invisible to the user
		FEATURE: CPU can do you damage and make you lose the game!
		FEATURE: boats are now able to be placed horizontally on row 10 and vertically on column 10
 		FEATURE: cheat code to see board enter coordinates x=69 and y=69
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

typedef char* CharPtr;

class battleShip{
  public:
    battleShip();
    ~battleShip();
    CharPtr* initialBoard();
    CharPtr* initialBoardB();
    void displayBoard(CharPtr* b);
    void displayBoardB(CharPtr* c);
    void placeBoat(string name, int length, CharPtr* &b);
    bool isFree(CharPtr* &b, int o, int l, int x, int y);
    bool isFinished(CharPtr* &b);
    int BOARD_SIZE; // moved global variable into class
};



int main() {

  battleShip battle;

  const int PATROL_BOAT_LENGTH = 2;
  const string PATROL_BOAT_NAME = "Patrol boat";
  const int DESTROYER_LENGTH = 3;
  const string DESTROYER_NAME = "Destroyer";
  const int SUB_LENGTH = 3;
  const string SUB_NAME = "Submarine";
  const int BATTLESHIP_LENGTH = 4;
  const string BATTLESHIP_NAME = "Battleship";
  const int CARRIER_LENGTH = 5;
  const string CARRIER_NAME = "Aircraft Carrier";
  int turn = 100; // 100 turns because 100 coordinates
  int health = 17; // 17 health because boats take up 17 coordinates
  int shot;

  //Initialize battleship board
  CharPtr* board = battle.initialBoard(); // initializes board with boats to be placed on
  CharPtr* boardB = battle.initialBoardB(); // initializes board with boats not visible to user
  //Place the boats on the board
  battle.placeBoat(PATROL_BOAT_NAME, PATROL_BOAT_LENGTH,
            board);
  battle.placeBoat(DESTROYER_NAME, DESTROYER_LENGTH,
            board);
  battle.placeBoat(SUB_NAME, SUB_LENGTH,
            board);
  battle.placeBoat(BATTLESHIP_NAME, BATTLESHIP_LENGTH,
            board);
  battle.placeBoat(CARRIER_NAME, CARRIER_LENGTH,
            board);

  int x_coord = -1;
  int y_coord = -1;
  while (!battle.isFinished(board)) {
    // featured code allows the CPU to do damage to the user
    srand( time( NULL ) );
    shot = (rand() % turn)+1; // generates number for probability that user is HIT!
    if(1 < shot && shot <= health+1){
      health = health - 1;
      cout << "YOU'VE BEEN HIT!" << endl;
    }
    // although the odds are incredibly low this ends the program if user health is 0 and the CPU wins
    if(health == 0){
      cout << "CPU sunk all your battle ships!" << endl;
      cout << "AHA YOU LOSE!" << endl;
      return 0;
    }
    cout << "your health is: " << health << endl;
    cout << "shots left: " << turn << endl;

    battle.displayBoardB(boardB); // displays board for user to see hits and misses
    cout << "Enter (X,Y) coordinate for missle: " << endl;
    cout << "(X and Y can be 1.." << (battle.BOARD_SIZE) << ") " << endl;
    cin >> x_coord;
    cin >> y_coord;
    if(x_coord == 69) {
      if(y_coord == 69){
        battle.displayBoard(board); // feautued cheat code allows user to see where boats are on the baord
      }
    }
    x_coord -= 1;
    y_coord -= 1;

    // takes user input and modifys the board or reports invalid coordinates
    if ((x_coord >= 0 && x_coord < battle.BOARD_SIZE)
        && (y_coord >= 0 && y_coord < battle.BOARD_SIZE)) {
          switch (board[y_coord][x_coord]) {
            case '-':
              boardB[y_coord][x_coord] = 'M';
 	      board[y_coord][x_coord] = 'M';
              cout << "MISS!" << endl;
              break;
            case '*':
              boardB[y_coord][x_coord] = 'H';
	      board[y_coord][x_coord] = 'H';
              cout << "HIT!" << endl;
              break;
            default:
              cout << "You are already shot here! Try again." << endl;
         }
    } else {
      cout << "Invalid coordinates!" << endl;  
    }
    turn = turn - 1; // indicates how many turns are left
  }
}

battleShip::battleShip(){ 
  BOARD_SIZE = 10;
}

battleShip::~battleShip(){}

// initialized dynamic 2d array for battle ship board
CharPtr* battleShip::initialBoard() {
  CharPtr* p1 = new CharPtr[BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    p1[i] = new char[BOARD_SIZE];
      for (int j=0; j < BOARD_SIZE; j++) {
        p1[i][j] = '-';
      }
  }
  return p1;
}

// intialized dynamic 2d array for battle ship display board
CharPtr* battleShip::initialBoardB() {
  CharPtr* p2 = new CharPtr[BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    p2[i] = new char[BOARD_SIZE];
      for (int j=0; j < BOARD_SIZE; j++) {
        p2[i][j] = '-';
      }
  }
  return p2;
}

/**
* displays the battle ship board
* @param b
*/
void battleShip::displayBoard(CharPtr* b) {
  cout << "  ";
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << i+1 << ' ';
  }
  cout << endl;
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << (i+1) << ' ';
    for (int j=0; j < BOARD_SIZE; j++) {
      cout << b[i][j] << ' ';
    }
    cout << endl;
  }
}

/**
* displays the battle ship board
* @param c
*/
void battleShip::displayBoardB(CharPtr* c) {
  cout << "  ";
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << i+1 << ' ';
  }
  cout << endl;
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << (i+1) << ' ';
    for (int j=0; j < BOARD_SIZE; j++) {
      cout << c[i][j] << ' ';
    }
    cout << endl;
  }
}

/**
* places boat on board
* @param name
* @param length
* @param b
*/
void battleShip::placeBoat(string name, int length, CharPtr* &b) {
  srand( time( NULL ) );
  int orientation;
  orientation = (rand() % 2)+1; // generates random orientation
 
  //get top/left most coordinate
  int x_coord = -1;
  int y_coord = -1;
  while (x_coord == -1 || y_coord == -1) {
      x_coord = (rand() % 6)+1; // generates random x coordinate
      y_coord = (rand() % 6)+1; // generates random y coordinate
      x_coord -= 1;
      y_coord -= 1;
      if ((x_coord >= 0 && x_coord <= BOARD_SIZE)
          && (y_coord >= 0 && y_coord <= BOARD_SIZE)) { 
            if (!isFree(b, orientation, length, x_coord, y_coord)) {
              x_coord = -1;
              y_coord = -1;
            }
      } else {
            x_coord = -1;
            y_coord = -1;
      }
  }

  // for the coordinates the boar takes up the points are filled with and astrix
  for (int i=0; i < length; i++) {
    if (orientation == 1) {
      //horizontal placement;
      b[y_coord][x_coord+i] = '*'; // x coordinate increases to extend the boat in the horizontal direction from initial coordinate
    } else if (orientation == 2) {
      //vertical placement
      b[y_coord+i][x_coord] = '*'; // y coordinate increases to extend the boat in the vertical direction from initial coordinate
    }
  }
}
 
/**
* checks to see if coordinate is free
* @param b
* @param o
* @param l
* @param x
* @param y
*/
bool battleShip::isFree(CharPtr* &b, int o, int l, int x, int y) {
  if ((o == 1) && (y+l-1 <= BOARD_SIZE)) { 
    // FEATURE enables boat to be places in tenth row
    //horizontal placement;
    for (int i=0; i < l; i++) {
        //horizontal placement;
        if (b[y][x+i] == '*') {
          return false;
        }
    }
    return true;
  } else if ((o == 2)  && (x+l-1 <= BOARD_SIZE)){ 
    // FEATURE enables boat to be placed in tenth column
    //vertical placement
    for (int i=0; i < l; i++) {
        //horizontal placement;
        if (b[y+i][x] == '*') {
          return false;
        }
    }
    return true;
  } else {
    return false;
  }
}

/**
* ends game
* @param b
*/
bool battleShip::isFinished(CharPtr* &b) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j=0; j < BOARD_SIZE; j++) {
      if (b[i][j] == '*')
        return false;
    }
  }
  cout << "YOU WON!" << endl;;
  return true; // if no astrix is found on board game ends
}
