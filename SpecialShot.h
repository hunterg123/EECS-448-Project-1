#define SPECIAL_SHOT_H
#ifndef SPECIAL_SHOT_H

class SpecialShot
{
	private:
	int m_double;
	int m_triple;
	int m_quad;
	int m_quint;
	int m_sext;

	void menu();

	public:
	void acquire(int shotType);
	void deplete(int shotType);

};
#endif
