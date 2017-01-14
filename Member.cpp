
#include "Member.h"
#include<iostream>
#include <cstring>

Member::Member():Person(){}

Member::Member(char* name,char* lastname,MyDate birthDate,MyDate memberDate):Person(name,lastname,birthDate){
	this->memberDate = memberDate;	
}

Member Member::input(){
	Person::input();
	cout<<" *** Membership Date *** "<<endl;
	memberDate.input();
	return *this;
}

bool Member::operator==(const Member &rhs){
	return (strcmp(this->name,rhs.name) == 0 && strcmp(this->lastname,rhs.lastname) == 0);
}

MyDate Member::getMemberDate(){
	return memberDate;
}



ostream& operator<< (ostream& os, const Member& obj) {
    os<<"name: "<<obj.name<<" | lastname: "<<obj.lastname<<" | birth date: "<< obj.birthDate<<endl;
    os<<"Membership date: " << obj.memberDate;
    return os;
}
