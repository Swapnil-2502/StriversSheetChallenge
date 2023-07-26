#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    
    if(root == NULL) return false;

    if(root->data == x) return true;

    if(root->data > x) return searchInBST(root->left,x);
    if(root->data < x) return searchInBST(root->right,x);

    //TC = O(log2 N); its log base 2
    //SC = O(H); recursion stack space
}