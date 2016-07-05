
/* Implement an algorithm to determine if a string has all unique characters.
 * What if you can not use additional data structures? */

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

bool isDuplicate(string s) {
	bool dup[256];
	std::memset(dup, false, sizeof(dup));
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		int index = (int)s[i];
		if (dup[index]) {
			return false;
		} else {
			dup[index] = true;
		}
	} 
	return true;
}

bool isDuplicate_bit(string s) {
	int dup[8];
	std::memset(dup, 0, sizeof(dup));
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		int index = s[i] / 32;
		int shift = s[i] % 32;
		if (dup[index] & (1 << shift)) {
			return false;
		} else {
			dup[index] = dup[index] | (1<<shift);
		}
	} 
	return true;
}

int main(int argc, const char *argv[]) {

	string s1 = "i am hawstein.";
    string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";

	std::cout << isDuplicate(s1) << std::endl;
	std::cout << isDuplicate(s2) << std::endl;

	std::cout << isDuplicate_bit(s1) << std::endl;
	std::cout << isDuplicate_bit(s2) << std::endl;

	return 0;
}

