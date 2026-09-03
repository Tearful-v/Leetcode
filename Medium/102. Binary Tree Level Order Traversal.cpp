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

    void GetLevel(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        if (level == answer.size()) {
            answer.push_back({});
        }

        answer[level].push_back(root->val);
        GetLevel(root->left, level + 1);
        GetLevel(root->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        GetLevel(root, 0);
        return answer;
    }
};
