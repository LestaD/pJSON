#include <string>
#include <vector>
#include <map>

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

	typedef std::map<std::string, Value*> Map;
	typedef std::pair<std::string, Value*> Pair;

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
	void kill();

	Type getType() const;
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

	Value*	get(int_j index);
	Value*	get(const char *key);
	Value*	get(std::string key);

	Value*	set(const char *key, Value *val);
	Value*	set(std::string key, Value *val);

	Value*	push(Value *val);
	Value*	push(int_j index, Value *val);
	Value*	push(const char *key, Value* val);

	Value*	remove(int_j index);
	Value*	remove(const char *key);
	Value*	remove(std::string key);

	int_j	length();


	Value& operator+=(const Value& rhs);
	Value& operator+=(const int& rhs);

protected:
	void nullinit();
	void copyfrom(Value&v);

	Value*	toArray();
	Value*	toObject();

	void convertToInt(bool change = false);
	void convertToDouble(bool change = false);
	void convertToBool(bool change = false);
	void convertToString(bool change = false);

	Value(Type typeflag);

private:
	
	int_j				m_Int;
	double				m_Double;
	bool				m_Bool;
	std::string			m_String;
	std::vector<Value*>	m_Array;
	Map					m_Object;

	Type m_TypeFlag;

};
}
}