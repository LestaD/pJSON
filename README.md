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
