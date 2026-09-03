class Solution {
public:

    int DefautlRob(vector<int> nums) {
        nums[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            nums[i] = std::max(nums[i-1], (nums[i]+nums[i-2]));
        }
        return nums[nums.size()-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return std::max(nums[1], nums[0]);
        return std::max(DefautlRob(std::vector<int>{nums.begin(), nums.end()-1}),
                DefautlRob(std::vector<int>{nums.begin() + 1, nums.end()}));
    }
};
