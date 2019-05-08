//Final Project:  ChequingAccount.h
// Workshop    : lab 9 
// Version 1.0
// Date        : 2018-11-22
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n)
	{
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] > max)
			{
				max = data[i];
			}
		}
		return max;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n)
	{
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}
        
	// sum returns the sum of n items in data
	//    
   template <typename T>
   T sum(const T* data, int n)
   {
	   sum = 0;
	   for (int i = 0; i < n; i++)
	   {
		   sum += data[i];
	   }
	   return sum;
   }
	// average returns the average of n items in data
	//
   template <typename T>
   T average(const T* data, int n)
   {
	   double avg = 0;
	   for (int i = 0; i < n; i++)
	   {
		   avg += data[i];
	   }
	   return avg / n;
   }

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
   template <typename T>
   bool read(std::istream& input, T* data, int n)
   {
	   if (input)
	   {
		   char comma = ',';
		   for (int i = 0; i < n; i++)
		   {
			   input >> comma >> data[i];
		   }
		   return true;
	   }
	   else {
		   return false;
	   }
   }
	// display inserts n items of data into std::cout
	//
   template <typename T>
   void display(const char* name, const T* data, int n)
   {
	   cout.width(20);
	   cout << name;
	   for (int i = 0; i < n; i++)
	   {
		   cout.width(COLUMN_WIDTH);
		   cout << data[i];
	   }
	   cout << endl;
   }

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

