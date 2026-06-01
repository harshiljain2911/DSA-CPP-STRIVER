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
		vector<int> postorder(TreeNode* root){
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        vector<int> left = postorder(root->left);
        vector<int> right = postorder(root->right);
        
        ans.insert(ans.end(),left.begin(),left.end());
        ans.insert(ans.end(),right.begin(),right.end());
        ans.push_back(root->data);

        return ans;

		}
};
