#ifndef AI_H
#define AI_H

#include "Boards.h"
#include <string>
#include <vector>
using namespace std;

class AI
{
	public:
		/**
		* @post: assigns num_ships to ships
						 difficulty to my_difficulty
						 place each ship randomly
		* @param: difficulty, to be assigned to my_difficulty
							ships, to be assigned to num_ships
		**/
    AI(int my_difficulty, int ships);

		/**
  	* @pre: None
  	* @post: None
  	**/
    ~AI();

		/**
		* @post figure out which kind of ship the AI needs to place based on its size
		* @param: size, the size of ship
		* @return: character 'B' if size of ship is 5
							 character 'C' if size of ship is 4
							 character 'S' if size of ship is 3
							 character 'D' if size of ship is 2
							 character 'F' if size of ship is 1
		**/
    char getShipType(int size);

		/**
		* @post: figure out the index of the ship in the ship_healths array based on its character type
		* @param: type, the letter of ship
		* @return: number '4' if letter of ship is 'B'
							 number '3' if letter of ship is 'C'
							 number '2' if letter of ship is 'S'
							 number '1' if letter of ship is 'D'
							 number '0' if letter of ship is 'F'
		**/
    int getShipIndex(char type);

		/**
		* @post: get the number of ship that remain on the board
		* @return: ships_remaining, the number of remaining ship
		**/
    int getShipsRemaining();

		/**
		* @post the ship is hit then mark 'X', is missed then mark '*'
		* @param: shot, the shooting coordinate
		* @return: intrue if hit ship, false otherwise
		**/
    bool isHit(std::string shot);

		/**
  	* @post all ship is sunk
		* @param: shot, the shooting coordinate
  	* @return: intrue if the number of healthy ship equal to 0, false otherwise
  	**/
    bool isSunk(std::string shot);

		/**
		* @post place each ship on the board
		**/
    void placeShips();

		/**
		* @post print AI shooting board
		**/
    void printShootBoard();

		/**
		* @post print AI ship board
		**/
    void printShipBoard();

		/**
		* @post mark 'X' if hit, mark '*' if miss
		* @param: shot, the shooting coordinate
							hit, the status of hit, intrue if hit, otherwise false
		**/
    void markShot(std::string shot, bool hit);

		/**
		* @post all ship is sunk
		* @param: direction, the ship direction
							row, the row coordinate of ship
							col, the col coordinate of ship
							size, the size of ship
							shipType, the letter that ship presented
		* @return: intrue if the ship can be placed, false otherwise
		**/
    bool placer(char direction, int row, int col, int size, char shipType); // helper function to test whether ships can be placed

		/**
		* @post get the hitting coordinate from AI
		* @return: the hitting coordinate
		**/
    string Move();

		/**
		* @post assign coords to m_coordsList from player class
		* @param: coords, coords assigned to be m_coordsList
		**/
    void getCoords(vector<string> coords);

		/**
		* @post get coords at certain position in m_coordsList
		**/
    void printCoords();

		/**
		* @post get the coordinate to shot
		* @return: the coordinate from the back of m_coordsList
		**/
    string getShotCoord();

		/**
		* @post: assign the shipSunk to different name
		* @return: shipSunk, the name of each ship
		**/
		string getShipSunk(string shot);

		/**
		* @post: mark 'X' over Ai's ship to indicate Ai was hit by player
		* @param: shot, the shooting coordinate
		**/
		void markHit(string shot);


	private:
    /**
    * @pre: none
    * @post: Shoots at a coordinate from the player, brought into ai class using getCoords(vector<string> coords)
    * @return: Returns a string coordinate to shoot at, i.e. A1, A2...
    **/
    string hardMove();

		/**
		* @post: shot in a random coordinate
		* @return: shot_coord for shotting
		**/
    string easyMove();

		/**
		* @post: shot in a random coordinate before hitting, shoots at a coordinate from the player after hitting once
		* @return: shot_coord for shotting
		**/
    string mediumMove();

		/**
		* @post: check if there is a spot orthogonal to a hit that is another ship
		* @return: shoot at this orthogonal ship
		**/
    string getOrthogonalMove(int row, int col);

    int difficulty; //difficulty level of the AI representing easy, medium, and hard
    int ship_healths[5] = {0, 0, 0, 0, 0}; //represents the health of each ship
    int num_ships; //the number of ships for the match

    Boards ship_board;
    Boards shoot_board;

    vector<string> m_coordsList; // list of coordinates to be shot at
};

#endif
