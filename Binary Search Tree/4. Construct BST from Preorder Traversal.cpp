#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* BuildTree(vector<int> &A, int &i, int bound){
    if(i==A.size() || A[i]>bound) return NULL;

    TreeNode<int>* root = new TreeNode<int>(A[i++]);
    root->left = BuildTree(A,i,root->data);
    root->right = BuildTree(A,i,bound);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int i=0;
    return BuildTree(preOrder,i,INT_MAX);

    //TC = O(3N) at worst case == O(N);
    //SC = O(1);
}