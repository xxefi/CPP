#include <iostream>
using namespace std;

struct TreeNode {
	int key{};
	TreeNode* left;
	TreeNode* right;
	TreeNode(int key)
		: key(key), left(nullptr), right(nullptr){}
};


class BinarySearchTree {
public:
	BinarySearchTree()
		: root(root){}

	~BinarySearchTree()
	{
		destroyTree(root);
	}

	void insert(int key);
	void remove(int key);
	void edit(int oldKey, int newKey);

	void PrintInfo() const;

private:
	TreeNode* root{};
	void destroyTree(TreeNode* node);
	TreeNode* insertRecursively(TreeNode* node, int key);
	TreeNode* findMinNode(TreeNode* node);
	TreeNode* removeRecursively(TreeNode* node, int key);
	void editRecursively(TreeNode* node, int oldKey, int newKey);
	void printTreeRecursively(TreeNode* node) const;
};


void BinarySearchTree::insert(int key) {
	root = insertRecursively(root, key);
}

TreeNode* BinarySearchTree::insertRecursively(TreeNode* node, int key) {
	if (node == nullptr) {
		return new TreeNode(key);
	}

	if (key < node->key) {
		node->left = insertRecursively(node->left, key);
	}
	else if (key > node->key) {
		node->right = insertRecursively(node->right, key);
	}
	return node;
}

void BinarySearchTree::remove(int key) {
	root = removeRecursively(root, key);
}

TreeNode* BinarySearchTree::findMinNode(TreeNode* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

TreeNode* BinarySearchTree::removeRecursively(TreeNode* node, int key) {
	if (node == nullptr) {
		return nullptr;
	}

	if (key < node->key) {
		node->left = removeRecursively(node->left, key);
	}
	else if (key > node->key) {
		node->right = removeRecursively(node->right, key);
	}
	else {
		if (node->left == nullptr) {
			TreeNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			TreeNode* temp = node->left;
			delete node;
			return temp;
		}

		TreeNode* temp = findMinNode(node->right);
		node->key = temp->key;
		node->right = removeRecursively(node->right, temp->key);
	}
	return node;
}

void BinarySearchTree::edit(int oldKey, int newKey) {
	remove(oldKey);
	insert(newKey);
}

void BinarySearchTree::PrintInfo() const {
	printTreeRecursively(root);
	cout << endl;
}

void BinarySearchTree::printTreeRecursively(TreeNode* node) const {
	if (node != nullptr) {
		printTreeRecursively(node->left);
		cout << node->key << " ";
		printTreeRecursively(node->right);
	}
}

void BinarySearchTree::destroyTree(TreeNode* node) {
	if (node != nullptr) {
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

void BinarySearchTree::editRecursively(TreeNode* node, int oldKey, int newKey) {
	if (node == nullptr) {
		return;
	}

	if (node->key == oldKey) {
		node->key = newKey;
	}

	editRecursively(node->left, oldKey, newKey);
	editRecursively(node->right, oldKey, newKey);
}


int main() {
	setlocale(LC_ALL, "ru");
	BinarySearchTree binarySearchTree;
	binarySearchTree.insert(50);
	binarySearchTree.insert(30);
	binarySearchTree.insert(70);
	binarySearchTree.insert(20);
	binarySearchTree.insert(40);
	binarySearchTree.insert(60);
	binarySearchTree.insert(80);
	cout << "Бинарное дерево до редактирование: " << endl;
	binarySearchTree.PrintInfo();

	binarySearchTree.remove(30);
	cout << "Бинарное дерево после удаление 30: " << endl;
	binarySearchTree.PrintInfo();

	binarySearchTree.edit(70, 55);
	cout << "Бинарное дерево после редактирование 70 в 55: " << endl;
	binarySearchTree.PrintInfo();
}
