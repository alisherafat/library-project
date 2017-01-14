#ifndef BORROW_H
#define BORROW_H
#include "Member.h"
#include "Book.h"

class Borrow{
	private:
		Member member;
		Book book;
	
	public:
		Borrow();
		Borrow(Member member,Book book);
		friend ostream& operator<< (ostream& stream, const Borrow& book);
		Member& getMember();
		Book& getBook();
};

#endif
