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
void leftView(TreeNode<int>*root,vector<int>&ans,int level){
    if(root==NULL) return;

    if(level == ans.size()) ans.push_back(root->data);

    leftView(root->left,ans,level+1);
    leftView(root->right,ans,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //Recursive
    vector<int> ans;
    if(root==NULL) return ans;

    leftView(root,ans,0);
    //TC = O(N);
    //SC = O(H) H==height of binary Tree;
    
    //Iterative
    vector<int> leftView;
    if(root==NULL) return leftView;

    queue<TreeNode<int>*>q;
    TreeNode<int>* temp = root;
    q.push(temp);

    while(!q.empty()){
        int n = q.size();

        for(int i=1;i<=n;i++){
            TreeNode<int>* node = q.front();
            q.pop();

            if(i==1) leftView.push_back(node->data);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return leftView;
    //TC = O(N);
    //SC = O(N);
}