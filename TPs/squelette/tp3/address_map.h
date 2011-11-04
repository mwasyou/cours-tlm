#ifndef ADDRESS_MAP_H
#define ADDRESS_MAP_H

#define SRAM_BASEADDR 0x20100000
#include "hardware/offsets/memory.h"

#define GPIO_BASEADDR 0x40000000
#include "hardware/offsets/gpio.h"

#define TIMER_BASEADDR 0x41C00000
#include "hardware/offsets/timer.h"

#define VGA_BASEADDR 0x73A00000
#include "hardware/offsets/vga.h"

#define UART_BASEADDR 0x40600000

#define INTC_BASEADDR 0x41200000

#endif
