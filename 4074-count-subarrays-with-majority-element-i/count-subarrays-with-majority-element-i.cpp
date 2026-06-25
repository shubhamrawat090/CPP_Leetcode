class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // convert target = +1
        // convert others = -1
        // Count subarrays where sum > 0
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] == target ? 1 : -1;
        }

        int count = 0;
        for(int l=0; l<n; l++) {
            int sum = 0;
            for(int r = l; r<n; r++) {
                sum += nums[r];
                if(sum > 0) count++;
            }
        }
        return count;
    }
};