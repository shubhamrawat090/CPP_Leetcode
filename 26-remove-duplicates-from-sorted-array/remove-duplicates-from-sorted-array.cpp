class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int writeIndex = 1;
        for (int readIndex = 1; readIndex < n; ++readIndex) {
            if (nums[readIndex] != nums[writeIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                ++writeIndex;
            }
        }
        return writeIndex;
    }
};