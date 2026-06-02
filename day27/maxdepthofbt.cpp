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
    int maxDepth(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL)
        {
            return ans.size();
        }

        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;

            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }

                level.push_back(node->data);
            }

            ans.push_back(level);
        }

        return ans.size();
    }
};
