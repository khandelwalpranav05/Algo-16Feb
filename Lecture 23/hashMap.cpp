#include <iostream>

using namespace std;

template <typename T>
class node {
public:
	string key;
	T value;
	node<T>* next;

	node(string key, T value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T>
class HashTable {
	int maxSize;
	int currSize;
	node<T>* *bucket;

	int hashFunction(string key) {
		int idx = 0;
		int mulFactor = 1;

		for (int i = 0; i < key.length(); i++) {
			int B = (key[i] % this->maxSize * mulFactor % this->maxSize) % this->maxSize;
			idx = (idx % this->maxSize + B % this->maxSize) % this->maxSize;

			mulFactor = (mulFactor % this->maxSize * 37 % this->maxSize);
		}

		return idx % this->maxSize;
	}

public:
	HashTable(int default_size = 7) {
		this->maxSize = default_size;
		this->currSize = 0;
		this->bucket = new node<T>*[this->maxSize];

		for (int i = 0; i < this->maxSize; i++) {
			bucket[i] = NULL;
		}
	}

	void rehash() {
		int oldSize = this->maxSize;
		node<T>* *oldBucket = this->bucket;

		this->maxSize = 2 * oldSize;
		this->bucket = new node<T>*[this->maxSize];

		for (int i = 0; i < this->maxSize; i++) {
			bucket[i] = NULL;
		}

		this->currSize = 0;

		for (int i = 0; i < oldSize; i++) {
			node<T>* temp = oldBucket[i];

			while (temp != NULL) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
		}

		delete [] oldBucket;
	}

	void insert(string key, T value) {

		float loadFactor = (float)currSize / maxSize;

		if (loadFactor > 0.5) {
			rehash();
		}

		int idx = hashFunction(key);

		node<T>* n = new node<T>(key, value);
		n->next = bucket[idx];
		bucket[idx] = n;

		this->currSize++;
	}

	T* search(string key) {
		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		while (temp != NULL) {
			if (temp->key == key) {
				return &(temp->value);
			}
			temp = temp->next;
		}

		return NULL;
	}

	void erase(string key) {

		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		if (temp == NULL) {
			cout << "NOT FOUND" << endl;
			return;
		}

		if (key == temp->key) {
			node<T>* toBeDeleted = bucket[idx];
			bucket[idx] = bucket[idx]->next;
			delete toBeDeleted;
			return;
		}

		while (temp->next != NULL) {
			if (temp->next->key == key) {
				break;
			}
			temp = temp->next;
		}

		if (temp->next == NULL) {
			cout << "NOT FOUND" << endl;
			return;
		}

		node<T>* toBeDeleted = temp->next;
		temp->next = temp->next->next;
		delete toBeDeleted;
	}

	void display() {

		for (int i = 0; i < this->maxSize; i++) {
			node<T>* temp = bucket[i];

			while (temp != NULL) {
				cout << "( " << temp->key << ", " << temp->value << ") ->";
				temp = temp->next;
			}
			cout << endl;
		}

		cout << "***********************************" << endl;
	}

};

int main() {

	HashTable<int> hp;

	hp.insert("Finland", 1);
	hp.insert("Canada", 9);
	hp.insert("Pakistan", 67);

	hp.display();

	hp.insert("India", 144);

	hp.insert("North Korea", 999);

	hp.display();

	// hp.erase("India");

	// hp.display();

	// int* data  = hp.search("pranav");

	// if (data == NULL) {
	// 	cout << "NOT FOUND" << endl;
	// } else {
	// 	cout << *data << endl;
	// }

	return 0;
}