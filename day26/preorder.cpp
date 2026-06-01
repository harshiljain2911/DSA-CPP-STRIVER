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
		vector<int> preorder(TreeNode* root){
	       vector<int> ans;

           if(root == NULL)
           {
            return ans;
           }

           ans.push_back(root->data);

           vector<int> left = preorder(root->left);
           vector<int> right = preorder(root->right);

           ans.insert(ans.end(),left.begin(),left.end());
           ans.insert(ans.end(),right.begin(),right.end());

           return ans;
		}
};
