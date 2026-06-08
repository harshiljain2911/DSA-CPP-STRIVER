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
    TreeNode* first = nullptr;   // first bad node
    TreeNode* second = nullptr;  // second bad node
    TreeNode* prev = nullptr;    // previous node in inorder

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Check if current node violates BST order
        if (prev && prev->data > root->data) {
            if (!first) first = prev;   // first violation: grab the bigger node
            second = root;              // always update second to current smaller node
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->data, second->data);
    }
};
