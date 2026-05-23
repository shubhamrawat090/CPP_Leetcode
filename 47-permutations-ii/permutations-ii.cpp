class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }

    void helper(vector<int>& nums, int start, vector<vector<int>>& result) {
        if(start == nums.size()) {
            result.push_back(nums);
        }

        unordered_set<int> used;

        for(int i=start; i<nums.size(); i++) {
            if(used.count(nums[i])) continue; // Already used

            used.insert(nums[i]);
            swap(nums[i], nums[start]);

            helper(nums, start+1, result);
            
            swap(nums[i], nums[start]);
        }
    }
};