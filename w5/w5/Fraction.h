//add file header comments here
/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/13
**********************************************************/

//header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// create namespace
namespace sict {
	// define the Fraction class
	class Fraction {
		// declare instance variables 
		int m_num;
		int m_denom;
		// declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		void setEmpty();
	public:
		//declare public member functions
		Fraction();
		Fraction(int numerator, int denominator);

		bool isEmpty() const;
		void display() const;
		// declare operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
	};
}
#endif 

