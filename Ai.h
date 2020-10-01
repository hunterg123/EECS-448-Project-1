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
                bool placer(char direction, int row, int col, int size, char shipType); // helper function to test whether ships can be placed

                string Move();

                void printBoard();

                void getCoords(vector<string> coords); // Function to get coords from player class
                void printCoords();

                string getShotCoord();
								string getShipSunk(string shot);
								void markHit(string shot); // mark 'X' over Ai's ship to indicate Ai was hit by player


	private:
                /**
                * @pre: none
                * @post: Shoots at a coordinate from the player, brought into ai class using getCoords(vector<string> coords)
                * @return: Returns a string coordinate to shoot at, i.e. A1, A2...
                **/
                string hardMove();
                string easyMove();
                string mediumMove();
                string getOrthogonalMove(int row, int col); // helper function for medium move, will check if there is a spot orthogonal to a hit that is another ship

                int difficulty;
                int ship_healths[5] = {0, 0, 0, 0, 0};
                int num_ships;

                Boards ship_board;
                Boards shoot_board;

                vector<string> m_coordsList; // list of coordinates to be shot at
};

#endif
