# pJSON
Work with JSON values from C++

## EXAMPLES

### Create and initialize value
```c++
#include <Value.h>
using namespace LESTAD::JSON;

// NULL
Value *val = new Value();

// Base
Value *vint = new Value(12);
Value *vfloat = new Value(56.154);
Value *vbool = new Value(true);

// String
Value *vstr = new Value("hello");
Value *vstdstr = new Value(std::string("world"));

// Array & Object
Value *varr = Value::Array();
Value *vobj = Value::Object();

```

### Check type and get value from object
```c++
val->isNull();
vfloat->isFloat(); // or ->isDouble();
vbool->isBool();
// ...

int a = vint->getInt();
float b = vfloat->getFloat();
double c = vfloat->getDouble();
const char* st = vstr->getString();
if (vbool->getBool()) {
  st = vstdstr->getString();
}

// string length and array size
int size = vstr->length();

// Struct in Value.h
Value::Type t = vfloat->getType();

if (vint->getType() == T_INT) {
  // ... do
}

// and get string (like "typeof" in JavaScript)
char* type = vfloat->getTypeString();
```

### Work with array
```c++
// insert at the end
varr->push(new Value(553));
varr->push(vfloat)
  ->push(vstr)
  ->push(vint);

for( int i = 0; i < varr->length(); i++) {
  cout << varr->get(i)->getTypeString() << " : " << varr->get(i)->getString() << endl;
}

// integer : 553
// float : 56.154
// string : hello
// integer : 12

```

### And as object
```c++
#include <iostream>
#include "Value.h"
#include "Printeger.h"
#include "JsonPrinter.h"

using namespace std;
using namespace LESTAD::JSON;

int main() {
	Value *root = new Value();
	root->push("name", new Value("LestaD"))
		->push("surname", new Value("Zeix"))
		->push("age", new Value(20))
		->push("nation", new Value("russian"))
		->push("male", new Value(true))
		->push("level", new Value(77.4));

	Value *mine = Value::Object();
	mine->push("w", new Value("speed"))
		->push("t", new Value("flash"));

	Value *internals = Value::Array();
	internals->push(new Value("mind"))
		->push(new Value("cute"))
		->push(new Value("clever"));
	internals->push(mine);

	Value *skills = Value::Object();
	skills->push("fast", new Value(6))
		->push("look", new Value(8));

	root->push("skills", skills)
		->push("internals", internals);

	Printeger *printer = new Printeger();
	printer->set(root);
	printer->set(new JsonPrinter(true));
	cout << printer->print() << endl;
    
	return 0;
}
```
equals:
```json
{
  "name": "LestaD",
  "surname": "Zeix",
  "age": 20,
  "nation": "russian",
  "male": true,
  "skills": {
    "fast": 6,
    "look": 8
  },
  "internals": ["mind", "cute", "clever", {
	   "t": "flash",
	   "w": "speed"
  }]
}
```

And convert to .ini:
```c++
#include "IniWriter.h"

// ...

writer->set(new LESTAD::BASE::IniWriter());
cout << writer->print() << endl;

```
```ini
name = "LestaD"
surname = "Zeix"
age = 20
nation = "russian"
male = true
internals = "mind","clever","cute"

internals[3]
t = "flash"
w = "speed"

[skills]
fast = 6
look = 8
```

