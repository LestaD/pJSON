#include "Value.h"
#include <sstream>
#include <cstdlib>
#include <iostream>


namespace LESTAD {
namespace JSON {

	// ----- CONTRUCTORS ----- //

	Value::Value() {
		nullinit();
		m_TypeFlag = T_UNDEFINED;
	}

	Value::Value(Value *copy) {
		nullinit();
		m_TypeFlag = copy->m_TypeFlag;
	}

	Value::Value(Value &copy) {
		nullinit();
		m_TypeFlag = copy.m_TypeFlag;
	}

	Value::Value(int val) {
		nullinit();
		m_TypeFlag = T_INT;
		m_Int = val;
	}

	Value::Value(double val) {
		nullinit();
		m_TypeFlag = T_DOUBLE;
		m_Double = val;
	}

	Value::Value(const char *val) {
		nullinit();
		m_TypeFlag = T_STRING;
		m_String = val;
	}

	Value::Value(std::string val) {
		nullinit();
		m_TypeFlag = T_STRING;
		m_String = val;
	}

	Value::Value(bool val) {
		nullinit();
		m_TypeFlag = T_BOOLEAN;
		m_Bool = val;
	}

	Value* Value::Array() {
		Value *pVal = new Value();
		pVal->m_TypeFlag = T_ARRAY;

		return pVal;
	}

	Value* Value::Object() {
		Value *pVal = new Value();
		pVal->m_TypeFlag = T_OBJECT;

		return pVal;
	}

	/**
	 * @protected
	 */
	Value::Value(Type typeflag) {
		nullinit();
		m_TypeFlag = typeflag;
	}


	// ----- DESTRUCTOR ----- //

	Value::~Value() {
		
	}


	// ----- . ----- //

	void Value::nullinit() {
		m_Int = 0;
		m_Double = 0.0;
		m_Bool = false;
	}


	bool Value::isEmpty() {
		if (getType() == T_UNDEFINED || getType() == T_NULL) return true;

		// WRITE IT
	}


	Value::Type Value::getType() {
		nullinit();
		return m_TypeFlag;
	}

	const char* Value::getTypeString() {
		switch(m_TypeFlag) {
			case T_INT:		return "integer";
			case T_DOUBLE:	return "double";
			case T_BOOLEAN:	return "boolean";
			case T_STRING:	return "string";
			case T_NULL:	return "null";
			case T_ARRAY:	return "array";
			case T_OBJECT:	return "object";

			default: return "undefined";
		}
	}


	// ----- TYPE CHECKING ----- //


	bool Value::isNull() {
		return m_TypeFlag == T_NULL;
	}

	bool Value::isInt() {
		return m_TypeFlag == T_INT;
	}

	bool Value::isDouble() {
		return m_TypeFlag == T_DOUBLE;
	}

	bool Value::isFloat() {
		return isDouble();
	}

	bool Value::isBool() {
		return m_TypeFlag == T_BOOLEAN;
	}

	bool Value::isString() {
		return m_TypeFlag == T_STRING;
	}

	bool Value::isArray() {
		return m_TypeFlag == T_ARRAY;
	}

	bool Value::isObject() {
		return m_TypeFlag == T_OBJECT;
	}


	// ----- GET AS TYPE ----- //

	int Value::getInt() {
		if (!isInt()) {
			convertToInt();
		}
		return m_Int;
	}

	double Value::getDouble() {
		if (!isDouble()) {
			convertToDouble();
		}
		return m_Double;
	}

	float Value::getFloat() {
		return (float)getDouble();
	}

	bool Value::getBool() {
		if(!isBool()) {
			convertToBool();
		}
		return m_Bool;
	}

	std::string Value::getString() {
		if(!isString()) {
			convertToString();
		}
		return std::string(m_String.c_str());
	}

	// ----- TYPE CONVERT ----- //

	void Value::convertToInt() {
		switch(m_TypeFlag) {
			case T_NULL:	m_Int = 0;					break;
			case T_DOUBLE:	m_Int = (int)m_Double;		break;
			case T_BOOLEAN: m_Int = m_Bool ? 1 : 0;		break;
			case T_STRING:	m_Int = std::atoi(m_String.c_str());		break;
		}
	}

	void Value::convertToDouble() {
		switch(m_TypeFlag) {
			case T_NULL:	m_Double = 0.0;					break;
			case T_INT:		m_Double = (double)m_Int;		break;
			case T_BOOLEAN: m_Double = m_Bool ? 1.0 : 0.0;	break;
			case T_STRING:	m_Double = std::atof(m_String.c_str());		break;
		}
	}

	void Value::convertToBool() {
		switch(m_TypeFlag) {
			case T_NULL:	m_Bool = false; 						break;
			case T_DOUBLE:	m_Bool = m_Double == 0 ? false : true;	break;
			case T_INT:		m_Bool = m_Int == 0 ? false : true;		break;
			case T_STRING:	m_Bool = m_String.length() > 0;
		}
	}

	void Value::convertToString() {
		switch(m_TypeFlag) {
			case T_NULL:	m_String.assign("");	break;
			case T_DOUBLE:	{
				std::ostringstream sstream;
				sstream.setf(std::ios::fixed, std::ios::floatfield);
				sstream.setf(std::ios::showpoint);
				sstream << m_Double;
				m_String = sstream.str();			break;
			}
			case T_INT: {
				std::ostringstream sstream;
				sstream << m_Int;
				m_String = sstream.str();			break;
			}
			case T_BOOLEAN: m_String = m_Bool? "true" : "false";
													break;
			
			case T_ARRAY: m_String = "array[]";		break;
			case T_OBJECT: m_String = "object";		break;
		}
	}

	// ----- SET VALUE ----- //

	Value* Value::set(Value *val) {
		switch (val->m_TypeFlag) {
			case T_INT: m_Int = val->m_Int; break;
			case T_DOUBLE: m_Double = val->m_Double; break;
			case T_STRING: m_String = val->m_String.c_str(); break;
			case T_BOOLEAN: m_Bool = val->m_Bool; break;
		}

		return this;
	}

	Value* Value::set(Value val) {
		switch (val.m_TypeFlag) {
			case T_INT: m_Int = val.m_Int; break;
			case T_DOUBLE: m_Double = val.m_Double; break;
			case T_STRING: m_String = val.m_String.c_str(); break;
			case T_BOOLEAN: m_Bool = val.m_Bool; break;
		}

		return this;
	}


	Value* Value::set(int val) {
		m_TypeFlag = T_INT;
		m_Int = val;

		return this;
	}


	Value* Value::set(double val) {
		m_TypeFlag = T_DOUBLE;
		m_Double = val;

		return this;
	}


	Value* Value::set(bool val) {
		m_TypeFlag = T_BOOLEAN;
		m_Bool = val;

		return this;
	}

	Value* Value::set(const char *val) {
		m_TypeFlag = T_STRING;
		m_String = val;
	}

	Value* Value::set(std::string val) {
		m_TypeFlag = T_STRING;
	}

	Value* Value::setNull() {
		m_TypeFlag = T_NULL;
		nullinit();

		return this;
	}


	// ----- CONVERTING ----- //

	Value* Value::toArray() {
		if (!isArray()) {
			nullinit();
			m_TypeFlag = T_ARRAY;
		}

		return this;
	}

	Value* Value::toObject() {
		if (!isObject()) {
			nullinit();
			m_TypeFlag = T_OBJECT;
		}

		return this;
	}

	Value* Value::get(int index) {
		if (length() < 1) return new Value(T_UNDEFINED);
		if (getType() != T_ARRAY) return new Value(T_NULL);
		if (index + 1 > length() ) return new Value(T_UNDEFINED);

		Value* p = m_Array.at(index);
		if (p) return p;

		return new Value(T_UNDEFINED);
	}


	/**
	 * Object
	 */
	Value* Value::get(const char *key) {
		
	}

	Value* Value::get(std::string key) {
		
	}

	int Value::length() {
		switch(getType()) {
			case T_STRING: return m_String.length();
			case T_ARRAY: return m_Array.size();
			default: return 0;
		}
	}

	Value* Value::push(Value* val) {
		if (getType() == T_ARRAY) {
			m_Array.push_back(val);
		}
		else {
			// maybe Exception?
		}
	}
}
}