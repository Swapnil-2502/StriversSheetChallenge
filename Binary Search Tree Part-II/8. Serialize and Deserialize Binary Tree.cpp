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
string serializeTree(TreeNode<int> *root)
{
    if(root == NULL) return "";
    queue<TreeNode<int>*> q;
    q.push(root);

    string s = "";

    while(!q.empty()){
        TreeNode<int>* currNode = q.front();
        q.pop();

        if(currNode==NULL) s.append("#,");
        else s.append(to_string(currNode->data)+',');

        if(currNode!=NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;

}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size()==0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s,str,',');

    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* currNode = q.front();
        q.pop();

        getline(s,str,',');

        if(str=="#") currNode->left = NULL;
        else{
            TreeNode<int>* l = new TreeNode<int>(stoi(str));
            currNode->left = l;
            q.push(l);
        }

        getline(s,str,',');

        if(str=="#") currNode->right = NULL;
        else{
            TreeNode<int>* r = new TreeNode<int>(stoi(str));
            currNode->right = r;
            q.push(r);
        }
    }
    return root;
}
//TC = O(N);
//SC = O(N);


