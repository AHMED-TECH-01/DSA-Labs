
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    // Search a node
    bool search(Node* node, int value) {
        if (node == NULL)
            return false;

        if (node->data == value)
            return true;

        return search(node->left, value) ||
               search(node->right, value);
    }

    // Pre-order traversal (Root, Left, Right)
    void preOrder(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal (Left, Right, Root)
    void postOrder(Node* node) {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree tree;

    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Searching 5: ";
    if (tree.search(tree.root, 5))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Pre-order Traversal: ";
    tree.preOrder(tree.root);

    cout << "\nPost-order Traversal: ";
    tree.postOrder(tree.root);

    return 0;
}
