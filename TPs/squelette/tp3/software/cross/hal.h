/********************************************************************
 * Copyright (C) 2009 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/*!
  \file hal.h
  \brief Harwdare Abstraction Layer : implementation for MicroBlaze
  ISS.

  
*/
#ifndef HAL_H
#define HAL_H

#include <stdint.h>

/* Compiling printf properly is hard, we just disable it */
#define printf(...) NULL


/* Dummy implementation of abort(): dereference a NULL pointer */
#define abort() ((*(int *)NULL) = 0)

/* TODO : implementer ces primitives pour la compilation croisée */
#define read_mem(a)     abort()
#define write_mem(a,d)  abort()
#define wait_for_irq()  abort()
#define cpu_relax()     abort()

#endif /* HAL_H */
