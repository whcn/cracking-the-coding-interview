
/* 5.5 Write a function to determine the number of bits required to convert integer A to integer B. Input: 31, 14 Output: 2 */

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

int countOneBits(int n) {
	int res = 0;
	while (n != 0) { 
		n &= (n-1);
		++res;
	} 
	return res;
}

int diffBits(int a, int b) {
	int c = a ^ b;
	return countOneBits(c);
}

int main(int argc, const char *argv[]) {

	int a, b;
	cin >> a >> b;
	std::cout << diffBits(a, b) << std::endl;

	return 0;
}

