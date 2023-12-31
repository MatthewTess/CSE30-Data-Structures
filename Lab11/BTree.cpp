#include <iostream>

class Node {
public:
    int key_value;
    Node* left;
    Node* right;
};

class BTree {
private:
    Node* root;

    void destroy_tree(Node* leaf);
    void insert(int key, Node* leaf);
    Node* search(int key, Node* leaf);

public:
    BTree();
    ~BTree();
    Node* BTree_root();
    void insert(int key);
    Node* search(int key);
    void destroy_tree();
};

BTree::BTree() {
    root = nullptr;
}

BTree::~BTree() {
    destroy_tree();
}

Node* BTree::BTree_root() {
    return root;
}

void BTree::destroy_tree(Node* leaf) {
    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key, Node* leaf) {
    if (key < leaf->key_value) {
        if (leaf->left != nullptr) {
            insert(key, leaf->left);
        } else {
            leaf->left = new Node;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    } else if (key >= leaf->key_value) {
        if (leaf->right != nullptr)
            insert(key, leaf->right);
        else {
            leaf->right = new Node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

Node* BTree::search(int key, Node* leaf) {
    if (leaf != nullptr) {
        if (key == leaf->key_value) {
            return leaf;
        }

        if (key < leaf->key_value) {
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right);
        }
    } else
        return nullptr;
}

void BTree::insert(int key) {
    if (root != nullptr) {
        insert(key, root);
    } else {
        root = new Node;
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

Node* BTree::search(int key) {
    return search(key, root);
}

void BTree::destroy_tree() {
    destroy_tree(root);
}

int main() {
    // Test the BTree class here

    return 0;
}
