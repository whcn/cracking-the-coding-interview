
/* 5.6 Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc). */

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


int main(int argc, const char *argv[]) {

	int n;
	cin >> n;
	cout << (((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa)) << endl;

	return 0;
}

