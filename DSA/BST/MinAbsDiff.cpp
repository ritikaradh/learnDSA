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

void inOrder(Node* root, int target, vector<int> &vec, bool isFound, int &idx){
    if(root == NULL) return;

    inOrder(root->left, target, vec, isFound, idx);

    {
        vec.push_back(root->data);
        if(root->data < target){
            idx += 1;
        }else if(root->data == target){
            isFound = true;
        }
    }

    inOrder(root->right, target, vec, isFound, idx);
}

int minAbsDiff(Node* root, int target){
    if(!root) return -1;
    
    if(!root->left && !root->right) return -1;
    
    //step1: get inOrder traversal of bst and idx of target
    vector<int> vec; 
    int idx = 0;
    bool isFound = false;
    inOrder(root, target, vec, isFound, idx);

    //step2: check if target node is found
    if(isFound) return 0;

    //step3: compute abs diff to the left and right of the target
    int leftAbsDiff = INT_MAX;
    int rightAbsDiff = INT_MAX;

    leftAbsDiff = abs(target - vec[idx]);
    if(idx != vec.size()-1)
        rightAbsDiff = abs(target - vec[idx+1]);

    // cout<<leftAbsDiff<<endl; 
    // cout<<rightAbsDiff<<endl;

    //step4: compare leftAbsDiff and rightAbsDiff
    if(leftAbsDiff < rightAbsDiff) return vec[idx];
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
    cout<<minAbsDiff(root, 19)<<endl;


    //return
    return 0;
}