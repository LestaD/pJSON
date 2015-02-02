#include "JsonPrinter.h"

namespace LESTAD { namespace JSON {
	
	JsonPrinter::JsonPrinter() {
		m_Value = Value::Object();
	}

	JsonPrinter::~JsonPrinter() {
		if (!m_Value->isEmpty()) m_Value->kill();
	}

	std::string JsonPrinter::print(Value *doc) {
		

		return "{\"@JsonPrinter\": \"It's not real result\"}";
	}

	void JsonPrinter::kill() {
		delete this;
	}

}}