/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : lab7
* Date        : 2018-11-08
**********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {

	const int MAX_ROUNDS = 100;
	const int SIZE = 40;
	class Hero
	{
		char mname[SIZE + 1];
		int mhealth;
		int mattack;
	public:
		Hero();
		Hero(const char* name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);


	};

	const Hero& operator*(const Hero& first, const Hero& second);

}

#endif
