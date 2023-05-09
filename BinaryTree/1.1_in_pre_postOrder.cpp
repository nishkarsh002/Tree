#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

void inordertreversel(node* root){
	if(root== NULL) return;

	inordertreversel(root->left);
	cout << root->data << " ";
	inordertreversel(root->right);
}

void PreOrdertreversel(node* root){
    if(root==NULL) return;

    cout << root->data << " ";
    PreOrdertreversel(root->left);
    PreOrdertreversel(root->right);
}

void PostOrdertreversel(node* root){
    if(root==NULL) return;

    PostOrdertreversel(root->left);
    PostOrdertreversel(root->right);
    cout << root->data << " ";
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}
/* Driver code*/
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "preorder traversal of binary tree is \n";
	PreOrdertreversel(root);
	return 0;
}