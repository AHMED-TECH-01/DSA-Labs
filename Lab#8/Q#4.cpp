#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val):data(val),right(nullptr),left(nullptr){}
};
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }

    return -1;
}
Node* buildTree(int preorder[], int inorder[],
                int start, int end, int &preIndex) {

    if (start > end)
        return NULL;

    int value = preorder[preIndex++];
    Node* root = new Node(value);

    if (start == end)
        return root;

    int position = search(inorder, start, end, value);

    root->left = buildTree(preorder, inorder,
                           start, position - 1, preIndex);

    root->right = buildTree(preorder, inorder,
                            position + 1, end, preIndex);

    return root;
}

void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};

    int n = 5;
    int preIndex = 0;

    Node* root = buildTree(preorder, inorder,
                           0, n - 1, preIndex);

    cout << "Constructed Tree (Inorder): ";
    inOrder(root);

    return 0;
}

