CXX=g++

SRCS=mia.cpp parabola.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: parabola

parabola: $(OBJS)
	$(CXX) $(OBJS) -o parabola.out

%.o: %.cpp
	$(CXX) -c $<
