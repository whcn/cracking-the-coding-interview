
/* 9.4 If you have a 2 GB file with one string per line, which sorting algorithm would you use to sort the file and why? */

#include <iostream>
#include <time.h> 
#include <utility> 
#include <queue> 
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

const string before_sort = "before.txt"; 
const string after_sort = "after.txt"; 
const string res = "result.txt"; 
const int totalNum = 15;
const int shardNum = 10;

void generator() {
	srand((unsigned int)time(NULL)); 
	ofstream ofs(before_sort); 
	for (int i = 0; i < totalNum; ++i) {
		ofs << endl << rand() % 1000; 
	} 
	ofs.close();
}

void sort_data() {
	ifstream ifs(before_sort); 
	vector<int> v;
	int tmp;
	while (!ifs.eof()) { 
		ifs >> tmp;
		v.push_back(tmp); 
	} 
	ifs.close();

	std::sort(v.begin(), v.end(), [](const int &lhs, const int &rhs){return lhs < rhs;}); 

	ofstream ofs(after_sort);
	for (auto is = v.begin(); is != v.end(); ++is) {
		ofs << endl << *is;
	} 
	ofs.close();
}

void divide_sort() {
	ifstream ifs(before_sort); 
	for (int i = 0; i < (totalNum + shardNum - 1) / shardNum; ++i) {
		vector<int> v;
		for (int i = 0; i < shardNum; ++i) {
			if (ifs.eof()) { 
				break;
			} 
			int tmp;
			ifs >> tmp;
			v.push_back(tmp); 
		} 

		std::sort(v.begin(), v.end(), [](const int a, const int b){return a > b;});

		string subFile = "data" + to_string(i) + ".txt";
		ofstream ofs(subFile); 
		while (!v.empty()) { 
			ofs << endl << v.back();
			v.pop_back();
		} 
		ofs.close(); 
	} 
	ifs.close();
}

void merge() {

	/* open multiple files */
	vector<ifstream> files((totalNum + shardNum - 1) / shardNum);
	int index = 0;
	for (auto is = files.begin(); is != files.end(); ++is) {
		string subFile = "data" + to_string(index++) + ".txt";
		(*is).open(subFile); 
	} 


	/* construct a priority queue */
	using my_pair = pair<int, ifstream *>; //can not use ifstream &
	using my_container = vector<my_pair>;
	auto my_comparator = [](const my_pair &lhs, const my_pair &rhs) { return lhs.first > rhs.first; };
	priority_queue<my_pair, my_container, decltype(my_comparator)> pq(my_comparator);


	/* every file push one element into queue */
	for (auto &item : files) {
		if (!item.eof()) { 
			int num;
			item >> num;
			pq.push(std::make_pair(num, &item)); 
		} 
	} 

	/* merge all files into result file */
	ofstream ofs(res); 
	while (!pq.empty()) { 
		auto tmp_pair = pq.top(); 
		pq.pop();
		ofs << tmp_pair.first << endl;

		if (!((*(tmp_pair.second)).eof())) { 
			int num;
			*(tmp_pair.second) >> num;
			pq.push(make_pair(num, tmp_pair.second)); 
		} 
	} 
	ofs.close();


	/* close files */
	index = 0;
	for (auto is = files.begin(); is != files.end(); ++is) {
		string subFile = "data" + to_string(index++) + ".txt";
		(*is).close(); 
	} 
}

int main(int argc, const char *argv[]) {

	generator();
	sort_data();
	divide_sort();
	merge();

	return 0;
}

