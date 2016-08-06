
/* 9.7 A circus is designing a tower routine consisting of people standing atop one another’s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower. EXAMPLE: Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110) Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190) */

#include <iostream>
#include <vector>
#include <queue> 
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

void longest_subsequence(vector<pair<int, int>> v) {

	/* <longestLength, prevIndex> */
	vector<pair<int, int>> res;
	for (int i = 0; i < v.size(); ++i) {
		int len = 1;
		int prevIndex = 0;
		for (int j = 0; j < i; ++j) {
			auto jcur = v.begin() + j;
			auto icur = v.begin() + i;
			auto rcur = res.begin() + j;

			if ((*jcur).second < (*icur).second && (*rcur).first >= len) { 
				len = (*rcur).first + 1;
				prevIndex = j;
			} 
		} 
		res.push_back(make_pair(len, prevIndex)); 
	} 

	for (auto i : res) {
		std::cout << i.first << ' ' << i.second << std::endl;
		 
	} 
	cout << endl;

	auto rit = res.end() - 1; 
	auto vit = v.end() - 1;
	while ((*rit).first != 1) { 
		std::cout << (*vit).first << ' ' << (*vit).second << std::endl;
		int prevIndex = (*rit).second;
		rit = res.begin() + prevIndex;
		vit = v.begin() + prevIndex;
	} 
	std::cout << (*vit).first << ' ' << (*vit).second << std::endl;
}

int main(int argc, const char *argv[]) {

	using my_pair = std::pair<int, int>;
	using my_container = std::vector<my_pair>;
	auto my_comparator = [](const my_pair &lhs, const my_pair &rhs){return lhs.first > rhs.first;}; 
	priority_queue<my_pair, my_container, decltype(my_comparator)> pq(my_comparator); 

	/* pq.push(make_pair(65, 100)); */ 
	/* pq.push(make_pair(70, 150)); */ 
	/* pq.push(make_pair(56, 90)); */ 
	/* pq.push(make_pair(75, 190)); */ 
	/* pq.push(make_pair(60, 95)); */ 
	/* pq.push(make_pair(68, 110)); */ 

	pq.push(make_pair(70, 150)); 
	pq.push(make_pair(68, 160)); 
	pq.push(make_pair(68, 160)); 
	pq.push(make_pair(75, 190)); 
	pq.push(make_pair(67, 155)); 


	vector<pair<int, int>> v;
	while (!pq.empty()) { 
		v.push_back(pq.top()); 
		pq.pop();
	} 

	longest_subsequence(v);

	return 0;
}

