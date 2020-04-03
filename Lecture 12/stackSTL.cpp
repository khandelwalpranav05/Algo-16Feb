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

int main() {

	stack<int> s;

	s.push(3);
	s.push(2);
	s.push(45);
	s.push(37);
	s.push(9);

	s.push(789);

	s.pop();
	s.pop();

	cout << s.size() << endl;

	s.pop();

	cout << s.top() << endl;

	s.pop();
	s.pop();
	s.pop();

	cout << s.empty() << endl;

	return 0;
}