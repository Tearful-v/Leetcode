class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        int mid = nums.size()/2;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != mid) {
                sum += std::abs(nums[mid] - nums[i]);
            }
        }
        return sum;
    }
};
