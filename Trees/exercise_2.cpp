#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

void insert(Node* root, int value){
    if (value < root->data){
        if (root->left == NULL){
            root->left = new Node(value);
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = new Node(value);
        } else {
            insert(root->right, value);
        }
    }
}

int calculateHeight(Node* node){
    if(node == NULL){
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int main() {
    //1.	Create a binary Tree
    BinaryTree tree(50);
    //2.	Randomly generate 50 numbers
    std::cout << "Numbers Generated: ";
    for (int i = 1; i <= 50; i++) {
        int num = (i*3)%100;
        std::cout << num << " ";
        insert(tree.getroot(), num); //3.	Insert each number into the tree
    }
    std::cout << "\n";
    //4.    Print a tree result
    std::cout << "\nIn-Order Traversal: " << tree.inOrderTraverse() << "\n";
    std::cout << "Pre-Order Traversal: " << tree.preOrderTraverse() << "\n";
    std::cout << "Post-Order Traversal: " << tree.postOrderTraverse() << "\n";
    //5.    Challenge: Implement a function that returns the height of the tree
    int height = calculateHeight(tree.getroot());
    std::cout << "Height of the Tree: " << height << "\n";

    return 0;
}