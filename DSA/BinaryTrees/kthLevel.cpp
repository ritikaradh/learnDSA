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
        this->left = left;
        this->right = right;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

//problem: print the nodes at the kth level of binary tree
void kthLevelNodes(Node* root, int k, int level=1){
    if(!root) return;

    if(level == k) { cout<<root->data<<" "; return; }

    kthLevelNodes(root->left, k, level+1);
    kthLevelNodes(root->right, k, level+1);
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(preorder);
    kthLevelNodes(root, 3);

    return 0;
}