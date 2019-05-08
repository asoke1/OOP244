/**********************************************************
* File        : SuperHero.cpp
* Name        : Abiodun Oke
* Workshop	  : Home7
* Date        : 2018-11-12
**********************************************************/

#include <iostream>
#include "SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero() : Hero()
	{
		msupAttBonus = 0;
		msupDef = 0;
	}

	SuperHero::SuperHero(const char * name, int health, int attack, int bonus, int defend) : Hero(name, health, attack)
	{
		if (name != nullptr && name[0] != '\0' && health != 0 && attack != 0)
		{
			Hero(name, health, attack);
			msupAttBonus = bonus;
			msupDef = defend;
		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::attackStrength() const
	{
		return Hero::attackStrength() + msupAttBonus;
	}

	int SuperHero::defend() const
	{
		return msupDef;
	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		// insert return statement here
		cout << "Super Fight! " << first << " vs " << second << " : ";
		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;

		int i = 0;
		while (i < MAX_ROUNDS && A.isAlive() && B.isAlive())
		{
			A -= B.attackStrength() - A.defend();
			B -= A.attackStrength() - B.defend();
			i++;
		}

		bool draw = A.isAlive() && B.isAlive();

		if (draw)
		{
			winner = &first;
		}
		else if (A.isAlive())
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}

		cout << "Winner is " << *winner << " in " << i << " rounds." << endl;

		return *winner;

	}

}
