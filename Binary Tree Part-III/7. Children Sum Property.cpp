#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    
    if(root == NULL) return;

    int children = 0;
    if(root->left) children += root->left->data;
    if(root->right) children += root->right->data;

    if(children >= root->data) root->data = children;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left or root->right) root->data = total;

    //TC = O(N);
    //SC = O(H);
}  