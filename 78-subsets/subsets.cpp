class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSubset;
        subsetsHelper(nums, 0, ans, currSubset);
        return ans;
    }

    void subsetsHelper(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> &currSubset) {
        if(i == nums.size()) {
            ans.push_back(currSubset);
            return;
        }

        // Include
        currSubset.push_back(nums[i]);
        subsetsHelper(nums, i+1, ans, currSubset); 

        // Exclude
        currSubset.pop_back();
        subsetsHelper(nums, i+1, ans, currSubset); 
    }
};