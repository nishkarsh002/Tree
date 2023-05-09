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

void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}

void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->right, ans, level+1);    
    solve(root->left, ans, level+1);
    
}
vector<int> rightView(Node *root){
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);
 
    vector<int> ans = leftView(root);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " " ;
    }cout << endl;
    return 0;
}