class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }

    void helper(vector<int>& nums, int start, vector<vector<int>>& result) {
        if(start == nums.size()) {
            result.push_back(nums);
        }

        for(int i=start; i<nums.size(); i++) {
            swap(nums[i], nums[start]);
            helper(nums, start+1, result);
            swap(nums[i], nums[start]);
        }
    }
};