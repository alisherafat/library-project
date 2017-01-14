#include "MyDate.h"
#include "MyException.h"
using namespace std;

MyDate::MyDate(){}

MyDate::MyDate(int year,int month,int day){
	setYear(year);
	setMonth(month);
	setDay(day);
}

void MyDate::setYear(int year){
	if(year<1000 || year>2500){
		throw MyException("Year is not in normal range!"); 
	}
	this->year = year;	
}

void MyDate::setMonth(int month){
	if(month <1 || month>12){
		throw MyException("month is not in normal range!"); 
	}
	this->month = month;
}

void MyDate::setDay(int day){
	if(day <1 || day>31){
		throw MyException("day is not in normal range!"); 
	}
	this->day = day;		
}

MyDate MyDate::input(){
	int year,month,day;
	cout<<"Enter year:";
	cin>>year;
	setYear(year);
	
	cout<<"Enter month:";
	cin>>month;
	setMonth(month);
	
	cout<<"Enter day:";
	cin>>day;
	setDay(day);
	
	return *this;
}

ostream& operator<< (ostream& os, const MyDate& obj) {
    os<<obj.year<<"-"<<obj.month<<"-"<< obj.day<<endl;
    return os;
}

