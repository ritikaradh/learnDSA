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

Node* insert(Node* root, int val){ //O(logn)
    if(!root){
        Node* root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else{
        root->right = insert(root->right, val);
    }


    return root;
}

Node* buildBST(vector<int> &arr){
    int n = arr.size();
    
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }


    return root;
}

void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);

    cout<<root->data<<" ";

    inOrder(root->right);
}

int main(){
    vector<int> arr = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr);
    inOrder(root);
    return 0;
}