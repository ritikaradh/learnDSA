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

static int idx = 0;

//this function accepts a preorder list and currindex of preorder list
Node* buildTree(vector<int> &preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    cout<<buildTree(preorder)<<endl;
    return 0;
}