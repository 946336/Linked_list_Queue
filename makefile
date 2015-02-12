
CXX = g++
CPPFLAGS = -g -Wall -Wextra -std="c++11"

list.o: dLinkedList.cpp
	$(CXX) $(CPPFLAGS) $^ -c -o $@