CXX = g++
LD = g++

INCDIR = ../inc
SRCDIR1 = src

VPATH = $(SRCDIR1) $(SRCDIR2) ..

CFLAGS = -O2 -I$(INCDIR) -framework OpenGL -framework GLUT `pkg-config --cflags --libs opencv`

TARGET = app

SRCS = $(foreach dir, .. $(SRCDIR1), $(wildcard $(dir)/*.cpp))
SRCS := $(notdir $(SRCS))

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(LD) $^ -o$(TARGET) $(LIBS)


%o:%c
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	-rm -rf $(OBJS)
	-rm -f $(TARGET)
	-rm -f depend

depend: $(SRCS)
	$(CXX) -M $(CFLAGS) $^ > $@

-include depend
