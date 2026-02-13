class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sum;
        helper(nums, 0, nums.size()-1, ans, sum);
        return ans;
    }

    void helper(vector<int>& arr, int l, int r, vector<vector<int>>& ans, vector<int> sum) {
        if(l > r) {
            ans.push_back(sum);
            return;
        }
        // pick
        sum.push_back(arr[l]);
        helper(arr, l+1, r, ans, sum);
        sum.pop_back();
        // not pick
        helper(arr, l+1, r, ans, sum);
    }
};