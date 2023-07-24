#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int> *root, TreeNode<int> *&prev){
    if(root == NULL) return ;

    solve(root->right,prev);
    solve(root->left,prev);

    root->right = prev;
    root->left = NULL;

    prev = root;

}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    //Approach 1 Recursion
    // TreeNode<int> * prev = NULL;

    // solve(root,prev);
    // return root;
    //TC = O(N);
    //SC = O(N); stack space

    //Approach 2 iterative
    stack<TreeNode<int>*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode<int>* curr = st.top();
        st.pop();

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);

        if(!st.empty()) curr->right = st.top();

        curr->left = NULL;
    }
    return root;
    //TC = O(N);
    //SC = O(N); stack space
}