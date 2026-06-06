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

    TreeNode* insert(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->data < val)
        {
            root->right = insert(root->right,val);
        }
        else
        {
            root->left = insert(root->left,val);
        }

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = NULL;

        for(int i : preorder)
        {
            root = insert(root,preorder[i]);
        }

        return root;
    }
};
