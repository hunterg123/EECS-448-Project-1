#ifndef SPECIAL_SHOT_H
#define SPECIAL_SHOT_H

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
	SpecialShot();
	~SpecialShot();

	void acquire(int shotType);
	void deplete(int shotType);
	bool inArsenal();

};
#endif
