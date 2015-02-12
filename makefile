
CXX = g++
CFF = clang++
CPPFLAGS = -g -Wall -Wextra -std="c++11"

list.o: dLinkedList.cpp
	$(CXX) $(CPPFLAGS) $^ -c -o $@

queue.o: queue.cpp
	$(CXX) $(CPPFLAGS) $^ -c -o $@

test: mainTest.cpp dLinkedList.cpp queue.cpp
	$(CFF) $(CPPFLAGS) $^ -o $@