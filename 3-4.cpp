
/* 3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:	(A) Only one disk can be moved at a time. (B) A disk is slid off the top of one rod onto the next rod. (C) A disk can only be placed on top of a larger disk. Write a program to move the disks from the first rod to the last using Stacks. */

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

#define N 3

/* 递归解法 */
/* void hanoi_recursive(int n, string src, string middle, string dst) { */
/* 	if (n == 1) { */ 
/* 		std::cout << to_string(n) + " from " + src + " to " + dst << std::endl; */
/* 		return; */
/* 	} */ 

/* 	hanoi_recursive(n-1, src, dst, middle); */
/* 	std::cout << to_string(n) + " from " + src + " to " + dst << std::endl; */
/* 	hanoi_recursive(n-1, middle, src, dst); */
/* } */


struct rod {
	rod(int t, int b, string s, string m, string d):top(t), bottom(b), src(s), middle(m), dst(d){}
	int top;
	int bottom;
	string src;
	string middle;
	string dst;
};


/* 递归的本质就是不断的压栈和出栈 */
/* (1~n,	0,		0) */
/* (n,		1~n-1,	0) */
/* (0,		1~n-1,	n) */
/* (0,		0,		1~n) */
void honoi_stack(string src, string middle, string dst) {
	stack<rod> s;
	s.push(rod(1, N, src, middle, dst));
	while (!s.empty()) { 
		rod tmp = s.top();
		s.pop();
		if (tmp.top == tmp.bottom) { 
			std::cout << to_string(tmp.top) + " from " + tmp.src + " to " + tmp.dst << std::endl;
		} else { 
			s.push(rod(tmp.top, tmp.bottom-1, tmp.middle, tmp.src, tmp.dst));
			s.push(rod(tmp.bottom, tmp.bottom, tmp.src, tmp.middle, tmp.dst));
			s.push(rod(tmp.top, tmp.bottom-1, tmp.src, tmp.dst, tmp.middle));
		} 
	} 
}


int main(int argc, const char *argv[]) {

	honoi_stack("left", "middle", "right");

	return 0;
}

