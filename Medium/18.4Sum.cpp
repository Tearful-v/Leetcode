class Solution {
public:

    void merge(std::vector<int>& nums, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<int> l(n1);
        std::vector<int> r(n2);
        for(int i = 0; i < n1; i++){
            l[i] = nums[left + i];
        }
        for(int j = 0; j < n2; j++){
            r[j] = nums[mid + 1 + j];
        }
        int k = left;
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2){
            if(l[i] < r[j]){
                nums[k] = l[i];
                i++;
            }
            else{
                nums[k] = r[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            nums[k] = l[i];
            i++;
            k++;
        }
        while(j < n2){
            nums[k] = r[j];
            j++;
            k++;
        }
    }

    void mergesort(std::vector<int>& nums, int left, int right){
        int mid = (left + right) >> 1;
        if(left < right){
            mergesort(nums, left, mid);
            mergesort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        std::vector<std::vector<int>>result;
        mergesort(nums, 0, nums.size()-1);
        for(long long i = 0; i < nums.size()-3; i++){
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for(long long j = i+1; j < nums.size()-2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                long long l = j+1;
                long long r = nums.size()-1;
                while(l < r){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target)
                        l++;
                    else if(sum == target){
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                    else if(sum > target)
                        r--;
                }
            }
        }
        return result;
    }
};