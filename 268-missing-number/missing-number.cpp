class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i = 0;
        while(i < n) { // Rearrange
            int correctIndex =  nums[i];
            if(nums[i] < n && i != nums[i]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        // Check
        int ans = n;
        for(int j=0; j<n; j++) {
            if(j != nums[j]) {
                ans = j;
                break;
            }
        }
        return ans;
    }
};