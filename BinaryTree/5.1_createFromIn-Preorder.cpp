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

int FindPosi(int in[], int ele , int m ){
    for (int i = 0; i < m; i++)
    {
        if(in[i]==ele){
            return i;
        }
       
    }
     return -1;
}

Node* solve(int in[] , int pre[] , int &index , int  inOstart , int inOend , int n){

    if(index >= n || inOstart > inOend){
        return NULL;
    }

    int ele = pre[index++];
    Node* root = new Node(ele);
    int posi = FindPosi(in , ele , n);

    root-> left = solve(in , pre , index , inOstart , posi -1 , n);
    root->right = solve(in , pre , index , posi+1 , inOend , n);

    return root;

}

Node* BuildTree(int in[], int pre[] , int n){

    int preIndex =0;
    Node* ans = solve(in , pre , preIndex , 0 , n-1 , n);
    return ans;

}