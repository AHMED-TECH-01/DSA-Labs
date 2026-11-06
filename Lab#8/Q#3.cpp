
#include <iostream>
#include <cmath>
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

int checkHeight(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root))
        cout << "Tree is Height Balanced";
    else
        cout << "Tree is Not Height Balanced";

    return 0;
}
