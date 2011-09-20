TARGET=run.x
all: $(TARGET)

SRCS=${wildcard *.cpp}
include Makefile.common

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)


