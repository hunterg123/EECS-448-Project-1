#include "SpecialShot.h"
#include <iostream>

SpecialShot::SpecialShot()
{
	m_double = 0;
	m_triple = 0;
	m_quad = 0;
	m_quint = 0;
	m_sext = 0;
}

SpecialShot::~SpecialShot()
{
}

void SpecialShot::acquire(int shotMultiple)
{
	switch(shotMultiple)
	{
		case 2: 
			std::cout << "A DOUBLE shot was captured!!!\n";
			m_double++;
			break;

		case 3:
			std::cout << "A TRIPLE shot was captured!!!\n";
			m_triple++;
			break;

		case 4:
			std::cout << "A QUADRUPLE shot was captured!!!\n";
			m_quad++;
			break;

		case 5:
			std::cout << "A QUINTUPLE shot was captured!!!\n";
			m_quint++;
			break;

		case 6:
			std::cout << "A SEXTUPLE shot was captured!!!\n";
			m_sext++;
			break;
	}
}
