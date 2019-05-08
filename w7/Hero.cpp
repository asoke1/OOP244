/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : lab7
* Date        : 2018-11-08
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {




	Hero::Hero()
	{
		mname[0] = '\0';
		mhealth = 0;
		mattack = 0;

	}

	Hero::Hero(const char * name, int health, int attack)
	{
		if (name[0] != '\0' && health > 0 && attack > 0)
		{
			mhealth = health;
			mattack = attack;
			strncpy(mname, name, SIZE);
			mname[SIZE] = '\0';
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			mhealth -= attack;

		}
	}

	bool Hero::isAlive() const
	{
		return (mhealth > 0) ? true : false;
	}

	int Hero::attackStrength() const
	{
		return mattack;
	}

	std::ostream & operator<<(std::ostream & os, const Hero& hero)
	{
		if (hero.mname[0] == '\0')
		{
			os << "No hero";
		}
		else {
			os << hero.mname;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		
		Hero a = first;
		Hero b = second;
		const Hero *winner = nullptr;

		int i = 0;
		while (i < MAX_ROUNDS && a.isAlive() && b.isAlive())
		{
			a -= b.attackStrength();
			b -= a.attackStrength();
			i++;
		}
		bool draw;
		if (a.isAlive() && b.isAlive())
		{
			 draw = true;
		}
		else {
			 draw = false;
		}

		if (draw)
		{
			winner = &first;
		}
		else if (a.isAlive())
		{
			 winner = &first;
		}
		else {

			 winner = &second;
		}

		cout << "Winner is " << *winner << " in " << i << " rounds." << endl;

		return *winner;
	}

}

