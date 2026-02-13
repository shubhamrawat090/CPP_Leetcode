class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subArr;
        sort(nums.begin(), nums.end());
        helper(nums, subArr, ans);
        return ans;
    }

    void helper(vector<int>& nums, vector<int>& subArr, vector<vector<int>>& ans) {
        if (subArr.size() == nums.size()) {
            ans.push_back(subArr);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(subArr.begin(), subArr.end(), nums[i]) != subArr.end()) {
                continue; // remove duplicates
            }
            subArr.push_back(nums[i]);
            helper(nums, subArr, ans);
            subArr.pop_back();
        }
    }
};