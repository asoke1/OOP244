/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H




// sict namespace
namespace sict {

	// define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
};

		// declare the function display(...),
		//         also in the sict namespace
	void display(const Kingdom&);
	
}
#endif // ! SICT_KINGDOM_H