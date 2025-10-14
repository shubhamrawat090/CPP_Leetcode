class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIndex = nums[i];
            if (i != nums[i] && nums[i] < n) {
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else {
                i++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (j != nums[j]) {
                return j;
            }
        }

        return n;
    }
};