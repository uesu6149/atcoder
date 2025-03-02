class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> vec;
        inorderTraversal(root, vec);
  //      sort(vec.begin(), vec.end());  // Already sorted

        // Find min abs
        int min = vec[1] - vec[0];
        for (int i = 2; i < vec.size(); i++) {
            if ((vec[i] - vec[i-1]) < min) {
                min = (vec[i] - vec[i-1]);
            }
        }

        return min;
    }

    void inorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right,vec);
    }
};