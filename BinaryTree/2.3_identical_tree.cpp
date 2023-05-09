#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

bool isIdentical(node *r1, node *r2){
    if(r1 == NULL && r2 == NULL) return true;
        
    if(r1 == NULL && r2 != NULL) return false;
        
    if(r1 != NULL && r2 == NULL) return false;
        
    bool checkR = isIdentical(r1->right , r2->right);
    bool checkL = isIdentical(r1->left , r2->left);
        
    bool value = r1->data == r2->data;  
          
    if(checkR && checkL && value) return true;

    return false;
}

// tc is o(n) but sc is o(log min(n,m)) due to recursive call stack

int main(){

    node* root1 = new node(1);
    node* root2 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
 
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    cout << isIdentical(root1 , root2);

    return 0;
}