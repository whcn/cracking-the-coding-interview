
/* 8.8 Write an algorithm to print all ways of arranging eight queens on a chess board so that none of them share the same row, column or diagonal. */

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
#include <tuple> 

using namespace std;

#define N 4

int point[N];

void output() {
	int chess[N][N];
	std::memset(chess, 0, sizeof(chess)); 
	for (int i = 0; i < N; ++i) {
		chess[i][point[i]] = 1;
	} 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << chess[i][j] << ' ';
		} 
		std::cout << std::endl;
	} 
	std::cout << std::endl;
}

void eightQueens(int row) {
	if (row == N) { 
		output();
		return;
	} 

	for (int col = 0; col < N; ++col) {
		bool flag = true;
		for (int i = 0; i < row; ++i) {
			if (col == point[i] || row - i == col - point[i] || row - i == point[i] - col) { 
				flag = false;
				break;
			}  
		} 
		if (flag) { 
			point[row] = col;
			eightQueens(row + 1); 
		} 
	} 
}

int main(int argc, const char *argv[]) {

	eightQueens(0);

	return 0;
}

