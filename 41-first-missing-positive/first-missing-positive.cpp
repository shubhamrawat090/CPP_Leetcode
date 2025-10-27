class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, N = nums.size();
        while (i < N) {
            if (nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        for (int j = 0; j < N; j++) {
            if (j + 1 != nums[j]) {
                return j + 1;
            }
        }

        return N + 1;
    }
};