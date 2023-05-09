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

pair<bool,int> isSumTreeFast(node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condition = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condition) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    bool isSumTree(node* root)
    {
        return isSumTreeFast(root).first;
    }

int solve(node* root){
        if(root==nullptr)
          return 0;
        int leftdata = solve(root->left);
        int rightdata = solve(root->right);
        int temp = root->data;
        root->data = leftdata + rightdata;
        return leftdata + temp + rightdata;
}

int main(){

    node *root = new node(25);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->right = new node(3);
    cout << isSumTree(root) << endl;
    if(!isSumTree(root)){
        cout << solve(root);
    }
    return 0;
}