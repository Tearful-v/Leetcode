class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size()));
        dp[0][0] = nums1[0] * nums2[0];
        for(int i = 1; i < nums1.size(); i++){
            dp[i][0] = std::max(dp[i-1][0], (nums1[i] * nums2[0]));
        }
        for(int j = 1; j < nums2.size(); j++){
            dp[0][j] = std::max(dp[0][j-1], (nums2[j] * nums1[0]));
        }
        for(int i = 1; i < nums1.size(); i++){
            for(int j = 1; j < nums2.size(); j++){
                dp[i][j] = std::max( std::max((dp[i-1][j-1] + nums1[i]*nums2[j]), (nums1[i]*nums2[j])), std::max (dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
    }
};