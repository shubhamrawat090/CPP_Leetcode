class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        helper(candidates, 0, target, result, path);
        return result;
    }

    void helper(vector<int>& nums, int i, int target, vector<vector<int>>& result, vector<int>& path) {
        if(target == 0) {
            result.push_back(path);
            return;
        }

        if(i == nums.size()) return; // No further possible

        // Take 
        if(target >= nums[i]) {
            path.push_back(nums[i]);
            helper(nums, i, target-nums[i], result, path);
            path.pop_back();
        }
        // Not take
        helper(nums, i+1, target, result, path);
    }
};