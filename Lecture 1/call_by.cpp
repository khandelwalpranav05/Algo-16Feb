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

void check(int *k) {
	// k++;

	*k = *k + 1;

	cout << "In the function" << endl;
	cout << "Value of a is " << *k << endl;
	cout << "Address of a is " << k << endl;
	cout << "**************************" << endl;

	cout << &k << endl;

	// return k;
}


int main() {

	int a = 10;


	// a = check(a);
	check(&a);
	cout << "In the Main" << endl;
	cout << "Value of a is " << a << endl;
	cout << "Address of a is " << &a << endl;
	cout << "***************************" << endl;

	// int x = 10;

	// int &z = x;

	// z++;

	// cout << "Value of x " << x << endl;

	return 0;
}