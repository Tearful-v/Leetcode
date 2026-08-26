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
    int max = -100000000;

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = std::max(0, dfs(root->left));
        int right = std::max(0, dfs(root->right));

        max = std::max(max, root->val + left + right);
        return std::max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max;
    }
};
