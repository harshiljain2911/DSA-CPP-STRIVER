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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->data != q->data) return false;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        return left && right;

    }
};
