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

bool search(TreeNode* root, int key) {
	//TODO
}

int main() {

	TreeNode* root = insert();

	preOrder(root);
	cout << endl;

	inOrder(root);
	cout << endl;

	return 0;
}

// 4 2 1 3 6 5 7 -1