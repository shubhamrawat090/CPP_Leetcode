class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for (int first = 0; first < n - 3; first++) {
            if (first != 0 && nums[first - 1] == nums[first])
                continue;

            for (int second = first + 1; second < n - 2; second++) {
                if (second > first + 1 && nums[second - 1] == nums[second])
                    continue;

                int third = second + 1;
                int fourth = n - 1;

                while (third < fourth) {
                    long long currSum =
                        (long long)nums[first] + (long long)nums[second] +
                        (long long)nums[third] + (long long)nums[fourth];
                    if (currSum > target) {
                        fourth--;
                    } else if (currSum < target) {
                        third++;
                    } else {
                        // FOUND TARGET
                        ans.push_back({nums[first], nums[second], nums[third],
                                       nums[fourth]});
                        third++, fourth--;
                        while (third < fourth && nums[third] == nums[third - 1])
                            third++;
                        while (third < fourth &&
                               nums[fourth] == nums[fourth + 1])
                            fourth--;
                    }
                }
            }
        }

        return ans;
    }
};