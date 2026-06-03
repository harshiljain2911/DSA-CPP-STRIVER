class Solution {
public:

    bool isLeaf(TreeNode* root)
    {
        return root->left == NULL &&
               root->right == NULL;
    }

    void addLeftBoundary(TreeNode* root,vector<int>& ans)
    {
        TreeNode* curr = root->left;

        while(curr)
        {
            if(!isLeaf(curr))
                ans.push_back(curr->data);

            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root,<int>& ans)
    {
        if(root == NULL)
            return;

        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root,<int>& ans)
    {
        TreeNode* curr = root->right;

        vector<int> temp;

        while(curr)
        {
            if(!isLeaf(curr))
                temp.push_back(curr->data);

            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for(int i=temp.size()-1;i>=0;i--)
        {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundary(TreeNode *root)
    {
        vector<int> ans;

        if(root == NULL)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->data);

        addLeftBoundary(root, ans);

        addLeaves(root, ans);

        addRightBoundary(root, ans);

        return ans;
    }
};
