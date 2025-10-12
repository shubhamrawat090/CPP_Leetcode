class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        vector<int> ans;
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};