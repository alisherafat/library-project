#ifndef MEMBER_H
#define MEMBER_H
#include "Person.h"
#include "MyDate.h"
#include <iostream>
class Member : public Person {
	private:
		MyDate memberDate;
	public:
		Member();
		Member(char* name,char* lastname,MyDate birthDate,MyDate memberDate);
		Member input();
		friend std::ostream& operator<< (std::ostream& stream, const Member& member);
		bool operator==(const Member &rhs);
		MyDate getMemberDate();
		
};

#endif
