#include <iostream>
#include <vector>
#include <climits>
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

Node* insert(Node* root, int val){
    if(!root) {
        return new Node(val);
    }

    else if(val < root->data){
        root->left = insert(root->left, val);
    }

    else{
        root->right = insert(root->right, val);
    }


    return root;
}

Node* buildBST(vector<int> &vec){
    int n = vec.size();

    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root,vec[i]);
    }


    return root;
}

void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool validateBSTHelper(Node* root, Node* min, Node* max){
    if(!root) return true;

    if(min && root->data < min->data) return false;
    if(max && root->data > max->data) return false;

    return validateBSTHelper(root->left, min, root)
        && validateBSTHelper(root->right, root, max);
}

bool validateBST(Node* root){
    return validateBSTHelper(root, NULL, NULL);
}

int main(){
    vector<int> vec = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(vec);
    inOrder(root);
    cout<<endl;
    cout<<validateBST(root)<<endl;

    root->data = 15;
    inOrder(root);
    cout<<endl;
    cout<<validateBST(root)<<endl;
    
    
    return 0;
}