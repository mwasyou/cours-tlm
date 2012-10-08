TARGET=run.x
all: $(TARGET)

SRCS=${wildcard *.cpp}
NO_SDL=no
ROOT=../..
include $(ROOT)/Makefile.common

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)


