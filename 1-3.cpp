
/* Design an algorithm and write code to remove the duplicate
   characters in a string without using any additional buffer. 
   NOTE: One or two additional variables are fine. 
   An extra copy of the array is not. 
   FOLLOW UP Write the test cases for this method. */

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

string deleteDup(string str) {
	for (int i = 0; i < str.length(); ++i) {
		for (int j = i+1; j < str.length(); ) {
			if (str[i] == str[j]) { 
				/* string left = str.substr(0, j); */
				/* string right = str.substr(j+1, str.length()-j-1); */
				/* std::cout << left << ' ' << right << std::endl; */
				/* str = left + right; */
				/* std::cout << str << std::endl; */
				str = str.substr(0, j) + str.substr(j+1, str.length()-j-1); 
			} else { 
				++j; 
			} 
		} 
	} 
	return str;
}

int main(int argc, const char *argv[]) {

	string str = "Design an algorithm and write code to remove.";
	string s1 = "abcde";
    string s2 = "aaabbb";
    string s3 = "";
    string s4 = "abababc";
    string s5 = "ccccc";

	std::cout << deleteDup(s1) << std::endl;
	std::cout << deleteDup(s2) << std::endl;
	std::cout << deleteDup(s3) << std::endl;
	std::cout << deleteDup(s4) << std::endl;
	std::cout << deleteDup(s5) << std::endl;

	return 0;
}
