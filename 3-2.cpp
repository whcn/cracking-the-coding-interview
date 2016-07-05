
/* 3.2 How would you design a stack which, in addition to push and pop, 
   also has a function min which returns the minimum element? 
   Push, pop and min should all operate in O(1) time. */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack> 
#include <list>
#include <functional>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <memory>

using namespace std;

template<class T> 
class newStack 
{ 
	public: 
		newStack (); 
		virtual ~newStack (); 
		void push(T value);
		T pop();
		T min();
		int size();

	private: 
		T arr[100];
		int ptr;
		int len;
		stack<T> minValues;
}; 


template<class T>
newStack<T>::newStack() {
	ptr = -1;
	len = 0;
}

template<class T>
newStack<T>::~newStack() {

}

template<class T>
void newStack<T>::push(T value) {
	++ptr;
	arr[ptr] = value;

	if (minValues.empty()) { 
		minValues.push(value);
	} else if (minValues.top() > value) {
		minValues.push(value);
	}

	++len;
}

template<class T>
T newStack<T>::pop() {
	T res = arr[ptr];
	--ptr;
	--len;
	if (res == minValues.top()) { 
		minValues.pop();
	} 
	return res;
}

template<class T>
T newStack<T>::min() {
	return minValues.top();
}

template<class T>
int newStack<T>::size() {
	return len;
}

int main(int argc, const char *argv[]) {

	newStack<int> s;
	s.push(2);
	s.push(1);
	s.push(3);
	s.push(0);
	std::cout << s.min() << std::endl;

	s.pop();
	std::cout << s.min() << std::endl;

	s.push(4);
	std::cout << s.min() << std::endl;
	return 0;
}
