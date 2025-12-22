class Solution {
public:

    int leftbinary(std::vector<int> &array, int target){
        int left = 0;
        int right = array.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(array[mid] < target)
                left = mid+1;
            else
                right = mid;
        }
        return right;
    }

    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;
        if(nums.size()>= 1)
            dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > dp[dp.size()-1])
                dp.push_back(nums[i]);
            else{
                int pos = leftbinary(dp, nums[i]);
                dp[pos] = nums[i];
            }
        }
        return dp.size();
    }
};