class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i=0;
        while(i < n) {
            int correctIndex = nums[i];
            if(nums[i] < n && nums[i] != i) {
                swap(nums[correctIndex], nums[i]);
            } else {
                i++;
            }
        }

        int ans = n;
        for(int j=0; j<n; j++) {
            if(nums[j] != j) {
                ans = j;
                break;
            }
        }

        return ans;
    }
};