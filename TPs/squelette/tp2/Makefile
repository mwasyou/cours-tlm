TARGET=run.x
all: $(TARGET)

SRCS=${wildcard *.cpp}
NO_SDL=no
include Makefile.common

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

