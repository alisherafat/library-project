#include "Borrow.h"

Borrow::Borrow(){}

Borrow::Borrow(Member member,Book book){
	this->member= member;
	this->book = book;
}

ostream& operator<< (ostream& os, const Borrow& obj) {
    os<<obj.member<<endl<<obj.book;
    return os;
}

Member& Borrow::getMember(){
	return member; 
}

Book& Borrow::getBook(){
	return book;
}
