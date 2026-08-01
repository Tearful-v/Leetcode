class Solution { //храним разрыв между соперниками
public:
    bool predictTheWinner(vector<int>& nums) {
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size()));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][i] = nums[i];
        }
        for (int lenght = 2; lenght <= nums.size(); ++lenght) {
            for (int left = 0; left + lenght <= nums.size(); ++left) {
                int right = left + lenght - 1;

                dp[left][right] = std::max (
                    nums[left] - dp[left + 1][right],
                    nums[right] - dp[left][right - 1]
                );
            }
        }
        return dp[0][nums.size() -1] >= 0;
    }
};
