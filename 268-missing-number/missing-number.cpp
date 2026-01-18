class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // sort(nums.begin(), nums.end());
        // // Rather than normal sorting we can use cyclic sort
        int i = 0;
        while(i < n) {
            int correctIndex = nums[i];
            if(i == nums[i] || nums[i] == n) {
                i++;
            } else {
                swap(nums[i], nums[correctIndex]);
            }
        }

        int ans = n;
        for(int i=0; i<n; i++) {
            if(i != nums[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};