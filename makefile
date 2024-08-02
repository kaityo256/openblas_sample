CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -I/usr/local/opt/openblas/include
LDFLAGS = -L/usr/local/opt/openblas/lib

all: a.out b.out

a.out: sample.cpp
	g++ $(CXXFLAGS) $< $(LDFLAGS) -lblas

b.out: parallel.cpp
	g++ $(CXXFLAGS) $< $(LDFLAGS) -lblas -o $@

clean:
	rm -f a.out
