#include <iostream>
#include <utility>
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
    //step0: initialize queue
    queue<Node*> q;
    
    //step1: push root and null in queue
    q.push(root); q.push(NULL);

    //step2: start while loop(until q is not empty)
    while(!q.empty()){
        //step3: store front in currNode pointer and pop front queue
        Node* currNode = q.front(); q.pop();

        //step6: base case i.e., track end of level
        if(!currNode){
            cout<<endl;

            if(q.empty()) break;

            q.push(NULL); continue;
        }

        //step4: print currNode data
        cout<<currNode->data<<" ";

        //step5: insert children in the queue iff they're not empty
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

//find diameter and height of binary tree together
pair<int,int> diameter(Node* root){
    if(!root) return make_pair(0,0);

    pair<int,int> leftInfo = diameter(root->left);
    pair<int,int> rightInfo = diameter(root->right);

    int currDiam = leftInfo.first + rightInfo.first + 1;

    int height = max(leftInfo.first, rightInfo.first) + 1;
    int diameter = max(currDiam, max(leftInfo.second, rightInfo.second));

    return make_pair(height, diameter);
}

int main(){
    vector<int> bt1 = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> bt2 = {1,2,4,9,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root1 = buildTree(bt1);
    //reset idx
    idx = -1;
    Node* root2 = buildTree(bt2);

    cout<<"First Binary Tree"<<endl;
    levelOrder(root1);
    cout<<"-----------------------------------------------"<<endl;
    cout<<"The diameter of first binary tree is "<<diameter(root1).second<<endl;
    cout<<"-----------------------------------------------"<<endl;


    cout<<"Second Binary Tree"<<endl;
    levelOrder(root2);
    cout<<"-----------------------------------------------"<<endl;
    cout<<"The diameter of second binary tree is "<<diameter(root2).second<<endl;
    cout<<"-----------------------------------------------"<<endl;

    return 0;
}
