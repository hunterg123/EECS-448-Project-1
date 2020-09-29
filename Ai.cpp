#include "Ai.h"
#include <time.h>

AI::AI(int my_difficulty, int ships)
{
    difficulty = my_difficulty;
    num_ships = ships;
    for (int i = 0; i < ships; i++) ship_healths[i] = i + 1;
    placeShips();
}

AI::~AI() {};

char AI::getShipType(int size)
{
    if (size == 5) return 'B';
    else if (size == 4) return 'C';
    else if (size == 3) return 'S';
    else if (size == 2) return 'D';
    else return 'F';
}

int AI::getShipIndex(char type)
{
  if (type == 'B') return 4;
  else if (type == 'C') return 3;
  else if (type == 'S') return 2;
  else if (type == 'D') return 1;
  else return 0;
}

bool AI::placer(char direction, int row, int col, int size, char shipType)
{
    if (direction == 'u')
    {
        if (row - size + 1 >= 1)
        {
            for (int j = row; j >= row - size + 1; j--) if (ship_board.getValue(j, col) != '~') return false;
            for (int j = row; j >= row - size + 1; j--) ship_board.setValue(j, col, shipType);
            return true;
        }
        return false;
    }
    else if (direction == 'd')
    {
        if (row + size - 1 <= 9)
        {
            for (int j = row; j <= row + size - 1; j++) if (ship_board.getValue(j, col) != '~') return false;
            for (int j = row; j <= row + size - 1; j++) ship_board.setValue(j, col, shipType);
            return true;
        }
        return false;
    }
    else if (direction == 'l')
    {
        if (col - size + 1 >= 1)
        {
            for (int j = col; j >= col - size + 1; j--) if (ship_board.getValue(row, j) != '~') return false;
            for (int j = col; j >= col - size + 1; j--) ship_board.setValue(row, j, shipType);
            return true;
        }
        return false;
    }
    else
    {
        if (col + size - 1 <= 9)
        {
            for (int j = col; j <= col + size - 1; j++) if (ship_board.getValue(row, j) != '~') return false;
            for (int j = col; j <= col + size - 1; j++) ship_board.setValue(row, j, shipType);
            return true;
        }
        return false;
    }
    return false;
}

void AI::placeShips()
{
    char directions[4] = {'u', 'd', 'l', 'r'}; // all potential directions
    srand(time(NULL)); // initialize the random
    for (int i = 1; i <= num_ships; i++)
    {
        bool ship_placed = false;
        char shipType = getShipType(i);
        while (!ship_placed)
        {
            int row = (rand() % 9) + 1; // choose random row to try
            int col = (rand() % 9) + 1; // choose random col to try
            char direction = directions[rand() % 4]; // generate random direction to try

            ship_placed = placer(direction, row, col, i, shipType); // place the ship
        }
    }
}


void AI::printShootBoard() { shoot_board.print(); }
void AI::printShipBoard() { ship_board.print(); }

std::string AI::Move() // Decides which kind of move to make based on difficulty setting
{
    std::string shot;
    if (difficulty == 1) shot = easyMove();
    else if (difficulty == 2) shot = mediumMove();
    else shot = hardMove();
    return shot;
}

std::string AI::easyMove()
{
  int rowNum = 0;
  int colNum = 0;
  std::string row = " ";
  std::string col = " ";
  std:: string shot_coord = " ";
  srand(time(NULL));
  std::string letter = "ABCDEFGHI";
  rowNum = rand()%9;
  colNum = (rand() % 9) + 1;
  if (shoot_board.getValue(colNum,rowNum+1) != 'X' && shoot_board.getValue(colNum,rowNum+1) != '*'){
    row = string (1, letter[rowNum]);
    col = to_string(colNum);
    shot_coord = row + col;
  }
  else{
    while (shoot_board.getValue(colNum,rowNum+1) == 'X' || shoot_board.getValue(colNum,rowNum+1) == '*'){
      rowNum = rand()%9;
      colNum = (rand() % 9) + 1;

    }
    row = string (1, letter[rowNum]);
    col = to_string(colNum);
    shot_coord = row + col;
  }
  return shot_coord;
}

string AI::hardMove()
{
  string shot = m_coordsList.back();
  m_coordsList.pop_back();
  return shot;
}


std::string AI::mediumMove()
{

}

void AI::getCoords(vector<string> coords)
{
    m_coordsList = coords;
}

void AI::markShot(std::string shot, bool hit)
{
  if (hit)  //if the shot is a hit
  {
    shoot_board.changepointat(shot, 'X');
  }
  else      //if it is a miss
  {
    shoot_board.changepointat(shot, '*');
  }
}

bool AI::isHit(std::string shot)
{
  char shipType = ship_board.getpointat(shot); // retrieve the type of ship (or '~' for no ship) that was hit

  if (shipType != '~') // check if a ship has been hit
  {
    ship_board.changepointat(shot, 'X');
    ship_healths[getShipIndex(shipType)]--; // decrement the ship's health
    return true;
  }
  else // no ship has been hit
  {
    ship_board.changepointat(shot, '*');
    return false;
  }
}

bool AI::isSunk(std::string shot){
  char shipType = ship_board.getpointat(shot);
  int shipIndex = getShipIndex(shipType);
  return (ship_healths[shipIndex] == 0);
}

int AI::getShipsRemaining(){
  int ships_remaining = 0;
  for (int i = 0; i < num_ships; i++) if (ship_healths[i] > 0) ships_remaining++;
  return ships_remaining;
}

void AI::printCoords()
{
  for(int i =0; i<m_coordsList.size(); i++)
  {
    cout << m_coordsList.at(i) << " ";
  }
}
