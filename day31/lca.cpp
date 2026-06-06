/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        if( (root->data < p) && (root->data < q) ) return lca(root->right,p,q);
	        else if( (root->data > p) && (root->data > q) ) return lca(root->left,p,q);
            else return root;
		}
};
