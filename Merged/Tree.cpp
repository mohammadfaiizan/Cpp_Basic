#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

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

int main(){
    cout << "Hello, Welocome to Tree PlayGround" << endl;
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
}