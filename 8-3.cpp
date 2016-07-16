
/* 8.3 Write a method that returns all subsets of a vector. */

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
#include <tuple> 

using namespace std;

set<vector<int>> s;

void init(vector<int> &s) {
	for (int i = 0; i < 4; ++i) {
		s.push_back(rand() % 10);
	} 
}

void output(vector<int> v) {
	auto it = v.begin();
	for (; it != v.end(); ++it) {
		std::cout << *it << ' ';
	} 
}


void allSubset(vector<int> v) {
	if (v.size() == 0) { 
		return;
	} 

	std::sort(v.begin(), v.end()); 
	s.insert(v); 
	for (auto is = v.begin(); is != v.end(); ++is) {
		vector<int> temp;
		temp.insert(temp.end(), v.begin(), is); 
		temp.insert(temp.end(), is + 1, v.end()); 
		allSubset(temp); 
	} 
}

int main(int argc, const char *argv[]) {

	vector<int> v;
	init(v);
	output(v);

	allSubset(v); 

	for (set<vector<int>>::iterator is = s.begin(); is != s.end(); ++is) {
		std::cout << std::endl;
		output(*is); 
	} 

	return 0;
}

