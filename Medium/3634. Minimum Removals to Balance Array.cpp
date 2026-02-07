class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int answer = INT_MAX;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            while(1LL * nums[j] > 1LL * nums[i]*k)
                i++;
            int cur = nums.size() - (j - i + 1);
            answer = std::min(answer, cur);
        }
        return answer;
    }
};
