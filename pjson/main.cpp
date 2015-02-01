#include <iostream>
#include "Value.h"

using namespace std;
using namespace JSON;


int main (int argc, char *argv[])
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);


	Value *val = new Value();
	cout << (val->isNull() ? "null" : "any") << endl;

	Value *vint = new Value(12);
	Value *vfl = new Value(56.154);
	Value *vbl = new Value(1912283.1);

	cout << vint->getFloat() << endl;
	cout << vfl->set(true)->getFloat() << " - " << (vfl->getBool() ? "true" : "false") << endl;
	cout << vbl->getInt() << " - " << vbl->getFloat() <<" - " << vbl->getString() << endl;

	Value *arr = Value::Array();
	arr->push(vbl);
	arr->push(vfl);
	cout << arr->getTypeString() << ": " << arr->length() << endl;

	cout << "Hello world!" << endl;
	
	return 0;
}

