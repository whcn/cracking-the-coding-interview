
/* Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”). */

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

bool isSubstring(string s1, string s2) {
	int len = s2.length();
	for (int i = 0; i < s1.length()-s2.length()-1; ++i) {
		if (s1.substr(i, len) == s2) { 
			return true;
		} 
	} 
	return false;
}

int main(int argc, const char *argv[]) {

	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	if (s1.length() != s2.length()) { 
		std::cout << "0" << std::endl;
		return 0;
	} 

	std::cout << isSubstring(s1+s1, s2) << std::endl;;

	return 0;
}


