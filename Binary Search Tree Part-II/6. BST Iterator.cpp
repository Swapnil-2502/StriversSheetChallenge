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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        PushAll(root);
    }

    int next()
    {
        TreeNode<int>*temp = st.top();
        st.pop();
        PushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void PushAll(TreeNode<int>* node){
        for(;node!=NULL;st.push(node),node = node->left);
    }
};
//TC = O(1);
//SC = O(H);


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/