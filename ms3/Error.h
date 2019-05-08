
// Final Project Milestone 2
//
// Version 1.0
// Date        : 2018-11-07
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_ERROR_H
#define AID_ERROR_H
#include <iostream>
namespace aid
{
	class Error
	{
		char* mmessage;

	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
		friend std::ostream& operator<<(std::ostream&, Error&);

	};
}


#endif // !AID_ERROR_H
