class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currList;
        helper(nums, 0, currList, result);
        return result;
    }

    void helper(vector<int>& nums, int i, vector<int> currList, vector<vector<int>>& result) {
        if(i == nums.size()) {
            result.push_back(currList);
            return;
        }

        // include ith element
        currList.push_back(nums[i]);
        helper(nums, i+1, currList, result);
        currList.pop_back();
        // exclude ith element
        helper(nums, i+1, currList, result);
    }
};