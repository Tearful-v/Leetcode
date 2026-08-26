/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validation (TreeNode* root, long long max, long long min) {
        if (!root) {
            return true;
        }
        if(root->val <= min || root->val >= max) {
            return false;
        }
        return validation(root->left, root->val, min) && validation(root->right, max, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return validation(root->left, root->val, LONG_LONG_MIN) && validation(root->right, LONG_LONG_MAX, root->val);
    }
};
