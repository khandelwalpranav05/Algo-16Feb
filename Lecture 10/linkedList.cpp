#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class node {
public:
	int data;
	node* next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void display(node* head) {

	node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void insertAtHead(node* &head, int data) {
	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertAtTail(node* &head, int data) {
	if (head == NULL) {
		insertAtHead(head, data);
		return;
	}

	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	node* n = new node(data);
	temp->next = n;
}

void deleteAtHead(node* &head) {

	node* toBeDeleted = head;

	head = head->next;
	delete toBeDeleted;
}

void deleteAtTail(node* &head) {
	if (head == NULL) return;

	if (head->next == NULL) {
		deleteAtHead(head);
		return;
	}

	node* temp = head;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;

	delete toBeDeleted;
}

int length(node* head) {

	node* temp = head;

	int len = 0;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}

bool search(node* head, int key) {
	node* temp = head;

	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}

	return false;
}

void insertAtIndex(node* &head, int data, int idx) {
	if (idx <= 1 or head == NULL) {
		insertAtHead(head, data);
		return;
	}

	if (idx > length(head)) {
		insertAtTail(head, data);
		return;
	}

	int jump = idx - 2;

	node* temp = head;

	while (jump != 0) {
		temp = temp->next;
		jump--;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtIndex(node* &head, int idx) {
	if (head == NULL) return;

	if (idx <= 1 or head->next == NULL) {
		deleteAtHead(head);
		return;
	}

	if (idx == length(head)) {
		deleteAtTail(head);
		return;
	}

	node* temp = head;
	int jump = idx - 2;

	while (jump != 0) {
		temp = temp->next;
		jump--;
	}

	node* toBeDeleted = temp->next;

	temp->next = temp->next->next;
	delete toBeDeleted;
}

node* midPoint(node* head) {

	node* slow = head;
	node* fast = head;

	//TODO
	while () {

	}

	return slow;
}

int main() {

	node* head = NULL;

	insertAtTail(head, 7);

	display(head);

	deleteAtTail(head);

	display(head);

	display(head);

	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	display(head);

	insertAtTail(head, 5);
	insertAtTail(head, 6);

	display(head);

	insertAtIndex(head, 789, 5);

	display(head);

	deleteAtIndex(head, 5);

	display(head);

	// cout << length(head) << endl;

	// deleteAtHead(head);

	// display(head);

	return 0;
}