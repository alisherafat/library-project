#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "MyDate.h"
#include <iostream>

using namespace std;

class Person{
	protected:
		char name[30];
		char lastname[30];
		MyDate birthDate;
		
		
	public:
		Person();
		Person(char* name,char* lastname,MyDate birthDate);
		Person input();
		friend ostream& operator<< (ostream& stream, const Person& obj);
		char* getName();
		char* getLastname();
	
		
};

#endif
