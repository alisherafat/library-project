#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "Member.h"
#include "Book.h"
#include "Borrow.h"

using namespace std;

void displayMenu();
void addBook();
void addMember();
void borrowBook();
void returnBook();
int searchBook(char* name);
int searchMember(char* name,char* lastname);
int searchBorrow(Member &m,Book &b);
/*
*/
void readDataFromFile();
void writeDataToFile();

vector<Member> members;
vector<Book> books;
vector<Borrow> borrows;
	
	
int main(int argc, char** argv) {
	
	
	int option;
	displayMenu();
	readDataFromFile();
	
	do{
		cout<<endl<< "choose option:";
		cin>>option;
		switch(option){
			case 1:{
				addBook();
				break;
			}
			case 2:{
				addMember();
				break;
			}
			case 3:{
				char name[30];
				cout<<"Enter name to find book:";
				cin>>name;
				int index = searchBook(name);
				if(index>-1){
					cout<< "Book found -> " << books[index];
				}else{
					cout<< "Book not found!";
				}
				break;
			}
			case 4: {
				char name[30],lastname[30];
				cout<<"Enter member name to find:";
				cin>>name;
				cout<<"Enter lastname:";
				cin>>lastname;
				int index = searchMember(name,lastname);
				if(index>-1){
					cout<< "Member found -> " << members[index];
				}else{
					cout<< "Member not found!";
				}
				break;
			}
			case 5:{
				borrowBook();
				break;
			}
			case 6:{
				returnBook();
				break;
			}
		}
	}while(option !=9);
	
	
    writeDataToFile();
	return 0;
}

void addBook(){
	Book b1;
	b1.input();
	int index = searchBook(b1.getName());
	if(index>-1){
		int lastCount = books[index].getCount();
		int newCount = lastCount + b1.getCount();
		books[index].setCount(newCount);
		cout<<"this book already exists!  count: "<<newCount<<endl;
		return;
	}
	books.push_back(b1);
	cout<<"Book added successfully."<<endl;
}
void addMember(){
	Member temp;
	temp.input();
	int index = searchMember(temp.getName(),temp.getLastname());
	if(index>-1){
		cout<<"this user is already a member!"<<endl;
		return;
	}
	members.push_back(temp);
	cout<<"Member joined successfully."<<endl;
}

int searchBook(char* name){
	for(int i = 0;i<books.size();i++){
		if(strcmp(books[i].getName(), name)==0){
			return i;
		}
	}
	return -1;
}

int searchMember(char* name,char* lastname){
	for(int i = 0;i<members.size();i++){
		if(strcmp(members[i].getName(), name)==0 && strcmp(members[i].getLastname(), lastname)==0){
			return i;
		}
	}
	return -1;
}

int searchBorrow(Member &m,Book &b){
	for(int i = 0;i<borrows.size();i++){
		if(borrows[i].getMember() == m && borrows[i].getBook() == b){
			return i;
		}
	}
	return -1;
}

void borrowBook(){
	char name[30],lastname[30],book[30];
	cout<<"member name: ";
	cin>>name;
	cout<<"lastname: " ;
	cin>>lastname;
	int mindex = searchMember(name,lastname);
	if(mindex < 0){
		cout<<"Oops! member not found...."<<endl;
		return;
	}
	
	cout<<"book name: ";
	cin>>book;
	int bindex = searchBook(book);
	if(bindex<0){
		cout<<"there is no book with this name in libarary!"<<endl;
		return;
	}
	
	if( books[bindex].getCount() < 1){
		cout<<"Sorry! book count is 0"<<endl;
		return;
	}
	
	books[bindex].setCount( books[bindex].getCount() - 1);
	 
	Borrow temp(members[mindex],books[bindex]);
	borrows.push_back(temp);
	cout<<"borrowed successfully..." <<endl;
	cout<<temp;
}

void returnBook(){
	char name[30],lastname[30],book[30];
	cout<<"member name: ";
	cin>>name;
	cout<<"lastname: " ;
	cin>>lastname;
	int mindex = searchMember(name,lastname);
	if(mindex < 0){
		cout<<"Oops! member not found...."<<endl;
		return;
	}
	
	cout<<"book name: ";
	cin>>book;
	int bindex = searchBook(book);
	if(bindex<0){
		cout<<"there is no book with this name in libarary!"<<endl;
		return;
	}
	
	int brindex = searchBorrow(members[mindex],books[bindex]);
	if(brindex<0){
		cout<<"this member has n't borrowed this book before!!"<<endl;
		return;
	}
	
	books[bindex].setCount( books[bindex].getCount() + 1);
	 
	borrows.erase(borrows.begin() + brindex);
	cout<<"book returned successfully..." <<endl;
}

void readDataFromFile(){
	cout<<endl<<endl<<"***** reading data from file *****"<<endl;
	
	size_t size1 = 0;
	ifstream fin1("books.dat", ios::in | ios::binary);
	if(fin1){
		fin1.read((char*)&size1, sizeof(size1));
		books.resize(size1);
 		fin1.read((char*)&books[0], books.size() * sizeof(Book));
 		cout<< "\t" << books.size() << " books loaded"<<endl;
		fin1.close();
	}
	
	size_t size2 = 0;
	ifstream fin2("members.dat", ios::in | ios::binary);
	if(fin2){
		fin2.read((char*)&size2, sizeof(size2));
		members.resize(size2);
 		fin2.read((char*)&members[0], members.size() * sizeof(Member));
 		cout<< "\t" << members.size() << " members loaded"<<endl;
		fin2.close();
	}

	size_t size3 = 0;
	ifstream fin3("borrows.dat", ios::in | ios::binary);
	if(fin3){
		fin3.read((char*)&size3, sizeof(size3));
		borrows.resize(size2);
 		fin3.read((char*)&borrows[0], borrows.size() * sizeof(Borrow));
 		cout<< "\t" << borrows.size() << " borrows loaded"<<endl;
		fin3.close();
	}
	
	cout<<endl<< "      ******************";
}

void writeDataToFile(){
	cout<<"writing data to file..."<<endl;
	
	ofstream f1out("books.dat", ios::out | ios::binary);
	size_t size1 = books.size();
 	f1out.write((char*)&size1, sizeof(size1));
 	f1out.write((char*)&books[0], books.size() * sizeof(Book));
 	f1out.close();
 	cout<<books.size() << " books saved..."<<endl;
 	
 	
	ofstream f2("members.dat", ios::out | ios::binary);
	size_t size2 = members.size();
 	f2.write((char*)&size2, sizeof(size2));
 	f2.write((char*)&members[0], members.size() * sizeof(Member));
 	f2.close();
 	cout<<members.size() << " members saved..."<<endl;	
 	
 	remove("borrows.dat");
 	if(borrows.size()<1){
 		return;
	}
 	ofstream f3("borrows.dat", ios::out | ios::binary);
	size_t size3 = borrows.size();
 	f3.write((char*)&size3, sizeof(size3));
 	f3.write((char*)&borrows[0], borrows.size() * sizeof(Borrow));
 	f3.close();
 	cout<<borrows.size() << " borrows saved..."<<endl;
  	
}
void displayMenu(){
	cout<<"1: Add Book"<< endl << "2: Add Member"<<endl<<"3: Search Book"<<endl;
	cout<<"4: Search Member"<<endl<<"5: Borrow Book"<<endl<<"6: Return Book"<<endl;
	cout<<"9: Exit";
}
