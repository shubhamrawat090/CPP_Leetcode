class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, result);
        return result;
    }

    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);
        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums, i+1, path, result);
            path.pop_back();
        }
    }
};