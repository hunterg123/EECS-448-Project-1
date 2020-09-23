#ifndef AI_H
#define AI_H

#include "Boards.h"
#include "Player.h"
#include <string>

class AI
{
	public:
			Player* computer;
        AI(int my_difficulty);
        ~AI();
				int shipsRemaining();
        void placeShips(int NumofShip);
				void isHit();
        bool Move();
        void easyMove();
        void mediumMove();
        void hardMove();


	private:
		int difficulty;
		int shipNum;
		int NumofshipsRemaining;
		std::string ship_row;
		std::string ship_col;
		std::string ship_coord1;
		std::string ship_coord2;

};

#endif
