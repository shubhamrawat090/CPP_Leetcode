class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = nums[0];
        int prev = nums[0];
        if(n > 1) {
            prev = max(nums[0], nums[1]);
        }

        for(int i=2; i<n; i++) {
            int take = nums[i] + prev2;
            int notTake =  prev;
            int curr = max(take, notTake);
            
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};