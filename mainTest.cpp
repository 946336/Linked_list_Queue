#include <iostream>
#include "queue.h"
using namespace std;

/*
apparently needed for my local copy of clang++ to work properly.
funny, b/c sometimes it straight up can't find iostream. :\

void *__gxx_personality_v0;
*/

int main(){
	Queue<double> was;

	for(int i = 0; i < 20; i++){
		was.enqueue(double(i)/3);
	}

	for(int i = 0; i < 20; i++){
		cout << i << " " << was.dequeue() << endl;
	}

	return 0;
}