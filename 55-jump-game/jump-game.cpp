class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1; i>0; i--) {
            // for i I try from i-1 to zero if I can reach
            bool canReach = false;

            for(int j=i-1; j>=0; j--) {
                if(j + nums[j] >= i) {
                    canReach = true;
                    break;
                }
            }

            if(canReach == false) {
                return false;
            }
        }
        return true;
    }
};