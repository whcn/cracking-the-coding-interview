
/* 9.5 Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string. Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4 Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1 */

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

int locate(string str[], int len, string target) {
	if (target == "") { 
		return -1;
	} 
	for (int i = 0; i < len; ++i) {
		if (str[i] == target) { 
			return i;
		}  
	} 
	return -1;
}

int bisection(string str[], int len, string target) {
	if (target == "") { 
		return -1;
	} 
	int begin = 0;
	int end = len - 1;
	while (begin <= end) { 
		int middle = (begin + end) / 2;
		int tmp = middle;
		while (tmp <= end && str[tmp] == "") { 
			++tmp;
		} 
		if (tmp > end) { 
			end = middle - 1;
			continue;
		}

		if (str[tmp] < target) { 
			begin = tmp + 1;
		} else if (str[tmp] > target) {
			end = middle - 1;
		} else { 
			return tmp; 
		} 
	} 
	return -1;
}

int main(int argc, const char *argv[]) {

	string str[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	int len = sizeof(str) / sizeof(str[0]); 

	cout << locate(str, len, "ball") << endl; 
	cout << locate(str, len, "ballcar") << endl; 

	cout << bisection(str, len, "ball") << endl; 
	cout << bisection(str, len, "ballcar") << endl; 


	return 0;
}

