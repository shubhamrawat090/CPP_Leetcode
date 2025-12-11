class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> ans;
        int n = nums.size();

        // Array is unsorted -> we sort it
        // NOTE: No need to sort the copy array because we need values not
        // indices
        sort(nums.begin(), nums.end());

        for (int first = 0; first < n - 2; first++) {
            // skip same values
            if (first > 0 && nums[first - 1] == nums[first]) {
                continue;
            }

            int second = first + 1;
            int third = n - 1;

            while (second < third) {
                int currSum = nums[first] + nums[second] + nums[third];
                if (currSum == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    // move both pointers
                    second++;
                    third--;
                    // skip duplicates for second and third
                    while (second < third && nums[second] == nums[second - 1])
                        second++;
                    while (second < third && nums[third] == nums[third + 1])
                        third--;
                } else if (currSum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return ans;
    }
};