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

TreeDetail largestBstInBinaryTree(TreeNode* root) {
	TreeDetail obj;

	if (root == NULL) {
		obj.bst = true;
		obj.size = 0;
		obj.maxValue = INT_MIN; // INT_MAX
		obj.minValue = INT_MAX; // INT_MIN
		return obj;
	}

	TreeDetail leftStatus = largestBstInBinaryTree(root->left);
	TreeDetail rightStatus = largestBstInBinaryTree(root->right);

	if (!leftStatus.bst or !rightStatus.bst or root->val < leftStatus.maxValue or root->val > rightStatus.minValue) {
		// NOT A BST
		obj.bst = false;
		obj.size = max(leftStatus.size, rightStatus.size);
		return obj;
	}

	// BST

	obj.bst = true;
	obj.size = leftStatus.size + 1 + rightStatus.size;

	obj.maxValue = root->right != NULL ? rightStatus.maxValue : root->val;
	obj.minValue = root->left != NULL ? leftStatus.minValue : root->val;

	return obj;
}

void inorderTraversal(TreeNode* root, int &count, int k, int &ans) {
	if (root == NULL) return;

	inorderTraversal(root->left, count, k, ans);

	count++;
	if (k == count) {
		ans = root->val;
	}

	inorderTraversal(root->right, count, k, ans);
}

int kthSmallest(TreeNode* root, int k) {

	int ans;
	int count = 0;
	inorderTraversal(root, count, k, ans);

	return ans;
}

TreeNode* buildBalancedBST(int arr[], int start, int end) {
	if (start > end) {
		return NULL;
	}

	int mid = start + (end - start) / 2;

	TreeNode* root = new TreeNode(arr[mid]);

	root->left = buildBalancedBST(arr, start, mid - 1);
	root->right = buildBalancedBST(arr, mid + 1, end);

	return root;
}

// LinkedListPair helper(Node* root) {
// 	LinkedListPair obj;

// 	if (root == NULL) {
// 		obj.head = NULL;
// 		obj.tail = NULL;
// 		return obj;
// 	}

// 	if (!root->left and !root->right) {
// 		obj.head = root;
// 		obj.tail = root;
// 		return obj;
// 	}

// 	if (root->left != NULL and root->right == NULL) {
// 		LinkedListPair leftPair = helper(root->left);

// 		leftPair.tail->right = root;
// 		root->left = leftPair.tail;

// 		obj.head = leftPair.head;
// 		obj.tail = root;
// 		return obj;
// 	}

// 	if (root->left == NULL and root->right != NULL) {
// 		LinkedListPair rightPair = helper(root->right);

// 		root->right = rightPair.head;
// 		rightPair.head->left = root;

// 		obj.head = root;
// 		obj.tail = rightPair.tail;
// 		return obj;
// 	}

// 	if (root->left != NULL and root->right != NULL) {
// 		LinkedListPair leftPair = helper(root->left);
// 		LinkedListPair rightPair = helper(root->right);

// 		leftPair.tail->right = root;
// 		root->left = leftPair.tail;

// 		root->right = rightPair.head;
// 		rightPair.head->left = root;

// 		obj.head = leftPair.head;
// 		obj.tail = rightPair.tail;
// 		return obj;
// 	}

// 	return obj;
// }

// class LinkedListPair {
// public:
// 	Node* head;
// 	Node* tail;
// };

int preIndex = 0;

TreeNode* buildTreeFromPreorderInorder(int pre[], int in[], int start, int end) {
	if (start > end) {
		return NULL;
	}

	TreeNode* root = new TreeNode(pre[preIndex]);

	int mid = -1;

	for (int i = start; i <= end; i++) {
		if (in[i] == pre[preIndex]) {
			mid = i;
			break;
		}
	}

	preIndex++;

	root->left = buildTreeFromPreorderInorder(pre, in, start, mid - 1);
	root->right = buildTreeFromPreorderInorder(pre, in, mid + 1, end);

	return root;
}

int main() {

	// TreeNode* root = insert();

	// TreeNode* root = NULL;
	// root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	// cout << search(root, 5) << endl;

	// cout << isBST(root) << endl;

	// TreeDetail obj = largestBstInBinaryTree(root);
	// cout << obj.size << endl;

	// int arr[] = {1, 2, 3, 4, 5, 6, 7};
	// int n = 7;

	// TreeNode* root = buildBalancedBST(arr, 0, n - 1);

	// preOrder(root);
	// cout << endl;

	int in[] = {1, 2, 3, 4, 5, 6, 7};
	int pre[] = {4, 2, 1, 3, 6, 5, 7};
	int n = 7;

	TreeNode* root = buildTreeFromPreorderInorder(pre, in, 0, n - 1);

	preOrder(root);
	cout << endl;

	inOrder(root);
	cout << endl;

	return 0;
}

// 4 2 1 3 6 5 7 -1

//leftview
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1

// largestBstInBinaryTree
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1