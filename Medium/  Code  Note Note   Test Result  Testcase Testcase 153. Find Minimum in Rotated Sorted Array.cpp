class Solution {
public:
    int findMin(vector<int>& nums) { //лівий бінарний пошук
        int left = 0;
        int right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            if (nums[left] < nums[mid] && nums[right] < nums[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return std::min(nums[left], nums[right]);
    }
};


/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};
*/
