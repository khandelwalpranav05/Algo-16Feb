#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* builtTree(TreeNode* root) {

	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new TreeNode(data);
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

// Time: O(N)
// Space: O(N) or O(h)
void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";

	preOrder(root->left);
	preOrder(root->right);
}

// Time: O(N)
// Space: O(N) or O(h)
void postOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);

	cout << root->val << " ";
}

// Time: O(N)
// Space: O(N) or O(h)
int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 1;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int total = leftCount + rightCount;
	return total;
}

// Inorder HomeWork
// Time: O(N)
// Space: O(N) or O(h)
void inOrder(TreeNode* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

// Time: O(N)
// Space: O(N) or O(h)
int sumOfNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int total = root->val + leftSum + rightSum;
	return total;
}

// Time: O(N)
// Space: O(N) or O(h)
bool search(TreeNode* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	bool leftSearch = search(root->left, key);
	bool rightSearch = search(root->right, key);

	// if (leftSearch or rightSearch) {
	// 	return true;
	// }

	// return false;
	return leftSearch or rightSearch;
}

// Time: O(N)
// Space: O(N) or O(h)
int height(TreeNode* root) {
	if (root == NULL) {
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight, rightHeight) + 1;
	return totalHeight;
}

// Time: O(N)
// Space: O(N) or O(h)
int replaceSum(TreeNode* root) {
	if (root == NULL) return 0;

	if (root->left == NULL and root->right == NULL) {
		return root->val;
	}

	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->val;
	root->val = leftSum + rightSum;

	return root->val + temp;
}

// Time: O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool leftSubtreeCheck = isSameTree(p->left, q->left);
	bool rightSubtreeCheck = isSameTree(p->right, q->right);

	if (leftSubtreeCheck and rightSubtreeCheck) {
		return true;
	}

	return false;
}


// Time: O(n^2)
bool isSubtree(TreeNode* s, TreeNode* t) {
	if (s == NULL) {
		return false;
	}

	if (isSameTree(s, t)) {
		return true;
	}

	bool leftMatch = isSubtree(s->left, t);
	bool rightMatch = isSubtree(s->right, t);

	if (leftMatch or rightMatch) {
		return true;
	}

	return false;
}


//Time: O(n^2)
int diameter(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDiameter = diameter(root->left);
	int rightDiameter = diameter(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int mereThrough = leftHeight + rightHeight + 2;

	int totalDia = max(mereThrough, max(leftDiameter, rightDiameter));

	return totalDia;
}

class DiaHeight {
public:
	int height;
	int diameter;
};

// Time: O(n)
DiaHeight diameterOptimized(TreeNode* root) {
	DiaHeight val;

	if (root == NULL) {
		val.diameter = 0;
		val.height = -1;
		return val;
	}

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;

	int leftHeight = leftPair.height;
	int rightHeight = rightPair.height;

	int mereThrough = leftHeight + rightHeight + 2;

	int totalDia = max(mereThrough, max(leftDiameter, rightDiameter));

	int meriHeight = max(leftHeight, rightHeight) + 1;

	val.diameter = totalDia;
	val.height = meriHeight;
	return val;
}

int main() {

	TreeNode* root = NULL;

	root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// postOrder(root);
	// cout << endl;

	// cout << countNodes(root) << endl;

	// cout << height(root) << endl;

	// replaceSum(root);

	// preOrder(root);
	// cout << endl;

	// cout << diameter(root) << endl;
	DiaHeight val = diameterOptimized(root);
	cout << val.diameter << endl;
	cout << val.height << endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1