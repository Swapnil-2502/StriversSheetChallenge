#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	if(root == NULL) return root;

    int currValue = root->data;

    if(currValue > p->data && currValue > q->data) return LCAinaBST(root->left,p,q);
    if(currValue < p->data && currValue < q->data) return LCAinaBST(root->right,p,q);

    return root;
}
//TC = O(H);
//SC = O(1);
