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
    vector<int> succPredBST(TreeNode* root,int key) {
        int pre = -1, suc = -1;
        
        // --- Find Predecessor ---
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr->data;   // candidate, but go right for a better one
                curr = curr->right;
            } else {
                curr = curr->left;  // too big or equal, go left
            }
        }
        
        // --- Find Successor ---
        curr = root;  // reset to root
        while (curr != NULL) {
            if (curr->data > key) {
                suc = curr->data;   // candidate, but go left for a better one
                curr = curr->left;
            } else {
                curr = curr->right; // too small or equal, go right
            }
        }
        
        return {pre, suc};
    }
};
