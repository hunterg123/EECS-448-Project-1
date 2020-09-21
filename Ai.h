#ifndef AI_H
#define AI_H

#include "Boards.h"

class AI
{
	public:
        AI(int my_difficulty);
        ~AI();

        void placeShips();

        bool Move();
        void easyMove();
        void mediumMove();
        void hardMove();

		
	private:
		int difficulty;

};

#endif
