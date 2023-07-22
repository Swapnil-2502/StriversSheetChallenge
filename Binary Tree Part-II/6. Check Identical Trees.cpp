#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/
bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1==NULL || root2==NULL) return (root1==root2);

    return (root1->data==root2->data &&
    solve(root1->left,root2->left)&&
    solve(root1->right,root2->right));
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return solve(root1,root2);	 
    //TC = O(N);
    //SC = O(N);
}