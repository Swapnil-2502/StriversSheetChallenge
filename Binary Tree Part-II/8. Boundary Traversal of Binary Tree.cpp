#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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

bool isleaf(TreeNode<int>* root){
    return (root->left == NULL && root->right == NULL);
}

void addLeftsubtree(TreeNode<int>* root, vector<int>&res){
    TreeNode<int>* curr = root->left;

    while(curr){
        if(!isleaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightsubtree(TreeNode<int>* root, vector<int>&res){
    TreeNode<int>* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }

}

void addleaf(TreeNode<int>* root, vector<int>&res){
    
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left) addleaf(root->left,res);
    if(root->right) addleaf(root->right,res);

}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(root == NULL) return res;

    if(!isleaf(root)) res.push_back(root->data);

    addLeftsubtree(root,res);
    addleaf(root,res);
    addRightsubtree(root,res);

    return res;

    //TC = O(H)+O(H)+O(N) = O(N);
    //SC = O(N);
}