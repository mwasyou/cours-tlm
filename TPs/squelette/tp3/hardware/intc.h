#ifndef INTC_H
#define INTC_H

#ifndef ENSITLM_H
#error Please include file "ensitlm.h"
#endif

#include <vector>

SC_MODULE(Intc) {
	SC_HAS_PROCESS(Intc);

	sc_core::sc_in<bool> in0;
	sc_core::sc_in<bool> in1;
	sc_core::sc_out<bool> out;

	explicit Intc(sc_core::sc_module_name name);

private:

	void merge();

};

#endif
