#include<iostream>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template<typename T>
class TreeNode {
public:
    TreeNode() : left{nullptr}, right{nullptr} {
        // empty default constructor
    }

    explicit TreeNode(const T& data, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr) 
        : data{data}, left{left}, right{right} {
            // empty body
        }

    T data;
    TreeNode<T> *left, *right;
};

template<typename T>
class BinarySearchTree {
public:
    // constructors
    BinarySearchTree() : root{nullptr} {}; // default constructor;
    // one parameter explicit constrctor
    explicit BinarySearchTree(const T& data) {
        root = new TreeNode<T>(data);
    }

    // insert operation
    void insert(const T& data) {
        
        if (root == nullptr) {
            root = new TreeNode<T>(data);
            return;
        }
        // call to the recursive insert method
        insert(data, root);

    }

    void insert(const T& data, TreeNode<T>* node) {

        // preserved thr BST property
        if (node->data < data) {
            // add the new node recursively based on existance of the right
            if (node->right != nullptr) 
                insert(data, node->right);
            else {
                node->right = new TreeNode<T>(data);
            }
        } else {
            // add the new node recursively based on existance of the left
            if (node->left != nullptr) 
                insert(data, node->left);
            else {
                node->left = new TreeNode<T>(data);
            }
        }
    }

    void iterative_insert(const T& data) {

        TreeNode<T>* newNode = new TreeNode<T>(data);
        TreeNode<T> *currentNode{root}, *prev{nullptr};

        while (currentNode != nullptr) {
            prev = currentNode;

            if (data > currentNode->data) 
                currentNode = currentNode->right;
            else 
                currentNode = currentNode->left;
        }

        // add the new node to prev node based on data
        if (prev == nullptr) {
            root = newNode;
        } else if (prev->data > data) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
        

    }

    // tree traversal methods
    void inorder_traversal(const TreeNode<T>* node) const {
        
        if (node != nullptr) {
            inorder_traversal(node->left);
            std::cout << node->data << " ";
            inorder_traversal(node->right);
        }

    }

    void preorder_traversal(const TreeNode<T>* node) const {
        
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorder_traversal(node->left);
            preorder_traversal(node->right);
        }
    }

    void postorder_traversal(const TreeNode<T>* node) const {

        if (node != nullptr) {
            postorder_traversal(node->left);
            postorder_traversal(node->right);
            std::cout << node->data << " ";
        }
    }

    const TreeNode<T>* const getRoot() const {
        return root;
    }

    bool is_empty() const {
        return root == nullptr;
    }

private:
    TreeNode<T>* root;

};

#endif