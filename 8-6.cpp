
/* 8.6 Implement the “paint fill” function that one might see on many image editing programs. That is, given a screen (represented by a 2 dimensional array of Colors), a point, and a new color, fill in the surrounding area until you hit a border of that color. */

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

#define N 5

int SCREEN[N][N];
int TEMP[N][N];
int pointColor;
int newColor;

void init() {
	srand((unsigned int)time(NULL)); 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			SCREEN[i][j] = rand() % 2; 
			TEMP[i][j] = SCREEN[i][j];
		} 
	} 
}

void output() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << SCREEN[i][j] << " ";
		} 
		std::cout << std::endl;
	} 
	std::cout << std::endl;
}

void paintFill(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= N || SCREEN[row][col] != pointColor || SCREEN[row][col] == newColor) { 
		return;
	} 

	SCREEN[row][col] = newColor;

	paintFill(row - 1, col); 
	paintFill(row + 1, col); 
	paintFill(row, col - 1); 
	paintFill(row, col + 1); 
}

int main(int argc, const char *argv[]) {

	init();
	output();

	int row, col;
	row = rand() % N;
	col = rand() % N;
	pointColor = SCREEN[row][col]; 
	newColor = -1;
	std::cout << row << ' ' << col << std::endl << std::endl;

	paintFill(row, col); 

	output();

	return 0;
}

