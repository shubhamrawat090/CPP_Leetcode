class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = n-1;
        for(int i=n-2; i>=0; i--) {
            if(i + nums[i] >= reach) {
                reach = i;
            }
        }
        return reach == 0;
    }
};