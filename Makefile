CXX = g++
LD = -g

TARGET = app
CFLAGS = -O2 -framework OpenGL -framework GLUT $(shell pkg-config --cflags --libs opencv)

SRCDIR = src
SRCS = $(foreach dir, .. $(SRCDIR), $(wildcard $(dir)/*.cpp))

OBJS = $(SRCS:.cpp=.o)
OBJS := $(notdir $(OBJS))

all: $(TARGET)
	$(CXX) -o $(TARGET) $(OBJS) $(CFLAGS)

$(TARGET):
#	@echo $(CFLAGS)
#	@echo $(SRCS)
#	@echo $(OBJS)
	$(CXX) -c $(SRCS) $(CFLAGS)

clean:
	rm -f $(TARGET)
	rm -f *.o
