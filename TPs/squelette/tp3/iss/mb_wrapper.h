/********************************************************************
 * Copyright (C) 2009 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#ifndef MB_WRAPPER_H
#define MB_WRAPPER_H

#ifndef ENSITLM_H
#error Please include file "ensitlm.h"
#endif

#include "microblaze.h"

/*!
  Wrapper for MicroBlaze ISS using the BASIC protocol.
*/
struct MBWrapper : sc_core::sc_module {
	ensitlm::initiator_socket<MBWrapper> socket;
	sc_core::sc_in<bool>               irq;

	void run_iss(void);

	typedef soclib::common::Iss iss_t;
	soclib::common::MicroBlazeIss m_iss;
	SC_CTOR(MBWrapper);
};

#endif // MB_WRAPPER_H
