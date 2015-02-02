#include "IPrinter.h"

namespace LESTAD { namespace JSON {

BasePrinter::BasePrinter() {
}

BasePrinter::~BasePrinter() {

}

std::string BasePrinter::print(Value * doc) {
	return "(BasePrinter)[ Please, use real printer! ]";
}

void BasePrinter::kill() {
	delete this;
}

}}
