
/* 2.4 You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. EXAMPLE Input: (3 -> 1 -> 5) + (5 -> 9 -> 2) Output: 8 -> 0 -> 8 */

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

void listAdd(list<int> lst1, list<int> lst2, list<int> &res) {
	if (lst1.empty() || lst2.empty()) { 
		return; 
	} 
	int minLen = min(lst1.size(), lst2.size());
	int carry = 0;
	int remain = 0;
	auto it1 = lst1.begin();
	auto it2 = lst2.begin();

	for (int i = 0; i < minLen; ++i) {
		remain = (*it1 + *it2 + carry) % 10;
		carry = (*it1 + *it2 + carry) / 10;
		res.push_back(remain);
		++it1;
		++it2;
	} 

	int len;
	list<int>::iterator it3;
	if (lst1.size() > lst2.size()) { 
		len = lst1.size() - minLen;
		it3 = it1;
	} else { 
		len = lst2.size() - minLen;
		it3 = it2;
	} 
	for (int i = 0; i < len; ++i) {
		remain = (*it3 + carry) % 10;
		carry = (*it3 + carry) / 10;
		res.push_back(remain);
		++it3;
	}
	if (carry != 0) { 
		res.push_back(carry) ;
	} 
}

int main(int argc, const char *argv[]) {

	list<int> lst1, lst2, res;
	lst1.push_front(9);
	lst1.push_front(9);
	lst1.push_front(9);

	lst2.push_front(0);
	lst2.push_front(0);
	lst2.push_front(1);

	auto it = lst1.begin();
	for (; it!=lst1.end(); ++it) {
		std::cout << *it << ' ';
	} 

	std::cout << std::endl;
	it = lst2.begin();
	for (; it!=lst2.end(); ++it) {
		std::cout << *it << ' ';
	} 

	listAdd(lst1, lst2, res);

	std::cout << std::endl;
	it = res.begin();
	for (; it!=res.end(); ++it) {
		std::cout << *it << ' ';
	} 
	return 0;
}

