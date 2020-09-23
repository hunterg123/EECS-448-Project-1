#include "Ai.h"
using namespace std;


AI::AI(int my_difficulty)
{
    difficulty = my_difficulty;
    shipNum = 0;
    computer = new Player();
}

void AI::placeShips(int NumofShip){
  shipNum = NumofShip;
  srand(time(NULL));
  cout << "Computer, Where would you like to place your SIZE ONE frigate?: ";
  ship_row = 'A' + rand() % 9; // randomly choose from A-I
  cout << ship_row;
  ship_col = to_string(rand() % 9+1); // randomly choose from 1-9
  cout << ship_col<<endl;
  ship_coord1 = ship_coord2 = ship_row + ship_col;
  Ship frigate(1, ship_coord1, ship_coord2, "frigate"); //creates the correct ship
  NumofshipsRemaining = NumofShip; //updates how many parts of it remain
  computer->markBoard(frigate); //marks it on the map
}
int AI::shipsRemaining(){
  return NumofshipsRemaining;
}
void AI::isHit(){
  NumofshipsRemaining = NumofshipsRemaining-1;
}
bool AI::Move() // Decides which kind of move to make based on difficulty setting
{
    if (difficulty == '1') easyMove();
    else if (difficulty == '2') mediumMove();
    else hardMove();
    return true;
}

void AI::easyMove()
{

}

void AI::hardMove()
{

}


void AI::mediumMove()
{

}
