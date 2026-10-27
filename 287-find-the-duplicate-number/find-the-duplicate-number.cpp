class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            int correctIndex = nums[i] - 1;
            if(correctIndex == n || nums[correctIndex] == nums[i]) {
                i++;
            } else {
                swap(nums[i], nums[correctIndex]);
            }
        }

        int ans = n;
        for(int i=0; i<n; i++) {
            if(nums[i] != i+1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};