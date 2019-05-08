/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 20-SEP-2018
// Author Abiodun Oke
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// the sict namespace
namespace sict {


	// definition for display(...) 
	void display(const Kingdom& obj)
	{
		//KINGDOM_NAME, population POPULATION<ENDL>
		cout << obj.m_name << ", population " << obj.m_population << endl;
	}

}