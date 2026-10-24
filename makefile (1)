# makefile for CS 210/496 Program 3

# specify compiler
CXX=g++
# compiler flags
# 	-Wall -> shows all warnings
# 	-g -> shows gdb debugging information
# 	-std=c++11 -> use the C++ 2011 ISO standard
CXXFLAGS=-Wall -g -std=c++11
# output flags
CXXOUT=-o p3
# separate compilation
CXXSEP=-c 

# loadbalancer main compilation
p3: p3.cpp webserver.o loadbalancer.o request.h
	$(CXX) $(CXXOUT) $(CXXFLAGS) $^

# compile webserver.o
webserver.o: webserver.cpp request.h
	$(CXX) $(CXXSEP) $(CXXFLAGS) $^

# compile loadbalancer.o
loadbalancer.o: loadbalancer.cpp loadbalancer.h request.h
	$(CXX) $(CXXSEP) $(CXXFLAGS) $^

# clean all *.o files and executable
clean:
	rm -f *.o *.gch p3 

# clean all *.o files
cleano:
	rm -f *.o

