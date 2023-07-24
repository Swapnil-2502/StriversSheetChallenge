#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int MaximumPathSum(TreeNode<int> *root,long long &maxi){
    if(root == NULL) return 0;

    long long leftSum = MaximumPathSum(root->left,maxi);
    long long rightSum = MaximumPathSum(root->right,maxi);

    maxi = max(maxi,root->val + leftSum + rightSum);

    return (root->val + max(leftSum,rightSum));
}

long long int findMaxSumPath(TreeNode<int> *root) {
   long long maxi = INT_MIN;

    if( !root || !root->left || !root->right) return -1;

    MaximumPathSum(root,maxi);

    return maxi;
    //TC = O(N);
    //SC = O(N);
}