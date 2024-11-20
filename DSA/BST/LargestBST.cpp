#include <iostream>
#include <vector>
#include <queue>
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

void levelOrder(Node* root){
    //step0: initialize data structure
    queue<Node*> q;

    //step1: push root and NULL into queue
    q.push(root); q.push(NULL);

    //step2: start while loop (until queue is not empty)
    while(!q.empty()){
        //step3: store front in currNode and pop front queue
        Node* currNode = q.front();
        q.pop();

        //step6: track next level
        if(!currNode){
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        //step4: print own data
        cout<<currNode->data<<" ";

        //step5: insert children of currNode into queue iff they're not empty
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

class Info{
    public:
    bool isBST;
    int min;
    int max;
    int size;

    //constructor
    Info(bool isBST, int min, int max, int size){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxSize;

Info* largestBST(Node* root){
    //base case
    if(root == NULL){
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    //get information from left and right subtrees
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    //create own information
    int currSize = leftInfo->size + rightInfo->size + 1;
    int currMin = min(leftInfo->min, root->data);
    int currMax = max(rightInfo->max, root->data);

    //check if valid bst
    if(
        leftInfo->isBST && 
        rightInfo->isBST &&
        leftInfo->max < root->data &&
        rightInfo->min > root->data
    ){
        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);

    }

    return new Info(false, currMin, currMax, currSize);
}

int main(){
    //build a bst manually
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    //print the level order of the above bst
    // levelOrder(root);

    //print the size of the largest BST in a Binary Tree
    largestBST(root);
    cout<<maxSize<<endl;


    return 0;
}
