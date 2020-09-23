#include "Ai.h"


AI::AI(int my_difficulty)
{
    difficulty = my_difficulty;
}

AI::~AI()
{
    delete[] m_coordsList; // Clean up memory taken
}

bool AI::Move() // Decides which kind of move to make based on difficulty setting
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


void AI::setNumCoords(int num)
{
    switch(num)
    {
        case 1: 
            m_numCoords = 1;
            break;
        case 2: 
            m_numCoords = 3;
            break;
        case 3:
            m_numCoords = 6;
            break;
        case 4:
            m_numCoords = 10;
            break;
        case 5:
            m_numCoords = 15;
            break;
        default:
            m_numCoords = 1;
            break;
    }
    coordsList(m_numCoords);
}

void AI::setCoords(string c)
{
    
}

void AI::coordsList(int size) 
{
    m_coordsList = new string[size];
    for(int i = 0; i < size; i++)
    {
        m_coordsList[i] = "";
    }
}