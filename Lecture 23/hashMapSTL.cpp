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

	unordered_map<string, int> hp;

	pair<string, int> p("India", 144);
	hp.insert(p);

	hp.insert(make_pair("Finland", 1));

	hp["Canada"] = 9;

	hp["Canada"] = 78;

	for (pair<string, int> val : hp) {
		cout << val.first << ", " << val.second << endl;
	}

	cout << hp["India"] << endl;

	cout << hp.count("Canada") << endl;
	cout << hp.count("IRAN") << endl;


	return 0;
}