
/* 1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, 
 * write a method to rotate the image by 90 degrees. Can you do this in place? */

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

int matrix[N][N];


void reverse(int matrix[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N / 2; ++j) {
			swap(matrix[j][i], matrix[N-j-1][i]);
		}  
	} 
}

void transpose(int matrix[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}  
	} 
}

int main(int argc, const char *argv[]) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = i * 5 + j;
		}  
	} 

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << matrix[i][j] << ' ';
		}  
		std::cout << std::endl;
	} 
	std::cout << std::endl;

	transpose(matrix);
	reverse(matrix);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << matrix[i][j] << ' ';
		}  
		std::cout << std::endl;
	} 

	return 0;
}



