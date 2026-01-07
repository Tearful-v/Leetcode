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

    long long answer = 0;

    void findsum(TreeNode* root, long long& sum){
        if(!root)
            return;
        sum += root->val;
        findsum(root->left, sum);
        findsum(root->right, sum);
    }

    long long findmin(TreeNode* root, long long sum){
        if(!root)
            return 0;
        long long current = root->val;
        current += findmin(root->left, sum) + findmin(root->right, sum);
        answer = std::max(answer, current * (sum - current));
        return current;
    }

    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        long long sum = 0;
        findsum(root, sum);
        findmin(root, sum);        
        return answer % 1000000007;
    }
};