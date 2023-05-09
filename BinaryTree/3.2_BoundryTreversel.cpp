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


void treverseLeft(Node* root , vector<int> &ans){
        if(root==NULL or (root->left==NULL and root->right==NULL))
           return;
         
        ans.push_back(root->data);
        
        if(root->left)
           treverseLeft(root->left ,ans);
        else{
            treverseLeft(root->right , ans);
        }
    }
    
    void treverseLeaf(Node* root , vector<int> &ans){
        if(root==NULL)
           return ;
        
        if(root->left==NULL and root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        treverseLeaf(root->left,ans);
        treverseLeaf(root->right,ans);
    }
    
    void treverseRight(Node* root , vector<int> &ans){
        if(root==NULL or (root->left == NULL and root->right==NULL)){
            return ;
        }
        
        if(root->right){
            treverseRight(root->right,ans);
        }
        else{
            treverseRight(root->left,ans);
        }
        
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        
        treverseLeft(root->left,ans);
        
        //treverse leaf
        treverseLeaf(root->left,ans);
        treverseLeaf(root->right,ans);
        
        treverseRight(root->right,ans);
        
        return ans;
    }

    int main(){

    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    vector<int> ans = boundary(root);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }cout<< endl;
    return 0;

    }