#include <string>
#include "Value.h"
#include "IPrinter.h"

#ifndef LESTAD_JSON_PRINTEGER_H
#define LESTAD_JSON_PRINTEGER_H

namespace LESTAD { namespace JSON {

class Printeger {
	
public:
	Printeger();
	Printeger(Value *init);
	Printeger(IPrinter *printer);
	Printeger(Value *init, IPrinter *printer);
	~Printeger();

	void set(IPrinter *printer);
	void set(Value *data);

	std::string print();

protected:
	Value*		m_Value;
	IPrinter*	m_Printer;
};

}}


#endif // LESTAD_JSON_PRINTEGER_H