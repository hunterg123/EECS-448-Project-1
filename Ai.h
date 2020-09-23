#ifndef AI_H
#define AI_H

#include "Boards.h"
#include <string>
#include <vector>
using namespace std;

class AI
{
	public:
        AI(int my_difficulty);
        ~AI();
        bool placer(char direction, int row, int col, int size, char shipType); // helper function to test whether ships can be placed
        void placeShips(int num_ships); // Places AI ships
        char getShipType(int size); // helper function to figure out which kind of ship the AI needs to place

        void Move();
        void easyMove();
        void mediumMove();
        void hardMove();

        void printBoard();

        void addCoords(string c);

	private:
		int difficulty;
                Boards ship_board;
                Boards shoot_board;
                vector<string> m_coordsList;


};

#endif
