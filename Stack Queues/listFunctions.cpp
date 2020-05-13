#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {

	list<int> val;

	val.push_back(1);
	val.push_back(2);
	val.push_back(3);
	val.push_back(4);

	// for (int v : val) {
	// 	cout << v << "->";
	// }
	// cout << endl;

	// cout << "Size -> " << val.size() << endl;

	val.push_front(45);
	val.push_front(23);
	val.push_front(78);
	val.push_front(65);

	// for (int v : val) {
	// 	cout << v << "->";
	// }
	// cout << endl;

	// cout << "Size -> " << val.size() << endl;

	// cout << "Head value ->" << val.front() << endl;

	// cout << "Tail value ->" << val.back() << endl;

	// cout << val.empty() << endl;

	val.sort();

	for (int v : val) {
		cout << v << "->";
	}
	cout << endl;

	return 0;
}