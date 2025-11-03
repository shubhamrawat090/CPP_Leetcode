class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        for(int j=0; j<n; j++) {
            if(j + 1 != nums[j]) {
                return nums[j];
            }
        }

        return -1;
    }
};