
CXX = g++
CFF = clang++
CPPFLAGS = -g -Wall -Wextra -std="c++11"
ARGHFLAGS = --always-make

list.o: dLinkedList.h
	$(CXX) $(CPPFLAGS) $^ -c -o $@

queue.o: queue.h
	$(CXX) $(CPPFLAGS) $^ -c -o $@

test: mainTest.cpp dLinkedList.cpp queue.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@

test2: mainTest.cpp dLinkedList.cpp queue.cpp
	$(CXX) $(ARGHFLAGS) $(CPPFLAGS) $^ -o $@