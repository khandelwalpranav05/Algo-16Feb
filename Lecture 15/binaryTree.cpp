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

	int rightDiameter = diameter(root->right);
	int leftDiameter = diameter(root->left);

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

// Time: O(n^2)
bool balanceBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	bool leftBalance = balanceBinaryTree(root->left);
	bool rightBalance = balanceBinaryTree(root->right);

	if (!leftBalance or !rightBalance) {
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int gap = abs(leftHeight - rightHeight);

	// if (gap > 1) {
	// 	return false;
	// }

	// return true;
	return gap <= 1;
}

class BalanceHeight {
public:
	int height;
	bool balance;
};

BalanceHeight balanceOptimized(TreeNode* root) {
	BalanceHeight val;

	if (root == NULL) {
		val.height = -1;
		val.balance = true;
		return val;
	}

	BalanceHeight leftPair = balanceOptimized(root->left);
	BalanceHeight rightPair = balanceOptimized(root->right);

	val.height = max(leftPair.height, rightPair.height) + 1;

	if (!leftPair.balance or !rightPair.balance) {
		val.balance = false;
		return val;
	}

	int gap = abs(leftPair.height - rightPair.height);

	if (gap > 1) {
		val.balance = false;
		return val;
	}

	val.balance = true;
	return val;

}

void display(vector<int> &temp) {
	for (int val : temp) {
		cout << val << "->";
	}
	cout << endl;
}

void printRootToLeaf(TreeNode* root, vector<int> path) {
	if (root == NULL) {
		// display(path);
		return;
	}

	path.push_back(root->val);

	if (root->left == NULL and root->right == NULL) {
		display(path);
		return;
	}

	printRootToLeaf(root->left, path);
	printRootToLeaf(root->right, path);
}

bool isMirror(TreeNode* p, TreeNode* q) {
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool leftCheck = isMirror(p->left, q->right);
	bool rightCheck = isMirror(p->right, q->left);

	return leftCheck and rightCheck;
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL) return true;

	return isMirror(root->left, root->right);
}

void levelOrder(TreeNode* root) {

	queue<TreeNode*> q;

	q.push(root);

	while (!q.empty()) {

		TreeNode* temp = q.front();
		q.pop();

		cout << temp->val << " ";

		if (temp->left != NULL) {
			q.push(temp->left);
		}

		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}

	cout << endl;
}

void levelOrderNewLine(TreeNode* root) {

	queue< pair<TreeNode*, int> > q;

	// pair<int, string> p(10, "pranav");
	// cout << p.first << endl;
	// cout << p.second << endl;

	pair<TreeNode*, int> p(root, 1);

	q.push(p);

	int currLevel = 1;

	// q.push({root, 1});

	while (!q.empty()) {

		pair<TreeNode*, int> temp = q.front();
		q.pop();

		TreeNode* node = temp.first;
		int level = temp.second;

		// MERA

		if (currLevel == level) {
			cout << node->val << " ";
		} else if (currLevel < level) {
			cout << endl;
			cout << node->val << " ";
			currLevel = level;
		}

		// PUSH
		if (node->left != NULL) {
			pair<TreeNode*, int> p(node->left, level + 1);
			q.push(p);
		}

		if (node->right != NULL) {
			pair<TreeNode*, int> p(node->right, level + 1);
			q.push(p);
		}
	}

	cout << endl;
}

// BFS
// Time: O(n)
void levelOrderNewLineBetter(TreeNode* root) {

	queue<TreeNode*> q;

	q.push(root);

	while (!q.empty()) {

		int len = q.size();

		for (int i = 0; i < len; i++) {

			TreeNode* temp = q.front();
			q.pop();

			cout << temp->val << " ";

			if (temp->left != NULL) {
				q.push(temp->left);
			}

			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}

		cout << endl;
	}
}

int maxSum(TreeNode* root, int &maxGlobal) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = maxSum(root->left, maxGlobal);
	int rightMax = maxSum(root->right, maxGlobal);

	leftMax = max(0, leftMax);
	rightMax = max(0, rightMax);

	int mereThroughPath = leftMax + root->val + rightMax;

	maxGlobal = max(maxGlobal, mereThroughPath);

	return max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode* root) {

	int maxGlobal = INT_MIN;
	maxSum(root, maxGlobal);
	return maxGlobal;
}

int firstTime = 1;

void leftView(TreeNode* root, int level) {
	if (root == NULL) {
		return;
	}

	if (level == firstTime) {
		cout << root->val << " ";
		firstTime++;
	}

	leftView(root->left, level + 1);
	leftView(root->right, level + 1);
}

void leftBoundary(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		return;
	}

	cout << root->val << " ";

	if (root->left != NULL) {
		leftBoundary(root->left);
	} else {
		leftBoundary(root->right);
	}
}

void rightBoundary(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		return;
	}

	if (root->right != NULL) {
		rightBoundary(root->right);
	} else {
		rightBoundary(root->left);
	}

	cout << root->val << " ";
}

void printLeafNode(TreeNode* root) {
	//TODO
}

void nodesKdistanceBelow(TreeNode* root, int k, int level) {
	if (root == NULL) return;

	if (level == k) {
		cout << root->val << " ";
	}

	nodesKdistanceBelow(root->left, k, level + 1);
	nodesKdistanceBelow(root->right, k, level + 1);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL) {
		return NULL;
	}

	if (root == p or root == q) {
		return root;
	}

	TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
	TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

	if (leftLCA != NULL and rightLCA != NULL) {
		return root;
	}

	if (leftLCA == NULL and rightLCA == NULL) {
		return NULL;
	}

	return leftLCA != NULL ? leftLCA : rightLCA;
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
	// DiaHeight val = diameterOptimized(root);
	// cout << val.diameter << endl;
	// cout << val.height << endl;

	// cout << balanceBinaryTree(root) << endl;

	// vector<int> temp;
	// printRootToLeaf(root, temp);

	// levelOrder(root);
	// levelOrderNewLine(root);
	// levelOrderNewLineBetter(root);

	// leftView(root, 1);
	// cout << endl;

	// leftBoundary(root);
	// cout << endl;

	// rightBoundary(root);
	// cout << endl;

	// int k = 3;
	// nodesKdistanceBelow(root, k, 0);
	// cout << endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1