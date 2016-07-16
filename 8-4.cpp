
/* 8.4 Write a method to compute all permutations of a string. */

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


void permutation(string s, int cur) {
	if (cur == s.size() - 1) { 
		std::cout << s << std::endl;
		return;
	} 

	for (int i = cur; i < s.size(); ++i) {
		string tmp = s;
		std::swap(tmp[cur], tmp[i]); 
		permutation(tmp, cur + 1); 
	} 
}

int main(int argc, const char *argv[]) {

	string s = "abc"; 
	permutation(s, 0); 

	return 0;
}

