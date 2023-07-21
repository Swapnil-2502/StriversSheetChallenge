#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> levelorder;
    if(root == NULL) return levelorder;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i=1;i<=n;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            levelorder.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return levelorder;
    //TC = O(N);
    //SC = O(N);
}