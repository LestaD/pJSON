#include <iostream>
#include "Value.h"

using namespace std;
using namespace LESTAD::JSON;

void test1();
void test2();
void test3();

int main (int argc, char *argv[])
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	test3();


	cout << "Hello world!" << endl;
	
	return 0;
}

void test3() {
	Value *v = new Value(1111);
	Value *v2 = new Value(v);
	*v2 += 2;
	cout << v->getInt() << " : " << v2->getInt() <<  endl;
}

void test2()
{
	Value *root = new Value();
	root->push("name", new Value("LestaD"))
		->push("surname", new Value("Zeix"))
		->push("age", new Value(20))
		->push("nation", new Value("russian"))
		->push("male", new Value(true));
	
	Value *internals = Value::Array();
	internals->push(new Value("mind"))
		->push(new Value("cute"))
		->push(new Value("clever"));
	
	Value *skills = Value::Object();
	skills->push("fast", new Value(6))
		->push("look", new Value(8));
	
	root->push("skills", skills)
		->push("internals", internals);
	


}

void test1()
{
	Value *val = new Value();
	cout << (val->isNull() ? "null" : "any") << endl;

	Value *vint = new Value(12);
	Value *vfl = new Value(56.154);
	Value *vbl = new Value(1912283.1);

	cout << vint->getFloat() << endl;
	cout << vfl->set(true)->getFloat() << " - " << (vfl->getBool() ? "true" : "false") << endl;
	cout << vbl->getInt() << " - " << vbl->getFloat() <<" - " << vbl->getString() << endl;

	Value *vstr = new Value("my any string");

	Value *vr = Value::Array();
	vr->push(vbl)
		->push(vfl)
		->push(vint);

	Value *arr = Value::Array();
	arr->push(new Value(1))
		->push(vstr)
		->push(new Value("Irina"))
		->push(vr);
	cout << arr->getTypeString() << ": " << arr->length() << endl;
	for (int_j i = 0; i < arr->length(); i++)
	{
		Value *item = arr->get(i);
		cout << item->getTypeString() << ": " << item->getString() << endl;
	}
	cout << "Test 1 complete!" << endl << endl;
}