#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &lis){
    idx++;

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

int kthAncestor(Node* root, int node, int k){
    if(!root) return -1;

    if(root->data == node){
        if(k==0) cout<<root->data<<endl;
        return 0;
    }

    int left = kthAncestor(root->left, node, k);
    int right = kthAncestor(root->right, node, k);

    if(left != -1){
        if(left + 1 == k) cout<<root->data<<endl;
        return left+1;
    }else if(right != -1){
        if(right + 1 == k) cout<<root->data<<endl;
        return right+1;
    }else return -1;
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(lis);
    kthAncestor(root, 4, 0);
    kthAncestor(root, 4, 1);
    kthAncestor(root, 4, 2);
    return 0;
}