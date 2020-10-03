/**
 * @author Tyler Rains & Octavio Sosa
 * @date 9/12 & 10/02/20
 * @brief Header file for the Player class.
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "SpecialShot.h"
#include "Boards.h"
#include "Ship.h"
#include <vector>
#include "Ai.h"

class Player
{
    private:
        Boards m_ship_board;            //Contains the player's board where they placed their ships and which one of theirs has been sunk.
        Boards m_shoot_board;           //Contains where the player has shot, hit, or sunk the enemies ships.
        std::string m_player_number;    //Are they player one or player two?
        int m_ships_remaining;          //How many ships the player has remaining.
        vector<string> m_playerCoords;  // list of players coordinates

        int m_bs_remaining; //How many b's characters remain (haven't been sunk)
        int m_cs_remaining; //How many c characters remain
        int m_fs_remaining; //etc.
        int m_ss_remaining; //...
        int m_ds_remaining; //...

				SpecialShot m_SpecialShot; //Encapsulates aspects of the player's special-shots 

        /**
         * 	Checks if the coordinates the user entered to place a ship at is valid or not.
         *  It will be valid if the coordinates were entered in the correct format, is trying to be placed vertical or horizontal (not diagonal),
         *  and if one of their ships is not already occupying that location.
         *  @param ship_coord1 The coordinate for where their ship will begin at.
         *  @param ship_coord2 The coordinate where their ship will end at.
         *  @param ship_size How large the ship will be (sizes vary between 1 and 5).
         *  @returns True if the coordinates are valid, false if they are invalid.
         */
        bool checkValidPlacement(std::string ship_coord1, std::string ship_coord2, int ship_size);

        /**
         * 	Marks the ships location onto the board so that the user can visually see its location.
         *  @param ship Takes in a ship, which will contain within it its' location data.
         *  @post Marks the ships location visually onto the board with the character it is marked as depending on the type of ship it is. For example, 'B' for battleship and 'F' for frigate.
         */
        void markBoard(Ship ship);

        /**
        * @pre: Must be a valid board with ships placed
        * @return: Returns all the coordinates from a board as a vector list
        **/
        vector<string> getCoordinatesFromBoard(); // Get coordinates list from a given board



    public:
      /**
      * @pre: There must exist a valid vector list of coordinates of ships
      * @post: Gets the coordinates of a players' ships
      * @return: Returns the coordinates of the players' ships
      **/
      vector<string> getCoords(); // returns players coords

      /**
         * 	The default constructor for the Player class.
         */
      Player();

      /**
         * 	The destructor for the Player class.
         */
      ~Player();

      /**
         *  Asks the user for the coordinates of where they would like to place their ships.
         *  How many ships and the size of the ships is determined by how many ships they are playing with.
         *  @param number_ships The number of ships the players are playing with.
         *  @param player_number Is the player player number one or player number two.
         *  @post The ships will be placed onto their m_ship_board.
         */
      void placeShips(int number_ships, int player_number);

      /**
         * 	Determines if the user has previously already shot at this location.
         *  @param shot A string containing the coordinates of where the player is attempting to shoot.
         *  @returns True if the player has not previously shot at that location, false if they've already shot and hit or missed.
         */
      bool uniqueShot(std::string shot);

      /**
         *  If the player's shot successfully hits an enemies ship it will be marked as a hit (X), if they miss it's a miss (*).
         *  @param shot The coordinates of where the user shot at.
         *  @param hit A boolean value containing whether or not the shot was a hit (true) or a miss (false).
         *  @post The shot location will be marked as a hit (X) or a miss (*) on the player's m_shoot_board.
         */
      void markShot(std::string shot, bool hit);

      //Connor - made new function to show where the enemy has shot at you and missed
      void markEnemyMiss(std::string shot);

      /**
         * 	Prints out the player's m_shoot_board, which is the locations of where they have shot and what the outcome has been.
         */
      void printShootBoard();

      /**
         * 	Prints out the player's m_ship_board, which is the location of their ships and what their current status are.
         */
      void printShipBoard();

      /**
         * 	Determines whether or not the enemies shot was a hit on one of the player's ships or not.
         *  @param shot The string containing the enemies shot attempt.
         *  @returns True if the enemies shot was successful in hitting a ship, false if not.
         */
      bool isHit(std::string shot);

      /**
         * 	Determines whether or not the shot that just hit the player's ship sunk it or not.
         *  @param shot The string containing the coordinates of the enemies shot.
         *  @returns True if the enemy just sunk one of the player's ships, false if not.
         */
      bool isSunk(std::string shot);

      /**
         * 	@returns How many ships the player has remaining that haven't been sunk.
         */
      int shipsRemaining();

			/**
			   *  
			   *  @returns True if the player has acquired a special-shot
			   */
			bool hasSpecialShot();

			/**
			   *  Prompts the user to select a valid shot-type (number 1-6)
			   *  @returns shotType as an int (e.g. single, double, triple, etc..)
			   */
      int selectShot();

 			/**
				 *  Prompts the user to coordinate their shot, according to a shotType, via a valid pivot coordinate and direction
			   *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
			   *  @returns shotVector A vector of strings which represent the coordinates of each shot
			   */ 
      std::vector<std::string> coordinateShot(int shotType);

 			/**
				 *	Constructs a vector of shot coordinates by moving in a pivotDirection from a pivotCoordinate by shotType number of incremental coordinates
				 *  @pre the inputs must be valid values (i.e. the resulting vector must not be out of range)
			   *  @param pivotCoord A string representing the pivot coordinate of form "colrow"(e.g. "A1")
				 *  @param pivotDirection A char representing the pivot direction (e.g. 'U' for up)
			   *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
			   *  @returns shotVector A vector of strings which represent the coordinates of each shot
			   */
      std::vector<std::string> getShotVector(std::string pivotCoord, char pivotDirection, int shotType);

 			/**
				 *	Gets the most recently sunk ship by full-name	
				 *  @pre ship counter for sunken ship must be assigned a value of 0 to designate sunken status
			   *  @returns ship name of ship that was most recently sunk
			   */
      std::string getShipSunk();

 			/**
				 *	Resets the ship counter of most recently sunken ship to 100
				 *  @pre ship counter for sunken ship must be assigned a value of 0 to designate sunken status
				 *	@post resets the ship counter of the most recently sunken ship to 100
			   */
      void resetShipSunk();

 			/**
				 *	Increments the player's special-shot counter for a particular shot-type based on the ship
				 *		they've just sunk
				 *  @pre The shipSunk must be a ship that was just sunk by the player 
				 *	@post Increments the player's special-shot counter for a particular shot-type based on the ship
				 *		they've just sunk
				 *	@param shipSunk the full-name of a ship that was sunk
			   */
      void acquireSpecialShot(std::string shipSunk);

 			/**
				 *	Decrements the player's special-shot counter for a particular shot-type based on the shotType
				 *		of the special-shot they've just launched
				 *  @pre the shotType must match the special-shot type that the player just launched
				 *	@post Decrements the player's special-shot counter for a particular shot-type based on the shotType
				 *		of the special-shot they've just launched
			   *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
			   */
      void depleteSpecialShot(int shotType);

 			/**
				 *	Validates a coordinate string
			   *  @param coord A coordinate string of form "colrow" (e.g. "A1")
				 * 	@return True if the coordinate string is of correct format and value (i.e. within range)
			   */
      bool validCoord(std::string coord);

 			/**
				 *	Validates a vector of coordinate strings and responds with precise feedback to player 
				 *  @pre the coordinate strings must be of format "colrow" (e.g. "A1")
			   *  @param shotVector A vector of strings which represent the coordinates of one or many shots
				 * 	@return True if the coordinate strings are valid shots
			   */
      bool validateShot(std::vector<std::string> shotVector);

      /**
         *  Asks the user which size of the ship and where they would like to replace their ships.
         *  @param number_ships The number of ships the players are playing with.
         *  @param player_number Is the player, player number one or player number two.
         *  @post The ships will be replaced onto their m_ship_board.
         */
      void replaceShip(int number_ships, int player_number);
      
};
#endif
