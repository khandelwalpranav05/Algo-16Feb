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

// class test {
// 	string name;
// 	int arr[89];
// 	char brr[67];
// }

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
	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void reverseIterative(node* &head) {
	node* prev = NULL;
	node* curr = head;

	while (curr != NULL) {

		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}

	head = prev;
}

node* reverseRecursive(node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* newHead = reverseRecursive(head->next);

	node* curr = head;

	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

node* merge(node* a, node* b) {
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	node* c;

	if (a->data <= b->data) {
		c = a;
		c->next = merge(a->next, b);
	} else {
		c = b;
		c->next = merge(a, b->next);
	}

	return c;
}

node* mergeSort(node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* mid = midPoint(head);

	node* a = head;

	node* b = mid->next;

	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a, b);

	return c;
}

node* kReverse(node* head, int k) {
	if (head == NULL or head->next == NULL ) {
		return head;
	}

	node* prev = NULL;
	node* curr = head;

	int count = 1;

	while (count <= k and curr != NULL) { //
		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		count++;
	}

	head->next = kReverse(curr, k);

	return prev;
}

void printInReverse(node* head) {

}

// node* kthFromLast(node* head) {
// 	//TODO
// }

int main() {

	// node* head = NULL;

	// insertAtTail(head, 7);

	// display(head);

	// deleteAtTail(head);

	// display(head);

	// insertAtHead(head, 4);
	// insertAtHead(head, 3);
	// insertAtHead(head, 2);
	// insertAtHead(head, 1);

	// display(head);

	// insertAtTail(head, 5);
	// insertAtTail(head, 6);

	// display(head);

	// cout << "Reversed *******************" << endl;

	// reverseIterative(head);

	// display(head);

	// cout << "Reversed *******************" << endl;

	// head = reverseRecursive(head);

	// display(head);

	// node* mid = midPoint(head);
	// cout << mid->data << endl;

	// insertAtHead(head, 90);

	// display(head);

	// mid = midPoint(head);
	// cout << mid->data << endl;


	// insertAtIndex(head, 789, 5);

	// display(head);

	// deleteAtIndex(head, 5);

	// display(head);

	// cout << length(head) << endl;

	// deleteAtHead(head);

	// display(head);

	// node* head1 = NULL;

	// insertAtTail(head1, 1);
	// insertAtTail(head1, 3);
	// insertAtTail(head1, 5);
	// insertAtTail(head1, 8);
	// insertAtTail(head1, 9);

	// node* head2 = NULL;

	// insertAtTail(head2, 2);
	// insertAtTail(head2, 4);
	// insertAtTail(head2, 6);
	// insertAtTail(head2, 7);

	// cout << "First Linked List ******************" << endl;
	// display(head1);

	// cout << "Second Linked List ******************" << endl;
	// display(head2);

	// node* mergedList = merge(head1, head2);

	// cout << " Merged Linked List ******************" << endl;
	// display(mergedList);

	// node* head = NULL;

	// insertAtTail(head, 1);
	// insertAtTail(head, 6);
	// insertAtTail(head, 5);
	// insertAtTail(head, 3);
	// insertAtTail(head, 4);
	// insertAtTail(head, 2);

	// display(head);

	// head = mergeSort(head);

	// display(head);

	node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	insertAtTail(head, 9);

	display(head);

	head = kReverse(head, 3);

	display(head);

	return 0;
}