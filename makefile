
CXX = g++
CFF = clang++
CPPFLAGS = -g -Wall -Wextra
CPP11 = -std="c++11"
ARGHFLAGS = --always-make

list.o: dLinkedList.h
	$(CXX) $(CPPFLAGS) $(CPP11) $^ -c -o $@

queue.o: queue.h
	$(CXX) $(CPPFLAGS) $(CPP11) $^ -c -o $@

test: mainTest.cpp dLinkedList.cpp queue.cpp
	$(CFF) $(CPPFLAGS) $^ -o $@

testHeavy: mainTest.cpp
	$(CXX) $(CPPFLAGS) $(CPP11) $(ARGHFLAGS) $^ -o $@

test98:mainTest.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@
