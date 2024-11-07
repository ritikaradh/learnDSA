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

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);

    return root;
}


//level order traveral of tree
void levelOrder(Node* root){
    //step0: initialize queue
    queue<Node*> q;

    //step1: push root and null to queue
    q.push(root); q.push(NULL);

    //step2: start while loop (until queue is not empty)
    while(!q.empty()){
        //step3: store front of queue in currNode pointer and pop front queue
        Node* currNode = q.front(); q.pop();

        //step6: base case ie., track next level
        if(!currNode){
            cout<<endl;

            if(q.empty()) break;

            q.push(NULL);
            continue; 
        }

        //step4: print currNode data
        cout<<currNode->data<<" ";

        //step5: insert children into queue if not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

int sumOfNodes(Node* root){
    if(!root) return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + root->data + rightSum;
}

int main(){
    vector<int> preorderLis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(preorderLis);

    levelOrder(root);

    cout<<"The sum of all the nodes in the binary tree is: "<<sumOfNodes(root)<<endl;

    return 0;
}

