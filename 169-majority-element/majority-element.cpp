class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0], votes = 0;
        for(int i=0; i<n; i++) {
            if(votes == 0) {
                candidate = nums[i];
            }
            
            if(nums[i] == candidate) {
                votes++;
            } else {
                votes--;
            }
        }

        return candidate;
    }
};