
/* 2.2 Implement an algorithm to find the nth to last element of a singly linked list. */

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

	list<int> lst;
	for (int i = 0; i < 10; ++i) {
		lst.push_back(rand()%100); 
	} 
	for (auto i : lst) {
		cout << i << ' ';
	} 
	cout << endl;

	int n;
	cin >> n;
	if (n < lst.size()) { 
		auto it = lst.begin();
		for (int i = 0; i < lst.size()-n; ++i) {
			++it;
		} 
		std::cout << *it << std::endl;
	}

	return 0;
}



