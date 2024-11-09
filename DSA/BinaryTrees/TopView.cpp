#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
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
    idx += 1;

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

//problem: top-view of a binary tree
void topView(Node* root){

    //step0: initialize queue (for level order traversal) and map data structure (to track top view)
    queue<pair<Node*,int>> q;
    map<int,int> dict;

    //step1: insert root and its horizontal distance into queue
    q.push(make_pair(root,0));

    //step2: start while loop (until queue is not empty)
    while(!q.empty()){

        //step3: store the front in currNode and currHD, and pop front the queue
        Node* currNode = q.front().first;
        int currHD = q.front().second;
        q.pop();

        //step6: insert into map
        if(!dict.count(currHD)) dict[currHD] = currNode->data;

        //step5: insert left and right child into queue iff they're not null
        if(currNode->left) q.push(make_pair(currNode->left, currHD-1));
        if(currNode->right) q.push(make_pair(currNode->right, currHD+1));
    }

    //step4: print map data
    for(auto it: dict){ 
        //here it is the iterator pointing to a key and value pair of the dictionary
        //it.first indicates key and it.second indicates value
        cout<<it.second<<" ";
    }
}

int main(){
    vector<int> preorderLis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(preorderLis);

    topView(root);

    return 0;
}
