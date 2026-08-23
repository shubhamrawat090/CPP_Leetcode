class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }

        while(ptr < n) {
            nums[ptr] = 0;
            ptr++;
        }
    }
};