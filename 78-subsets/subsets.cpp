class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subArr;
        helper(nums, 0, subArr, ans);
        return ans;
    }

    void helper(vector<int>& nums, int start, vector<int>& subArr, vector<vector<int>>& ans) {
        ans.push_back(subArr);

        for(int i=start; i<nums.size(); i++) {
            subArr.push_back(nums[i]);
            helper(nums, i+1, subArr, ans);
            subArr.pop_back();
        }
    }
};