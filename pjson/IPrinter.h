#include "Value.h"
#include <string>

namespace LESTAD {
	namespace JSON {
		class IPrinter {
		public:
			virtual std::string print(Value *doc) = 0;
			virtual void kill() = 0;
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

