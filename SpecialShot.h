/**
 * @author Octavio Sosa
 * @date 10/02/20
 * @brief Header file for the SpecialShot class.
 */

#ifndef SPECIAL_SHOT_H
#define SPECIAL_SHOT_H

class SpecialShot
{
	private:
	int m_double; //counter for double shot
	int m_triple; //counter for triple shot
	int m_quad; //counter for quadruple shot
	int m_quint; //counter for quintuple shot
	int m_sext; //counter for sextuple shot


	public:
	/**
		 * 	The default constructor for the SpecialShot class
		 */
	SpecialShot();

	/**
		 * 	The default destructor for the SpecialShot class.
		 */
	~SpecialShot();

	/**
		 *  Prints the count of all the player's special-shots 
		 */
	void menu();

	/**
		 *	Increments the player's special-shot counter for a particular shot-type 
		 *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
		 */
	void acquire(int shotType);

	/**
		 *	Decrements the player's special-shot counter for a particular shot-type 
		 *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
		 */
	void deplete(int shotType);

	/**
		 *	Determines whether a shotType count is greater than 0
		 *  @param shotType An int representing a shot-type (e.g. single, double, triple, etc..)
		 * 	@returns True if the count of the shotType is greater than 0
		 *		;when shotType is 0, returns true if any shotType count is greater than 0)
		 */
	bool inArsenal(int shotType);

};
#endif
