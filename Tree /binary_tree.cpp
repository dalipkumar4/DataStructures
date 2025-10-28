#include <iostream>
#include<queue>
using namespace std;

// Class for each node in the binary tree
class Node {
    public:
        int data;
        Node *left, *right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* root,int value){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // Check left child
        if(temp->left == NULL){
            temp->left = new Node(value);
            return;
        } else{
            q.push(temp->left);
        }

        // Check right child
        if(temp->right == NULL){
            temp->right = new Node(value);
            return;
        } else{
            q.push(temp->right);
        }
    }
}


// Inorder Traversal (to check result)
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(35);
    root->left->right = new Node(55);

    // Display traversals
    cout << "Before insertion (Inorder): ";
    inorder(root);
    cout << endl;
    
    insert(root,70);
    cout << "After insertion (Inorder): ";
    inorder(root);
    cout << endl;
    return 0;
}
