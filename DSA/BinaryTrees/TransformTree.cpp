#include <iostream>
#include <vector>
#include <queue>
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
    idx++;

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

void levelOrder(Node* root){
//breadth first search (bfs)

    //step0: initialize queue data structure
    queue<Node*> q;

    //step1: push root and null into queue
    q.push(root); q.push(NULL);

    //step2: start while loop (until queue is not empty)
    while(!q.empty()){

        //step3: store front in currNode pointer and pop front the queue
        Node* currNode = q.front(); q.pop();

        //step6: base case ie, track next level
        if(!currNode){
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        //step4: print data of currNode
        cout<<currNode->data<<" ";

        //step5: insert currNode's children in queue iff they're not empty
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

int transformTree(Node* root) {
    if(!root) return 0;

    int parent = root->data;

    int left = transformTree(root->left);
    int right = transformTree(root->right);

    root->data = left+right;

    return left+right+parent;
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(lis);

    levelOrder(root);

    cout<<"--------------------------------"<<endl;

    transformTree(root);

    cout<<"--------------------------------"<<endl;

    levelOrder(root);


    return 0;
}