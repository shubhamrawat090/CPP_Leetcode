class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0, n=nums.size();
        while(i < n) {
            if(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        int ans = n + 1;
        for(int j=0; j<n; j++) {
            if(nums[j] != j + 1) {
                ans = j + 1;
                break;
            }
        }

        return ans;
    }
};