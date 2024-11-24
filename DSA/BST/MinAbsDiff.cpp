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

void inOrder(Node* root, int target, vector<int> &vec, int &idx){
    if(root == NULL) return;

    inOrder(root->left, target, vec, idx);

    {
        vec.push_back(root->data);
        if(root->data < target){
            idx += 1;
        }
    }

    inOrder(root->right, target, vec, idx);
}

int minAbsDiff(Node* root, int target){
    if(!root) return -1;
    
    if(!root->left && !root->right) return -1;
    
    //step1: get inOrder traversal of bst and idx of target
    vector<int> vec; 
    int idx = 0;
    inOrder(root, target, vec, idx);

    //step2: compute abs diff to the left and right of the target
    int leftAbsDiff = INT_MAX;
    int rightAbsDiff = INT_MAX;

    if(idx != 0)
        leftAbsDiff = vec[idx] - vec[idx-1];
        cout<<leftAbsDiff<<endl;
    if(idx != vec.size()-1)
        rightAbsDiff = vec[idx+1] - vec[idx];
        cout<<rightAbsDiff<<endl;

    //step3: compare leftAbsDiff and rightAbsDiff
    if(leftAbsDiff < rightAbsDiff) return vec[idx-1];
    return vec[idx+1];
}

int main(){
    //create bst
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->right = new Node(20);


    //get min abs diff of target node
    cout<<minAbsDiff(root, 5)<<endl;


    //return
    return 0;
}