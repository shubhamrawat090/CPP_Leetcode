class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int first = 0; first <= n - 4; first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second <= n - 3; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                int third = second + 1, fourth = n - 1;
                while (third < fourth) {
                    long long sum =
                        (long long)nums[first] + (long long)nums[second] +
                        (long long)nums[third] + (long long)nums[fourth];
                    if (sum == target) {
                        ans.push_back({nums[first], nums[second], nums[third],
                                       nums[fourth]});
                        int thirdVal = nums[third];
                        int fourthVal = nums[fourth];
                        // Skip duplicates
                        while (third < fourth && nums[third] == thirdVal)
                            third++;
                        while (third < fourth && nums[fourth] == fourthVal)
                            fourth--;
                    } else if (sum > target) {
                        fourth--;
                    } else {
                        third++;
                    }
                }
            }
        }

        return ans;
    }
};