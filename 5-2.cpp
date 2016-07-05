
/* 5.2 Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation. If the number can not be represented accurately in binary, print “ERROR” */

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
#include <cmath> 

using namespace std;

string int2bin(double integers) {
	string res = "";
	while ((int)integers != 0) { 
		res = to_string((int)integers % 2) + res; 
		integers = integers / 2;
	} 
	return res;
}

string dec2bin(double decimals) {

	string res = "";
	while (decimals > 0) { 
		if (res.size() > 32) { 
			std::cout << "ERROR" << std::endl;
			exit(0);
		} 
		decimals *= 2;
		res += to_string((int)decimals);
		decimals -= (int)decimals;
	} 
	return res;
}

int main(int argc, const char *argv[]) {

	double input = 5.625;
	double integers = (double)(int)input;
	double decimals = input - integers;
	std::cout << integers << ' ' << decimals << std::endl;

	string res = "";
	res += int2bin(integers);
	res += ".";
	res += dec2bin(decimals);
	std::cout << res << std::endl;

	return 0;
}

