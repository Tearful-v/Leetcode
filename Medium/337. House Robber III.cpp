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
    using PII = std::pair<int, int>;

    PII dfs(TreeNode* root) {
        if (!root) {
            return std::make_pair(0, 0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int take = root->val + left.second + right.second;
        int skip = std::max(left.first, left.second) +
                   std::max(right.first, right.second);
        return std::make_pair(take, skip);
    }

    int rob(TreeNode* root) {
        auto answer = dfs(root);
        return std::max(answer.first, answer.second);
    }
};
