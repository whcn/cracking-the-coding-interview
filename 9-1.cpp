
/* 9.1 You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order. */

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

const int LEN = 5;

void init(int arr[]) {
	for (int i = 0; i < LEN; ++i) {
		arr[i] = rand() % 100;
	} 
}

void output(int *arr) {
	for (int i = 0; i < LEN; ++i) {
		std::cout << arr[i] << ' ';
	} 
	std::cout << std::endl;
}

void merge(int *a, int *b) {
	int end = LEN;
	for (int i = 0; i < LEN; ++i) {
		int cursor = 0;
		while (a[cursor] <= b[i] && cursor < end) { 
			++cursor;
		} 
		for (int j = end - 1; j >= cursor; --j) {
			a[j + 1] = a[j];
		} 
		a[cursor] = b[i]; 
		++end;
	} 
}

void merge1(int *a, int *b) {
	int aLen = LEN - 1;
	int bLen = LEN - 1;
	int end = 2 * LEN - 1;
	while (aLen >= 0 && bLen >= 0) { 
		if (a[aLen] > b[bLen]) { 
			a[end--] = a[aLen--]; 
		} else { 
			a[end--] = b[bLen--]; 
		} 
	} 
	while (bLen >= 0) { 
		a[end--] = b[bLen--]; 
	} 
}

int main(int argc, const char *argv[]) {

	std::srand((unsigned int)time(NULL)); 
	int a[100], b[100];
	init(a); 
	init(b); 
	std::sort(a, a+LEN); 
	std::sort(b, b+LEN); 
	output(a);
	output(b);
	merge1(a, b); 
	for (int i = 0; i < 2 * LEN; ++i) {
		std::cout << a[i] << ' ';
	} 
	std::cout << std::endl;

	return 0;
}

