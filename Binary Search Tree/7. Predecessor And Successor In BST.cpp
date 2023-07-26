#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   
    BinaryTreeNode<int>* curr = root;
    int Succ = -1;

    while(curr){
        if(curr->data > key){
            Succ = curr->data;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    int Pred = -1;
    curr = root;

     while(curr){
        if(curr->data < key){   
            Pred = curr->data;        
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    
    return {Pred,Succ};
    //TC = O(H);
    //SC = O(1);
}
