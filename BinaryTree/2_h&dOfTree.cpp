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

int diameterOpt(node* root, int* height){
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;
    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;
    if (root == NULL) {
        *height = 0;
        return 0; // diameter is also 0
    }
    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter 
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int height2(node* root){
    // Initialising a variable to count the
    // height of tree
    int depth = 0;
    queue<node*> q;
    // Pushing first level element along with NULL
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        // When NULL encountered, increment the value
        if (temp == NULL) {
            depth++;
        }
        // If NULL not encountered, keep moving
        if (temp != NULL) {
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
    return depth;
}

int height(node* root){
    if(root==NULL)
      return 0;
    int lefth = height(root->left);
    int righth = height(root->right);

    return max(righth , lefth)+1;
}

int diameter(node* root){

    if(root==NULL) return 0;

    int dia1 = diameter(root->left);
    int dia2 = diameter(root->right);
    int dia3 = height(root->left) + height(root->right) + 1;

    int ans = max(dia1 , max(dia2,dia3));

    // int height = 0;
    // calling the function to find the result.
    // int diameter = diameterOpt(root, &height);

    return ans;
}

pair<int,int> fastdia(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p; 
    }

    pair<int,int> left = fastdia(root->left);
    pair<int, int> right = fastdia(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int , int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second) + 1;
    return ans ;    
}

// use ans.first for diameter in o(n) use ans. second for height



int main(){

    node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

    int ans = height(root);
    cout << ans << " " << diameter(root);
    
    return 0;

}