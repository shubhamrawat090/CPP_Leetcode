class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
        }

        for(int i=0; i<nums.size(); i++) {
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }
            temp.push_back(nums[i]);
            helper(ans, temp, nums);
            temp.pop_back();
        }
    }
};