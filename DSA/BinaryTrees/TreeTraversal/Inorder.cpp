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

    //base case
    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);
}

void inorderTraversal(Node* root){
    //base case
    if(root == NULL) return;

    //call left
    inorderTraversal(root->left);

    //print own data
    cout<<root->data<<", ";

    //call right
    inorderTraversal(root->right);
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(lis);
    inorderTraversal(root);
    return 0;
}