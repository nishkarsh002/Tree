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

vector<int> TopView(Node* root){
    vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
}

vector<int> BottomView(Node* root){
    vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    vector<int> res = TopView(root);
    for(int i=0; i<res.size(); i++){
        cout<< res[i] << " " ;
    }cout << endl;

    Node *root1 = new Node(20);
    root1->left = new Node(8);
    root1->right = new Node(22);
    root1->left->left = new Node(5);
    root1->left->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(25);
    root1->left->right->left = new Node(10);
    root1->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    vector<int> ans = BottomView(root1);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " " ;
    }cout << endl;
    return 0;
}
