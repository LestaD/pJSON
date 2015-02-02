#include <string>
#include "Value.h"
#include "IPrinter.h"

#ifndef LESTAD_JSON_JSONPRINTER_H
#define LESTAD_JSON_JSONPRINTER_H

namespace LESTAD { namespace JSON {
	
	class JsonPrinter : public IPrinter {
	public:
		JsonPrinter();
		~JsonPrinter();

		virtual std::string print(Value *doc);
		virtual void kill();

	private:
		Value* m_Value;
	};

}}

#endif // LESTAD_JSON_JSONPRINTER_H