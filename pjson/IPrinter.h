#include "Value.h"
#include <string>

#ifndef LESTAD_JSON_IPRINTER_H
#define LESTAD_JSON_IPRINTER_H

namespace LESTAD {
	namespace JSON {
		class IPrinter {
		public:
			virtual std::string print(Value *doc) = 0;
			virtual void kill() = 0;
			friend Value;
		};

		class BasePrinter : public IPrinter {
		public:
			BasePrinter();
			~BasePrinter();
			
			virtual std::string print(Value *doc);
			virtual void kill();
		};
	}
}

#endif // LESTAD_JSON_IPRINTER_H