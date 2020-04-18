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

TreeNode* builtBST(TreeNode* root, int data) {
	if (root == NULL) {
		return new TreeNode(data);
		// root = new TreeNode(data);
		// return root;
	}

	if (root->val > data) {
		root->left = builtBST(root->left, data);
	} else {
		root->right = builtBST(root->right, data);
	}

	return root;
}

TreeNode* insert() {

	TreeNode* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		root = builtBST(root, data);
		cin >> data;
	}

	return root;
}

void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";

	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}


// Time: O()
bool search(TreeNode* root, int key) {
	if (root == NULL) return false;

	if (root->val == key) return true;

	if (key > root->val) {
		return search(root->right, key);
	} else {
		return search(root->left, key);
	}
}

bool isBST(TreeNode* root, int minRange = INT_MIN, int maxRange = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	bool leftBST = isBST(root->left, minRange, root->val);
	bool rightBST = isBST(root->right, root->val, maxRange);

	if (leftBST and rightBST and root->val > minRange and root->val < maxRange) {
		return true;
	}

	return false;
}

class TreeDetail {
public:
	int size;
	bool bst;
	int minValue;
	int maxValue;
};

// TreeDetail largestBstInBinaryTree(TreeNode* root) {}

int main() {

	TreeNode* root = insert();

	// TreeNode* root = NULL;
	// root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	// cout << search(root, 5) << endl;

	// cout << isBST(root) << endl;


	return 0;
}

// 4 2 1 3 6 5 7 -1

//leftview
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1