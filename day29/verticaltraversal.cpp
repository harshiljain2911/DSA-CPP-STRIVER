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
    vector<tuple<int,int,int>> nodes; // col,row,val

    void dfs(TreeNode* root,int row,int col) {
        if(!root) return;
        nodes.push_back({col,row,root->data});
        dfs( root->left , row + 1 , col - 1);
        dfs( root->right , row + 1 , col + 1);

    }

    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	dfs(root,0,0);
        sort(nodes.begin(),nodes.end());

        vector<vector<int>> result;
        int prevcol = INT_MIN;

        for (auto& [col,row,val] : nodes)
        {
            if(col != prevcol)
            {
                result.push_back({});
                prevcol = col;
            }
            result.back().push_back(val);
        }

        return result;
    }

};
