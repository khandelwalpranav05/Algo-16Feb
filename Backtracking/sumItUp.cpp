#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> v) {

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void subsets(int si, vector<int> nums, vector<int> temp) {
	if (si == nums.size()) {
		display(temp);
		return;
	}

	// Add Karo
	temp.push_back(nums[si]);
	subsets(si + 1, nums, temp);

	// mat Karo
	temp.pop_back();
	subsets(si + 1, nums, temp);

}

void helper(int si, vector<int> nums, vector<int> temp, int target) {
	if (target == 0) {
		display(temp);
		return;
	}

	if (target < 0) {
		return;
	}

	for (int i = si; i < nums.size(); i++) {
		if (i == si or nums[i] != nums[i - 1]) {
			temp.push_back(nums[i]);
			helper(i + 1, nums, temp, target - nums[i]);
			temp.pop_back();
		}
	}
}

int main() {

	vector<int> v; // dynamic array

	v.push_back(1);
	v.push_back(2); // 1 2 2 3
	v.push_back(2);
	v.push_back(3);

	int target = 3;

	vector<int> temp;
	// subsets(0, v, temp);

	helper(0, v, temp, target);

	return 0;
}