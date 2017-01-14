#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class Book{
	private:
		char name[30];
		char author[30];
		int count;
	public:
		Book();
		Book(char* name,char* author, int count);
		friend ostream& operator<< (ostream& stream, const Book& book);
		bool operator==(const Book& rhs);
		Book input();
		char* getName();
		char* getAuthor();
		int getCount();
		void setCount(int newCount);
};

#endif
