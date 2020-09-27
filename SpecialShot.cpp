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

bool SpecialShot::inArsenal(int shotType)
{
	switch(shotType)
	{
		case 0:
			if(m_double || m_triple || m_quad || m_quint || m_sext) //any special shot
			{
				return true;
			}
			break;

		case 1:
			return true;

		case 2:
			if(m_double){ return true; }
			break;

		case 3:
			if(m_triple){ return true; }
			break;

		case 4:
			if(m_quad){ return true; }
			break;

		case 5:
			if(m_quint){ return true; }
			break;

		case 6:
			if(m_sext){ return true; }
			break;
	}

	return false;
}
