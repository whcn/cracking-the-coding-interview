
/* 2.1 Write code to remove duplicates from an unsorted linked list. 
   FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? */

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

void removeDuplicate(list<int> &lst) {
	list<int>::iterator il, ir;
	for (il = lst.begin(); il != lst.end(); ++il) {
		auto tmp = il; //NOTE: ir = ++il will move il's location, so need a variable be intermedia value
		for (ir = ++tmp; ir != lst.end(); ++ir) {
			if (*ir == *il) { 
				lst.erase(ir);
			}
		} 
	} 
}

int main(int argc, const char *argv[]) {

	std::srand((unsigned int)time(NULL));
	list<int> lst;
	for (int i = 0; i < 10; ++i) {
		lst.push_back(rand()%5); 
	} 
	for (auto i : lst) {
		cout << i << ' ';
	} 
	cout << endl;

	removeDuplicate(lst);

	for (auto i : lst) {
		cout << i << ' ';
	} 
	return 0;
}

