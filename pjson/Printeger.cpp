#include "Printeger.h"

namespace LESTAD { namespace JSON {
	
	Printeger::Printeger() {
		m_Value = Value::Object();
		m_Printer = new BasePrinter();
	}

	Printeger::Printeger(Value *init) {
		m_Value = init;
		m_Printer = new BasePrinter();
	}

	Printeger::Printeger(IPrinter *printer) {
		m_Printer = printer;
		m_Value = Value::Object();
	}

	Printeger::Printeger(Value *init, IPrinter *printer) {
		m_Value = init;
		m_Printer = printer;
	}

	void Printeger::set(Value *data) {
		if (m_Value) m_Value->kill();
		if (!data) {
			m_Value = new Value();
		}
		m_Value = data;
	}

	void Printeger::set(IPrinter *printer) {
		if (m_Printer) m_Printer->kill();
		if (printer == 0) return;
		m_Printer = printer;
	}


	std::string Printeger::print() {
		if (m_Printer == 0 || m_Value == 0) return 0;
		if (m_Value->isEmpty()) return std::string("");
		if (m_Printer) {
			return m_Printer->print(m_Value);
		}
		return 0;
	}
}}