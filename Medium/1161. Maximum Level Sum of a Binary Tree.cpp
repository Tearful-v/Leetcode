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

    void findmax(TreeNode* root, int level, std::vector<int>&sum){
        if(!root)
            return;
        if(sum.size() == level)
            sum.push_back(root->val);
        else
            sum[level] += root->val;
        findmax(root->left, level+1, sum);
        findmax(root->right, level+1, sum);
    }

    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;
        std::vector<int>sum;
        int level = 0;
        int max = INT_MIN;
        sum.push_back(root->val);
        findmax(root->left, level+1, sum);
        findmax(root->right, level+1, sum);
        for(int i = 0; i < sum.size(); i++){
            if(sum[i] > max){
                max = sum[i];
                level = i;
            }
        }
        return level + 1;
    }
};