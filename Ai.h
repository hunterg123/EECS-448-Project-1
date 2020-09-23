#ifndef AI_H
#define AI_H

#include "Boards.h"
#include <string>
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

        void setNumCoords(int num); // sets the number of coordinates in play
        void setCoords(string c);
		
	private:
                void coordsList(int size); // Initialize Coordinate list
		int difficulty;
                int listSize;
                string* m_coordsList;
                int m_numCoords;

};

#endif
