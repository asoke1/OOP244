/**********************************************************
 * Name        : Abiodun Stephen Oke
 * Date        : 2018/09/27
 **********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account
	{
		char m_fname[max_name_length + 1];
		char m_gname[max_name_length + 1];
		long long m_sin;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

	};



}
#endif // !SICT_CRA_ACCOUNT_H

