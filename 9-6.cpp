
/* 9.6 Given a matrix in which each row and each column is sorted, write a method to find an element in it. */

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

const int ROWS = 5;
const int COLS = 5;

void locate(int matrix[ROWS][COLS], int target) {
	if (target < matrix[0][0] || target > matrix[ROWS - 1][COLS - 1]) { 
		std::cout << "error" << std::endl;
		return;
	} 

	int row;
	int row_begin = 0;
	int row_end = ROWS;
	while (row_begin <= row_end) { 
		int row_middle = (row_begin + row_end) / 2;
		if (matrix[row_middle][0] == target) { 
			row = row_middle;
			break;
		} 
		if (matrix[row_middle][0] < target && matrix[row_middle + 1][0] > target) { 
			row = row_middle;
			break;
		} 
		if (matrix[row_middle][0] > target && matrix[row_middle - 1][0] < target) { 
			row = row_middle - 1;
			break;
		} 
		if (matrix[row_middle][0] > target) { 
			row_end = row_middle - 1;
		} else { 
			row_begin = row_middle + 1; 
		} 
	} 

	for (int i = 0; i <= row; ++i) {
		int begin = 0;
		int end = COLS - 1;
		while (begin <= end) { 
			int middle = (begin + end) / 2;
			if (matrix[i][middle] < target) { 
				begin = middle + 1;
			} else if (matrix[i][middle] > target) {
				end = middle - 1; 
			} else { 
				std::cout << i << ' ' << middle << std::endl; 
				break;
			} 
		} 
	} 
}


int main(int argc, const char *argv[]) {

	int matrix[ROWS][COLS] =  {
		{1, 2, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{3, 4, 5, 6, 7},
		{4, 5, 6, 7, 8},
		{5, 6, 7, 8, 9},
	};
	
	int row = 0;
	int col = 0;
	locate(matrix, 8);

	return 0;
}

