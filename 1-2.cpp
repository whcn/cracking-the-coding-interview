
/* Write code to reverse a C-Style String. (C-String means that “abcd” is 
 * represented as five characters, including the null character.) */

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

void reverse(char *str) {
	int len = strlen(str); //sizeof contain null character, but strlen don't
	for (int i = 0; i < len/2; ++i) {
		swap(str[i], str[len-i-1]);
	} 
}

int main(int argc, const char *argv[]) {

	char str[] = "abcdefghi";
	reverse(str);
	std::cout << str << std::endl;
	return 0;
}

