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

int height(node* root){
    if(root==NULL)
      return 0;
    int lefth = height(root->left);
    int righth = height(root->right);

    return max(righth , lefth)+1;
}

pair<bool, int> isBalancedFast(node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
}
    

bool check(node* root){

    if(root == NULL) return true;

    bool left = check(root->left);
    bool right = check(root->right);

    bool diff = abs(height(root->left)-height(root->right)) <= 1;

    if(left && right && diff) return 1;
    else return 0;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    cout << isBalancedFast(root).first ;
    return 0;

}