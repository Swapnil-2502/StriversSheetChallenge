#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    
    if(root == NULL) return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i=0;i<n-1;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if(!q.empty()){
                node->next = q.front();
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        BinaryTreeNode<int>* y = q.front();
        q.pop();
        if(y->left) q.push(y->left);
        if(y->right) q.push(y->right);

    }
    //TC = O(N);
    //SC = O(N);

}