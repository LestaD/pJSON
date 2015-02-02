#include <string>
#include "Value.h"
#include "IPrinter.h"

#ifndef LESTAD_JSON_JSONPRINTER_H
#define LESTAD_JSON_JSONPRINTER_H

namespace LESTAD { namespace JSON {
	
	class JsonPrinter : public IPrinter {
	public:
		JsonPrinter();
		JsonPrinter(bool pretty);
		~JsonPrinter();

		void pretty();

		virtual std::string print(Value *doc);
		virtual void kill();
	
	protected:
		
		std::string recursivePrint(Value *doc, int level);
		std::string appendSpace(int level);

	private:
		bool	m_bPretty;
		Value*	m_Value;
	};

}}

#endif // LESTAD_JSON_JSONPRINTER_H