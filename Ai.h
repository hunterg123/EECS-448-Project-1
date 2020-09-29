#ifndef AI_H
#define AI_H

#include "Boards.h"
#include <string>
#include <vector>
using namespace std;

class AI
{
	public:
                AI(int my_difficulty, int ships);
                ~AI();
                
                char getShipType(int size); // helper function to figure out which kind of ship the AI needs to place based on its size
                int getShipIndex(char type); /// helper function that will return the index of the ship in the ship_healths array based on its character type
                int getShipsRemaining();
                bool isHit(std::string shot);
                bool isSunk(std::string shot);
                void placeShips(); // Places AI ships
                void printShootBoard();
                void printShipBoard();
                void markShot(std::string shot, bool hit);
                void addCoords(string c);
                bool placer(char direction, int row, int col, int size, char shipType); // helper function to test whether ships can be placed

                string Move();

                void printBoard();

                void getCoords(vector<string> coords); // Function to get coords from player class
                void printCoords();

                string getShotCoord();


	private:
                string hardMove();
                std::string easyMove();
                std::string mediumMove();
                
                int difficulty;
                int ship_healths[5] = {0, 0, 0, 0, 0};
                int num_ships;

                Boards ship_board;
                Boards shoot_board;

                vector<string> m_coordsList; // list of coordinates to be shot at
};

#endif
