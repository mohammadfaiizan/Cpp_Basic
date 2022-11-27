#include<iostream>
#include<queue>
using namespace std;

//==========================================
// Tree Declaration

class node{
public:
    int data;
    node* left;
    node* right;
};

//==========================================
// Tree Creation

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

//==========================================
// Tree traversal

void InOrder(node* temp){
    if(temp == NULL)
        return;
    InOrder(temp->left);
    cout << temp->data << " ";
    InOrder(temp->right);
}

void PreOrder(node* temp){
    if(temp == NULL)
        return;
    cout << temp->data << " ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

void PostOrder(node* temp){
    if(temp == NULL)
        return;
    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << temp->data << " ";
}

void levelOrder(node* temp){
    if (temp == NULL)
        return;
    queue<node*> q;
    q.push(temp);
    while(!q.empty()){
        node* front = q.front();
        cout << front->data << " ";
        q.pop();

        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);
    }
}

//==========================================
// Main function to call different function

int main(){
    cout << "Hello, Welocome to Tree PlayGround\n" << endl;
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "InOrder Traversal: "; InOrder(root); cout << endl;
    cout << "PreOrder Traversal: "; PreOrder(root); cout << endl;
    cout << "PostOrder Traversal: "; PostOrder(root); cout << endl;
    cout << "Level Order Traversal: "; levelOrder(root); cout << endl;
}