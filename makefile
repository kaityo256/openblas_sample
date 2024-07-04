CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -I/usr/local/opt/openblas/include
LDFLAGS = -L/usr/local/opt/openblas/lib

all: a.out

a.out: sample.cpp
	g++ $(CXXFLAGS) sample.cpp $(LDFLAGS) -lblas

clean:
	rm -f a.out
