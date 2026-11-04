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
    std::vector<std::vector<int>> answer;

    void dfs(TreeNode* root, std::vector<int> route,
            int amount, int target) {
        if (!root) {
            return;
        }
        route.push_back(root->val);
        amount += root->val;
        if (!root->left && !root->right) {
            if (amount == target) {
                answer.push_back(route);
            }
            return;
        }
        dfs(root->left, route, amount, target);
        dfs(root->right, route, amount, target);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, {}, 0, targetSum);
        return answer;
    }
};
