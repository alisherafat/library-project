#include "Person.h"
#include <cstring>

Person::Person(){
}

Person::Person(char* name,char* lastname,MyDate birthDate){
	strcpy(this->name,name);
	this->birthDate = birthDate;
}

char* Person::getName(){
	return name;
}

char* Person::getLastname(){
	return lastname;
}

Person Person::input(){
	cout<<"Enter firstname:";
	cin>>this->name;
	cout<<"Enter lastname: ";
	cin>>this->lastname;
	cout<<" *** Birth Date *** " <<endl;
	birthDate.input();
}

ostream& operator<< (ostream& os, const Person& obj) {
    os<<"name: "<<obj.name<<" | lastname: "<<obj.lastname<<" | birth date: "<< obj.birthDate<<endl;
    return os;
}

