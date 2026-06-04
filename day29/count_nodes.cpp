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
     int countNodes(TreeNode* root) {
        // If tree is empty, return 0
        if (root == NULL) {
            return 0;
        }
        // Get height from left side
        int lh = findHeightLeft(root);
        // Get height from right side
        int rh = findHeightRight(root);
        // If heights are equal, it's a perfect binary tree
        if (lh == rh) {
            // Use formula: 2^h - 1
            return (1 << lh) - 1;
        }
        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Helper function to find height of leftmost path
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Helper function to find height of rightmost path
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};
