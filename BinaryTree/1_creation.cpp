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

void levelOrderTreversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while (q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) // some child are there
                q.push(NULL);
        }

        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}

node* CreateTree(node* root){
    cout << "enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1) return NULL;
    cout << "enter the data for left node:" << data << endl;
    root->left = CreateTree(root->left);
    cout << "enter the data for right node:" << data << endl;
    root->right = CreateTree(root->right);
    return root;
}

vector<int> levelOrder(node* root)
    {
      //Your code here
      vector<int> dfs;
          queue<node*> q;
          if(root==NULL)return dfs;
          q.push(root);
          while(q.size()){
              node* curr=q.front();
              q.pop();
              dfs.push_back(curr->data);
              if(curr->left)q.push(curr->left);
              if(curr->right)q.push(curr->right);
          }
          return dfs;      
}

int main(){

    node* root = NULL;
    root = CreateTree(root);
    return 0;

}