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


        // FIXED: pass min/max range instead of checking only immediate children
    bool validBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;                          // FIX 1: null = valid, not false
        if (root->data <= minVal || root->data >= maxVal)  // FIX 2: range check, not child check
            return false;
        return validBST(root->left,  minVal,    root->data)   // FIX 3: removed dead code + typo
            && validBST(root->right, root->data, maxVal);
    }

    int heightBST(TreeNode* root) {
        
        
        int nodes=0;
        queue<TreeNode*> q;

        if (root == NULL)
        {
            return nodes;
        }

        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }

                level.push_back(node->data);

            }
            
            nodes+=level.size();
        }
        return nodes;
    }
    


		int largestBST(TreeNode* root){
			
            if(!root) return 0;

            int current_height = 0;

           if (validBST(root, LONG_MIN, LONG_MAX)) {        // FIX 8: pass range bounds
            current_height = heightBST(root);
        }

        // recurse into left and right subtrees regardless
        int leftheight = largestBST(root->left);
        int rightheight = largestBST(root->right);

        return max({current_height, leftheight, rightheight});

		}
};
