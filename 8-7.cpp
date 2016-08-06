
/* 8.7 Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents. */

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

/* ------------------------------------------------ */

/* ERROR VERSION! DOUBLE COUNT*/
/* for example, 6 = 5 * 1 + (1, 5) + (5, 1) */
int error(int n, int quarters, int dimes, int nickles, int pennies) {
	int sum = 25 * quarters + 10 * dimes + 5 * nickles + pennies;
	if (sum > n) { 
		return 0;
	} 
	if (sum == n) { 
		return 1;
	} 
	return 
		error(n, quarters + 1, dimes, nickles, pennies) + 
		error(n, quarters, dimes + 1, nickles, pennies) +
		error(n, quarters, dimes, nickles + 1, pennies) +
		error(n, quarters, dimes, nickles, pennies + 1);
}

/* ------------------------------------------------ */

int combination(int n, int sum, int coinValue) {
	if (sum > n) { 
		return 0;
	} 
	if (sum == n) { 
		return 1;
	} 

    /* if current coinValue is 10, the next only can choose <= 10 */
    /* this limit can avoid double count */ 
	int res = 0;
	switch(coinValue) {
		case 25 : res += combination(n, sum + 25, 25);
		case 10 : res += combination(n, sum + 10, 10);
		case 5  : res += combination(n, sum + 5, 5);
		case 1  : res += combination(n, sum + 1, 1);
	}
	return res;
}

int main(int argc, const char *argv[]) {

	/* 25, 10, 5, 1 */
	int n;
	cin >> n;
	int res = combination(n, 0, 25); 
	std::cout << res << std::endl;

	return 0;
}

