using namespace std;
#include "Book.h"
#include<iostream>
#include<cstring>

Book::Book(){}

Book::Book(char* name,char* author,int count){
	strcpy(this->name,name);
	strcpy(this->author,author);
	this->count = count;
}

ostream& operator<< (ostream& os, const Book& obj) {
    os<<"name: "<<obj.name<<" | author: "<<obj.author<<" | count: "<< obj.count<<endl;
    return os;
}

Book Book::input(){
	cout<<"Enter name:";
	cin>>this->name;
	cout<<"Enter Author:";
	cin>>this->author;
	cout<<"Enter Count:";
	cin>>this->count;

	return *this;
}

char* Book::getName(){
	return name;
}

char* Book::getAuthor(){
	return author;
}

void Book::setCount(int newCount){
	this->count = newCount;
}

int Book::getCount(){
	return count;
}

bool Book::operator==(const Book &rhs){
	return strcmp(this->name,rhs.name) == 0;
}
