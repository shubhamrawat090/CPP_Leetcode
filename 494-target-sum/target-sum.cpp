class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursive(nums, target, 0, 0);
    }

    int recursive(vector<int>& nums, int& target, int sum, int i) {
        int n = nums.size();
        if(i == n) {
            return sum == target ? 1 : 0;
        }

        // pick - make curr num minus(-), notPick - keep curr num plus(+)
        int pick = recursive(nums, target, sum - nums[i], i+1);
        int notPick = recursive(nums, target, sum + nums[i], i+1);
        return pick + notPick;
    }
};