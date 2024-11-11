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

Node* removeLeafNodes(Node* root, int target) {
    if (!root) return nullptr;

    // Recursively call removeLeafNodes on left and right children
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (!root->left && !root->right && root->data == target) {
        delete(root);
        return nullptr;
    }

    return root;  // Return the current node if it wasn't deleted
}



int main(){
    vector<int> lis = {2, 1, -1, -1, 1, -1, -1};
    Node* root = buildTree(lis);

    cout<<removeLeafNodes(root,1)<<endl;

    return 0;
}