
/* 3.6 Write a program to sort a stack in ascending order. You should not make any assump- tions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty. */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <functional>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <queue> 
#include <stack> 

using namespace std;

void sortStack(stack<int> &s) {

	priority_queue<int> d;

	while (!s.empty()) { 
		int tmp = s.top();
		s.pop();
		d.push(tmp);
	} 

	while (!d.empty()) { 
		 int tmp = d.top();
		 d.pop();
		 s.push(tmp);
	} 

	while (!s.empty()) { 
		std::cout << s.top() << " ";
		s.pop();
	} 

}

int main(int argc, const char *argv[]) {

	srand((unsigned int)time(NULL));
	stack<int> s;
	deque<int> d;

	for (int i = 0; i < 10; ++i) {
		int value = rand() % 8;
		s.push(value);
		std::cout << value << " ";
	} 
	std::cout << std::endl;

	sortStack(s);

	return 0;
}

