class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(nums, ans, path);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans,
                vector<int>& path) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(path.begin(), path.end(), nums[i]) != path.end()) {
                continue;
            }

            path.push_back(nums[i]);
            helper(nums, ans, path);
            path.pop_back();
        }
    }
};