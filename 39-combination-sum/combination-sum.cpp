class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, candidates, target, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int remain, int start) {
        if(remain < 0) {
            return;
        }

        if(remain == 0) {
            ans.push_back(temp);
        }

        for(int i=start; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(ans, temp, nums, remain - nums[i], i);
            temp.pop_back();
        }
    }
};