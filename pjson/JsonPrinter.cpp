#include "JsonPrinter.h"

namespace LESTAD { namespace JSON {
	
	JsonPrinter::JsonPrinter() {
		m_Value = Value::Object();
		m_bPretty = false;
	}

	JsonPrinter::JsonPrinter(bool pretty) {
		m_Value = Value::Object();
		m_bPretty = pretty;
	}

	JsonPrinter::~JsonPrinter() {
		if (!m_Value->isEmpty()) m_Value->kill();
	}

	void JsonPrinter::pretty() {
		m_bPretty = true;
	}

	std::string JsonPrinter::print(Value *doc) {
		if(m_Value->isEmpty()) m_Value->kill();
		m_Value = doc;

		std::string result = "{\n";

		if (!m_Value->isObject()) return "{\"@JsonPrinter\": \"Bad value. JSON root must be object\"}";


		Value::Map keys = m_Value->__getKeys();

		int l = 0;
		Value::Map::iterator last = keys.end();
		--last;
		for (Value::Map::iterator i = keys.begin(); i != keys.end(); i++, l++) {
			if (m_bPretty) result.append(" ");
			result.append("\"");
			result.append((*i).first);
			result.append("\":");
			if (m_bPretty) result.append(" ");

			result.append(recursivePrint((*i).second, 0));

			if (i != last) {
				result.append(",");
				if(m_bPretty) result.append("\n");
			}
		}

		result.append("\n}");

		return result;
	}

	void JsonPrinter::kill() {
		delete this;
	}

	/**
	 * Print element
	 * If element is array or object run once
	 */
	std::string JsonPrinter::recursivePrint(Value *doc, int level) {
		std::string chunk = "";
		switch(doc->getType()) {
			case Value::T_NULL:
			case Value::T_UNDEFINED:		chunk.append("null"); break;
			case Value::T_STRING:			chunk.append("\""); chunk.append(doc->getString()); chunk.append("\""); break;
			case Value::T_INT:
			case Value::T_DOUBLE:			chunk.append(doc->getString()); break;
			case Value::T_BOOLEAN:			chunk.append(doc->getBool() ? "true" : "false"); break;
			case Value::T_ARRAY: {
				int_j size = doc->length();
				chunk.append("[");
				for (int_j i = 0; i < size; i++) {
					chunk.append(recursivePrint(doc->get(i), level+1));
					if (i+1 < size) {
						chunk.append(",");
						if (m_bPretty) {
							chunk.append(" ");
						}
					}
				}
				chunk.append("]");
				break;
			}
			case Value::T_OBJECT: {
				Value::Map keys = doc->__getKeys();
				chunk.append("{");
				if (m_bPretty) chunk.append("\n");
				int l = 0;
				Value::Map::iterator last = keys.end();
				--last;
				for (Value::Map::iterator i = keys.begin(); i != keys.end(); i++, l++) {
					if (m_bPretty) chunk.append(" ");
					chunk.append("\"");
					chunk.append((*i).first);
					chunk.append("\":");
					if (m_bPretty) chunk.append(" ");

					chunk.append(recursivePrint((*i).second, level+2));

					if (i != last) {
						chunk.append(",");
						if(m_bPretty) chunk.append("\n");
					}
				}
				if (m_bPretty) chunk.append("\n");
				chunk.append(appendSpace(level));
				chunk.append("}");
				break;
			}
		}

		//chunk.append(appendSpace(level));

		return chunk;
	}

	std::string JsonPrinter::appendSpace(int level) {
		if (m_bPretty) {
			std::string ret = "";
			for (int i = 0; i < level; i++) ret.append(" ");
			return ret;
		}

		return "";
	}

}}