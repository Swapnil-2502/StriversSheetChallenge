#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{

    if(root == NULL) return 0;

    queue<TreeNode<int>*> q;
    q.push(root);

    int maxi = INT_MIN;

    while(!q.empty()){

        int n = q.size();
        maxi = max(maxi,n);

        for(int i=1;i<=n;i++){
            TreeNode<int>* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return maxi;
    //Tc = O(N);
    //SC = O(N);
    
}