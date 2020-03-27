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

int main() {

	node* head = NULL;

	insertAtTail(head, 7);

	display(head);

	deleteAtTail(head);

	display(head);

	// display(head);

	// insertAtHead(head, 4);
	// insertAtHead(head, 3);
	// insertAtHead(head, 2);
	// insertAtHead(head, 1);

	// display(head);

	// insertAtTail(head, 5);
	// insertAtTail(head, 6);

	// display(head);

	// deleteAtHead(head);

	// display(head);

	return 0;
}