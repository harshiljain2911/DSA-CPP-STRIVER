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

    int height(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int left = height(root->left);

        if(left == -1)
        {
            return -1;
        }

        int right = height(root->right);
        if(right == -1)
        {
            return -1;
        }

        if(abs(left-right) > 1)
            return -1;

        return 1 + max(left,right);
    }


    bool isBalanced(TreeNode *root){
    	return height(root) != -1;
    }
};
