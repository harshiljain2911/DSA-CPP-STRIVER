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
    // Helper: find leftmost (smallest) node in a subtree
    TreeNode* getMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // FOUND the node — handle 3 cases

            // Case 1: no left child
            if (root->left == nullptr)
                return root->right;

            // Case 2: no right child
            if (root->right == nullptr)
                return root->left;

            // Case 3: both children exist
            TreeNode* successor = getMin(root->right);  // smallest in right subtree
            root->data = successor->val;                  // copy successor value up
            root->right = deleteNode(root->right, successor->data); // delete successor
        }

        return root;
    }
};
