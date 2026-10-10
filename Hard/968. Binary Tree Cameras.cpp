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
    int answer = 0;

    int dfs(TreeNode* root) {
        if (!root) {
            return -1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == -1 && right == -1) {
            return 0;
        }
        if (left == 0 || right == 0) {
            ++answer;
            return 2;
        }
        if (left == 1 || right == 1) {
            return 0;
        }
        if ((left == 1 && right == 2) || (left == 2 && right == 1)) {
            return 1;
        }
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if (!dfs(root)) {
            ++answer;
        }
        return answer;
    }
};
