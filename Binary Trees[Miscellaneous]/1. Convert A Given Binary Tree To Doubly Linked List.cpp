#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/

void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head){
    if(root == NULL) return;

    solve(root->right,head);
    root->right = head;

    if(head) head->left = root;

    head = root;

    solve(root->left,head);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* temp = NULL;
    solve(root,temp);
    return temp;
}
//TC = O(N);
//SC = O(1); agnoring recursion stack space