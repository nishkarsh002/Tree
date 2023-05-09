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

void solve(Node* root , int k , int &count , vector<int> path){
    if(root==NULL) return ;

    path.push_back(root->data);

    solve(root->left , k , count , path);
    solve(root->right , k , count , path);

    int n = path.size();
    int sum =0;
    for(int i=n-1; i>=0; i--){
        sum += path[i];
        if(sum==k) count++;
    } 

    path.pop_back();  // totally optional because in each return it automatically lose last element
}

// given solution is for root to leaf paths

void findPaths(Node* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> data);
        if (!(node -> left) && !(node -> right) && sum == node -> data)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> data, path, paths);
        findPaths(node -> right, sum - node -> data, path, paths);
        path.pop_back();
}

int kPath(Node* root , int k){
    vector<int> path ;
    int count = 0;
    solve(root ,k, count , path);
    return count;
}


int main(){
    return 0;
}