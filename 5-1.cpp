
/* 5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j). EXAMPLE: Input: N = 10000000000, M = 10101, i = 2, j = 6 Output: N = 10001010100 */

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
#include <stack> 

using namespace std;

string dec2bin(int n) {
	string res = "";

	while (n != 0) { 
		res = to_string(n % 2) + res;
		n /= 2;
	} 
	std::cout << res << std::endl;
	return res;
}

string replaceSubstring1(int i, int j, string N, string M) {
	N.replace(N.size() - j - 1, M.size(), M);
	return dec2bin(stoi(N, 0, 2));
}

string replaceSubString2(int i, int j, int N, int M) {
	int right = ((1 << i) - 1) & N;
	return dec2bin((N >> (j + 1) << (j + 1)) | (M << i) | (right));
}

int main(int argc, const char *argv[]) {

	int N, M;
	int i, j;

	N = 0b10000000000;
	M = 0b10101;

	i = 2;
	j = 6;

	replaceSubstring1(i, j, dec2bin(N), dec2bin(M));
	replaceSubString2(i, j, N, M);

	return 0;
}

