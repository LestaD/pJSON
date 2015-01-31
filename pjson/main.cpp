#include <iostream>
#include "Value.h"

using namespace std;
using namespace JSON;


int main (int argc, char *argv[])
{
	Value *val = new Value();
	cout << (val->isNull() ? "null" : "any") << endl;

	Value *vint = new Value(12);
	Value *vfl = new Value(56.154);
	Value *vbl = new Value(true);

	cout << vint->getFloat() << endl;
	cout << vfl->getDouble() << " - " << (vfl->getBool() ? "true" : "false") << endl;
	cout << vbl->getInt() << " - " << vbl->getFloat() << " - " << vbl->getString() << endl;

	cout << "Hello world!" << endl;
	
	return 0;
}

