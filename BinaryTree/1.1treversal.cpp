// A recursive C++ program to print
// REVERSE level order traversal
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

/*Function prototypes*/
void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

/* Function to print REVERSE
level order traversal a tree*/
void reverseLevelOrder(node* root)  // time complexity for this solution is O(n^2)
{
	int h = height(root);
	int i;
	for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
		printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}


void RLOusingQueue(node* root) // time complexity for this is o(n)
{
    stack <node*> S;
    queue <node*> Q;
    Q.push(root);
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    } 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
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
	cout << "Reverse Level Order traversal of binary tree is \n";
	RLOusingQueue(root);
	return 0;
}