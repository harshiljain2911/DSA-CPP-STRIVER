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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        queue<TreeNode*> q;
        int rev = 0;

        if (root == NULL) {
            return ans;
        }

        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                level.push_back(node->data);
            }
            if (rev == 1)
                reverse(level.begin(),level.end());

            ans.push_back(level);
            rev=!rev;
        }

        return ans;
    }
};
