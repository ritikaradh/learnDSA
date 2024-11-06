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

void postorderTraversal(Node* root){
    if(root == NULL) return;

    //call left
    postorderTraversal(root->left);

    //call right
    postorderTraversal(root->right);

    //print own data
    cout<<root->data<<", ";
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    
    Node* root = buildTree(lis);
    
    postorderTraversal(root);

    return 0;
}