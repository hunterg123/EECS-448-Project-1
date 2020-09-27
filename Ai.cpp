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

            ship_placed = placer(direction, row, col, i, shipType);
        }
    }
}


void AI::printBoard()
{
    ship_board.print();
}

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
  srand(time(NULL));
  std::string letter = "ABCDEFGHI";
  std::string row = string (1, letter[rand()%9]);
  std::string col = to_string((rand() % 9) + 1);
  std:: string shot_coord = row + col;
  return shot_coord;
}

std::string AI::hardMove()
{

}


std::string AI::mediumMove()
{

}

void AI::addCoords(string c)
{
    m_coordsList.push_back(c);
}

bool AI::isHit(std::string shot)
{
  //if the player's ship was hit, it will enter the correct if statement depending on which type of ship was hit
  if (ship_board.getpointat(shot) == 'B')
  {
    ship_board.changepointat(shot, 'X'); //updates it from a B to show its been hit
    ship_healths[4]--;
    return true;
  }
  else if (ship_board.getpointat(shot) == 'C')
  {
    ship_board.changepointat(shot, 'X'); //same as above
    ship_healths[3]--;
    return true;
  }
  else if (ship_board.getpointat(shot) == 'F')
  {
    ship_board.changepointat(shot, 'X');
    ship_healths[0]--;
    return true;
  }
  else if (ship_board.getpointat(shot) == 'S')
  {
    ship_board.changepointat(shot, 'X');
    ship_healths[2]--;
    return true;
  }
  else if (ship_board.getpointat(shot) == 'D')
  {
    ship_board.changepointat(shot, 'X');
    ship_healths[1]--;
    return true;
  }
  return false;
}

bool AI::isSunk(){
  if (getShipsRemaining() == 0) return true;
  else return false;
}

int AI::getShipsRemaining(){
  int ships_remaining = 0;
  for (int i = 0; i < num_ships; i++) if (ship_healths[i] > 0) ships_remaining++;
  return ships_remaining;
}
