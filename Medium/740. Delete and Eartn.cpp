class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];
        int max = nums[0];
        for(int i = 0; i < nums.size(); i++)
            max = std::max(max, nums[i]);

        std::vector<int>pref(max+1, 0);
        for(int i = 0; i < nums.size(); i++)
            pref[nums[i]] += nums[i];

        for(int i = 2; i < max+1; i++)
            pref[i] = std::max(pref[i]+pref[i-2], pref[i-1]);

        return pref[max];
    }
};
