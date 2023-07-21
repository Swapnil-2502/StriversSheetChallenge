#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode<int>*,pair<int,int>>> q;
    map<int,map<int,vector<int>>> mp;

    q.push({root,{0,0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        mp[it.second.first][it.second.second].push_back(it.first->data);

        if(it.first->left) q.push({it.first->left,{it.second.first-1,it.second.second+1}});
        if(it.first->right) q.push({it.first->right,{it.second.first+1,it.second.second+1}});
    }

    for(auto it: mp){
        for(auto i : it.second){
            for(auto j: i.second){
                ans.push_back(j);
            }
        }
    }
    return ans;
    //TC = O(N)N;
    //SC = O(N);
}