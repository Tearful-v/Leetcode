class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_map<int, int>mp;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            mp[nums[j]]++;
            if(mp[nums[j]] <= 2){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};