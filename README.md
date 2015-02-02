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
#include "Value.h"
#include "Writer.h"
#include "JsonWriter.h"

using namespace LESTAD::JSON;

int main() {
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
    	
    Writer *writer = new Writer();
    writer->set(new JsonWriter());
    cout << writer->print(root, true) << endl;
    
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
  "internals": ["mind", "cute", "clever"]
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

[skills]
fast = 6
look = 8
```

