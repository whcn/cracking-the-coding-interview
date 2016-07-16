
/* 8.1 Write a method to generate the nth Fibonacci number. */

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
#include <time.h> 

using namespace std;

long long fibonacci(long long n) { //recursion version
	if (n == 0) { 
		return 0;
	} 
	if (n == 1) { 
		return 1;
	} 
	return fibonacci(n-1) + fibonacci(n - 2);
}

long long fibonacci1(long long n) { //matrix powers version
	long long matrix[2][2] = {{1, 1}, {1, 0}};
	long long partPower[2][2] = {{1, 1}, {1, 0}};
	long long res;
	int mulNum = n -2;
	while (mulNum > 0) { 
		long long temp[2][2] = {0};
		if (mulNum & 1) { 
			temp[0][0] = partPower[0][0] * matrix[0][0] + partPower[0][1] * matrix[1][0];
			temp[0][1] = partPower[0][0] * matrix[0][1] + partPower[0][1] * matrix[1][1];
			temp[1][0] = partPower[1][0] * matrix[0][0] + partPower[1][1] * matrix[1][0];
			temp[1][1] = partPower[1][0] * matrix[0][1] + partPower[1][1] * matrix[1][1];
			partPower[0][0] = temp[0][0];
			partPower[0][1] = temp[0][1];
			partPower[1][0] = temp[1][0];
			partPower[1][1] = temp[1][1];

		} 
		temp[0][0] = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
		temp[0][1] = matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1];
		temp[1][0] = matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0];
		temp[1][1] = matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1];
		matrix[0][0] = temp[0][0];
		matrix[0][1] = temp[0][1];
		matrix[1][0] = temp[1][0];
		matrix[1][1] = temp[1][1];

		mulNum = mulNum >> 1;
	} 
	res = partPower[0][0] * 1 + partPower[0][1] * 0;
	return res;
}

int main(int argc, const char *argv[]) {

	long long n = 50;
	clock_t start = clock();
	long long res = fibonacci(n);
	std::cout << res << std::endl;
	clock_t end = clock();
	std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	start = clock();
	res = fibonacci1(n);
	std::cout << res << std::endl;
	end = clock();
	std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	return 0;
}

