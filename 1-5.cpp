
/* 1.5 Write a method to replace all spaces in a string with ‘%20’. */

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

void replaceSpace(string &s) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ') { 
			s = s.substr(0, i) + "%20" + s.substr(i+1, s.length()-i-1);
		} 
	} 
}

int main(int argc, const char *argv[]) {

	string str = "1.5 Write a method to replace all spaces in a string with ‘%20’.";
	replaceSpace(str);
	std::cout << str << std::endl;

	return 0;
}


