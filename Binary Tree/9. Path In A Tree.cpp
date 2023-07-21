#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool Inorder(TreeNode<int> *root, vector<int>&Path, int x){

	if(root == NULL) return false;

	Path.push_back(root->data);

	if(root->data == x) return true;

	if(Inorder(root->left,Path,x) || Inorder(root->right,Path,x)) return true;

	Path.pop_back();
	return false;

}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    //Using Recursion
	//Using Inorder Traversal

	vector<int> Path;
	if(root == NULL) return Path;

	Inorder(root,Path,x);
	return Path;
	//Tc = O(N);
	//SC = O(H);
}
