#include "SpecialShot.h"
#include <iostream>
#include <string>

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

void SpecialShot::acquire(int shotType)
{
	switch(shotType)
	{
		case 2: 
			std::cout << "\nA DOUBLE shot was captured!!!\n";
			m_double++;
			break;

		case 3:
			std::cout << "\nA TRIPLE shot was captured!!!\n";
			m_triple++;
			break;

		case 4:
			std::cout << "\nA QUADRUPLE shot was captured!!!\n";
			m_quad++;
			break;

		case 5:
			std::cout << "\nA QUINTUPLE shot was captured!!!\n";
			m_quint++;
			break;

		case 6:
			std::cout << "\nA SEXTUPLE shot was captured!!!\n";
			m_sext++;
			break;
	}
}

void SpecialShot::deplete(int shotType)
{
	switch(shotType)
	{
		case 2:
			m_double--;
			std::cout << "\nDOUBLE shot launched!!!\n";
			break;
		
		case 3:
			m_triple--;
			std::cout << "\nTRIPLE shot launched!!!\n";
			break;

		case 4:
			m_quad--;
			std::cout << "\nQUADRUPLE shot launched!!!\n";
			break;

		case 5:
			m_quint--;
			std::cout << "\nQUINTUPLE shot launched!!!\n";
			break;

		case 6:
			m_sext--;
			std::cout << "\nSEXTUPLE shot launched!!!\n";
			break;
	}
}

void SpecialShot::menu()
{
	std::cout << "\n=============================\n";
	std::cout << "---------{ ARSENAL }---------\n";
	std::cout << "1) Single: infinite\n";
	std::cout << "2) Double: " << m_double << "\n";
	std::cout << "3) Triple: " << m_triple << "\n";
	std::cout << "4) Quadruple: " << m_quad << "\n";
	std::cout << "5) Quintuple: " << m_quint << "\n";
	std::cout << "6) Sextuple: " << m_sext << "\n";
	std::cout << "=============================\n";
}
