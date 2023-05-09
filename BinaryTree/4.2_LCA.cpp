// lowest common ancestor
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data ;
        Node* left;
        Node* right;

        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node* LCA(Node* root , int n1 , int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = LCA(root->left , n1 ,n2);
    Node* rightAns = LCA(root->right , n1 , n2);

    if(leftAns != NULL and rightAns != NULL){
        return root;
    }

    else if(leftAns != NULL || rightAns == NULL){
        return leftAns;
    }

    else if(leftAns == NULL || rightAns != NULL){
        return rightAns;
    }

    else{
        return NULL;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    Node* lca = LCA(root, 4, 5);
    cout << lca->data;
    return 0;
}