
/* 8.2 Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot? FOLLOW UP Imagine certain squares are “off limits”, such that the robot can not step on them. Design an algorithm to get all possible paths for the robot. */

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
int GRID[N][N];
vector<tuple<int, int>> PATH;


void init() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			GRID[i][j] = 1;
		}  
		std::cout << std::endl;
	} 
	for (int i = 0; i < 2; ++i) {
		GRID[rand() % N][rand() % N] = 0;
	} 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << GRID[i][j] << ' ';
		}  
		std::cout << std::endl;
	} 
}

/* x axis toward left, y axis toward up */
/* if x or y equal 1, there remain only one way to destination */
int pathNum(int x, int y) { 
	if (x == 1 || y == 1) { 
		return 1;
	} 
	return pathNum(x-1, y) + pathNum(x, y-1);
}

void allPath(int row, int col, int len) {
	if (row < N && col < N && GRID[row][col] == 1) { 

		if (PATH.size() <= len) { 
			PATH.push_back(make_tuple(row, col));
			len++;
		} else { 
			PATH.at(len++) = make_tuple(row, col);
		} 

		if (row == N - 1 && col == N - 1) { 
			for (int i = 0; i < PATH.size(); ++i) {
				std::cout << "(" << get<0>(PATH[i]) << ',' << get<1>(PATH[i]) << ") ";
			} 
			std::cout << std::endl;
		} else { 
			allPath(row, col + 1, len);
			allPath(row + 1, col, len);
		} 
	} 
}

int main(int argc, const char *argv[]) {

	init();
	allPath(0, 0, 0);

	int res;
	res = pathNum(N, N);
	std::cout << res << std::endl;

	return 0;
}

