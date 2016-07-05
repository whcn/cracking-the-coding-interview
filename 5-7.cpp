
/* 5.7 An array A[1…n] contains all the integers from 0 to n except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is “fetch the jth bit of A[i]”, which takes constant time. Write code to find the missing integer. Can you do it in O(n) time? */

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

#define N 10

int fetchBit(int n, int j) {
	return (n >> j) & 1;
}

int main(int argc, const char *argv[]) {

	vector<int> v;
	for (int i = 0; i <= N; ++i) {
		v.push_back(i) ;
	} 

	v.erase(v.begin() + 9);

	int prev = 0;
	int i;
	for (i = 0; i < v.size(); ++i) {
		int next = fetchBit(v[i], 0);
		if (prev != next) { 
			std::cout << i << " miss" << std::endl;
			break;
		} 
		prev = (prev == 0? 1 : 0);
	} 
	if (i == v.size()) { 
		std::cout << i << " miss" << std::endl;
	} 

	return 0;
}

