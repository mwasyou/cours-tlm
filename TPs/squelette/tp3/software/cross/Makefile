TARGET_CC = microblaze-uclinux-gcc
TARGET_LD = microblaze-uclinux-ld
TARGET_OBJDUMP = microblaze-uclinux-objdump
TARGET_READELF = microblaze-uclinux-readelf
HOST_CC = gcc
HOST_LD = ld
HOST_OBJDUMP = objdump
HOST_READELF = readelf

INCLUDE = -I. -I../..

OBJS = main.o boot.o it.o
EXEC = a.out

# Disassembly of the generated executable.
dump.txt: $(EXEC)
	$(TARGET_OBJDUMP) -d $< > $@

# Summary of the sections and their size.
sections.txt: $(EXEC)
	$(TARGET_READELF) -S $< > $@


$(EXEC): # dependencies
	echo "Rule for linking not implemented."; exit 1
# (use $(TARGET_LD), and use the -T option to point to linker script ldscript)

main.o: # dependencies
	echo "Rule for compilation not implemented"; exit 1
# (compile with target C compiler)

%.o: %.s
	echo "Rule for assembly not implemented"; exit 1

.PHONY: clean realclean
clean:
	-$(RM) $(OBJS) $(EXEC) dump.txt

realclean: clean
	-$(RM) *~
