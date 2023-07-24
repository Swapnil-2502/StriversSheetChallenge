/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 #include<bits/stdc++.h>
TreeNode<int>* BuildTree(vector<int>& postorder,int postStart,int postEnd,
vector<int>& inorder, int inStart, int inEnd, map<int,int> &mp){

     if(inStart > inEnd || postStart > postEnd) return NULL;

     TreeNode<int>* root = new TreeNode<int>(postorder[postEnd]);

     int inRoot = mp[root->data];
     int numsleft = inRoot - inStart;

     root->left = BuildTree(postorder,postStart,postStart+numsleft-1,
     inorder,inStart,inRoot-1,mp);

     root->right = BuildTree(postorder,postStart+numsleft,postEnd-1,
     inorder,inRoot+1,inEnd,mp);

     return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	map<int,int> mp;

     for(int i=0;i<inorder.size();i++){
          mp[inorder[i]] = i;
     }

     return BuildTree(postorder,0,postorder.size()-1,
     inorder,0,inorder.size()-1,mp);

     //TC = O(N logN);
     //SC = O(N);
}
