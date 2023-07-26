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
void solve(TreeNode<int>* root, int k, int &count, int &ans){
    if(root == NULL) return;

    solve(root->right,k,count,ans);
    count++;
    if(count==k){
        ans = root->data;
    }
    solve(root->left,k,count,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    int count = 0;
    solve(root,k,count,ans);
    return ans;
    //TC = O(N);
    //SC = O(1);
}

