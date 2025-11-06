class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ans, path);
        return ans;
    }

    void helper(vector<int>& nums, int start, vector<vector<int>>& ans, vector<int>& path) {
        ans.push_back(path);

        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums, i+1, ans, path);
            path.pop_back();
        }
    }
};