/**********************************************************
* File        : SuperHero.h
* Name        : Abiodun Oke
* Workshop	  : Home7 
* Date        : 2018-11-12
**********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero 
	{
		int msupAttBonus;
		int msupDef;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defend);
		int attackStrength() const;
		int defend() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}
#endif // !SICT_SUPERHERO_H


