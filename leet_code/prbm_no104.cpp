class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }

        int right = maxDepth(root->right) + 1;
        int left = maxDepth(root->left) + 1;
        
        return (right > left) ? right : left;
    }
};