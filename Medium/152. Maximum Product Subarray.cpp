class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        int result = max;

        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];
            int tmp = std::max(current, std::max(min*current, max*current));
            min = std::min(current, std::min(max*current, min*current));
            max = tmp;
            result = std::max(max, result);
        }

        return result;
    }
};
