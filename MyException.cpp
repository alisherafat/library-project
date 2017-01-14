#include "MyException.h"
using namespace std;
MyException::MyException(string message):exception(){
	this->message = message;
}

string MyException::getMessage(){
	return message;
}
