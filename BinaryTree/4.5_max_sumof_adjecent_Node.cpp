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

pair<int,int> solve(Node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int , int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair <int,int> res ;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;

}

// res.first is the value of the data including that level and the res.second id the data of the value excluding that level


int getmaxSum(Node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first , ans.second);

}

int main(){
    return 0;
}
