class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefix = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int tmp = (prefix + i) / (i + 1);
            ans = std::max(ans, tmp);
        }

        return ans;
    }
};
