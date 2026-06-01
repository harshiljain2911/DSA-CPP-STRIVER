
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }

                level.push_back(node->data);
            }
            ans.push_back(level);
        }

    return ans;

    }
};
