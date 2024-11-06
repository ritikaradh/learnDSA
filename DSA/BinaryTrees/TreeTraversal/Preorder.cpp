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
        Node* left = NULL;
        Node* right = NULL;
    }
};

static int idx = -1;

//this function accepts a preorder list and currindex of preorder list
Node* buildTree(vector<int> &preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

//preorder traversal
void preorderTraversal(Node* root){
    //base case
    if(root == NULL) {cout<<"-1"<<", "; return;}

    //print root
    cout<<root->data<<", ";

    //print left
    preorderTraversal(root->left);

    //print right
    preorderTraversal(root->right);
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    
    Node* root = buildTree(lis);
    
    preorderTraversal(root);

    return 0;
}