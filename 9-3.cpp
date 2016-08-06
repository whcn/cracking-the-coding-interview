
/* 9.3 Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. You may assume that the array was originally sorted in increasing order. EXAMPLE: Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14) Output: 8 (the index of 5 in the array) */

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

int find(int arr[], int len, int value)  {
	int begin = 0;
	int end = len;
	while (begin < end) { 
		int middle = (end + begin) / 2;
		if (arr[middle] == value) { 
			return middle;
		} 
		if (arr[begin] < arr[middle]) { 
			if (arr[begin] <= value && arr[middle] >= value) { 
				end = middle;
			} else { 
				begin = middle; 
			} 
		} else { 
			if (arr[middle] <= value && arr[end - 1] >= value) { 
				begin = middle;
			} else { 
				end = middle; 
			} 
		} 
	} 
	return -1;
}

int main(int argc, const char *argv[]) {

	int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int len = sizeof(arr) / sizeof(arr[0]); 
	int res = find(arr, len, 5); 
	std::cout << res << std::endl;

	int b[] = {2, 2, 2, 2, 3, 2, 2};
	len = sizeof(b) / sizeof(b[0]); 
	res = find(b, len, 3); 
	std::cout << res << std::endl;
	return 0;
}

