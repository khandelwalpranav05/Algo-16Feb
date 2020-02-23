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

string removeDuplicates(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = removeDuplicates(ros);

	if (recursionResult[0] == ch) {
		return recursionResult;
	} else {
		return ch + recursionResult;
	}
}

int main() {

	cout << removeDuplicates("abbccdggf") << endl;

	return 0;
}