
/* 8.5 Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parentheses. EXAMPLE: input: 3 (e.g., 3 pairs of parentheses) output: ()()(), ()(()), (())(), ((())) */

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

#define N 3

string combination[100];

void parentheses(int len, int leftNum, int rightNum) {
	if (leftNum > rightNum) { 
		return;
	} 
	if (leftNum == 0) { 
		for (int i = 0; i < 2 * N - rightNum; ++i) {
			std::cout << combination[i];
		} 
		for (int i = 0; i < rightNum; ++i) {
			std::cout << ')';
		} 
		std::cout << std::endl;
		return;
	} 
	combination[len] = '('; 
	parentheses(len + 1, leftNum - 1, rightNum); 
	combination[len] = ')'; 
	parentheses(len + 1, leftNum, rightNum - 1); 
	return;
}

int main(int argc, const char *argv[]) {

	parentheses(0, N, N); 

	return 0;
}

