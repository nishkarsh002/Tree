#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data ;
        node* left;
        node* right;

        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

node* solve(node* root , int &k , int key){
    if(root == NULL) return NULL;

    if(root->data == key){
        return root;
    }

    node* leftans = solve(root->left , k ,key);
    node* rightans = solve(root->right , k , key);

    if(leftans != NULL && rightans == NULL ){
        k--;
        if(k==0){
            k = INT_MAX;
            return root; // ager kabhi k 0 ho upper mile to answer change na ho jye
        }
        return leftans;
    }

    if(leftans == NULL && rightans != NULL ){
        k--;
        if(k==0){
            k = INT_MAX;
            return root; // ager kabhi k 0 ho upper mile to answer change na ho jye
        }
        return rightans;
    }

    return NULL;
}

int Kthancestor(node* root , int k , int key){
    node* ans = solve(root , k , key);
    if(ans == NULL || ans->data==key){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main(){

  node* root = new node(1);
  root->left = new node(4);
  root->left->right = new node(7);
  root->left->left = new node(3);
  root->left->right->left = new node(8);
  root->right = new node(2);
  root->right->right = new node(6);

  int ans = Kthancestor(root , 1 , 3);
  cout << ans;
    return 0;
}