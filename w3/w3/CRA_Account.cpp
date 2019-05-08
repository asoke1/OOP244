/*Name        : Abiodun Oke
 * Date        : 2018/10/01
 * **********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;


namespace sict
{



	void CRA_Account::set(int year, double balance)
	{
		if (isValidSin(m_sin) && m_numYrs < max_yrs)
		{
			m_taxYrs[m_numYrs] = year;
			m_balDue[m_numYrs] = balance;
			m_numYrs++;
		}
	}

	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		if (sin >= min_sin && sin <= max_sin && isValidSin(sin) && familyName[0] != '\0' && givenName[0] != '\0')
		{
			strncpy(m_fname, familyName, max_name_length);
			strncpy(m_gname, givenName, max_name_length);
			m_fname[max_name_length] = '\0';
			m_gname[max_name_length] = '\0';
			m_sin = sin;
			m_numYrs = 0;
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
			for (int i = 0; i < m_numYrs; i++)
			{
				if (m_taxYrs[i] == 0)
					break;
				else
				{
					cout.precision(2);
					if (m_balDue[i] > 2)
					{
						cout.setf(ios::fixed);
						cout << "Year (" << m_taxYrs[i] << ") balance owing: " << m_balDue[i] << endl;
					}
					else if (m_balDue[i] < -2)
					{
						cout.setf(ios::fixed);
						cout << "Year (" << m_taxYrs[i] << ") refund due: " << -1 * m_balDue[i] << endl;
					}
					else
					{
						cout << "Year (" << m_taxYrs[i] << ") No balance owing or refund due!" << endl;
					}
				}
				cout.unsetf(ios::fixed);
			}

		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	bool CRA_Account::isValidSin(int sin) const
	{

		int sum = 0;

		int evens[4] = { (((sin / 10) % 10) * 2), (((sin / 1000) % 10) * 2), (((sin / 100000) % 10) * 2), (((sin / 10000000) % 10) * 2) };
		int odds[4] = { (((sin / 100) % 10)), (((sin / 10000) % 10)), (((sin / 1000000) % 10)), (((sin / 100000000) % 10)) };

		for (int i = 0; i < 4; i++)
		{
			sum += ((((evens[i] / 1) % 10) + ((evens[i] / 10) % 10)));
			sum += odds[i];
		}

		int upIntTen = ((sum + 9) / 10) * 10;

		if (((upIntTen - sum) == (sin / 1) % 10) && sin >= min_sin && sin <= max_sin)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

}
