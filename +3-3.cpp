
/* 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple. intherefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack). FOLLOW UP Implement a function popAt(int index) which performs a pop operation on a specific sub-stack. */

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

 
class SetOfStacks 
{ 
	public: 
		SetOfStacks (); 
		virtual ~SetOfStacks (); 
		void push(int value);
		int pop();
		int popAt(int index);

	private: 
		int limitLen;
		vector<stack<int>> stacks;
}; 



SetOfStacks::SetOfStacks() {
	limitLen = 5;
	stack<int> s;
	stacks.push_back(s);
}


SetOfStacks::~SetOfStacks() {

}


void SetOfStacks::push(int value) {
	stack<int> tmp = stacks.back();
	tmp.push(value);
	if (tmp.size() == limitLen) { 
		stack<int> s;
		stacks.push_back(s);
	} 
}


int SetOfStacks::pop() {
	int res = stacks.back().top();
	stacks.back().pop();
	if (stacks.back().empty() && stacks.size() > 1) { 
		stacks.erase(--stacks.end());
	} 
	return res;
}


int SetOfStacks::popAt(int index) {
	/* vector<stack<int>> it = stacks.begin() + 5; */
	/* std::cout << stacks.size() << std::endl; */
	vector<stack<int>>::iterator it = stacks.begin() + 5;
	std::cout << (*it).top() << std::endl;
	/* stacks.erase(it); */
	/* if (index / limitLen + 1 > stacks.size()) { */ 
	/* 	return NULL; */
	/* } */ 
	/* auto it = stacks.begin(); */
	/* it += index; */
	/* int res = *it.top(); */
	/* *it.pop(); */
	/* if (*it.empty() && stacks.size() > 1) { */ 
	/* 	stacks.erase(it); */
	/* } */ 
	return 0;
}

int main(int argc, const char *argv[]) {

	SetOfStacks ss;
	for (int i = 0; i < 21; ++i) {
		ss.push(i);
	} 

	/* int res = ss.popAt(3); */
	ss.popAt(3);
	/* std::cout << res << std::endl; */

	return 0;
}
