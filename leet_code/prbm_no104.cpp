class Solution {
public:

	int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth_Uesugi(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }

        int right = maxDepth(root->right) + 1;
        int left = maxDepth(root->left) + 1;
        
        return (right > left) ? right : left;
    }
};