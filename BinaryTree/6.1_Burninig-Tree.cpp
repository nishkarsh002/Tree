#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
    int data ;
    Node* left;
    Node* right;

    Node(int d){
        this ->data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &NodeToParent)

{

    Node *result = NULL;

    queue<Node *> q;

    q.push(root);

    NodeToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
       q.pop();

 
        if (front->data == target)
        {
            result = front;
        }
 
        if (front->left)
        {
            NodeToParent[front->left] = front;
            q.push(front->left);
        }
 
        if (front->right)
        {
            NodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

int burnTree(Node *targetNode, map<Node *, Node *> &NodetoParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);

    visited[targetNode] = true;
    int ans = 0;
    while (!q.empty())    {   

        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process every neighbouring node
            Node *front = q.front();
            q.pop();
 
            if (front->left && !visited[front->left])
            {   
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag =1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (NodetoParent[front] && !visited[NodetoParent[front]])
            {
                flag = 1;
                q.push(NodetoParent[front]);
                visited[NodetoParent[front]] = true;
            }
        }
        if(flag == true){
            ans++;
        }
    }
    return ans;
}
    int minTime(Node* root, int target) 
    {
    map<Node *, Node *> NodeToParent;
    Node *targetNode = createParentMapping(root, target, NodeToParent);
    int ans = burnTree(targetNode, NodeToParent);
    return ans;
    }


int main(){


    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(13);
    root->right->left = new Node(14);
    root->right->right = new Node(15);
    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);
    int targetNode = 14;

    int ans = minTime(root , 14);
    cout << ans;
    return 0;

}