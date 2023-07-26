#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

bool helper(TreeNode<int>* root, stack<TreeNode<int>*> &st, TreeNode<int>* leaf){

    st.push(root);

    if(root->left == NULL && root->right == NULL){

        if(root->data == leaf->data) return true;

        else{
            st.pop();
            return false;
        }
    }


    bool left = false, right = false;

    if(root->left){
        left = helper(root->left,st,leaf);
    }

    if(left) return true;

    if(root->right){
        right = helper(root->right,st,leaf);
    }

    if(right) return true;

    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(root == NULL) return root;

	stack<TreeNode<int>*> st;

    helper(root,st,leaf);

    TreeNode<int>* newroot = st.top();
    st.pop();

    TreeNode<int>* parent = newroot;

    while(!st.empty()){

        TreeNode<int>* curNode = st.top();
        st.pop();

        if(curNode->left == parent){
            curNode->left = NULL;
            parent->left = curNode;
        }
        else{
            curNode->right = curNode->left;
            curNode->left = NULL;
            parent->left = curNode;
        }
        parent = parent->left;
    }

    return newroot;
}
