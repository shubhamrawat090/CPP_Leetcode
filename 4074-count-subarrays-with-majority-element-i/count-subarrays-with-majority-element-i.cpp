class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int count = 0;
        for(int l=0; l<n; l++) {
            int targetCount = 0;
            for(int r = l; r<n; r++) {
                if(target == nums[r]) targetCount++;
                if(targetCount > (r-l+1) / 2) count++;
            }
        }
        return count;
    }
};