
#include <iostream>
#include <algorithm>
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

int rob(Node* root) {
    if (root == NULL)
        return 0;

    // Option 1: Rob current house
    int robCurrent = root->data;

    if (root->left != NULL) {
        robCurrent += rob(root->left->left);
        robCurrent += rob(root->left->right);
    }

    if (root->right != NULL) {
        robCurrent += rob(root->right->left);
        robCurrent += rob(root->right->right);
    }

    // Option 2: Do not rob current house
    int notRobCurrent = rob(root->left) +
                        rob(root->right);

    return max(robCurrent, notRobCurrent);
}

int main() {
    Node* root = new Node(3);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(3);
    root->right->right = new Node(1);

    cout << "Maximum Money: " << rob(root);

    return 0;
}
