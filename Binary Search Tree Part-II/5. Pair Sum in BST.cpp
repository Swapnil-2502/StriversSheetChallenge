#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BSTiterator{
    stack<BinaryTreeNode<int>*> st;
    //reverse = true = before;
    //reverse = false = next;
    bool reverse = true;

    public:
        BSTiterator(BinaryTreeNode<int>* root, bool isReverse){
            reverse = isReverse;
            PushAll(root);
        } 

        int next(){
            BinaryTreeNode<int>* temp = st.top();
            st.pop();
            if(!reverse) PushAll(temp->right);
            else PushAll(temp->left);
            return temp->data;
        }

        void PushAll(BinaryTreeNode<int>* node){
            for(;node!=NULL;){
                st.push(node);
                if(reverse == true){
                    node = node->right;
                }
                else node = node->left;
            }
        }
};


    bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(!root) return false;
    BSTiterator l(root,false);
    BSTiterator r(root,true);

    int i = l.next();
    int j = r.next();

    while(i<j){
        if(i+j==k) return true;
        if(i+j>k) j = r.next();
        else i = l.next();
    }
    return false;
}
//TC = O(N);
//SC = O(H)*2;
