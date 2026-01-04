class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 6) continue;
            int sum = 0;
            int count = 0;
            for(int d = 2; d * d <= nums[i]; d++){
                if(nums[i] % d == 0){
                    int q = nums[i]/d;
                    if(d == q){
                        sum += d;
                        count++;
                    }
                    else{
                        sum += d + q;
                        count += 2;
                    }
                    if (count > 2)
                        break;
                }
            }
            if (count == 2)
                answer += sum + 1 + nums[i];
        }
        return answer;
    }
};