class Solution { //dp solution O(n^2)
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> dp(size, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < size; i++)
            for(int j = 1; j <= nums[i] && (i+j) < size; j++)
                dp[i+j] = std::min((dp[i]+1), dp[i+j]);
        return dp[size-1];
    }
};


class Solution { // greedy O(n)
public:
    int jump(vector<int>& nums) {
        int far = 0;
        int jumps = 0;
        int end = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            far = std::max(far, i + nums[i]);
            if (i == end){
                jumps++;
                end = far;
            }
        }
        return jumps;
    }
};
