
/* 5.3 Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation. */

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

int numOfOneBits(int n) {
	int res = 0;
	while (n != 0) { 
		n &= (n - 1);
		++res;
	} 
	return res;
}

int nextSmallest(int n) {
	int res = n;
	while (numOfOneBits(--res) != numOfOneBits(n)) { 
		;
	} 
	return res;
}

int nextLargest(int n) {
	int res = n;
	while (numOfOneBits(++res) != numOfOneBits(n)) { 
		;
	}
	return res;
}


int main(int argc, const char *argv[]) {

	int n;
	cin >> n;
	std::cout << numOfOneBits(n) << std::endl;

	return 0;
}

