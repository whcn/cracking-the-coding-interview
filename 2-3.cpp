
/* 2.3 Implement an algorithm to delete a node in the middle of a single linked list, 
 * given only access to that node. EXAMPLE Input: the node ‘c’ from the linked list a->b->c->d->e 
 * Result: nothing is returned, but the new linked list looks like a->b->d->e */

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

#define LEN 10

struct node {
	int data;
	node *next;
} /* optional variable list */;

node* init()  {
	node *head = NULL;
	for (int i = 0; i < LEN; ++i) {
		node *tmp = new node();
		tmp->data = i;
		tmp->next = NULL;
		if (head == NULL) { 
			head = tmp;
		} else { 
			tmp->next = head;
			head = tmp;
		} 
	} 
	return head;
}

void deleteNode(node* target) {
	if (target == NULL) { 
		return;
	} 
	if (target->next == NULL) { 
		target->data = -1;
		return;
	} 
	int tmp = target->next->data;
	target->next = target->next->next;
	target->data = tmp;
}

node* moveTarget(node *target, int n) {
	if (n > 0 && n <= LEN) { 
		for (int i = 1; i < n; ++i) {
			target = target->next; 
		} 
		return target;
	} else { 
		std::cout << "surpass list length" << std::endl; 
		return NULL;
	} 
}

int main(int argc, const char *argv[]) {

	int n;
	while (cin >> n) { 
		node* head = init();
		node *traversal = head;
		while (traversal != NULL && traversal->data != -1) { 
			std::cout << traversal->data << ' ';
			traversal = traversal->next;
		} 
		std::cout << std::endl;

		node *target = head;
		target = moveTarget(target, n);

		deleteNode(target); 
		traversal = head;
		while (traversal != NULL && traversal->data != -1) { 
			std::cout << traversal->data << ' ';
			traversal = traversal->next;
		} 
		std::cout << std::endl;
	} 

	return 0;
}


