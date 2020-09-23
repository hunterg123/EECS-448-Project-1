#include "Ai.h"

AI::AI(int my_difficulty)
{
    difficulty = my_difficulty;
}

<<<<<<< HEAD
AI::~AI()
{

}

bool AI::Move() // Decides which kind of move to make based on difficulty setting
||||||| merged common ancestors
bool AI::Move() // Decides which kind of move to make based on difficulty setting
=======
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

void AI::placeShips(int num_ships)
{
    char directions[4] = {'u', 'd', 'l', 'r'}; // all potential directions

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

void AI::Move() // Decides which kind of move to make based on difficulty setting
>>>>>>> master
{
    if (difficulty == '1') easyMove();
    else if (difficulty == '2') mediumMove();
    else hardMove();
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

void AI::addCoords(string c)
{
    m_coordsList.push_back(c);
}