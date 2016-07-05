
/* 2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list. EXAMPLE input: A -> B -> C -> D -> E -> C (the same C as earlier) output: C */

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

using namespace std;

int main(int argc, const char *argv[]) {

	list<char> lst;
	lst.push_back('A');
	lst.push_back('B');
	lst.push_back('C');
	lst.push_back('D');
	lst.push_back('E');
	lst.push_back('F');
	lst.push_back('C');

	auto it = lst.begin();
	for (; it != lst.end(); ++it) {
		std::cout << *it << ' ';
	} 
	std::cout << std::endl;

	map<char, int> m;
	it = lst.begin();
	while (it != lst.end()) { 
		++m[*it];
		++it;
	} 
	for (auto i : m) {
		if (i.second == 2) { 
			std::cout << i.first << std::endl;
		} 
		 
	} 

	return 0;
}

