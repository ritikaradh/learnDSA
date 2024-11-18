#include <iostream>
#include <vector>
using namespace std;

class Node{
    public: 
    int val;
    Node* left;
    Node* right;

    //constructor
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(!root) {
        Node* root = new Node(val);
        return root;
    }

    else if(val < root->val){
        root->left = insert(root->left, val);
    }

    else if(val > root->val) {
        root->right = insert(root->right, val);
    }

    return root; 
}

Node* buildBST(vector<int> &vec){
    int n = vec.size();

    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, vec[i]);
    }

    return root;
}

void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);

    cout<<root->val<<" ";

    inOrder(root->right);
}

void printRange(Node* root, int start, int end){
    if(root == NULL) return;
    if(start < root->val) printRange(root->left, start, end);
    if(start <= root->val && root->val <= end) cout<<root->val<<" ";
    if(root->val < end) printRange(root->right, start, end);
}

int main(){
    vector<int> vec = {8,5,3,1,4,6,10,11,14};
    Node* root = buildBST(vec);
    inOrder(root);
    cout<<endl;
    printRange(root, 5, 12);
    cout<<endl;
    return 0;
}