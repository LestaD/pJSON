﻿#include <string>
#include <vector>

namespace LESTAD {

namespace JSON {

#ifdef LESTAD_INT_TYPE_LONGLONG
	typedef long long int int_j;
#elseif defined (LESTAD_INT_TYPE_LONG)
	typedef long int int_j;
#elseif defined (LESTAD_INT_TYPE_SHORT)
	typedef short int int_j;
#else
	typedef int int_j;
#endif

class Value {
	
	enum Type {
		T_NULL = 0,
		T_INT,
		T_DOUBLE,
		T_STRING,
		T_BOOLEAN,
		T_ARRAY,
		T_OBJECT,

		T_UNDEFINED = -1
	};

public:
	Value();
	Value(Value *copy);
	Value(Value &copy);
	Value(int_j val);
	Value(const char* val);
	Value(std::string val);
	Value(double val);
	Value(bool val);

	static Value* Array();
	static Value* Object();

	~Value();

	Type getType();
	const char* getTypeString();

	bool isEmpty();
	bool isNull();
	bool isInt();
	bool isDouble();
	bool isFloat();
	bool isBool();
	bool isString();
	bool isArray();
	bool isObject();

	int_j		getInt();
	double		getDouble();
	float		getFloat();
	bool		getBool();
	std::string	getString();

	Value*	set(Value *val);
	Value*	set(Value val);
	Value*	set(int_j val);
	Value*	set(double val);
	Value*	set(bool val);
	Value*	set(const char *val);
	Value*	set(std::string val);

	Value*	setNull();


	Value*	toArray();
	Value*	toObject();
	Value*	get(int_j index);
	Value*	get(const char *key);
	Value*	get(std::string key);

	Value*	set(const char *key, Value *val);
	Value*	set(std::string key, Value *val);

	Value*	push(Value *val);

	int_j	length();


protected:
	void nullinit();

	void convertToInt();
	void convertToDouble();
	void convertToBool();
	void convertToString();

	Value(Type typeflag);

private:
	
	int_j				m_Int;
	double				m_Double;
	bool				m_Bool;
	std::string			m_String;
	std::vector<Value*>	m_Array;

	Type m_TypeFlag;

};
}
}