/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:

    vector<int> ans;

    void dfs(TreeNode *root, int level) {

        if(root == NULL)
        {
            return;
        }

        if(level == ans.size())
        {
            ans.push_back(root->data);
        }

        dfs(root->right,level+1);
        dfs(root->left,level+1);

    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
