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

Node* insert(Node* root, int val){
    if(!root){
        Node* node = new Node(val);
        return node;
    }

    else if(val < root->data){
        root->left = insert(root->left, val);
    }

    else{
        root->right = insert(root->right, val);
    }


    return root;
}

void inOrder(Node* root) {
    if(!root) return;

    inOrder(root->left);

    cout<<root->data<<" ";

    inOrder(root->right);
}

Node* buildBST(vector<int> &arr){
    int n = arr.size();

    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }


    return root;
}

Node* getISS(Node* root){
    while(root->left){
        root = root->left;
    }

    return root;
}

Node* delNodeBST(Node* root, int key){
    if(!root) return NULL;

    if(root->data == key){
        //case 1: currNode is leaf node
        if(!root->left && !root->right){
            root = NULL;
        }

        //case 2
        else if(!root->left || !root->right){
            if(root->left) return root->left;
            if(root->right) return root->right;
        }

        //case 3
        else{
            Node* ISS = getISS(root->right);
            root->data = ISS->data;
            root->right = delNodeBST(root->right, ISS->data);
        }
    }

    else if(root->data > key){
        root->left = delNodeBST(root->left, key);
    }
    
    else{
        root->right = delNodeBST(root->right, key);
    }

    return root;
}

int main(){
    vector<int> vec = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(vec);
    inOrder(root);

    cout<<endl;

    delNodeBST(root, 4);
    inOrder(root);

    cout<<endl;

    delNodeBST(root, 10);
    inOrder(root);

    cout<<endl;

    delNodeBST(root, 5);
    inOrder(root);

    cout<<endl;


    return 0;
}