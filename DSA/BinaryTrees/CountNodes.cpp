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
        this->left = left;
        this->right = right;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &lis){
    idx++;

    if(lis[idx]==-1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);

    
    return root;
}

//level order traversal: breadth first search
void levelOrder(Node* root){
    //step0: initialize queue
    queue<Node*> q;

    //step1: push root & NULL to queue
    q.push(root);
    q.push(NULL);

    //step2: start while loop (queue is not empty)
    while(!q.empty()){
        
        //step3: store front in currNode pointer and pop front the queue
        Node* currNode = q.front();
        q.pop();

        //step6: base case i.e., track end of a level
        if(!currNode){
            cout<<endl;

            if(q.empty()) break;

            q.push(NULL);
            continue;
        }

        //step4: print current node's data
        cout<<currNode->data<<" ";

        //step5: insert children into the queue iff they're not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

int countOfNodes(Node* root){
    if(!root) return 0;

    int left = countOfNodes(root->left);
    int right = countOfNodes(root->right);

    return left + right + 1;
}

int main(){
    vector<int> preorderLis = {5,6,8,-1,-1,9,-1,-1,7,-1,10,-1,-1};

    Node* root = buildTree(preorderLis);

    levelOrder(root);

    cout<<"The no. of nodes present in this binary tree is: "<<countOfNodes(root)<<endl;

    return 0;
}