
/* 3.1 Describe how you could use a single array to implement three stacks. */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <array> 
#include <functional>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <memory>

using namespace std;

#define LEN 900
#define NUM 3

class arr2stack { 
	public: 
		arr2stack (); 
		/* virtual ~arr2stack (); */ 
		int pop(int stackNum);
		void push(int stackNum, int value);
		bool empty(int stackNum);
		int size(int stackNum);
		int top(int stackNum);

	private: 
		std::array<int, LEN> arr;
		int topPtr[NUM];
		int len[NUM];
}; 

int arr2stack::top(int stackNum) {
	return arr[topPtr[stackNum]];
}

arr2stack::arr2stack() {
	for (int i = 0; i < NUM; ++i) {
		topPtr[i] = -1; 
		len[i] = 0;
	} 
}

int arr2stack::pop(int stackNum) {
	int value = arr[topPtr[stackNum]];
	if (len[stackNum] == 1) { 
		topPtr[stackNum] = -1;
	} else { 
		--topPtr[stackNum]; 
	} 
	--len[stackNum];
	return value;
}

void arr2stack::push(int stackNum, int value) {
	if (len[stackNum] == 0) { 
		topPtr[stackNum] = stackNum * LEN / NUM;
	} else { 
		topPtr[stackNum]++; 
	} 
	arr[topPtr[stackNum]] = value;
	++len[stackNum];
}

bool arr2stack::empty(int stackNum) {
	if (len[stackNum] == 0) { 
		return true;
	} 
	return false;
}

int arr2stack::size(int stackNum) {
	return len[stackNum];
}

int main(int argc, const char *argv[]) {

	arr2stack test;
	for(int i=0; i<10; ++i)
		test.push(0, i);
	for(int i=10; i<20; ++i)
		test.push(1, i);
	for(int i=100; i<110; ++i)
		test.push(2, i);
	for(int i=0; i<3; ++i)
		cout<<test.top(i)<<" ";

	cout<<endl;
	for(int i=0; i<3; ++i){
		test.pop(i);
		cout<<test.top(i)<<" ";
	}

	std::cout << std::endl;
	test.push(0, 111);
	test.push(1, 222);
	test.push(2, 333);
	for(int i=0; i<3; ++i)
		cout<<test.top(i)<<" ";
	return 0;
}

