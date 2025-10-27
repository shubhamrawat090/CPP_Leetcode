class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, N = nums.size();
        while (i < N) {
            if (nums[i] != INT_MIN) {
                // if nums[i] = INT_MIN => -INF - 1 is not possible
                int correctIndex = nums[i] - 1;
                if (nums[i] != INT_MIN && nums[i] > 0 && nums[i] <= N &&
                    nums[i] != nums[correctIndex]) {
                    swap(nums[i], nums[correctIndex]);
                } else {
                    i++;
                }
            } else {
                i++;
            };
        }

        for (int j = 0; j < N; j++) {
            if (j + 1 != nums[j]) {
                return j + 1;
            }
        }

        return N + 1;
    }
};