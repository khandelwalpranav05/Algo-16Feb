#include <iostream>

using namespace std;

class node {
public:
	int data;
	node* right;
	node* down;

	node(int data) {
		this->data = data;
		this->right = NULL;
		this->down = NULL;
	}
};

void insertAtRight(node* &head, int data) {

	node* n = new node(data);
	node* temp = head;

	if (head == NULL) {
		head = n;
		return;
	}

	while (temp->right != NULL) {
		temp = temp->right;
	}

	temp->right = n;
}

void insertAtDown(node*&head, int data, int idx) {

	int steps = 1;

	node* temp = head;

	while (steps < idx) {
		steps++;
		temp = temp->right;
	}

	while (temp->down != NULL) {
		temp = temp->down;
	}

	node* n = new node(data);

	temp->down = n;
}

void display(node* head) {

	node* row = head;
	while (row != NULL) {

		node* col = row;

		while (col != NULL) {
			cout << col->data << " ";
			col = col->down;
		}

		row = row->right;
		cout << endl;
	}
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
		c->down = merge(a->down, b);
	} else {
		c = b;
		c->down = merge(a, b->down);
	}

	return c;
}

node* flattenLinkedList(node* head) {
	if (head == NULL or head->right == NULL) {
		return head;
	}

	node* a = head;
	node* b = head->right;

	b = flattenLinkedList(b);

	node* c = merge(a, b);
	return c;
}

void displayFlatten(node*head) {
	node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

int main() {

	node* head = NULL;
	insertAtRight(head, 1);
	insertAtRight(head, 3);
	insertAtRight(head, 2);

	insertAtDown(head, 15, 1);
	insertAtDown(head, 16, 1);

	insertAtDown(head, 8, 2);
	insertAtDown(head, 17, 2);

	insertAtDown(head, 9, 3);

	display(head);

	cout << "*****FLATTEN*******" << endl;

	head = flattenLinkedList(head);

	displayFlatten(head);

	return 0;
}