class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, 0, nums.size() - 1, ans, curr);
        return ans;
    }

    void helper(vector<int>& nums, int l, int r, vector<vector<int>>& ans, vector<int>& curr) {
        if(l > r) {
            ans.push_back(curr);
            return;
        }

        // INCLUDE
        curr.push_back(nums[l]);
        helper(nums, l + 1, r, ans, curr);

        // EXCLUDE
        curr.pop_back();
        helper(nums, l + 1, r, ans, curr);
    }
};