// Binary Search Tree operations in C++

/*
    -> In order to delete a node, we must reach to that particular node from the root
    -> If a value that we want to delete is less from the root itself we would call the
        program to delete from the left subtree otherwise right subtree (vice versa)
    -> 

*/
#include <iostream>
using namespace std;


struct node{
  int data;
  struct node *left; 
  struct node *right;
};


// Create a node
struct node *NewNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}



// Inorder Traversal
void Inorder(struct node *root){
    if(root != NULL){
        Inorder(root->left);
        cout << root->data << " -> ";
        Inorder(root->right);
    }
}

// Insert a node
struct node *Insert(struct node *node, int data) {
    // Return a new node if the tree is empty
    if(node == NULL){
        return NewNode(data);
    }

    // Traverse to the right place and Insert the node
    if(data < node->data){
        node->left = Insert(node->left, data);
    }
    else{
        node->right = Insert(node->right, data);
    }
    return node;
}


// Find the Inorder successor
struct node *MinValueNode(struct node *node){
    struct node *current = node;

    // Find the leftmost leaf
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}


// Deleting a node
struct node *DeleteNode(struct node *root, int data){
    // Return if the tree is empty
    if (root == NULL){
        return root;
    }

    // Find the node to be deleted
    if(data < root->data){
        root->left = DeleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = DeleteNode(root->right, data);
    }
    else{
        // If the node is with only one child or no child
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = MinValueNode(root->right);

        // Place the Inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the Inorder successor
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}


int main(){

    struct node *root = NULL;

    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 10);
    root = Insert(root, 14);
    root = Insert(root, 4);

    cout << "Inorder traversal: ";
    Inorder(root);

    cout << "\nAfter deleting 10\n";
    root = DeleteNode(root, 10);

    cout << "Inorder traversal: ";
    Inorder(root);
}