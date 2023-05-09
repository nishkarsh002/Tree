#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data ;
     Node* left ;
     Node* right;

    Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}


Node* buildUtil(int in[], int post[], int inStrt, int inEnd,
                int* pIndex)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
    Node* node = new Node(post[*pIndex]);
    (*pIndex)--;
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return node;
 
    /* Else find the index of this node in Inorder
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->data);
 
    /* Using index in Inorder traversal, construct left and
       right subtrees */
    node->right
        = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left
        = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
 
    return node;
}
 
// This function mainly initializes index of root
// and calls buildUtil()
Node* buildTree(int in[], int post[], int n)
{
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
 
    Node* root = buildTree(in, post, n);
 
    cout << "Preorder of the constructed tree : \n";
    preOrder(root);
 
    return 0;
}