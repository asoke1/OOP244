/**********************************************************
 * * Name        : Abiodun Oke
 * * Workshop	  : home
 * * Date        : 2018-11-05
 * **********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	const int MAX_CHAR = 20;

	class Contact {
		char mname[MAX_CHAR];
		long long *mphone;
		int mnoOfphone;
		// private member function
		bool isValidPhone(const long long phone) const;
		void init(const Contact& obj);


	public:
		// Constructors

		Contact();
		Contact(const char* name, const long long* phone, int numofphone);
		~Contact();
		Contact(const Contact& obj);
		Contact& operator=(const Contact& obj);
		Contact& operator+=(long long phone);
		// member functions
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_CONTACT_H
