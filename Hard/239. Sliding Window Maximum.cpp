class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> d;
        std::vector<int> answer;

        int left = 0;
        int right = left + k - 1;

        for (int i = 0; i < k; ++i) {
            while (!d.empty() && nums[d.back()] <= nums[i]) {
                d.pop_back();
            }

            d.push_back(i);
        }

        answer.push_back(nums[d.front()]);
        while (right < nums.size() - 1){
            ++left;
            ++right;
            if (left > d.front()) {
                d.pop_front();
            }

            while (!d.empty() && nums[d.back()] <= nums[right]) {
                d.pop_back();
            }

            d.push_back(right);
            answer.push_back(nums[d.front()]);
        }
        return answer;
    }
};
