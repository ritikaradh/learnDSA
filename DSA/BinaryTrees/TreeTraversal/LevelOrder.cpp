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

    //left child
    root->left = buildTree(lis);

    //right child
    root->right = buildTree(lis);


    return root;
}

//breadth first search (bfs)
void levelOrder(Node* root){

    //step1: insert root and null in queue
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //step2: start while loop
    while(!q.empty()){
        //step3: store front in another currNode pointer and pop front of queue
        Node* currNode = q.front();
        q.pop();

        //step6: base case i.e., track end of level
        if(!currNode){
            if(q.empty()) break;
            q.push(NULL);
            cout<<endl;
            continue;
        }

        //step4: print the data of currNode
        cout<<currNode->data<<" ";

        //step5: insert the children of currNode in the queue iff they're not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }

}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(preorder);
    levelOrder(root);
    return 0;
}
