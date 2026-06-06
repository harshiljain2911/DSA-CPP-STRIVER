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

        bool validate(TreeNode *root,long long min , long long max) {
            
            if(!root) return true;

            if(root->data < min || root->data >= max) return false;

            return (validate(root->left,min,root->data) && validate(root->right,root->data,max));
        }

		bool isBST(TreeNode* root){
			return validate(root,LLONG_MIN,LLONG_MAX);
		}
};
