class Solution {
public:

    int countl;
    int counts;
    vector<int> result;

    void inorder(TreeNode* root) {
        if (root == nullptr || counts == 0)
            return;

        inorder(root->left);

        if(counts == 0) return;

        counts--;

        if (counts == 0) {
            result.push_back(root->data);
            return;
        }

        inorder(root->right);
    }

    void revinorder(TreeNode* root) {
        if (root == nullptr || countl == 0)
            return;

        revinorder(root->right);

        if(countl == 0) return;

        countl--;

        if (countl == 0) {
            result.push_back(root->data);
            return;
        }

        revinorder(root->left);
    }

    vector<int> kLargesSmall(TreeNode* root, int k) {

        countl = k;
        counts = k;

        inorder(root);      // kth smallest
        revinorder(root);   // kth largest

        return result;
    }
};
