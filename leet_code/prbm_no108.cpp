/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
/*
    void insert(int data, TreeNode* root) {

        TreeNode* newNode = new TreeNode(data);

        // RootNodeがないので、これがRootとなる
        if (!root) {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        while (1) {
            // 新しいデータが現在のノードより小さい場合
            if (newNode->val < current->val) {
                if (!current->left) {
                    current->left = newNode;
                    return;
                }
                current = current->left; // 左ノードに移動
            } else {
                if (!current->right) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }
    */
    /*
        TreeNode* insertNode(TreeNode* root, const vector<int>& nums, int start,
       int end, int id) { int middle = start + (end-start)/2;

            if (root == nullptr) {
                root = new TreeNode(nums[middle]);
            }

            printf("%d,%d,%d,%d\n", start, end,middle,id);
            if (start >= end) {
                return nullptr;
            }

            root->left = insertNode(root, nums, start, middle-1, 1);
            root->right = insertNode(root, nums, middle+1, end, 2);
            return (new TreeNode(nums[middle]));
        }
    */

    TreeNode* insertNode(const std::vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int middle = start + (end - start) / 2;

        TreeNode* newNode = new TreeNode(nums[middle]);

        newNode->left = insertNode(nums, start, middle - 1);
        newNode->right = insertNode(nums, middle + 1, end);

        return newNode;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        if (nums.size() == 1) {
            return (new TreeNode(nums[0]));
        }

        root = insertNode(nums, 0, nums.size() - 1);

        return root;
    }

    /*
        TreeNode* sortedArrayToBST(vector<int>& nums) {

            //
            if (nums.size() == 1) {
                return (new TreeNode(nums[0]));
            }

            TreeNode* root = nullptr;
            for (int i = 0; i < nums.size(); i++) {
                // insert(nums[i], root);

                TreeNode* newNode = new TreeNode(nums[i]);

                // RootNodeがないので、これがRootとなる
                if (!root) {
                    root = newNode;
                    continue;
                }

                TreeNode* current = root;
                if (0) {
                    printf("Current:%d, newNode:%d\n", current->val,
       newNode->val);
                }

                while (1) {
                    // 新しいデータが現在のノードより小さい場合
                    if (newNode->val < current->val) {
                        if (!current->left) {
                            current->left = newNode;
                            break;
                        }
                        current = current->left; // 左ノードに移動
                    } else {
                        if (!current->right) {
                            current->right = newNode;
                            break;
                        }
                        current = current->right;
                    }
                }
            }

            cout<<"Root:"<<root->val<<endl;

            return root;
        }
        */
};