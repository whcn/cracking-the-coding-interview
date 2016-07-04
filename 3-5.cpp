
/* 3.5 Implement a MyQueue class which implements a queue using two stacks. */

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
#include <stack> 

using namespace std;

class MyQueue 
{ 
	public: 
		MyQueue (); 
		virtual ~MyQueue (); 
		void push(int value);
		void pop();
		int size();
		bool empty();
		int front();
		int back();

	private: 
		stack<int> s1;
		stack<int> s2;
}; 

int MyQueue::front() {
	if (s1.empty()) { 
		std::cout << "Stack Empty" << std::endl;
		exit(0);
	} 

	while (!s1.empty()) { 
		int tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	} 

	int res = s2.top();

	while (!s2.empty()) { 
		int tmp = s2.top();
		s2.pop();
		s1.push(tmp);
	} 

	return res;
}

int MyQueue::back() {
	if (s1.empty()) { 
		std::cout << "Stack Empty" << std::endl;
		exit(0);
	} else { 
		return s1.top();
	}  
}

MyQueue::MyQueue() {

}

MyQueue::~MyQueue() {

}

void MyQueue::push(int value) {
	s1.push(value);
}

void MyQueue::pop() {
	if (s1.empty()) { 
		std::cout << "Stack empty" << std::endl;
		exit(0);
	} 

	while (!s1.empty()) { 
		int tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	} 
	s2.pop();

	while (!s2.empty()) { 
		int tmp = s2.top();
		s2.pop();
		s1.push(tmp);

	} 
}

int MyQueue::size() {
	return s1.size();
}

bool MyQueue::empty() {
	if (s1.empty()) { 
		return true;  
	} else { 
		return false; 
	} 
}


int main(int argc, const char *argv[]) {

	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	q.pop();
	std::cout << q.size() << std::endl;
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	
	return 0;
}

