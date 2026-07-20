class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        for (int first = 0; first <= n - 3; first++) {
            if(first > 0 && nums[first] == nums[first-1]) continue;
            int second = first + 1, third = n-1;
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) {
                    int firstVal = nums[first], secondVal = nums[second], thirdVal = nums[third];
                    // Skipping same values
                    while(second < third && nums[second] == secondVal) second++; 
                    while(second < third && nums[third] == thirdVal) third--; 
                    ans.push_back({firstVal, secondVal, thirdVal});
                } else if(sum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return ans;
    }
};