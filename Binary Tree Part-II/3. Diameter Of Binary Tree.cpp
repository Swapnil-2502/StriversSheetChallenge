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
#include<bits/stdc++.h>

int findDiameter(TreeNode<int> *root, int &diameter){

    if(root == NULL) return 0;

    int lh = findDiameter(root->left,diameter);
    int rh = findDiameter(root->right,diameter);
    diameter = max(diameter,lh+rh);

    return 1 + max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter = 0;

    findDiameter(root,diameter);

    return diameter;
    //TC = O(N);
    //SC = O(N);
}
