
/* 9.2 Write a method to sort an array of strings so that all the anagrams are next to each other. */

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
#include <string> 

using namespace std;

void split(vector<string> &v, string str) {
	int pre = 0;
	int delimiter;
	while ((delimiter = str.find_first_of(", .", pre)) != std::string::npos) { 
		string subStr = str.substr(pre, delimiter - pre); 
		if (!subStr.empty()) { 
			v.push_back(subStr); 
		} 
		pre = delimiter + 1;
	}
}

void output(vector<string> v) {
	for (auto is = v.begin(); is != v.end(); ++is) {
		std::cout << *is << ' ';
	} 
	std::cout << std::endl;
}

bool isAnagrams(string lhs, string rhs) {
	std::sort(lhs.begin(), lhs.end()); 
	std::sort(rhs.begin(), rhs.end()); 
	return lhs < rhs;
}

int main(int argc, const char *argv[]) {

	string str = "The dog is god, the god is dog.";
	vector<string> v;
	split(v, str); 
	output(v);
	std::sort(v.begin(), v.end(), isAnagrams); 
	output(v);

	return 0;
}
