/**********************************************************
 * Name        : Abiodun Oke
 * Date        : 2018/09/27
 **********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;


namespace sict
{



	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		if ((sin >= min_sin && sin <= max_sin))
		{
			strncpy(m_fname, familyName, max_name_length);
			strncpy(m_gname, givenName, max_name_length);
			m_fname[max_name_length] = '\0';
			m_gname[max_name_length] = '\0';
			m_sin = sin;
		}
		else {
			m_fname[0] = '\0';
			m_gname[0] = '\0';
			m_sin = 0;
		}
	}

	bool CRA_Account::isEmpty() const
	{
		return ((m_sin < min_sin || m_sin > max_sin || m_sin == 0)) ? true : false;
	}

	void CRA_Account::display() const
	{
		if (!isEmpty())
		{
			cout << "Family Name: " << m_fname << endl;
			cout << "Given Name : " << m_gname << endl;
			cout << "CRA Account: " << m_sin << endl;

		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

}
