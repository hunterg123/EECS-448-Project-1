/**
 * @author Trey Werr
 * @date 9/7
 * @brief Header file for the Ship class.
 */

#ifndef SHIP_H
#define SHIP_H

#include "ShipInterface.h"

class Ship : public ShipInterface
{
	public:
		/**
		 * Constructor for Ship.
		 * @param length - the length of the Ship, or how many spaces it occupies
		 * @param location - the coordinates of the spaces the Ship occupies on the board
		 */
		Ship(int length, std::string coord1, std::string coord2, std::string name);
			
		/**
		 *  @returns m_length The integer length of the ship
		 */
		int getLength() const { return m_length; }

		/**
		 * 	@param coord A coordinate of form "colrow" (e.g. "A1")
		 *  @returns True if the coord matches one of the ship's coordinates
		 */
		bool isHit(std::string coord);

		/**
		 *  @returns m_hits The number of times the ship has been hit
		 */
		int numHits() const { return m_hits; }

		/**
		 *  @returns True if the number of hits is equivalent to the number of ship coordinates
		 */
		bool isSunk() const;

		/**
		 *  @returns m_coord1 The coordinate of the front of the ship
		 */
		std::string getCoord1() const { return m_coord1; }

		/**
		 *  @returns m_coord2 The coordinate of the back of the ship
		 */
		std::string getCoord2() const { return m_coord2; }

		/**
		 * @return m_name The type of ship it is. Example: "cruiser" or "destroyer".
		 */
		std::string getName() const { return m_name; }

		/**
		 * @param coord A coordinate string of form "colrow" (e.g. "A1")
		 * @return intCoord A pointer to a size 2 array representing the col and row in int format
		 */
		int* stoiCoord(std::string coord);

		/**
		 * @param coord A pointer to a size 2 array representing the col and row in int format
		 * @return strCoord A coordinate string of form "colrow" (e.g. "A1")
		 */
		std::string itosCoord(int* coord);

	private:
		int m_length; // ship length
		std::string m_coord1; // coordinate of front of ship
		std::string m_coord2; // coordinate of back of ship
		std::string m_hitLocations; //coordinates of entire ship
		std::string m_name; //ship name
		int m_hits; // number of times ships been hit
		int intCoord[2]; //coordinates in int format
};

#endif
