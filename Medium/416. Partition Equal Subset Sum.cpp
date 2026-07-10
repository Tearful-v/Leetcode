class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int target = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum % 2 != 0)
            return 0;
        target = sum/2; //Далее решаем классическую задачу о рюкзаке: можно ли из Nums собрать вес target?

        std::vector<bool> possible(target + 1, false);
        possible[0] = true;

        for (int i = 0; i < nums.size(); ++i)
            for (int x = target - nums[i]; x >= 0; --x) //либо вес был собран ранее
                possible[x + nums[i]] = possible[x + nums[i]] || possible[x]; //либо можно собрать прибавив вес nums[i]

        return possible[target];
    }
};
