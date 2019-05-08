/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/11
**********************************************************/

// insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
//	continue the namespace
namespace sict
{
	// implement the default constructor
	Fraction::Fraction() {
		setEmpty();
	}

	// implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator)
	{
		if (numerator >= 0 && denominator > 0)
		{
			m_num = numerator;
			m_denom = denominator;
			reduce();
		}
		else {
			setEmpty();
		}
	}

	



	// implement the max query
	int Fraction::max() const
	{
		return (m_num > m_denom ? m_num : m_denom);
	}
	// implement the min query
	int Fraction::min() const
	{
		return (m_num < m_denom ? m_num : m_denom);
	}

	// implement the reduce modifier
	void Fraction::reduce()
	{
		int temp = gcd();
		m_num /= temp;
		m_denom /= temp;
	}
	// implement the display query
	void Fraction::display() const
	{
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (m_denom == 1)
		{
			cout << m_num;
		}
		else {
			cout << m_num << "/" << m_denom;
		}
		
		
	}
	
	// implement the isEmpty query
bool Fraction::isEmpty() const
	{
	return (m_num == 0 && m_denom == 0) ? true : false;
	}
	
	// implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) const
	{
		Fraction result;
		if (isEmpty() == false && rhs.isEmpty() == false)
		{
			result.m_denom = m_denom * rhs.m_denom;
			result.m_num = m_num * rhs.m_denom + rhs.m_num * m_denom;
			result.reduce();
		}
		return result;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	// set object to a safe empty state
	void Fraction::setEmpty()
	{
		m_num = 0;
		m_denom = 0;
	}

}
