#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void Preorder(TreeNode *root,vector<int> &pre){
    if(root == NULL) return;

    pre.push_back(root->data);
    Preorder(root->left,pre);
    Preorder(root->right,pre);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    //Recusive
    vector<int> pre;
    if(root == NULL) return pre;
    Preorder(root,pre);

    return pre;
    //TC = O(N);
    //SC = O(1);

    //Iteractive
    stack<TreeNode* > st;
    vector<int>preOrder;
    TreeNode* node = root;

    while(true){
        if(node != NULL){
            preOrder.push_back(node->data);
            if(node->right) st.push(node->right);
            node= node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
        }
    }
    return preOrder;
    //TC = O(N);
    //SC = O(N);
}