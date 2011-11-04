#include "ensitlm.h"

#include "mb_wrapper.h"
#include "memory.h"
#include "bus.h"
#include "timer.h"
#include "vga.h"
#include "intc.h"
#include "gpio.h"


#include "../elf-loader/loader/include/loader.h"
#include "../elf-loader/loader/include/exception.h"

namespace soclib { namespace common {
		extern bool elf_load( const std::string &filename, soclib::common::Loader &loader );
	}};
#define SOFT_SIZE 0x2000

int sc_main(int, char**)
{
	MBWrapper cpu("MBWrapper");
	Memory inst_ram("inst_ram", 0x00002000); // 8Kb
	Memory data_ram("data_ram", 0x00100000);
	Bus bus("bus");
	TIMER timer("timer", sc_core::sc_time(20, sc_core::SC_NS));
	Vga vga("vga");
	Intc intc("intc");
	Gpio gpio("gpio");

	sc_core::sc_signal<bool> timer_irq("timer_irq");
	sc_core::sc_signal<bool> vga_irq("vga_irq");
	sc_core::sc_signal<bool> cpu_irq("cpu_irq");

	// Load the program in RAM
	soclib::common::Loader::register_loader("elf", soclib::common::elf_load);
	try {
		soclib::common::Loader loader("../software/cross/a.out");
		loader.load(inst_ram.storage, 0, SOFT_SIZE);
	} catch (soclib::exception::RunTimeError e) {
		std::cerr << "unable to load ELF file in memory:" << std::endl;
		std::cerr << e.what() << std::endl;
		abort();
	}

	// initiators
	cpu.socket.bind(bus.target);
	vga.initiator(bus.target);

	// targets
	bus.initiator(data_ram.target);
	bus.initiator(inst_ram.target);
	bus.initiator(vga.target);
	bus.initiator(timer.target);
	bus.initiator(gpio.target);

	// interrupts
	vga.irq(vga_irq);
	timer.irq(timer_irq);
	intc.in0(vga_irq);
	intc.in1(timer_irq);
	intc.out(cpu_irq);
	cpu.irq(cpu_irq);

	//      port             start addr  size
	bus.map(inst_ram.target, 0x00000000, 0x00002000);
	bus.map(data_ram.target, 0x20100000, 0x00100000);
	bus.map(vga.target,      0x73A00000, 0x00010000);
	bus.map(gpio.target,     0x40000000, 0x00010000);
	bus.map(timer.target,    0x41C00000, 0x00010000);

	// start the simulation
	sc_core::sc_start();

	return 0;
}
