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

        void placeShips();

        bool Move();
        void easyMove();
        void mediumMove();
        void hardMove();

        void addCoords(string c);
		
	private:
		int difficulty;
                int listSize;
                vector<string> m_coordsList;

};

#endif
