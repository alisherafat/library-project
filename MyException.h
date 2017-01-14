#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
#include <exception>

using namespace std;
class MyException :public exception{
	private:
		string message;
	public:
		MyException(string message);
		string getMessage();
		 ~MyException() throw() {}
		const char* what() const throw() { return message.c_str(); }
};

#endif
