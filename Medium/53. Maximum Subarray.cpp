class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];

        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = std::max(nums[i-1] + nums[i], nums[i]);
            max = std::max(max, nums[i]);
        }

        return max;
    }
};
