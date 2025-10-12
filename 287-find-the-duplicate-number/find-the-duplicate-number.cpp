class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) {
                return nums[i];
            }
        }

        return -1; // DOESN'T MATTER WHAT YOU RETURN HERE. BECAUSE CODE NEVER REACHES HERE DUE TO THE NATURE OF THE TEST CASES
    }
};