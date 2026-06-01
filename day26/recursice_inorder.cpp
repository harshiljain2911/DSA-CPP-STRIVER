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
		vector<int> inorder(TreeNode* root){
	        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        vector<int> left = inorder(root->left);
        vector<int> right = inorder(root->right);
        
        ans.insert(ans.end(),left.begin(),left.end());
        ans.push_back(root->data);
        ans.insert(ans.end(),right.begin(),right.end());

        return ans;

		}
};
