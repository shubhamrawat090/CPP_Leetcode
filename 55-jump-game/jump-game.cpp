class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = n-1;
        for(int i=n-2; i>=0; i--) {
            if(i + nums[i] >= farthest) {
                farthest = i;
            }
        }

        return farthest == 0;
    }
};