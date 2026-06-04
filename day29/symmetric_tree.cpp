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

    bool ismirror(TreeNode* left, TreeNode* right) {

        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->data != right->data) return false;

        return (ismirror(left->left,right->right)) && (ismirror(left->right,right->left));

    }

    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
};
