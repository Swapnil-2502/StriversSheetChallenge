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

int check(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    int leftheight = check(root->left);
    if(leftheight == -1) return -1;
    int rightheight = check(root->right);
    if(rightheight == -1) return -1;

    if(abs(leftheight-rightheight)>1) return -1;
    return 1+max(leftheight,rightheight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    
    return check(root) != -1;
    //TC = O(N);
    //SC = O(N);
}