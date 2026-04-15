class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp (amount+1, amount+1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0)
                    dp[i] = std::min(dp[i-coins[j]]+1, dp[i]);
            }
        }
        if(dp[amount] != amount+1)
            return dp[amount];
        return -1;
    }
};
