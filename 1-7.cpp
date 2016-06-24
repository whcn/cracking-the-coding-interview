
/* 1.7 Write an algorithm such that if an element in an MxN matrix is 0, 
 * its entire row and column is set to 0. */

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

#define M 5
#define N 6

void setZeros(int m[M][N]) {
	set<int> row;
	set<int> col;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (m[i][j] == 0) { 
				row.insert(i);
				col.insert(j);
			} 
		}  
	} 
	for (auto i : row) {
		std::memset(m[i], 0, sizeof(int)*N);
	} 
	for (auto i : col) {
		for (int j = 0; j < M; ++j) {
			m[j][i] = 0; 
		} 
	} 
}

int main(int argc, const char *argv[]) {

	srand((unsigned)time(NULL));  
	int m[M][N];
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			m[i][j] = rand()%9;
		}  
	} 

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << m[i][j] << ' ';
		}  
		std::cout << std::endl;
	} 
	std::cout << std::endl;

	setZeros(m);

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << m[i][j] << ' ';
		}  
		std::cout << std::endl;
	} 

	return 0;
}

