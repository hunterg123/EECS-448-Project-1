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
        bool placer(char direction, int row, int col, int size, char shipType); // helper function to test whether ships can be placed
        void placeShips(); // Places AI ships
        char getShipType(int size); // helper function to figure out which kind of ship the AI needs to place

        void Move();
        std::string easyMove();
        void mediumMove();
        void hardMove();

        void printBoard();
	bool isHit(std::string shot);
	bool isSunk();
	int getShipsRemaining();

        void addCoords(string c); // Function to add coords to the list when passed in by user

	private:
	int difficulty;
        int ship_healths[5] = {0, 0, 0, 0, 0};
        int num_ships;

        Boards ship_board;
        Boards shoot_board;
        void shootCoords(vector<string> coords); // Function to update the coords list after a shot

        vector<string> m_coordsList; // list of coordinates to be shot at


};

#endif
