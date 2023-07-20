#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void Postorder(TreeNode *root,vector<int> &post){
    if(root == NULL) return;

    Postorder(root->left,post);
    Postorder(root->right,post);
    post.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // //Recusion
    vector<int>post;
    if(root == NULL) return post;

    Postorder(root,post);
    return post;
    //TC = O(N);
    //SC = O(1);

    //Iteravtive
    //Using Two Stack
    
    vector<int> PostOrder;
    if(root == NULL) return PostOrder;
    stack<TreeNode*> s1,s2;
    TreeNode* node = root;
    s1.push(node);

    while(!s1.empty()){        
        node = s1.top();
        s1.pop();
        s2.push(node);

        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);

    }

    while(!s2.empty()){
        node = s2.top();
        s2.pop();
        PostOrder.push_back(node->data);
    }
    return PostOrder;
    //TC = O(N);
    //SC = O(2N);

    //Using One Stack;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    vector<int> Postorder;

    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                Postorder.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    Postorder.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }

    return Postorder;
    //TC = O(N);
    //SC = O(N);

}