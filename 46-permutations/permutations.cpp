class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }

    void helper(vector<int>& nums, int start, vector<vector<int>>& ans) {
        int n = nums.size();
        if(start == n) {
            ans.push_back(nums);
            return;
        }

        for(int i=start; i<n; i++) {
            swap(nums[i], nums[start]);
            helper(nums, start+1, ans);
            swap(nums[i], nums[start]);
        }
    }
};