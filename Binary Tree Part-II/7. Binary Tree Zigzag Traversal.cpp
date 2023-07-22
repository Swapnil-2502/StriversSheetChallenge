#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    deque<BinaryTreeNode<int>*> dq;
    dq.push_front(root);
    bool flag = false; //false means left to right ans true means opposite

    while(!dq.empty()){

        int n = dq.size();

        for(int i=1;i<=n;i++){
            if(flag==false){
            BinaryTreeNode<int>* node = dq.front();
            dq.pop_front();

            ans.push_back(node->data);

            if(node->left) dq.push_back(node->left);
            if(node->right) dq.push_back(node->right);

            }
            else if(flag==true){
                BinaryTreeNode<int>* node = dq.back();
                dq.pop_back();

                ans.push_back(node->data);

                if(node->right) dq.push_front(node->right);
                if(node->left) dq.push_front(node->left);
            }
        }
        
        flag = !flag;
    }
    return ans;
    //TC = O(N);
    //SC =O(N);
}
