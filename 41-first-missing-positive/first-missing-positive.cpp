class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // rearrange - cyclic sort
        while (i < n) {
            if (nums[i] != INT_MIN) {
                int correctIndex = nums[i] - 1;
                if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIndex]) {
                    swap(nums[i], nums[correctIndex]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (j + 1 != nums[j]) {
                return j + 1;
            }
        }

        return n + 1;
    }
};