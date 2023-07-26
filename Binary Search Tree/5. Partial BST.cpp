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

bool solve(BinaryTreeNode<int> *root, int lb,int ub){
    if(root == NULL) return true;

    if(root->data>ub || root->data<lb) return false;

    return solve(root->right,root->data,ub) && solve(root->left,lb,root->data);
}

bool validateBST(BinaryTreeNode<int> *root) {
    
    return solve(root,-INT_MIN,INT_MAX);

    //TC = O(N);
    //SC = O(1);
}
