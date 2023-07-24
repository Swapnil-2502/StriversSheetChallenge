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
#include<bits/stdc++.h>

// TreeNode<int> *BuildTree(vector<int> &preorder,int preStart,int preEnd,
// vector<int> &inorder, int inStart, int inEnd,map<int,int> mp){

//     if(preStart > preEnd || inStart > inEnd) return NULL;

//     TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);

//     int inRoot = mp[root->data];
//     int leftnums = inRoot - inStart; 

//     root->left = BuildTree(preorder,preStart+1,preStart+leftnums,
//     inorder,inStart,inRoot-1,mp);

//     root->right = BuildTree(preorder,preStart+leftnums+1,preEnd,inorder,
//     inRoot+1,inEnd,mp);

//     return root;
// }   

// TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
// {
// 	map<int,int> mp;
//     for(int i=0;i<inorder.size();i++){
//         mp[inorder[i]] = i;
//     }

//     TreeNode<int>* root = BuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

//     return root;
//     //TC = O(N);
//     //SC = O(N);
// }

int findIndex(vector<int> &inorder,int element)
{   
    for(int i=0;i<inorder.size();i++)
    {        
        if(inorder[i]==element)            
        return i;    
    }    
    return -1; 
} 
 
TreeNode<int> * solve(vector<int> &inorder, vector<int> &preorder,int &index,int inorderStart,int inorderEnd,int size)
{    
    if( index >=size || inorderStart>inorderEnd ) 
    {
        return NULL;
    }  
 
    int element=preorder[index++];    
 
    TreeNode<int> *root=new TreeNode<int>(element);    
 
    int position=findIndex(inorder,element);    
 
    root->left=solve(inorder,preorder,index,inorderStart,position-1,size);    
    root->right=solve(inorder,preorder,index,position+1,inorderEnd,size); 
 
    return root; 
}
 
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int index=0;   
    int n=inorder.size();    
    TreeNode<int> *root=solve(inorder,preorder,index,0,n-1,n);    
    return root;
}




