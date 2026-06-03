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
    int diameter = 0;

    int height(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        diameter = max(diameter,left+right);    

        return 1+max(left,right);

    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);

        return diameter;

    }
};
