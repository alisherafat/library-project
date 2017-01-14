#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
using namespace std;
class MyDate{
	private:
		int year,month,day;
	public:
		MyDate();
		MyDate(int year,int month,int day);
		friend ostream& operator<<(ostream& stream, const MyDate& obj);
		void setYear(int year);
		void setMonth(int month);
		void setDay(int day);
		MyDate input();
};

#endif
