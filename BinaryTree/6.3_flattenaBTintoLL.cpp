// C++ Program to flatten a given Binary Tree into linked
// list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

// utility that allocates a new Node with the given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to convert binary tree into linked list by
// altering the right node and making left node point to
// NULL
void flatten(Node* root)
{
	// traverse till root is not NULL
	while (root) {
		// if root->left is not NULL
		if (root->left != NULL) {
			// set curr node as root->left;
			Node* curr = root->left;
			// traverse to the extreme right of curr
			while (curr->right) {
				curr = curr->right;
			}
			// join curr->right to root->right
			curr->right = root->right;
			// put root->left to root->right
			root->right = root->left;
			// make root->left as NULL
			root->left = NULL;
		}
		// now go to the right of the root
		root = root->right;
	}
}

// To find the inorder traversal
void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->right = newNode(6);
	flatten(root);
	cout << "The Inorder traversal after flattening binary "
			"tree ";
	inorder(root);
	return 0;
}

// This code is contributed by Harsh Raghav
