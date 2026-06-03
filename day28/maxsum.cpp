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
    int sum = INT_MIN;

    int depsum(TreeNode* node) {
        if (node == NULL) return 0;

        // Clamp to 0: don't extend into a negative-sum subtree
        int left  = max(0, depsum(node->left));
        int right = max(0, depsum(node->right));

        // Best path passing THROUGH this node (local candidate)
        sum = max(sum, left + right + node->data);

        // Return the best single-arm extension to the parent
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        depsum(root);
        return sum;
    }
};	
