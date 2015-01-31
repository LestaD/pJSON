#include "Value.h"
#include <sstream>
#include <cstdlib>

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



	Value::Value(bool val) {
		nullinit();
		m_TypeFlag = T_BOOLEAN;
		m_Bool = val;
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
			
			// ...
		}
	}
}
