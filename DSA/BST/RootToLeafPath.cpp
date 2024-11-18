#include <iostream>
#include <vector>
#include <string>
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

    if(val < root->data){
        root->left = insert(root->left, val);
    }

    else if(val > root->data){
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

void pathHelper(Node* root, vector<int> &path){
    //step0: if root is NULL then return
    if(!root) return;

    //step1: insert root->data into string if root NOT NULL
    path.push_back(root->data);

    //step2: check if leaf node
    if(!root->left && !root->right){
        //step2.1: print string
        for(int node: path){
            cout<<node<<" ";
        }
        cout<<endl;

        // //step2.2: pop back string ie., remove root from string
        path.pop_back();

        //step2.3: return control
        return;
    }

    //step3: call children
    pathHelper(root->left, path);
    pathHelper(root->right, path);

    //step4: remove node
    path.pop_back();
}

void path(Node* root){
    vector<int> path;
    pathHelper(root, path);
}

int main(){
    vector<int> vec = {8,5,3,1,4,6,10,11,14};
    Node* root = buildBST(vec);
    path(root);
    return 0;
}