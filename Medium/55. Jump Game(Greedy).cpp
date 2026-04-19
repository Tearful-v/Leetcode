class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 1)
            return true;

        int energy = nums[0];
        bool flag = false;
        std::vector<int>::iterator it = nums.begin();

        while(it != nums.end() && energy > 0){
            if(it + 1 == nums.end())
                return true;

            ++it;
            energy -= 1;
            energy = std::max(energy, *it);
        }

        if(it + 1 == nums.end())
            return true;
        return false;
    }
};

//Greedy idea - O(n); DP idea - O(n^2)(nested loop)
