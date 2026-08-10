class NumArray {
public:
    NumArray(vector<int>& nums) : nums_(nums) {
        tree_.resize(nums_.size() + 1, 0);

        for (int i = 0; i < nums_.size(); ++i) {
            int current = nums_[i];
            int k = i + 1;

            while (k <= nums_.size()) {
                tree_[k] += current;
                k += k & -k;
            }
        }
    }

    void update(int index, int val) {
        int delta = val - nums_[index];
        nums_[index] = val;
        int k = index + 1;
        while (k < tree_.size()) {
            tree_[k] += delta;
            k += k & -k;
        }
    }

    int sumPrefix(int k) {
        int sum = 0;
        while (k >= 1) {
            sum += tree_[k];
            k -= k & -k;
        }
        return sum;
    }

    int sumRange(int left, int right) {
        return sumPrefix(right + 1) - sumPrefix(left);
    }

private:
    std::vector<int> nums_;
    std::vector<int> tree_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
