
/* 1.4 Write a method to decide if two strings are isAnagrams or not. */

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

bool isAnagram(string s1, string s2) {
	if (s1.length() != s2.length()) { 
		return false;
	} 
	map<char, int> m1, m2;
	for (int i = 0; i < s1.length(); ++i) {
		++m1[s1[i]];
		++m2[s2[i]];
	} 
	if (m1 == m2) { 
		return true; 
	} else { 
		return false; 
	} 
}

int main(int argc, const char *argv[]) {

	string s1 = "hello";
	string s2 = "leohl";
	string s3 = "eeohl";
	std::cout << isAnagram(s1, s2) << std::endl;
	std::cout << isAnagram(s1, s3) << std::endl;

	return 0;
}



