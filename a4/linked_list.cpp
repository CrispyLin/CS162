#include "linked_list.h"
#include <iostream>
using namespace std;

Linked_List::Linked_List() {
	this->head = NULL;
	this->length = 0;
}

int Linked_List::get_length() {
	return this->length;
}

Node* Linked_List::get_head() const{
	return this->head;
}

void Linked_List::print() {
	Node* n = this->head;
	while (n!=NULL) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

void Linked_List::clear() {
	Node* n = this->head;
	Node* next = n->next;
	while (next != NULL) {
		this->length--;
		delete n;
		n = next;
		if (next->next != NULL) {
			next = next->next;
		}
		else {
			next = NULL;
		}
	}
	delete n;
	this->length--;
}

void Linked_List::push_front(int val) {
	Node* n = this->head;
	Node* new_node = new Node;
	new_node->val = val;
	new_node->next = n;
	this->head = new_node;
	this->length++;
	return;
}

void Linked_List::push_back(int val) {
	Node* n = this->head;
	Node* new_node = new Node;
	new_node->val = val;
	new_node->next = NULL;
	while (n->next != NULL) {
		n = n->next;
	}
	n->next = new_node;
	this->length++;
}

void Linked_List::insert(int val, unsigned int index) {
	if (index < 0 || index > this->length)
		return;


	if (index == 0)//index 0 means add a new node to the front
		push_front(val);
	else if (index == this->length) //index size means add a new node to the tail of the list
		push_back(val);
	else {//otherwise I need to look for the correct position in the list
		Node* n = this->head;
		Node* parent = NULL;

		Node* new_node = new Node;
		new_node->val = val;

		for (int i = 0; i < index; i++) {
			parent = n;//hold the index-1's address
			n = n->next;//iterate
		}
		parent->next = new_node;
		new_node->next = n;
		this->length++;
	}	
}

//reference: https://www.techiedelight.com/merge-sort-singly-linked-list/
void Linked_List::sort_ascending() {
	MergeSort(&(this->head)); //time complexcity is O(nlogn)
}

//selection sort takes O(n^2) time
void Linked_List::sort_descending() {
	Node* h = NULL;
	Node* p = NULL;
	Node* q = NULL;
	Node* min1 = NULL;
	Node* min2 = NULL;
	while (head!=NULL)
	{
		for (p = head, min1 = head; p; q = p, p = p->next)//loop to find the smallest node
		{
			if (min1->val > p->val){
				min2 = q;
				min1 = p;
			}
		}
		if (min1 == head)//if the smallest node is the head node
			head = head->next;//remove the node from the list
		else
			min2->next = min1->next;//remove the smallest node

		min1->next = h;
		h = min1;
	}
	head = h;
}

bool is_prime(int val) {
	if (val < 2) 
		return false;

	for (int d = 2; d < val; ++d) {
		if (val % d == 0)
			return false;
	}
	return true;
}

//finding a prime number takes O(n) time, there are n prime numbers, so it takes O(n^2) time
int count_prime(const Linked_List& L) {
	int count = 0;
	Node* n = L.get_head();
	while (n != NULL) {
		if (is_prime(n->val) == true) {
			count++;
		}
		n = n->next;
	}
	return count;
}



Node* SortedMerge(Node* a, Node* b){
	// Base case
	if (a == NULL)
		return b;

	else if (b == NULL)
		return a;

	Node* return_node = NULL;

	// Pick a or b
	if (a->val <= b->val)
	{
		return_node = a;
		return_node->next = SortedMerge(a->next, b);
	}
	else
	{
		return_node = b;
		return_node->next = SortedMerge(a, b->next);
	}

	return return_node;
}

void split(Node* L,Node** f,Node** b){
	if (L == NULL || L->next == NULL)
	{
		*f = L;
		*b = NULL;
		return;
	}

	Node* n1 = L;
	Node* n2 = L->next;

	while (n2 != NULL)
	{
		n2 = n2->next;
		if (n2 != NULL)
		{
			n1 = n1->next;
			n2 = n2->next;
		}
	}

	*f = L;
	*b = n1->next;
	n1->next = NULL;
}

//Merge sort algorithm
void MergeSort(Node** head){
	// Base case
	if (*head == NULL || (*head)->next == NULL)
		return;

	Node* a;
	Node* b;

	// Split the list
	split(*head, &a, &b);

	// Recursively sort the lists
	MergeSort(&a);
	MergeSort(&b);

	// combine two sorted sublists
	*head = SortedMerge(a, b);
}
